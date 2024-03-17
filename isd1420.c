#include "basic.h"

#define ISDCOMM		PA_Addr	  		//录放音地址/操作模式输入地址,linked to PA, 8255
#define I8255_PC	PC_Addr			//ISD1420控制输出口

#define VOICE_1_0x00 0x00
#define VOICE_2_0x10 0x10
#define VOICE_3_0x20 0x20
#define VOICE_4_0x30 0x30
#define VOICE_5_0x40 0x40
#define VOICE_6_0x50 0x50
#define VOICE_7_0x60 0x60
#define VOICE_8_0x70 0x70

#define VOICE_AD_0x80 0x80

#define PC4_BASE ((unsigned char)(4 << 1))
#define PC5_BASE ((unsigned char)(5 << 1))
#define PC6_BASE ((unsigned char)(6 << 1))
#define PC7_BASE ((unsigned char)(7 << 1))

#define SET_PC4(x) outportb(CON_Addr, (x)|PC4_BASE)
#define SET_PC5(x) outportb(CON_Addr, (x)|PC5_BASE)
#define SET_PC6(x) outportb(CON_Addr, (x)|PC6_BASE)
#define SET_PC7(x) outportb(CON_Addr, (x)|PC7_BASE)

#define SET_REC(x) SET_PC4(x)
#define SET_PLAYE(x) SET_PC5(x)
#define SET_PLAYL(x) SET_PC6(x)

u8 KeepMode;						//保存REC、PLAYE、PLAYL当前值

/* mode must be from 0 to 7 */
void write_mode(u8 mode) {
	SET_REC(mode & 0x1);
	SET_PLAYE((mode & 0x2) >> 1);
	SET_PLAYL((mode & 0x4) >> 2);
}

//延时
void Delay20ms()
{
	u16 i = 1320;
	while (--i)
	{;}
}

//延时0.25s（兼有键盘检测功能）
void Delay_025S()
{
	u16 i = 16000;
	while (i--) {;}
	i = 16000;
	while (i--) {;}
}

//延时
void Delay50ms()
{
	u16 i = 6600;
	while (--i) {;}
}

//初始化
void initISD()
{
	/* set REC, PLAYE, PLAYL to 1 */
	SET_REC(1);		//语音模块初始化，关闭录放音功能
	SET_PLAYE(1);
	SET_PLAYL(1);

	KeepMode = 7;							
	outportb(ISDCOMM, 0);	//允许手动录放音,当A6,A7为高时，无法手动放音
}

//停止录放音
void stopISD()
{
	u8 i = (KeepMode & 0xfb);  /* set PLAYL bit to 0 */
	write_mode(i);					//PLAYL:一个负脉冲停止放音
	i |= 4;
	write_mode(i);
	i |= 3;				
	/* set REC PLAYE PLAYL to 1 */	
	write_mode(i);					//1->REC,PLAYE, 关闭所有操作指令
	KeepMode = i;  
	outportb(ISDCOMM, 0);					//允许手动录放音,当A6,A7为高时，无法手动放音
	Delay50ms();
	Delay50ms();
	Delay50ms();
}

//操作模式
void modeISD(u8 mode)
{
	u8 i;
	stopISD();								//初始化,REC,PLAYE,PLAYL置位，设置操作模式
	outportb(ISDCOMM, mode);				//设置操作模式命令在mode中
	i = KeepMode & 0xfb;
	write_mode(i);					//给PLAYL一个上升沿,锁存命令
	i |= 4;
	write_mode(i);
	KeepMode = i;
}

//放音
void playISD(u8 startadr)
{
	u8 i;
	stopISD();								//暂停之前的录放音操作
	outportb(ISDCOMM, startadr);			//设置放音起始地址
	i = KeepMode & 0xfd;
	write_mode(i);					//0->PLAYE 开始放音,边沿放音模式
	i |= 2;
	write_mode(i);
	KeepMode = i;
}

//play for 2 sec
void KEY_PLAY(u8 startadr)
{
	u16 count = 8;  /* release the voice for 2 sec */
	playISD(startadr);							//调用录音子程序
	while (count--)
	{
		Delay_025S();					//延时
	}
}

//play for 4 sec
void KEY_PLAY4(u8 startadr)
{
	u16 count = 16;  /* release the voice for 4 sec */
	playISD(startadr);							//调用录音子程序
	while (count--)
	{
		Delay_025S();					//延时
	}
}
