/********************************************************		
*		12864J液晶显示器
*12864J：1.图形点阵液晶显示器，分辨率为128X64。可显示图形
*	   和8×4个(16×16点阵)汉字。
*	 2.采用8位数据总线并行输入输出和8条控制线。
* 	 3.指令简单，7种指令
********************************************************/

#include "12864.h"
#include "basic.h"
#include "kb_8255.h"
#include "word_lib.h"
#include "isd1420.h"

#define	IO8259_0	0x250
#define	IO8259_1	0x251

#define D_ORDER 1
#define D_REVERSE 0

/* discard "shake" when the keys are pushed */
void delayLittle() {
	unsigned char i;
	unsigned int j;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 0xf000; j++)
		{;}
	}
}
/* ----------------------------------------------------- */
/* ----------------------------------------------------- */

/* Display "欢迎使用报站器" */
void DisHYSY();

/* "出站" function with rolling */
void chuzhanROLL(u8 station, u8 directioin);

/* "出站" function */
void chuzhan(u8 station, u8 directioin);

/* "进站" function */
void jinzhan(u8 station, u8 direction);

/* play "进站" related voice */
void jinzhanVoice(u8 station, u8 direction);

/* show advertisement */
void guanggao();

/* play advertisement voice */
void guanggaoVOICE();

void reverseDirection(unsigned char *station, unsigned char *direction);

void nextStation(unsigned char *station, unsigned char *direction);

void prevStation(unsigned char *station, unsigned char *direction);

/* ----------------------------------------------------- */
/* ----------------------------------------------------- */

/* initialize 8259 */
void Init8259()
{
	outportb(IO8259_0,0x13);  /* ICW1 */
	outportb(IO8259_1,0x8);	  /* ICW2 */
	outportb(IO8259_1,0x9);	  /* ICW3 */
	outportb(IO8259_1,0xfe);  /* OCW1 */
}

u8 g_direction = D_ORDER;
u8 g_station = 0;
u8 g_guanggao_status = 0;

/* core interrupt handler */
void interrupt INT_0x8(void)
{
	u8 key_value;
	if (scan_any_pushed()) {
		key_value = get_key_value();
		switch (key_value)
		{
		case 0:
			/* 上/下行 */
			reverseDirection(&g_station, &g_direction);  /* reverse the direction */
			delayLittle();
			break;
		case 1:
			/* 进一站 */
			nextStation(&g_station, &g_direction);
			delayLittle();
			break;
		case 2:
			/* 出站 */
			chuzhanROLL(g_station, g_direction);
			delayLittle();  /* add for delaying the interrupt handler */
			break;
		case 4:
			/* 广告 */
			guanggao(g_guanggao_status);
			guanggaoVOICE();
			g_guanggao_status++;
			g_guanggao_status %= 3;
			delayLittle();
			break;
		case 5:
			/* 退一站 */
			prevStation(&g_station, &g_direction);
			delayLittle();
			break;
		case 6:
			/* 进站 */
			jinzhan(g_station, g_direction);
			jinzhanVoice(g_station, g_direction);
			nextStation(&g_station, &g_direction);
			delayLittle();
			break;
		}
	}
	outportb(IO8259_0,0x20);  /* general EOI */
}

/* Display "欢迎使用报站器" */
void DisHYSY() {
	Dis(2, 0, LEFT_SCREEN, FOUR_WORD_LEN, hysybzq);
	Dis(2, 0, RIGHT_SCREEN, THREE_WORD_LEN, &hysybzq[4*WORD_SIZE]);
}

