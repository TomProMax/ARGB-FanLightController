/*
* @Description: WS2812驱动-静态ROM表（可节省内存和提高代码执行速度）
 * @Author: Tomood
 * @Date: 2024-03-25 23:07:58
 * @LastEditTime: 2024-06-15 15:21:21
 * @FilePath: \ARGB-ligtcontroller\bsp\ws2812.h
 */
#ifndef ws2812_rom_table_h
#define ws2812_rom_table_h
#include "main.h"

//用于实现彩虹效果的数组 包含一个彩虹变换周期的数据
const uint32_t rainbow_buf[256*3] = {
		//Step1 G:0->255 ; R:255->0 ; B:0->0
		0x00ff00,
		0x01fe00,
		0x02fd00,
		0x03fc00,
		0x04fb00,
		0x05fa00,
		0x06f900,
		0x07f800,
		0x08f700,
		0x09f600,
		0x0af500,
		0x0bf400,
		0x0cf300,
		0x0df200,
		0x0ef100,
		0x0ff000,
		0x10ef00,
		0x11ee00,
		0x12ed00,
		0x13ec00,
		0x14eb00,
		0x15ea00,
		0x16e900,
		0x17e800,
		0x18e700,
		0x19e600,
		0x1ae500,
		0x1be400,
		0x1ce300,
		0x1de200,
		0x1ee100,
		0x1fe000,
		0x20df00,
		0x21de00,
		0x22dd00,
		0x23dc00,
		0x24db00,
		0x25da00,
		0x26d900,
		0x27d800,
		0x28d700,
		0x29d600,
		0x2ad500,
		0x2bd400,
		0x2cd300,
		0x2dd200,
		0x2ed100,
		0x2fd000,
		0x30cf00,
		0x31ce00,
		0x32cd00,
		0x33cc00,
		0x34cb00,
		0x35ca00,
		0x36c900,
		0x37c800,
		0x38c700,
		0x39c600,
		0x3ac500,
		0x3bc400,
		0x3cc300,
		0x3dc200,
		0x3ec100,
		0x3fc000,
		0x40bf00,
		0x41be00,
		0x42bd00,
		0x43bc00,
		0x44bb00,
		0x45ba00,
		0x46b900,
		0x47b800,
		0x48b700,
		0x49b600,
		0x4ab500,
		0x4bb400,
		0x4cb300,
		0x4db200,
		0x4eb100,
		0x4fb000,
		0x50af00,
		0x51ae00,
		0x52ad00,
		0x53ac00,
		0x54ab00,
		0x55aa00,
		0x56a900,
		0x57a800,
		0x58a700,
		0x59a600,
		0x5aa500,
		0x5ba400,
		0x5ca300,
		0x5da200,
		0x5ea100,
		0x5fa000,
		0x609f00,
		0x619e00,
		0x629d00,
		0x639c00,
		0x649b00,
		0x659a00,
		0x669900,
		0x679800,
		0x689700,
		0x699600,
		0x6a9500,
		0x6b9400,
		0x6c9300,
		0x6d9200,
		0x6e9100,
		0x6f9000,
		0x708f00,
		0x718e00,
		0x728d00,
		0x738c00,
		0x748b00,
		0x758a00,
		0x768900,
		0x778800,
		0x788700,
		0x798600,
		0x7a8500,
		0x7b8400,
		0x7c8300,
		0x7d8200,
		0x7e8100,
		0x7f8000,
		0x807f00,
		0x817e00,
		0x827d00,
		0x837c00,
		0x847b00,
		0x857a00,
		0x867900,
		0x877800,
		0x887700,
		0x897600,
		0x8a7500,
		0x8b7400,
		0x8c7300,
		0x8d7200,
		0x8e7100,
		0x8f7000,
		0x906f00,
		0x916e00,
		0x926d00,
		0x936c00,
		0x946b00,
		0x956a00,
		0x966900,
		0x976800,
		0x986700,
		0x996600,
		0x9a6500,
		0x9b6400,
		0x9c6300,
		0x9d6200,
		0x9e6100,
		0x9f6000,
		0xa05f00,
		0xa15e00,
		0xa25d00,
		0xa35c00,
		0xa45b00,
		0xa55a00,
		0xa65900,
		0xa75800,
		0xa85700,
		0xa95600,
		0xaa5500,
		0xab5400,
		0xac5300,
		0xad5200,
		0xae5100,
		0xaf5000,
		0xb04f00,
		0xb14e00,
		0xb24d00,
		0xb34c00,
		0xb44b00,
		0xb54a00,
		0xb64900,
		0xb74800,
		0xb84700,
		0xb94600,
		0xba4500,
		0xbb4400,
		0xbc4300,
		0xbd4200,
		0xbe4100,
		0xbf4000,
		0xc03f00,
		0xc13e00,
		0xc23d00,
		0xc33c00,
		0xc43b00,
		0xc53a00,
		0xc63900,
		0xc73800,
		0xc83700,
		0xc93600,
		0xca3500,
		0xcb3400,
		0xcc3300,
		0xcd3200,
		0xce3100,
		0xcf3000,
		0xd02f00,
		0xd12e00,
		0xd22d00,
		0xd32c00,
		0xd42b00,
		0xd52a00,
		0xd62900,
		0xd72800,
		0xd82700,
		0xd92600,
		0xda2500,
		0xdb2400,
		0xdc2300,
		0xdd2200,
		0xde2100,
		0xdf2000,
		0xe01f00,
		0xe11e00,
		0xe21d00,
		0xe31c00,
		0xe41b00,
		0xe51a00,
		0xe61900,
		0xe71800,
		0xe81700,
		0xe91600,
		0xea1500,
		0xeb1400,
		0xec1300,
		0xed1200,
		0xee1100,
		0xef1000,
		0xf00f00,
		0xf10e00,
		0xf20d00,
		0xf30c00,
		0xf40b00,
		0xf50a00,
		0xf60900,
		0xf70800,
		0xf80700,
		0xf90600,
		0xfa0500,
		0xfb0400,
		0xfc0300,
		0xfd0200,
		0xfe0100,
		0xff0000,
		//Step2 G:255->0 ; R:0 -> 0 ;  B:0->255
		0xff0000,
		0xfe0001,
		0xfd0002,
		0xfc0003,
		0xfb0004,
		0xfa0005,
		0xf90006,
		0xf80007,
		0xf70008,
		0xf60009,
		0xf5000a,
		0xf4000b,
		0xf3000c,
		0xf2000d,
		0xf1000e,
		0xf0000f,
		0xef0010,
		0xee0011,
		0xed0012,
		0xec0013,
		0xeb0014,
		0xea0015,
		0xe90016,
		0xe80017,
		0xe70018,
		0xe60019,
		0xe5001a,
		0xe4001b,
		0xe3001c,
		0xe2001d,
		0xe1001e,
		0xe0001f,
		0xdf0020,
		0xde0021,
		0xdd0022,
		0xdc0023,
		0xdb0024,
		0xda0025,
		0xd90026,
		0xd80027,
		0xd70028,
		0xd60029,
		0xd5002a,
		0xd4002b,
		0xd3002c,
		0xd2002d,
		0xd1002e,
		0xd0002f,
		0xcf0030,
		0xce0031,
		0xcd0032,
		0xcc0033,
		0xcb0034,
		0xca0035,
		0xc90036,
		0xc80037,
		0xc70038,
		0xc60039,
		0xc5003a,
		0xc4003b,
		0xc3003c,
		0xc2003d,
		0xc1003e,
		0xc0003f,
		0xbf0040,
		0xbe0041,
		0xbd0042,
		0xbc0043,
		0xbb0044,
		0xba0045,
		0xb90046,
		0xb80047,
		0xb70048,
		0xb60049,
		0xb5004a,
		0xb4004b,
		0xb3004c,
		0xb2004d,
		0xb1004e,
		0xb0004f,
		0xaf0050,
		0xae0051,
		0xad0052,
		0xac0053,
		0xab0054,
		0xaa0055,
		0xa90056,
		0xa80057,
		0xa70058,
		0xa60059,
		0xa5005a,
		0xa4005b,
		0xa3005c,
		0xa2005d,
		0xa1005e,
		0xa0005f,
		0x9f0060,
		0x9e0061,
		0x9d0062,
		0x9c0063,
		0x9b0064,
		0x9a0065,
		0x990066,
		0x980067,
		0x970068,
		0x960069,
		0x95006a,
		0x94006b,
		0x93006c,
		0x92006d,
		0x91006e,
		0x90006f,
		0x8f0070,
		0x8e0071,
		0x8d0072,
		0x8c0073,
		0x8b0074,
		0x8a0075,
		0x890076,
		0x880077,
		0x870078,
		0x860079,
		0x85007a,
		0x84007b,
		0x83007c,
		0x82007d,
		0x81007e,
		0x80007f,
		0x7f0080,
		0x7e0081,
		0x7d0082,
		0x7c0083,
		0x7b0084,
		0x7a0085,
		0x790086,
		0x780087,
		0x770088,
		0x760089,
		0x75008a,
		0x74008b,
		0x73008c,
		0x72008d,
		0x71008e,
		0x70008f,
		0x6f0090,
		0x6e0091,
		0x6d0092,
		0x6c0093,
		0x6b0094,
		0x6a0095,
		0x690096,
		0x680097,
		0x670098,
		0x660099,
		0x65009a,
		0x64009b,
		0x63009c,
		0x62009d,
		0x61009e,
		0x60009f,
		0x5f00a0,
		0x5e00a1,
		0x5d00a2,
		0x5c00a3,
		0x5b00a4,
		0x5a00a5,
		0x5900a6,
		0x5800a7,
		0x5700a8,
		0x5600a9,
		0x5500aa,
		0x5400ab,
		0x5300ac,
		0x5200ad,
		0x5100ae,
		0x5000af,
		0x4f00b0,
		0x4e00b1,
		0x4d00b2,
		0x4c00b3,
		0x4b00b4,
		0x4a00b5,
		0x4900b6,
		0x4800b7,
		0x4700b8,
		0x4600b9,
		0x4500ba,
		0x4400bb,
		0x4300bc,
		0x4200bd,
		0x4100be,
		0x4000bf,
		0x3f00c0,
		0x3e00c1,
		0x3d00c2,
		0x3c00c3,
		0x3b00c4,
		0x3a00c5,
		0x3900c6,
		0x3800c7,
		0x3700c8,
		0x3600c9,
		0x3500ca,
		0x3400cb,
		0x3300cc,
		0x3200cd,
		0x3100ce,
		0x3000cf,
		0x2f00d0,
		0x2e00d1,
		0x2d00d2,
		0x2c00d3,
		0x2b00d4,
		0x2a00d5,
		0x2900d6,
		0x2800d7,
		0x2700d8,
		0x2600d9,
		0x2500da,
		0x2400db,
		0x2300dc,
		0x2200dd,
		0x2100de,
		0x2000df,
		0x1f00e0,
		0x1e00e1,
		0x1d00e2,
		0x1c00e3,
		0x1b00e4,
		0x1a00e5,
		0x1900e6,
		0x1800e7,
		0x1700e8,
		0x1600e9,
		0x1500ea,
		0x1400eb,
		0x1300ec,
		0x1200ed,
		0x1100ee,
		0x1000ef,
		0x0f00f0,
		0x0e00f1,
		0x0d00f2,
		0x0c00f3,
		0x0b00f4,
		0x0a00f5,
		0x0900f6,
		0x0800f7,
		0x0700f8,
		0x0600f9,
		0x0500fa,
		0x0400fb,
		0x0300fc,
		0x0200fd,
		0x0100fe,
		0x0000ff,
		//Step3 G:0->0 ; R:0 -> 255 ;  B:255->0
		0x0000ff,
		0x0001fe,
		0x0002fd,
		0x0003fc,
		0x0004fb,
		0x0005fa,
		0x0006f9,
		0x0007f8,
		0x0008f7,
		0x0009f6,
		0x000af5,
		0x000bf4,
		0x000cf3,
		0x000df2,
		0x000ef1,
		0x000ff0,
		0x0010ef,
		0x0011ee,
		0x0012ed,
		0x0013ec,
		0x0014eb,
		0x0015ea,
		0x0016e9,
		0x0017e8,
		0x0018e7,
		0x0019e6,
		0x001ae5,
		0x001be4,
		0x001ce3,
		0x001de2,
		0x001ee1,
		0x001fe0,
		0x0020df,
		0x0021de,
		0x0022dd,
		0x0023dc,
		0x0024db,
		0x0025da,
		0x0026d9,
		0x0027d8,
		0x0028d7,
		0x0029d6,
		0x002ad5,
		0x002bd4,
		0x002cd3,
		0x002dd2,
		0x002ed1,
		0x002fd0,
		0x0030cf,
		0x0031ce,
		0x0032cd,
		0x0033cc,
		0x0034cb,
		0x0035ca,
		0x0036c9,
		0x0037c8,
		0x0038c7,
		0x0039c6,
		0x003ac5,
		0x003bc4,
		0x003cc3,
		0x003dc2,
		0x003ec1,
		0x003fc0,
		0x0040bf,
		0x0041be,
		0x0042bd,
		0x0043bc,
		0x0044bb,
		0x0045ba,
		0x0046b9,
		0x0047b8,
		0x0048b7,
		0x0049b6,
		0x004ab5,
		0x004bb4,
		0x004cb3,
		0x004db2,
		0x004eb1,
		0x004fb0,
		0x0050af,
		0x0051ae,
		0x0052ad,
		0x0053ac,
		0x0054ab,
		0x0055aa,
		0x0056a9,
		0x0057a8,
		0x0058a7,
		0x0059a6,
		0x005aa5,
		0x005ba4,
		0x005ca3,
		0x005da2,
		0x005ea1,
		0x005fa0,
		0x00609f,
		0x00619e,
		0x00629d,
		0x00639c,
		0x00649b,
		0x00659a,
		0x006699,
		0x006798,
		0x006897,
		0x006996,
		0x006a95,
		0x006b94,
		0x006c93,
		0x006d92,
		0x006e91,
		0x006f90,
		0x00708f,
		0x00718e,
		0x00728d,
		0x00738c,
		0x00748b,
		0x00758a,
		0x007689,
		0x007788,
		0x007887,
		0x007986,
		0x007a85,
		0x007b84,
		0x007c83,
		0x007d82,
		0x007e81,
		0x007f80,
		0x00807f,
		0x00817e,
		0x00827d,
		0x00837c,
		0x00847b,
		0x00857a,
		0x008679,
		0x008778,
		0x008877,
		0x008976,
		0x008a75,
		0x008b74,
		0x008c73,
		0x008d72,
		0x008e71,
		0x008f70,
		0x00906f,
		0x00916e,
		0x00926d,
		0x00936c,
		0x00946b,
		0x00956a,
		0x009669,
		0x009768,
		0x009867,
		0x009966,
		0x009a65,
		0x009b64,
		0x009c63,
		0x009d62,
		0x009e61,
		0x009f60,
		0x00a05f,
		0x00a15e,
		0x00a25d,
		0x00a35c,
		0x00a45b,
		0x00a55a,
		0x00a659,
		0x00a758,
		0x00a857,
		0x00a956,
		0x00aa55,
		0x00ab54,
		0x00ac53,
		0x00ad52,
		0x00ae51,
		0x00af50,
		0x00b04f,
		0x00b14e,
		0x00b24d,
		0x00b34c,
		0x00b44b,
		0x00b54a,
		0x00b649,
		0x00b748,
		0x00b847,
		0x00b946,
		0x00ba45,
		0x00bb44,
		0x00bc43,
		0x00bd42,
		0x00be41,
		0x00bf40,
		0x00c03f,
		0x00c13e,
		0x00c23d,
		0x00c33c,
		0x00c43b,
		0x00c53a,
		0x00c639,
		0x00c738,
		0x00c837,
		0x00c936,
		0x00ca35,
		0x00cb34,
		0x00cc33,
		0x00cd32,
		0x00ce31,
		0x00cf30,
		0x00d02f,
		0x00d12e,
		0x00d22d,
		0x00d32c,
		0x00d42b,
		0x00d52a,
		0x00d629,
		0x00d728,
		0x00d827,
		0x00d926,
		0x00da25,
		0x00db24,
		0x00dc23,
		0x00dd22,
		0x00de21,
		0x00df20,
		0x00e01f,
		0x00e11e,
		0x00e21d,
		0x00e31c,
		0x00e41b,
		0x00e51a,
		0x00e619,
		0x00e718,
		0x00e817,
		0x00e916,
		0x00ea15,
		0x00eb14,
		0x00ec13,
		0x00ed12,
		0x00ee11,
		0x00ef10,
		0x00f00f,
		0x00f10e,
		0x00f20d,
		0x00f30c,
		0x00f40b,
		0x00f50a,
		0x00f609,
		0x00f708,
		0x00f807,
		0x00f906,
		0x00fa05,
		0x00fb04,
		0x00fc03,
		0x00fd02,
		0x00fe01,
		0x00ff00
};

#endif

