/********************************************************		
*		12864J液晶显示器
*12864J：1.图形点阵液晶显示器，分辨率为128X64。可显示图形
*	   和8×4个(16×16点阵)汉字。
*	 2.采用8位数据总线并行输入输出和8条控制线。
* 	 3.指令简单，7种指令
********************************************************/

#include "12864.h"
#include "basic.h"
#include "key_board_8255.h"
#include "word_lib.h"

/* Display "欢迎使用报站器" */
void DisHYSY() {
	Dis(2, 0, LEFT_SCREEN, FOUR_WORD_LEN, hysybzq);
	Dis(2, 0, RIGHT_SCREEN, THREE_WORD_LEN, &hysybzq[4*WORD_SIZE]);
}

/* "出站" function */
void chuzhan(u8 station) {
	u8 row = 2;
	LCD_INIT();
	Dis(row, 0, LEFT_SCREEN, FOUR_WORD_LEN, xyz);  /* 下一站 */
	// if (station == 0) {
	// 	Dis(row, 0, RIGHT_SCREEN, FOUR_WORD_LEN, whjd);  /* 文海酒店 */
	// } else if (station == 1) {
	// 	Dis(row, 0, RIGHT_SCREEN, THREE_WORD_LEN, zjf);  /* 张家坊 */
	// } else if (station == 2) {
	// 	Dis(row, 0, RIGHT_SCREEN, FOUR_WORD_LEN, gjdq);  /* 赣江大桥 */
	// } else if (station == 3) {
	// 	Dis(row, 0, RIGHT_SCREEN, THREE_WORD_LEN, lsc);  /* 岭上村 */
	// }

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
	DelayTime();
	DelayTime();
}
/* "进站" function */
void jinzhan(u8 station) {
	u8 row = 2;
	LCD_INIT();
	switch (station)
	{
	case 0:
		Dis(row, 0, FOUR_WORD_LEN, FOUR_WORD_LEN, whjd);  /* 文海酒店 */
		break;
	case 1:
		Dis(row, 0, FOUR_WORD_LEN, THREE_WORD_LEN, zjf);  /* 张家坊 */
		break;
	case 2:
		Dis(row, 0, FOUR_WORD_LEN, FOUR_WORD_LEN, gjdq);  /* 赣江大桥 */
		break;
	case 3:
		Dis(row, 0, FOUR_WORD_LEN, THREE_WORD_LEN, lsc);  /* 岭上村 */
		break;
	case 4:
		Dis(row, 0, FOUR_WORD_LEN, FOUR_WORD_LEN, tjgd);  /* 天际光电 */
		break;
	case 5:
		Dis(row, 0, FOUR_WORD_LEN, FOUR_WORD_LEN, zgsh);  /* 中国石化 */
		break;
	case 6:
		Dis(row, 0, FOUR_WORD_LEN, FOUR_WORD_LEN, rayy);  /* 仁安医院 */
		break;
	}
	Dis(row, 0, RIGHT_SCREEN, THREE_WORD_LEN, dl);  /* "  到了" */
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
			// 	/* 出站 */
			// 	chuzhan(station);
			// }
			switch (key_value)
			{
			case 2:
				/* 出站 */
				chuzhan(station);
				break;
			case 6:
				/* 进站 */
				jinzhan(station);
				station++;
				station &= 0x7;
				break;
			}
		}
	}
	
}