/* "出站" function with rolling */
void chuzhanROLL(u8 station, u8 directioin) {
	u8 row = 2;
	LCD_INIT();
	if (directioin == D_ORDER)
	{
		/* in order: from 0火车站 to 7仁安医院 */
		switch (station)
		{
		case 0:
			CZ4DisRoll(row, whjd);  /* 文海酒店 */
			break;
		case 1:
			CZ3DisRoll(row, zjf);  /* 张家坊 */
			break;
		case 2:
			CZ4DisRoll(row, gjdq);  /* 赣江大桥 */
			break;
		case 3:
			CZ3DisRoll(row, lsc);  /* 岭上村 */
			break;
		case 4:
			CZ4DisRoll(row, tjgd);  /* 天际光电 */
			break;
		case 5:
			CZ4DisRoll(row, zgsh);  /* 中国石化 */
			break;
		case 6:
			CZ4DisRoll(row, rayy);  /* 仁安医院 */
			break;
		}
	} else {
		/* reverse order: from 7仁安医院 to 0火车站 */
		switch (station)
		{
		case 1:
			CZ3DisRoll(row, hcz);  /* 火车站 */
			break;
		case 2:
			CZ4DisRoll(row, whjd);  /* 文海酒店 */
			break;
		case 3:
			CZ3DisRoll(row, zjf);  /* 张家坊 */
			break;
		case 4:
			CZ4DisRoll(row, gjdq);  /* 赣江大桥 */
			break;
		case 5:
			CZ3DisRoll(row, lsc);  /* 岭上村 */
			break;
		case 6:
			CZ4DisRoll(row, tjgd);  /* 天际光电 */
			break;
		case 7:
			CZ4DisRoll(row, zgsh);  /* 中国石化 */
		}
	}
	DelayTime();
	DelayTime();
}

