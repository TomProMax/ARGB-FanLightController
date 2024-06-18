from queue import Queue

import pyaudiowpatch as pyaudio
import wave
import os

# 文件名字
filename = "loopback_record_class.wav"
# 数据格式 24bit
data_format = pyaudio.paInt24


class ARException(Exception):
    """Base class for AudioRecorder`s exceptions"""

 
class WASAPINotFound(ARException):
    ...


class InvalidDevice(ARException):
    ...


class AudioRecorder:
    CHUNK_SIZE = 512
    # 构造函数
    def __init__(self, p_audio: pyaudio.PyAudio, output_queue: Queue):
        self.p = p_audio
        self.output_queue = output_queue
        self.stream = None
                      
    # 静态方法 可以在不实例化类的情况下直接访问该方法
    @staticmethod
    # 找到WSAPI的默认设备
    def get_default_wasapi_device(p_audio: pyaudio.PyAudio):        
        try: # Get default WASAPI info
            wasapi_info = p_audio.get_host_api_info_by_type(pyaudio.paWASAPI)
        except OSError:
            raise WASAPINotFound("Looks like WASAPI is not available on the system")
        # Get default WASAPI speakers
        sys_default_speakers = p_audio.get_device_info_by_index(wasapi_info["defaultOutputDevice"])
        # 找到loopback设备
        if not sys_default_speakers["isLoopbackDevice"]:
            for loopback in p_audio.get_loopback_device_info_generator():
                if sys_default_speakers["name"] in loopback["name"]:
                    return loopback
                    break
            else:
                raise InvalidDevice("Default loopback output device not found.\n\nRun `python -m pyaudiowpatch` to check available devices")
    
    def callback(self, in_data, frame_count, time_info, status):
        """Write frames and return PA flag"""
        # 将loopback数据写入fifo
        self.output_queue.put(in_data)
        return (in_data, pyaudio.paContinue)
    
    def start_recording(self, target_device: dict):
        # 关闭之前打开的音频流 防止冲突
        self.close_stream()
        # 打开音频流
        self.stream = self.p.open(format=data_format,
                channels=target_device["maxInputChannels"],
                rate=int(target_device["defaultSampleRate"]),
                frames_per_buffer=self.CHUNK_SIZE,
                input=True,
                input_device_index=target_device["index"],
                stream_callback=self.callback
        )
        
    def stop_stream(self):
        self.stream.stop_stream()
        
    def start_stream(self):
        self.stream.start_stream()
    
    def close_stream(self):
        if self.stream is not None:
            self.stream.stop_stream()
            self.stream.close()
            self.stream = None
    # @property方法被装饰为属性，所以可以像访问属性一样来获取它的值，而不需要使用括号进行方法调用
    @property    
    def stream_status(self):
        return "closed" if self.stream is None else "stopped" if self.stream.is_stopped() else "running"


if __name__ == "__main__":
    # 创建audio流
    p  = pyaudio.PyAudio()
    #创建FIFO队列
    audio_queue = Queue()
    #实例化AudioRecorder类
    ar = AudioRecorder(p, audio_queue)
    #构建提示信息
    help_msg = 30*"-"+"\n\n\nStatus:\nRunning=%s | Device=%s | output=%s\n\nCommands:\nlist\nrecord\npause\ncontinue\nstop {*.wav\\default}\n"
    #初始化默认目标设备
    target_device = None
    
    try:
        while True:
            print(help_msg % (ar.stream_status, target_device["index"] if target_device is not None else "None", filename))
            # 获取用户键盘输入 并以空格为间隔符分割成列表
            com = input("Enter command: ").split()
            
            if com[0] == "list":
                p.print_detailed_system_info()
                
            elif com[0] == "record":
                try:
                    target_device = ar.get_default_wasapi_device(p)
                    print("Default WASAPI device:")
                    print(target_device)  # 打印设备信息
                except ARException as E:
                    print(f"Something went wrong... {type(E)} = {str(E)[:30]}...\n")
                    continue
                ar.start_recording(target_device)

            elif com[0] == "pause":
                ar.stop_stream()

            elif com[0] == "continue":
                ar.start_stream()

            elif com[0] == "stop":
                ar.close_stream()
                # 是否指定文件名
                if len(com)>1 and com[1].endswith(".wav") and os.path.exists(os.path.dirname(os.path.realpath(com[1]))):
                    filename = com[1]
                else:
                    filename = filename
                #写入文件
                wave_file = wave.open(filename, 'wb')
                wave_file.setnchannels(target_device["maxInputChannels"])
                wave_file.setsampwidth(pyaudio.get_sample_size(data_format))
                wave_file.setframerate(int(target_device["defaultSampleRate"]))
                #直到全部把队列的数据写进文件
                while not audio_queue.empty():
                    wave_file.writeframes(audio_queue.get())
                wave_file.close()
                print(f"The audio is written to a [{filename}]. Exit...")
                break
            else:
                print(f"[{com[0]}] is unknown command")
    # 捕获键盘中断异常
    except KeyboardInterrupt:
        print("\n\nExit without saving...")
    finally:       
        ar.close_stream()
        p.terminate()
        