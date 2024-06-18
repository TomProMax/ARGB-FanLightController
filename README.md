<!--
 * @Description: en
 * @Author: Tomood
 * @Date: 2024-06-17 23:59:19
 * @LastEditors: Tomood
 * @LastEditTime: 2024-06-18 11:45:11
 * @FilePath: \PythonProjecte:\STM32project\ARGB-ligtcontroller\README.md
 * Copyright (c) 2024 by Tomood, All Rights Reserved. 
-->
# ARGB-FanLightController
立创开源硬件平台: [Oshwhub-ARGB-FanLightController](https://oshwhub.com/tompromax/argb-light-controller)
## Introduction
An ARGB-Fan's Light Controller based on STM32F030 with python host

## How to deploy on the STM32 platform
To deploy the driver on your stm32(or other 32bit MCU) ,just follow the following this steps:<br />
1.cp the ws2812.c ws2812.h ws2812_rom_table.h to your new prj.<br />
2.**rewrite the defines** in **ws2812.h**.<br />
3.**rewrite the DMA interrupt's Callback api** and recofig your DMA and TIMER.<br />
Then enjoy your job.<br />

## About python host program
The host computer program is for these funtion:<br />
1.CPU temperature/usage monitoring.<br />
2.music spectrum display(Use WSAPI loopback).<br />
the host is **not yet complete**.

## About Issues
if you have some problems in this prj ,please submit issues.
