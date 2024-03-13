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

#define	IO8259_0	0x250
#define	IO8259_1	0x251

#define D_ORDER 1
#define D_REVERSE 0

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

/* show advertisement */
void guanggao();

/* ----------------------------------------------------- */
/* ----------------------------------------------------- */

/* initialize 8259 */
void Init8259()
{
	outportb(IO8259_0,0x12);  /* ICW1 */
	outportb(IO8259_1,0x8);	  /* ICW2 */
	outportb(IO8259_1,0xfe);  /* OCW1 */
}

u8 g_direction = D_ORDER;
u8 g_station = 0;

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
			g_direction = !g_direction;  /* reverse the direction */
			break;
		case 1:
			/* ��һվ */
			if (g_direction == D_ORDER) {
				g_station++;
			} else {
				g_station--;
			}
			g_station &= 0x7;
			break;
		case 2:
			/* ��վ */
			chuzhan(g_station, g_direction);
			break;
		case 4:
			/* ��� */
			guanggao();
			break;
		case 5:
			/* ��һվ */
			if (g_direction == D_REVERSE) {
				g_station--;
			} else {
				g_station++;
			}
			g_station &= 0x7;
			break;
		case 6:
			/* ��վ */
			jinzhan(g_station, g_direction);
			g_station++;
			g_station &= 0x7;
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
	// if (station == 0) {
	// 	Dis(row, 0, RIGHT_SCREEN, FOUR_WORD_LEN, whjd);  /* �ĺ��Ƶ� */
	// } else if (station == 1) {
	// 	Dis(row, 0, RIGHT_SCREEN, THREE_WORD_LEN, zjf);  /* �żҷ� */
	// } else if (station == 2) {
	// 	Dis(row, 0, RIGHT_SCREEN, FOUR_WORD_LEN, gjdq);  /* �ӽ����� */
	// } else if (station == 3) {
	// 	Dis(row, 0, RIGHT_SCREEN, THREE_WORD_LEN, lsc);  /* ���ϴ� */
	// }
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

/* show advertisement */
void guanggao() {
	LCDClear();
	DisIMG();
	DisIMG2();
	DelayTime();
	DelayTime();
	DelayTime();
}

main()
{
	u8 station = 0;
	u8 key_value = 0;
	u8 direction = D_ORDER;

	/* start */
	init8255();	/* initialize 8255 */
	LCD_INIT();
	DisHYSY();
	DelayTime();

	while (1)
	{
		if (scan_any_pushed()) {
			key_value = get_key_value();
			// if (key_value == 2) {
			// 	/* ��վ */
			// 	chuzhan(station);
			// }
			switch (key_value)
			{
			case 0:
				/* ��/���� */
				direction = !direction;  /* reverse the direction */
				break;
			case 1:
				/* ��һվ */
				if (direction == D_ORDER) {
					station++;
				} else {
					station--;
				}
				station &= 0x7;
				break;
			case 2:
				/* ��վ */
				chuzhan(station, direction);
				break;
			case 4:
				/* ��� */
				guanggao();
				break;
			case 5:
				/* ��һվ */
				if (direction == D_REVERSE) {
					station--;
				} else {
					station++;
				}
				station &= 0x7;
				break;
			case 6:
				/* ��վ */
				jinzhan(station, direction);
				station++;
				station &= 0x7;
				break;

			}
		}
	}
	
}

void main_8259() {
	disable();					//���ж�
	/* start */
	/* ------changes for 8259------ */
	Init8259(); /* 8259 */
	setvect(8, INT_0x8);			//��ʼ���ж�����, 8:��8���ж�����,INT_0:�жϴ������
	/* ---------------------------- */
	init8255();	/* initialize 8255 */
	LCD_INIT();
	DisHYSY();
	DelayTime();
	enable();					//���ж�
	while(1)
	{
		;
	}
}