/*
 * @Description: WS2812驱动头文件
 * @Author: Tomood
 * @Date: 2024-03-25 23:07:58
 * @LastEditTime: 2024-06-15 15:21:21
 * @FilePath: \ARGB-ligtcontroller\bsp\ws2812.h
 */
#ifndef __RGB_H
#define __RGB_H
#include "main.h"

/*灯参数宏*/
#define WS2812_NUM               30                            	     //WS2812串联个数
#define WS2812_DATA_LEN          24                           		 //WS2812数据长度(RGB888 = 24bit)
#define WS2812_BUF_SIZE          (WS2812_NUM + 1) * WS2812_DATA_LEN  //ws2812级联后需要的数组长度(需要增加复位码)

/*WS2812对应码元的定时器计数值 PWM周期：800 kHz*/
#define High_Code             40                        //1 码相对计数值
#define Low_Code              20-1                        //0 码相对计数值

/*生成PWM的定时器和通道定义*/
#define WS2812_TIM  htim17
#define WS2812_CHANNEL  TIM_CHANNEL_1 

extern uint16_t WS2812_Buf[];

//基础控制函数
void WS2812_Write_Data(uint32_t Color, uint8_t index);
void WS2812_Set_All(uint32_t Color);
void WS2812_Update(void);
uint32_t WS2812_rgb2color(uint8_t red, uint8_t green, uint8_t blue);
//灯控效果in while(1)
void WS2812_Rainbow(uint8_t speed);
void WS2812_RunningHorse(uint8_t speed,uint8_t color_offset);
#endif


