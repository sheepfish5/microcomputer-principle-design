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

#define D_ORDER 1
#define D_REVERSE 0

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
	// if (station == 0) {
	// 	Dis(row, 0, RIGHT_SCREEN, FOUR_WORD_LEN, whjd);  /* 文海酒店 */
	// } else if (station == 1) {
	// 	Dis(row, 0, RIGHT_SCREEN, THREE_WORD_LEN, zjf);  /* 张家坊 */
	// } else if (station == 2) {
	// 	Dis(row, 0, RIGHT_SCREEN, FOUR_WORD_LEN, gjdq);  /* 赣江大桥 */
	// } else if (station == 3) {
	// 	Dis(row, 0, RIGHT_SCREEN, THREE_WORD_LEN, lsc);  /* 岭上村 */
	// }
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
			// 	/* 出站 */
			// 	chuzhan(station);
			// }
			switch (key_value)
			{
			case 2:
				/* 出站 */
				chuzhan(station, direction);
				break;
			case 6:
				/* 进站 */
				jinzhan(station, direction);
				station++;
				station &= 0x7;
				break;
			case 0:
				/* 上/下行 */
				direction = !direction;  /* reverse the direction */
				break;
			}
		}
	}
	
}

