/********************************************************		
*		12864JҺ����ʾ��
*12864J��1.ͼ�ε���Һ����ʾ�����ֱ���Ϊ128X64������ʾͼ��
*	   ��8��4��(16��16����)���֡�
*	 2.����8λ�������߲������������8�������ߡ�
* 	 3.ָ��򵥣�7��ָ��
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

/* Display "��ӭʹ�ñ�վ��" */
void DisHYSY();

/* "��վ" function with rolling */
void chuzhanROLL(u8 station, u8 directioin);

/* "��վ" function */
void chuzhan(u8 station, u8 directioin);

/* "��վ" function */
void jinzhan(u8 station, u8 direction);

/* play "��վ" related voice */
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
			/* ��/���� */
			reverseDirection(&g_station, &g_direction);  /* reverse the direction */
			delayLittle();
			break;
		case 1:
			/* ��һվ */
			nextStation(&g_station, &g_direction);
			delayLittle();
			break;
		case 2:
			/* ��վ */
			chuzhanROLL(g_station, g_direction);
			delayLittle();  /* add for delaying the interrupt handler */
			break;
		case 4:
			/* ��� */
			guanggao(g_guanggao_status);
			guanggaoVOICE();
			g_guanggao_status++;
			g_guanggao_status %= 3;
			delayLittle();
			break;
		case 5:
			/* ��һվ */
			prevStation(&g_station, &g_direction);
			delayLittle();
			break;
		case 6:
			/* ��վ */
			jinzhan(g_station, g_direction);
			jinzhanVoice(g_station, g_direction);
			nextStation(&g_station, &g_direction);
			delayLittle();
			break;
		}
	}
	outportb(IO8259_0,0x20);  /* general EOI */
}

/* Display "��ӭʹ�ñ�վ��" */
void DisHYSY() {
	Dis(2, 0, LEFT_SCREEN, FOUR_WORD_LEN, hysybzq);
	Dis(2, 0, RIGHT_SCREEN, THREE_WORD_LEN, &hysybzq[4*WORD_SIZE]);
}

/* "��վ" function with rolling */
void chuzhanROLL(u8 station, u8 directioin) {
	u8 row = 2;
	LCD_INIT();
	if (directioin == D_ORDER)
	{
		/* in order: from 0��վ to 7�ʰ�ҽԺ */
		switch (station)
		{
		case 0:
			CZ4DisRoll(row, whjd);  /* �ĺ��Ƶ� */
			break;
		case 1:
			CZ3DisRoll(row, zjf);  /* �żҷ� */
			break;
		case 2:
			CZ4DisRoll(row, gjdq);  /* �ӽ����� */
			break;
		case 3:
			CZ3DisRoll(row, lsc);  /* ���ϴ� */
			break;
		case 4:
			CZ4DisRoll(row, tjgd);  /* ��ʹ�� */
			break;
		case 5:
			CZ4DisRoll(row, zgsh);  /* �й�ʯ�� */
			break;
		case 6:
			CZ4DisRoll(row, rayy);  /* �ʰ�ҽԺ */
			break;
		}
	} else {
		/* reverse order: from 7�ʰ�ҽԺ to 0��վ */
		switch (station)
		{
		case 1:
			CZ3DisRoll(row, hcz);  /* ��վ */
			break;
		case 2:
			CZ4DisRoll(row, whjd);  /* �ĺ��Ƶ� */
			break;
		case 3:
			CZ3DisRoll(row, zjf);  /* �żҷ� */
			break;
		case 4:
			CZ4DisRoll(row, gjdq);  /* �ӽ����� */
			break;
		case 5:
			CZ3DisRoll(row, lsc);  /* ���ϴ� */
			break;
		case 6:
			CZ4DisRoll(row, tjgd);  /* ��ʹ�� */
			break;
		case 7:
			CZ4DisRoll(row, zgsh);  /* �й�ʯ�� */
		}
	}
	DelayTime();
	DelayTime();
}

