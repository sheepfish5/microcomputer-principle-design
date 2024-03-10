/********************************************************		
*		12864JҺ����ʾ��
*12864J��1.ͼ�ε���Һ����ʾ�����ֱ���Ϊ128X64������ʾͼ��
*	   ��8��4��(16��16����)���֡�
*	 2.����8λ�������߲������������8�������ߡ�
* 	 3.ָ��򵥣�7��ָ��
********************************************************/

#include "12864.h"
#include "basic.h"
#include "key_board_8255.h"
#include "word_lib.h"

/* Display "��ӭʹ�ñ�վ��" */
void DisHYSY() {
	Dis(2, 0, LEFT_SCREEN, FOUR_WORD_LEN, hysybzq);
	Dis(2, 0, RIGHT_SCREEN, THREE_WORD_LEN, &hysybzq[4*WORD_SIZE]);
}

/* "��վ" function */
void chuzhan(u8 station) {
	u8 row = 2;
	LCD_INIT();
	Dis(row, 0, LEFT_SCREEN, FOUR_WORD_LEN, xyz);  /* ��һվ */
	// if (station == 0) {
	// 	Dis(row, 0, RIGHT_SCREEN, FOUR_WORD_LEN, whjd);  /* �ĺ��Ƶ� */
	// } else if (station == 1) {
	// 	Dis(row, 0, RIGHT_SCREEN, THREE_WORD_LEN, zjf);  /* �żҷ� */
	// } else if (station == 2) {
	// 	Dis(row, 0, RIGHT_SCREEN, FOUR_WORD_LEN, gjdq);  /* �ӽ����� */
	// } else if (station == 3) {
	// 	Dis(row, 0, RIGHT_SCREEN, THREE_WORD_LEN, lsc);  /* ���ϴ� */
	// }

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
	DelayTime();
	DelayTime();
}
/* "��վ" function */
void jinzhan(u8 station) {
	u8 row = 2;
	LCD_INIT();
	switch (station)
	{
	case 0:
		Dis(row, 0, FOUR_WORD_LEN, FOUR_WORD_LEN, whjd);  /* �ĺ��Ƶ� */
		break;
	case 1:
		Dis(row, 0, FOUR_WORD_LEN, THREE_WORD_LEN, zjf);  /* �żҷ� */
		break;
	case 2:
		Dis(row, 0, FOUR_WORD_LEN, FOUR_WORD_LEN, gjdq);  /* �ӽ����� */
		break;
	case 3:
		Dis(row, 0, FOUR_WORD_LEN, THREE_WORD_LEN, lsc);  /* ���ϴ� */
		break;
	case 4:
		Dis(row, 0, FOUR_WORD_LEN, FOUR_WORD_LEN, tjgd);  /* ��ʹ�� */
		break;
	case 5:
		Dis(row, 0, FOUR_WORD_LEN, FOUR_WORD_LEN, zgsh);  /* �й�ʯ�� */
		break;
	case 6:
		Dis(row, 0, FOUR_WORD_LEN, FOUR_WORD_LEN, rayy);  /* �ʰ�ҽԺ */
		break;
	}
	Dis(row, 0, RIGHT_SCREEN, THREE_WORD_LEN, dl);  /* "  ����" */
	DelayTime();
	DelayTime();
}

main()
{
	/* start */
	init8255();	/* initialize 8255 */
	LCD_INIT();
	DisHYSY();
	DelayTime();

	u8 station = 0;
	u8 key_value = 0;
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
			case 2:
				/* ��վ */
				chuzhan(station);
				break;
			case 6:
				/* ��վ */
				jinzhan(station);
				station++;
				station &= 0x7;
				break;
			}
		}
	}
	
}