/* "出站" function */
void chuzhan(u8 station, u8 directioin) {
	u8 row = 2;
	LCD_INIT();
	Dis(row, 0, LEFT_SCREEN, FOUR_WORD_LEN, xyz);  /* 下一站__ */
	if (directioin == D_ORDER)
	{
		/* in order: from 0火车站 to 7仁安医院 */
		switch (station)
		{
		case 0:
			Dis(row, 0, RIGHT_SCREEN, FOUR_WORD_LEN, whjd);  /* 文海酒店 */
			break;
		case 1:
			Dis(row, 0, RIGHT_SCREEN, THREE_WORD_LEN, zjf);  /* 张家坊 */
			break;
		case 2:
			Dis(row, 0, RIGHT_SCREEN, FOUR_WORD_LEN, gjdq);  /* 赣江大桥 */
			break;
		case 3:
			Dis(row, 0, RIGHT_SCREEN, THREE_WORD_LEN, lsc);  /* 岭上村 */
			break;
		case 4:
			Dis(row, 0, RIGHT_SCREEN, FOUR_WORD_LEN, tjgd);  /* 天际光电 */
			break;
		case 5:
			Dis(row, 0, RIGHT_SCREEN, FOUR_WORD_LEN, zgsh);  /* 中国石化 */
			break;
		case 6:
			Dis(row, 0, RIGHT_SCREEN, FOUR_WORD_LEN, rayy);  /* 仁安医院 */
			break;
		}
	} else {
		/* reverse order: from 7仁安医院 to 0火车站 */
		switch (station)
		{
		case 1:
			Dis(row, 0, RIGHT_SCREEN, THREE_WORD_LEN, hcz);  /* 火车站 */
			break;
		case 2:
			Dis(row, 0, RIGHT_SCREEN, FOUR_WORD_LEN, whjd);  /* 文海酒店 */
			break;
		case 3:
			Dis(row, 0, RIGHT_SCREEN, THREE_WORD_LEN, zjf);  /* 张家坊 */
			break;
		case 4:
			Dis(row, 0, RIGHT_SCREEN, FOUR_WORD_LEN, gjdq);  /* 赣江大桥 */
			break;
		case 5:
			Dis(row, 0, RIGHT_SCREEN, THREE_WORD_LEN, lsc);  /* 岭上村 */
			break;
		case 6:
			Dis(row, 0, RIGHT_SCREEN, FOUR_WORD_LEN, tjgd);  /* 天际光电 */
			break;
		case 7:
			Dis(row, 0, RIGHT_SCREEN, FOUR_WORD_LEN, zgsh);  /* 中国石化 */
		}
	}
	DelayTime();
	DelayTime();
}
/* "进站" function */
void jinzhan(u8 station, u8 direction) {
	u8 row = 2;
	LCD_INIT();
	if (direction == D_ORDER) {
		switch (station)
		{
		case 0:
			Dis(row, 0, LEFT_SCREEN, FOUR_WORD_LEN, whjd);  /* 文海酒店 */
			break;
		case 1:
			Dis(row, 0, LEFT_SCREEN, THREE_WORD_LEN, zjf);  /* 张家坊 */
			break;
		case 2:
			Dis(row, 0, LEFT_SCREEN, FOUR_WORD_LEN, gjdq);  /* 赣江大桥 */
			break;
		case 3:
			Dis(row, 0, LEFT_SCREEN, THREE_WORD_LEN, lsc);  /* 岭上村 */
			break;
		case 4:
			Dis(row, 0, LEFT_SCREEN, FOUR_WORD_LEN, tjgd);  /* 天际光电 */
			break;
		case 5:
			Dis(row, 0, LEFT_SCREEN, FOUR_WORD_LEN, zgsh);  /* 中国石化 */
			break;
		case 6:
			Dis(row, 0, LEFT_SCREEN, FOUR_WORD_LEN, rayy);  /* 仁安医院 */
			break;
		}
	} else {
		switch (station)
		{
		case 1:
			Dis(row, 0, LEFT_SCREEN, THREE_WORD_LEN, hcz);  /* 火车站 */
			break;
		case 2:
			Dis(row, 0, LEFT_SCREEN, FOUR_WORD_LEN, whjd);  /* 文海酒店 */
			break;
		case 3:
			Dis(row, 0, LEFT_SCREEN, THREE_WORD_LEN, zjf);  /* 张家坊 */
			break;
		case 4:
			Dis(row, 0, LEFT_SCREEN, FOUR_WORD_LEN, gjdq);  /* 赣江大桥 */
			break;
		case 5:
			Dis(row, 0, LEFT_SCREEN, THREE_WORD_LEN, lsc);  /* 岭上村 */
			break;
		case 6:
			Dis(row, 0, LEFT_SCREEN, FOUR_WORD_LEN, tjgd);  /* 天际光电 */
			break;
		case 7:
			Dis(row, 0, LEFT_SCREEN, FOUR_WORD_LEN, zgsh);  /* 中国石化 */
		}
	}
	Dis(row, 0, RIGHT_SCREEN, THREE_WORD_LEN, dl);  /* "  到了" */
	DelayTime();
	DelayTime();
}

void jinzhanVoice(u8 station, u8 direction) {
	if (direction == D_ORDER) {
		switch (station)
		{
		case 0:
			KEY_PLAY(VOICE_2_0x10);  /* 文海酒店 */
			break;
		case 1:
			KEY_PLAY(VOICE_3_0x20);  /* 张家坊 */
			break;
		case 2:
			KEY_PLAY(VOICE_4_0x30);  /* 赣江大桥 */
			break;
		case 3:
			KEY_PLAY(VOICE_5_0x40);  /* 岭上村 */
			break;
		case 4:
			KEY_PLAY(VOICE_6_0x50);  /* 天际光电 */
			break;
		case 5:
			KEY_PLAY(VOICE_7_0x60);  /* 中国石化 */
			break;
		case 6:
			KEY_PLAY(VOICE_8_0x70);  /* 仁安医院 */
			break;
		}
	} else {
		switch (station)
		{
		case 1:
			KEY_PLAY(VOICE_1_0x00);  /* 火车站 */
			break;
		case 2:
			KEY_PLAY(VOICE_2_0x10);  /* 文海酒店 */
			break;
		case 3:
			KEY_PLAY(VOICE_3_0x20);  /* 张家坊 */
			break;
		case 4:
			KEY_PLAY(VOICE_4_0x30);  /* 赣江大桥 */
			break;
		case 5:
			KEY_PLAY(VOICE_5_0x40);  /* 岭上村 */
			break;
		case 6:
			KEY_PLAY(VOICE_6_0x50);  /* 天际光电 */
			break;
		case 7:
			KEY_PLAY(VOICE_7_0x60);  /* 中国石化 */
		}
	}
}