/* "��վ" function */
void chuzhan(u8 station, u8 directioin) {
	u8 row = 2;
	LCD_INIT();
	Dis(row, 0, LEFT_SCREEN, FOUR_WORD_LEN, xyz);  /* ��һվ__ */
	if (directioin == D_ORDER)
	{
		/* in order: from 0��վ to 7�ʰ�ҽԺ */
		switch (station)
		{
		case 0:
			Dis(row, 0, RIGHT_SCREEN, FOUR_WORD_LEN, whjd);  /* �ĺ��Ƶ� */
			break;
		case 1:
			Dis(row, 0, RIGHT_SCREEN, THREE_WORD_LEN, zjf);  /* �żҷ� */
			break;
		case 2:
			Dis(row, 0, RIGHT_SCREEN, FOUR_WORD_LEN, gjdq);  /* �ӽ����� */
			break;
		case 3:
			Dis(row, 0, RIGHT_SCREEN, THREE_WORD_LEN, lsc);  /* ���ϴ� */
			break;
		case 4:
			Dis(row, 0, RIGHT_SCREEN, FOUR_WORD_LEN, tjgd);  /* ��ʹ�� */
			break;
		case 5:
			Dis(row, 0, RIGHT_SCREEN, FOUR_WORD_LEN, zgsh);  /* �й�ʯ�� */
			break;
		case 6:
			Dis(row, 0, RIGHT_SCREEN, FOUR_WORD_LEN, rayy);  /* �ʰ�ҽԺ */
			break;
		}
	} else {
		/* reverse order: from 7�ʰ�ҽԺ to 0��վ */
		switch (station)
		{
		case 1:
			Dis(row, 0, RIGHT_SCREEN, THREE_WORD_LEN, hcz);  /* ��վ */
			break;
		case 2:
			Dis(row, 0, RIGHT_SCREEN, FOUR_WORD_LEN, whjd);  /* �ĺ��Ƶ� */
			break;
		case 3:
			Dis(row, 0, RIGHT_SCREEN, THREE_WORD_LEN, zjf);  /* �żҷ� */
			break;
		case 4:
			Dis(row, 0, RIGHT_SCREEN, FOUR_WORD_LEN, gjdq);  /* �ӽ����� */
			break;
		case 5:
			Dis(row, 0, RIGHT_SCREEN, THREE_WORD_LEN, lsc);  /* ���ϴ� */
			break;
		case 6:
			Dis(row, 0, RIGHT_SCREEN, FOUR_WORD_LEN, tjgd);  /* ��ʹ�� */
			break;
		case 7:
			Dis(row, 0, RIGHT_SCREEN, FOUR_WORD_LEN, zgsh);  /* �й�ʯ�� */
		}
	}
	DelayTime();
	DelayTime();
}
/* "��վ" function */
void jinzhan(u8 station, u8 direction) {
	u8 row = 2;
	LCD_INIT();
	if (direction == D_ORDER) {
		switch (station)
		{
		case 0:
			Dis(row, 0, LEFT_SCREEN, FOUR_WORD_LEN, whjd);  /* �ĺ��Ƶ� */
			break;
		case 1:
			Dis(row, 0, LEFT_SCREEN, THREE_WORD_LEN, zjf);  /* �żҷ� */
			break;
		case 2:
			Dis(row, 0, LEFT_SCREEN, FOUR_WORD_LEN, gjdq);  /* �ӽ����� */
			break;
		case 3:
			Dis(row, 0, LEFT_SCREEN, THREE_WORD_LEN, lsc);  /* ���ϴ� */
			break;
		case 4:
			Dis(row, 0, LEFT_SCREEN, FOUR_WORD_LEN, tjgd);  /* ��ʹ�� */
			break;
		case 5:
			Dis(row, 0, LEFT_SCREEN, FOUR_WORD_LEN, zgsh);  /* �й�ʯ�� */
			break;
		case 6:
			Dis(row, 0, LEFT_SCREEN, FOUR_WORD_LEN, rayy);  /* �ʰ�ҽԺ */
			break;
		}
	} else {
		switch (station)
		{
		case 1:
			Dis(row, 0, LEFT_SCREEN, THREE_WORD_LEN, hcz);  /* ��վ */
			break;
		case 2:
			Dis(row, 0, LEFT_SCREEN, FOUR_WORD_LEN, whjd);  /* �ĺ��Ƶ� */
			break;
		case 3:
			Dis(row, 0, LEFT_SCREEN, THREE_WORD_LEN, zjf);  /* �żҷ� */
			break;
		case 4:
			Dis(row, 0, LEFT_SCREEN, FOUR_WORD_LEN, gjdq);  /* �ӽ����� */
			break;
		case 5:
			Dis(row, 0, LEFT_SCREEN, THREE_WORD_LEN, lsc);  /* ���ϴ� */
			break;
		case 6:
			Dis(row, 0, LEFT_SCREEN, FOUR_WORD_LEN, tjgd);  /* ��ʹ�� */
			break;
		case 7:
			Dis(row, 0, LEFT_SCREEN, FOUR_WORD_LEN, zgsh);  /* �й�ʯ�� */
		}
	}
	Dis(row, 0, RIGHT_SCREEN, THREE_WORD_LEN, dl);  /* "  ����" */
	DelayTime();
	DelayTime();
}