/* show advertisement */
void guanggao(u8 status) {
	LCDClear();
	switch (status)
	{
	case 0:
		DisIMGl(myImg);
		DisIMGr(myImg2);
		break;
	case 1:
		DisIMGl(myImg3);
		DisIMGr(myImg4);
		break;
	case 2:
		DisIMGl(myImg5);
		DisIMGr(myImg6);
		break;
	}

	// DisIMG1();
	// DisIMG2();
	DelayTime();
	DelayTime();
	DelayTime();
}

void guanggaoVOICE() {
	KEY_PLAY(VOICE_AD_0x80);
}

void nextStation(unsigned char *station, unsigned char *direction) {
	/* 进一站 */
	if (*direction == D_ORDER) {
		(*station)++;
		if (*station == 7) {
			/* already arrived at the final station */
			*direction = D_REVERSE;
		}
	} else {
		(*station)--;
		if (*station == 0) {
			/* already arrived at the original station */
			*direction = D_ORDER;
		}
	}
	(*station) &= 0x7;
}

void prevStation(unsigned char *station, unsigned char *direction) {
	/* in order and the station is the original now. there is no previous station */
	if (*direction == D_ORDER && *station == 0)
		return ;
	
	/* in reverse order and the station is the final now. there is no previous station */
	if (*direction == D_REVERSE && *station == 7) 
		return ;
	
	if (*direction == D_ORDER) {
		(*station)--;
	} else {
		(*station)++;
	}
	*station &= 0x7;
}

void reverseDirection(unsigned char *station, unsigned char *direction) {
	if (*station == 0 && *direction == D_ORDER) 
		return ;
	if (*station == 7 && *direction == D_REVERSE) 
		return ;
	*direction = !(*direction);
}

void main_old()
{
	u8 station = 0;
	u8 key_value = 0;
	u8 direction = D_ORDER;
	u8 guanggao_status = 0;

	/* start */
	init8255();	/* initialize 8255 */
	initISD();
	LCD_INIT();
	DisHYSY();
	DelayTime();

	while (1)
	{
		if (scan_any_pushed()) {
			key_value = get_key_value();
			switch (key_value)
			{
			case 0:
				/* 上/下行 */
				reverseDirection(&station, &direction);  /* reverse the direction */
				delayLittle();
				break;
			case 1:
				/* 进一站 */
				nextStation(&station, &direction);
				delayLittle();
				break;
			case 2:
				/* 出站 */
				chuzhanROLL(station, direction);
				break;
			case 4:
				/* 广告 */
				guanggao(guanggao_status);
				guanggaoVOICE();
				guanggao_status++;
				guanggao_status %= 3;
				delayLittle();
				break;
			case 5:
				/* 退一站 */
				prevStation(&station, &direction);
				delayLittle();
				break;
			case 6:
				/* 进站 */
				jinzhan(station, direction);
				jinzhanVoice(station, direction);
				nextStation(&station, &direction);
				delayLittle();
				break;
			}
		}
	}
	
}

/* use interrupt */
void main() {
	disable();					//关中断
	/* start */
	/* ------changes for 8259------ */
	Init8259(); /* 8259 */
	setvect(8, INT_0x8);			//初始化中断向量, 8:第8号中断向量,INT_0:中断处理程序
	/* ---------------------------- */
	init8255();	/* initialize 8255 */
	initISD();
	LCD_INIT();
	DisHYSY();
	DelayTime();
	enable();					//开中断
	while(1)
	{
		outportb(PB_Addr, 0x0);
	}
}