void jinzhanVoice(u8 station, u8 direction) {
	if (direction == D_ORDER) {
		switch (station)
		{
		case 0:
			KEY_PLAY(VOICE_2_0x10);  /* �ĺ��Ƶ� */
			break;
		case 1:
			KEY_PLAY(VOICE_3_0x20);  /* �żҷ� */
			break;
		case 2:
			KEY_PLAY(VOICE_4_0x30);  /* �ӽ����� */
			break;
		case 3:
			KEY_PLAY(VOICE_5_0x40);  /* ���ϴ� */
			break;
		case 4:
			KEY_PLAY(VOICE_6_0x50);  /* ��ʹ�� */
			break;
		case 5:
			KEY_PLAY(VOICE_7_0x60);  /* �й�ʯ�� */
			break;
		case 6:
			KEY_PLAY(VOICE_8_0x70);  /* �ʰ�ҽԺ */
			break;
		}
	} else {
		switch (station)
		{
		case 1:
			KEY_PLAY(VOICE_1_0x00);  /* ��վ */
			break;
		case 2:
			KEY_PLAY(VOICE_2_0x10);  /* �ĺ��Ƶ� */
			break;
		case 3:
			KEY_PLAY(VOICE_3_0x20);  /* �żҷ� */
			break;
		case 4:
			KEY_PLAY(VOICE_4_0x30);  /* �ӽ����� */
			break;
		case 5:
			KEY_PLAY(VOICE_5_0x40);  /* ���ϴ� */
			break;
		case 6:
			KEY_PLAY(VOICE_6_0x50);  /* ��ʹ�� */
			break;
		case 7:
			KEY_PLAY(VOICE_7_0x60);  /* �й�ʯ�� */
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
	/* ��һվ */
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
				/* ��/���� */
				reverseDirection(&station, &direction);  /* reverse the direction */
				delayLittle();
				break;
			case 1:
				/* ��һվ */
				nextStation(&station, &direction);
				delayLittle();
				break;
			case 2:
				/* ��վ */
				chuzhanROLL(station, direction);
				break;
			case 4:
				/* ��� */
				guanggao(guanggao_status);
				guanggaoVOICE();
				guanggao_status++;
				guanggao_status %= 3;
				delayLittle();
				break;
			case 5:
				/* ��һվ */
				prevStation(&station, &direction);
				delayLittle();
				break;
			case 6:
				/* ��վ */
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
	disable();					//���ж�
	/* start */
	/* ------changes for 8259------ */
	Init8259(); /* 8259 */
	setvect(8, INT_0x8);			//��ʼ���ж�����, 8:��8���ж�����,INT_0:�жϴ������
	/* ---------------------------- */
	init8255();	/* initialize 8255 */
	initISD();
	LCD_INIT();
	DisHYSY();
	DelayTime();
	enable();					//���ж�
	while(1)
	{
		outportb(PB_Addr, 0x0);
	}
}