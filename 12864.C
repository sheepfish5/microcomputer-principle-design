/********************************************************		
*		12864J液晶显示器
*12864J：1.图形点阵液晶显示器，分辨率为128X64。可显示图形
*	   和8×4个(16×16点阵)汉字。
*	 2.采用8位数据总线并行输入输出和8条控制线。
* 	 3.指令简单，7种指令
********************************************************/

#include "12864.h"
#include "word_lib.h"
#include "basic.h"


//***************************************
//基本控制		
//***************************************					
//写左半屏控制指令
void WRComL(unsigned char _data)
{
	outportb(WR_COM_AD_L, _data);
	while (inportb(RD_BUSY_AD) & 0x80)	//检查液晶显示是否处于忙状态
	{;}
}

//写右半屏控制指令
void WRComR(unsigned char _data)
{
	outportb(WR_COM_AD_R, _data);
	while (inportb(RD_BUSY_AD) & 0x80)	//检查液晶显示是否处于忙状态
	{;}
}

//写左半屏数据
void WRDataL(unsigned char _data)
{
	outportb(WR_DATA_AD_L, _data);
	while (inportb(RD_BUSY_AD) & 0x80)	//检查液晶显示是否处于忙状态
	{;}
}

//写右半屏数据
void WRDataR(unsigned char _data)
{
	outportb(WR_DATA_AD_R, _data);
	while (inportb(RD_BUSY_AD) & 0x80)	//检查液晶显示是否处于忙状态
	{;}
}

//显示左半屏数据，count-显示数据个数
void DisplayL(unsigned char *pt, char count)
{
	while (count--)
	{
		WRDataL(*pt++);			//写左半屏数据
	}
}

//显示右半屏数据，count-显示数据个数
void DisplayR(unsigned char * pt, char count)
{
	while (count--)
	{
		WRDataR(*pt++);			//写右半屏数据
	}
}

//设置左半屏起始显示行列地址,x-X起始行序数(0-7)，y-Y起始列序数(0-63)
void SETXYL(unsigned char x, unsigned char y)
{
	WRComL(x+X);				//行地址=行序数+行基址
	WRComL(y+Y);				//列地址=列序数+列基址
}

//设置右半屏起始显示行列地址,x:X起始行序数(0-7)，y:Y起始列序数(0-63)
void SETXYR(unsigned char x, unsigned char y)
{
	WRComR(x+X);				//行地址=行序数+行基址
	WRComR(y+Y);				//列地址=列序数+列基址
}

//***************************************
//显示图形		
//***************************************
//显示左半屏一行图形,A-X起始行序数(0-7)，B-Y起始列地址序数(0-63)
void LineDisL(unsigned char x, unsigned char y, unsigned char * pt)
{
	SETXYL(x,y);				//设置起始显示行列
	DisplayL(pt, 64);			//显示数据
}

//显示右半屏一行图形,A-X起始行地址序数(0-7)，B-Y起始列地址序数(0-63)
void LineDisR(unsigned char x, unsigned char y, unsigned char * pt)
{
	SETXYR(x,y);				//设置起始显示行列
	DisplayR(pt, 64);			//显示数据
}

//***************************************
//显示字体，显示一个数据要占用X行两行位置
//***************************************
//右半屏显示一个字节/字：x-起始显示行序数X(0-7)；y-起始显示列序数Y(0-63)；pt-显示字数据首地址
void ByteDisR(unsigned char x, unsigned char y,unsigned char * pt)
{
	SETXYR(x,y);			//设置起始显示行列地址
	DisplayR(pt, 8);			//显示上半行数据
	SETXYR(x+1,y);			//设置起始显示行列地址
	DisplayR(pt+8, 8);		//显示下半行数据
}

void WordDisR(unsigned char x, unsigned char y,unsigned char * pt)
{
	SETXYR(x,y);			//设置起始显示行列地址
	DisplayR(pt, 16);		//显示上半行数据
	SETXYR(x+1,y);			//设置起始显示行列地址
	DisplayR(pt+16, 16);	//显示下半行数据
}

/* write a 8x16 char at (x,y) */
//左半屏显示一个字节/字：x-起始显示行序数X(0-7)；y-起始显示列序数Y(0-63)；pt-显示字数据首地址
void ByteDisL(unsigned char x, unsigned char y,unsigned char * pt)
{
	SETXYL(x,y);			//设置起始显示行列地址
	DisplayL(pt, 8);		//显示上半行数据
	SETXYL(x+1,y);			//设置起始显示行列地址
	DisplayL(pt+8, 8);		//显示下半行数据
}

/* write a 16x16 char at (x,y) */
void WordDisL(unsigned char x, unsigned char y,unsigned char * pt)
{
	SETXYL(x,y);			//设置起始显示行列地址
	DisplayL(pt, 16);		//显示上半行数据
	SETXYL(x+1,y);			//设置起始显示行列地址
	DisplayL(pt+16, 16);	//显示下半行数据
}

/* 
 * clear both screens by setting all bits to 0
 */
void LCDClear()
{
//清左半屏
	unsigned char x,y;
	char j;
	x = 0;						//起始行，第0行
	y = 0;						//起始列，第0列
	for (x = 0; x < 8; x++)		//共8行
	{
		SETXYL(x,y);			//设置起始显示行列地址
		j = 64;
		while (j--)
			WRDataL(0);
	}
//清右半屏
	x = 0;						//起始行，第0行
	y = 0;						//起始列，第0列
	for (x = 0; x < 8; x++)		//共8行
	{
		SETXYR(x,y);			//设置起始显示行列地址
		j = 64;
		while (j--)
			WRDataR(0);
	}
}

/* initialize both sreens by setting all bits to 0 */	
void LCD_INIT()
{
	WRComL(0x3e);			//初始化左半屏，关显示
	WRComL(FirstLine);		//设置起始显示行，第0行
	WRComR(0x3e);			//初始化右半屏，关显示
	WRComR(FirstLine);		//设置起始显示行，第0行
	LCDClear();				//清屏
	WRComL(0x3f);			//开显示
	WRComR(0x3f);			//开显示
}

//延时程序
void DelayTime()
{
	// unsigned char i;
	// unsigned int j;
	// for (i = 0; i < 3; i++)
	// {
	// 	for (j = 0; j < 0xffff; j++)
	// 	{;}
	// }
}

/* Display "下一站  " on the left 2nd row */
void DisXYZ()
{
	u8 rowNo = 2;
	WordDisL(rowNo, 0, &xyz[0]);  /* 下 */
	WordDisL(rowNo, WORD_WIDE, &xyz[WORD_SIZE]);  /* 一 */
	WordDisL(rowNo, 2*WORD_WIDE, &xyz[WORD_SIZE*2]); /* 站 */
	WordDisL(rowNo, 3*WORD_WIDE, &xyz[WORD_SIZE*3]); /* blank */
}

/* 
 * (x,y): start coordinate, y can be set to 0
 * wordSize: FOUR_WORD_LEN or THREE_WORD_LEN
 * flagLR: LEFT_SCREEN or RIGHT_SCREEN
 * ptr: point to the content
 */
void Dis(u8 x, u8 y, u8 flagLR, u8 wordSize, unsigned char *ptr) {
	if (flagLR == LEFT_SCREEN && wordSize == THREE_WORD_LEN) {
		WordDisL(x, y, &ptr[0]);
		WordDisL(x, y+WORD_WIDE, &ptr[WORD_SIZE]);
		WordDisL(x, y+WORD_WIDE*2, &ptr[WORD_SIZE*2]);
	} else if (flagLR == LEFT_SCREEN && wordSize == FOUR_WORD_LEN) {
		WordDisL(x, y, &ptr[0]);
		WordDisL(x, y+WORD_WIDE, &ptr[WORD_SIZE]);
		WordDisL(x, y+WORD_WIDE*2, &ptr[WORD_SIZE*2]);
		WordDisL(x, y+WORD_WIDE*3, &ptr[WORD_SIZE*3]);
	} else if (flagLR == RIGHT_SCREEN && wordSize == THREE_WORD_LEN) {
		WordDisR(x, y, &ptr[0]);
		WordDisR(x, y+WORD_WIDE, &ptr[WORD_SIZE]);
		WordDisR(x, y+WORD_WIDE*2, &ptr[WORD_SIZE*2]);
	} else if (flagLR == RIGHT_SCREEN && wordSize == FOUR_WORD_LEN) {
		WordDisR(x, y, &ptr[0]);
		WordDisR(x, y+WORD_WIDE, &ptr[WORD_SIZE]);
		WordDisR(x, y+WORD_WIDE*2, &ptr[WORD_SIZE*2]);
		WordDisR(x, y+WORD_WIDE*3, &ptr[WORD_SIZE*3]);
	}
}

/* Display "  到了" on the right 2nd row */
void DisDL() {
	Dis(2, 0, RIGHT_SCREEN, THREE_WORD_LEN, dl);
}

/* general function: Display a image on the left LCD */
void DisIMGl(unsigned char *img) {
	u16 i = 0;
	for (; i<8; i++) {
		LineDisL(i, 0, &img[i*64]);
	}
}

/* general function: Display a image on the right LCD */
void DisIMGr(unsigned char *img) {
	u16 i = 0;
	for (; i<8; i++) {
		LineDisR(i, 0, &img[i*64]);
	}
}

/* Display a image on the left LCD */
void DisIMG1() {
	u16 i = 0;
	for (; i<8; i++) {
		LineDisL(i, 0, &myImg[i*64]);
	}
}

/* Display a image on the right LCD */
void DisIMG2() {
	u16 i = 0;
	for (; i<8; i++) {
		LineDisR(i, 0, &myImg2[i*64]);
	}
}

/* the functions below are about controling message to roll from right to left */

/* 
 * display left n column of a two-line Chinese word at (x, y) on the left screen
 * constraint y+n <= 64
 */
void WordNcDisL(u8 x, u8 y, u8 n, unsigned char *ptr) {
	SETXYL(x, y);
	DisplayL(ptr, n);
	SETXYL(x+1, y);
	DisplayL(ptr+WORD_WIDE, n);
}

/* 
 * display left n column of a two-line Chinese word at (x, y) on the right screen
 * constraint y+n <= 64
 */
void WordNcDisR(u8 x, u8 y, u8 n, unsigned char *ptr) {
	SETXYR(x, y);
	DisplayR(ptr, n);
	SETXYR(x+1, y);
	DisplayR(ptr+WORD_WIDE, n);
}

/* 
 * display left n column of a two-line ascii byte at (x, y) on the left screen
 * constraint y+n <= 64
 */
void ByteNcDisL(u8 x, u8 y, u8 n, unsigned char *ptr) {
	SETXYL(x, y);
	DisplayL(ptr, n);
	SETXYL(x+1, y);
	DisplayL(ptr+BYTE_WIDE, n);
}

/* 
 * display left n column of a two-line ascii byte at (x, y) on the right screen
 * constraint y+n <= 64
 */
void ByteNcDisR(u8 x, u8 y, u8 n, unsigned char *ptr) {
	SETXYR(x, y);
	DisplayR(ptr, n);
	SETXYR(x+1, y);
	DisplayR(ptr+BYTE_WIDE, n);
}

/* 下一站__ roll to the right screen */
void XYZDisRollR() {
	u8 i;
	u8 row = 2;
	/* i = 62, 60, 58, 56, ..., 4, 2, 0 */
	for (i = 62; i <= 62; i -= 2) {
		WordNcDisR(row, i, MIN(WORD_WIDE, 64-i), xyz);  /* 下 */
		if (64 - i > 16) {
			/* 一 */
			/* i = 46, 44, 42, 40, ..., 4, 2, 0 */
			WordNcDisR(row, i+16, MIN(WORD_WIDE, 48-i), xyz+WORD_SIZE);
		}
		if (64 - i > 32) {
			/* 站 */
			/* i = 30, 28, 26, 24, ..., 4, 2, 0 */
			WordNcDisR(row, i+32, MIN(WORD_WIDE, 32-i), xyz+2*WORD_SIZE);
		}
		if (64 - i > 48) {
			/* blank */
			/* i = 14, 12, 10, 8, 6, 4, 2, 0 */
			WordNcDisR(row, i+48, MIN(WORD_WIDE, 16-i), xyz+3*WORD_SIZE);
		}
		DelayTime();
		LCDClear();
	}
}

/* 下一站__ roll to the whole screen */
void XYZDisRoll() {
	u8 i;
	u8 row = 2;
	int j;

	/* 下一站__ roll to the right screen */
	/* i = 62, 60, 58, 56, ..., 4, 2, 0 */
	for (i = 62; i <= 62; i -= 2) {
		WordNcDisR(row, i, MIN(WORD_WIDE, 64-i), xyz);  /* 下 */
		if (64 - i > 16) {
			/* 一 */
			/* i = 46, 44, 42, 40, ..., 4, 2, 0 */
			WordNcDisR(row, i+16, MIN(WORD_WIDE, 48-i), xyz+WORD_SIZE);
		}
		if (64 - i > 32) {
			/* 站 */
			/* i = 30, 28, 26, 24, ..., 4, 2, 0 */
			WordNcDisR(row, i+32, MIN(WORD_WIDE, 32-i), xyz+2*WORD_SIZE);
		}
		if (64 - i > 48) {
			/* blank */
			/* i = 14, 12, 10, 8, 6, 4, 2, 0 */
			WordNcDisR(row, i+48, MIN(WORD_WIDE, 16-i), xyz+3*WORD_SIZE);
		}
		DelayTime();
		LCDClear();
	}

	/* 下一站__ roll to the left screen and disappear from the right */
	/* i = 62, 60, 58, 56, ..., 4, 2, 0 */
	for (i = 62, j = 2; i <= 62; i -= 2, j += 2) {
		/* left screen */
		WordNcDisL(row, i, MIN(WORD_WIDE, 64-i), xyz);  /* 下 */
		if (64 - i > 16) {
			/* 一 */
			/* i = 46, 44, 42, 40, ..., 4, 2, 0 */
			WordNcDisL(row, i+16, MIN(WORD_WIDE, 48-i), xyz+WORD_SIZE);
		}
		if (64 - i > 32) {
			/* 站 */
			/* i = 30, 28, 26, 24, ..., 4, 2, 0 */
			WordNcDisL(row, i+32, MIN(WORD_WIDE, 32-i), xyz+2*WORD_SIZE);
		}
		if (64 - i > 48) {
			/* blank */
			/* i = 14, 12, 10, 8, 6, 4, 2, 0 */
			WordNcDisL(row, i+48, MIN(WORD_WIDE, 16-i), xyz+3*WORD_SIZE);
		}

		/* right screen */
		/* 下 */
		if (j <= 16) {
			WordNcDisR(row, 0, 16 - j, xyz + j);
		}
		/* 一 */
		if (j <= 16) {
			WordNcDisR(row, 16 - j, 16, xyz + WORD_SIZE);
		} else if (j > 16 && j < 32) {
			WordNcDisR(row, 0, 16 - (j-16), xyz + WORD_SIZE + j - 16);
		}
		/* 站 */
		if (j <= 32) {
			WordNcDisR(row, 32 - j, 16, xyz + 2*WORD_SIZE);
		} else if (j > 32 && j < 48) {
			WordNcDisR(row, 0, 32 - (j-16), xyz + 2*WORD_SIZE + j - 32);
		}
		/* blank */
		if (j <= 48) {
			WordNcDisR(row, 48 - j, 16, xyz + 3*WORD_SIZE);
		} else if (j > 48) {
			WordNcDisR(row, 0, 48 - (j-16), xyz + 3*WORD_SIZE + j - 48);
		}
		DelayTime();
		LCDClear();
	}
}

/* 下一站__正正正正 roll to the whole screen */
void CZ4DisRoll(u8 row, unsigned char *ptr) {
	u8 i;
	int j;

	/* 下一站__ roll to the whole right screen */
	/* i = 62, 60, 58, 56, ..., 4, 2, 0 */
	for (i = 62; i <= 62; i -= 2) {
		WordNcDisR(row, i, MIN(WORD_WIDE, 64-i), xyz);  /* 下 */
		if (64 - i > 16) {
			/* 一 */
			/* i = 46, 44, 42, 40, ..., 4, 2, 0 */
			WordNcDisR(row, i+16, MIN(WORD_WIDE, 48-i), xyz+WORD_SIZE);
		}
		if (64 - i > 32) {
			/* 站 */
			/* i = 30, 28, 26, 24, ..., 4, 2, 0 */
			WordNcDisR(row, i+32, MIN(WORD_WIDE, 32-i), xyz+2*WORD_SIZE);
		}
		if (64 - i > 48) {
			/* blank */
			/* i = 14, 12, 10, 8, 6, 4, 2, 0 */
			WordNcDisR(row, i+48, MIN(WORD_WIDE, 16-i), xyz+3*WORD_SIZE);
		}
		DelayTime();
		LCDClear();
	}

	/* 下一站__ roll to the whole left screen and disappear from the right */
	/* 正正正正 roll to the whole right screen */
	/* i = 62, 60, 58, 56, ..., 4, 2, 0 */
	for (i = 62, j = 2; i <= 62; i -= 2, j += 2) {
		/* left screen */
		WordNcDisL(row, i, MIN(WORD_WIDE, 64-i), xyz);  /* 下 */
		if (64 - i > 16) {
			/* 一 */
			/* i = 46, 44, 42, 40, ..., 4, 2, 0 */
			WordNcDisL(row, i+16, MIN(WORD_WIDE, 48-i), xyz+WORD_SIZE);
		}
		if (64 - i > 32) {
			/* 站 */
			/* i = 30, 28, 26, 24, ..., 4, 2, 0 */
			WordNcDisL(row, i+32, MIN(WORD_WIDE, 32-i), xyz+2*WORD_SIZE);
		}
		if (64 - i > 48) {
			/* blank */
			/* i = 14, 12, 10, 8, 6, 4, 2, 0 */
			WordNcDisL(row, i+48, MIN(WORD_WIDE, 16-i), xyz+3*WORD_SIZE);
		}

		/* right screen */
		/* 下 */
		if (j <= 16) {
			WordNcDisR(row, 0, 16 - j, xyz + j);
		}
		/* 一 */
		if (j <= 16) {
			WordNcDisR(row, 16 - j, 16, xyz + WORD_SIZE);
		} else if (j > 16 && j < 32) {
			WordNcDisR(row, 0, 16 - (j-16), xyz + WORD_SIZE + j - 16);
		}
		/* 站 */
		if (j <= 32) {
			WordNcDisR(row, 32 - j, 16, xyz + 2*WORD_SIZE);
		} else if (j > 32 && j < 48) {
			WordNcDisR(row, 0, 32 - (j-16), xyz + 2*WORD_SIZE + j - 32);
		}
		/* blank */
		if (j <= 48) {
			WordNcDisR(row, 48 - j, 16, xyz + 3*WORD_SIZE);
		} else if (j > 48) {
			WordNcDisR(row, 0, 48 - (j-16), xyz + 3*WORD_SIZE + j - 48);
		}

		/* right screen */
		/* 正正正正 */
		WordNcDisR(row, i, MIN(WORD_WIDE, 64-i), ptr);  /* 下 */
		if (64 - i > 16) {
			/* 一 */
			/* i = 46, 44, 42, 40, ..., 4, 2, 0 */
			WordNcDisR(row, i+16, MIN(WORD_WIDE, 48-i), ptr+WORD_SIZE);
		}
		if (64 - i > 32) {
			/* 站 */
			/* i = 30, 28, 26, 24, ..., 4, 2, 0 */
			WordNcDisR(row, i+32, MIN(WORD_WIDE, 32-i), ptr+2*WORD_SIZE);
		}
		if (64 - i > 48) {
			/* blank */
			/* i = 14, 12, 10, 8, 6, 4, 2, 0 */
			WordNcDisR(row, i+48, MIN(WORD_WIDE, 16-i), ptr+3*WORD_SIZE);
		}
		DelayTime();
		if (i != 0) 
			LCDClear();
	}
}

/* 下一站__正正正__ roll to the whole screen */
void CZ3DisRoll(u8 row, unsigned char *ptr) {
	u8 i;
	int j;

	/* 下一站__ roll to the whole right screen */
	/* i = 62, 60, 58, 56, ..., 4, 2, 0 */
	for (i = 62; i <= 62; i -= 2) {
		WordNcDisR(row, i, MIN(WORD_WIDE, 64-i), xyz);  /* 下 */
		if (64 - i > 16) {
			/* 一 */
			/* i = 46, 44, 42, 40, ..., 4, 2, 0 */
			WordNcDisR(row, i+16, MIN(WORD_WIDE, 48-i), xyz+WORD_SIZE);
		}
		if (64 - i > 32) {
			/* 站 */
			/* i = 30, 28, 26, 24, ..., 4, 2, 0 */
			WordNcDisR(row, i+32, MIN(WORD_WIDE, 32-i), xyz+2*WORD_SIZE);
		}
		if (64 - i > 48) {
			/* blank */
			/* i = 14, 12, 10, 8, 6, 4, 2, 0 */
			WordNcDisR(row, i+48, MIN(WORD_WIDE, 16-i), xyz+3*WORD_SIZE);
		}
		DelayTime();
		LCDClear();
	}

	/* 下一站__ roll to the whole left screen and disappear from the right */
	/* 正正正 roll to the whole right screen */
	/* i = 62, 60, 58, 56, ..., 4, 2, 0 */
	for (i = 62, j = 2; i <= 62; i -= 2, j += 2) {
		/* left screen */
		WordNcDisL(row, i, MIN(WORD_WIDE, 64-i), xyz);  /* 下 */
		if (64 - i > 16) {
			/* 一 */
			/* i = 46, 44, 42, 40, ..., 4, 2, 0 */
			WordNcDisL(row, i+16, MIN(WORD_WIDE, 48-i), xyz+WORD_SIZE);
		}
		if (64 - i > 32) {
			/* 站 */
			/* i = 30, 28, 26, 24, ..., 4, 2, 0 */
			WordNcDisL(row, i+32, MIN(WORD_WIDE, 32-i), xyz+2*WORD_SIZE);
		}
		if (64 - i > 48) {
			/* blank */
			/* i = 14, 12, 10, 8, 6, 4, 2, 0 */
			WordNcDisL(row, i+48, MIN(WORD_WIDE, 16-i), xyz+3*WORD_SIZE);
		}

		/* right screen */
		/* 下 */
		if (j <= 16) {
			WordNcDisR(row, 0, 16 - j, xyz + j);
		}
		/* 一 */
		if (j <= 16) {
			WordNcDisR(row, 16 - j, 16, xyz + WORD_SIZE);
		} else if (j > 16 && j < 32) {
			WordNcDisR(row, 0, 16 - (j-16), xyz + WORD_SIZE + j - 16);
		}
		/* 站 */
		if (j <= 32) {
			WordNcDisR(row, 32 - j, 16, xyz + 2*WORD_SIZE);
		} else if (j > 32 && j < 48) {
			WordNcDisR(row, 0, 32 - (j-16), xyz + 2*WORD_SIZE + j - 32);
		}
		/* blank */
		if (j <= 48) {
			WordNcDisR(row, 48 - j, 16, xyz + 3*WORD_SIZE);
		} else if (j > 48) {
			WordNcDisR(row, 0, 48 - (j-16), xyz + 3*WORD_SIZE + j - 48);
		}

		/* right screen */
		/* 正正正 */
		WordNcDisR(row, i, MIN(WORD_WIDE, 64-i), ptr);  /* 下 */
		if (64 - i > 16) {
			/* 2 */
			/* i = 46, 44, 42, 40, ..., 4, 2, 0 */
			WordNcDisR(row, i+16, MIN(WORD_WIDE, 48-i), ptr+WORD_SIZE);
		}
		if (64 - i > 32) {
			/* 3 */
			/* i = 30, 28, 26, 24, ..., 4, 2, 0 */
			WordNcDisR(row, i+32, MIN(WORD_WIDE, 32-i), ptr+2*WORD_SIZE);
		}

		DelayTime();
		if (i != 0) 
			LCDClear();
	}
}

/* 进站 */
/* 正正正正__到了 roll to the whole screen */
void JZ4DisRoll(u8 row, unsigned char *ptr) {
	u8 i;
	int j;

	/* 正正正正 roll to the right screen */
	/* i = 62, 60, 58, 56, ..., 4, 2, 0 */
	for (i = 62; i <= 62; i -= 2) {
		WordNcDisR(row, i, MIN(WORD_WIDE, 64-i), ptr);  /* 1 */
		if (64 - i > 16) {
			/* 2 */
			/* i = 46, 44, 42, 40, ..., 4, 2, 0 */
			WordNcDisR(row, i+16, MIN(WORD_WIDE, 48-i), ptr+WORD_SIZE);
		}
		if (64 - i > 32) {
			/* 3 */
			/* i = 30, 28, 26, 24, ..., 4, 2, 0 */
			WordNcDisR(row, i+32, MIN(WORD_WIDE, 32-i), ptr+2*WORD_SIZE);
		}
		if (64 - i > 48) {
			/* 4 */
			/* i = 14, 12, 10, 8, 6, 4, 2, 0 */
			WordNcDisR(row, i+48, MIN(WORD_WIDE, 16-i), ptr+3*WORD_SIZE);
		}
		DelayTime();
		LCDClear();
	}

	/* 正正正正 roll to the left screen and disappear from the right */
	/* __到了 roll to the right screen */
	/* i = 62, 60, 58, 56, ..., 4, 2, 0 */
	for (i = 62, j = 2; i <= 62; i -= 2, j += 2) {
		/* left screen */
		WordNcDisL(row, i, MIN(WORD_WIDE, 64-i), ptr);  /* 1 */
		if (64 - i > 16) {
			/* 2 */
			/* i = 46, 44, 42, 40, ..., 4, 2, 0 */
			WordNcDisL(row, i+16, MIN(WORD_WIDE, 48-i), ptr+WORD_SIZE);
		}
		if (64 - i > 32) {
			/* 3 */
			/* i = 30, 28, 26, 24, ..., 4, 2, 0 */
			WordNcDisL(row, i+32, MIN(WORD_WIDE, 32-i), ptr+2*WORD_SIZE);
		}
		if (64 - i > 48) {
			/* 4 */
			/* i = 14, 12, 10, 8, 6, 4, 2, 0 */
			WordNcDisL(row, i+48, MIN(WORD_WIDE, 16-i), ptr+3*WORD_SIZE);
		}

		/* right screen */
		/* 正正正正 disapear from the right */
		/* 1 */
		if (j <= 16) {
			WordNcDisR(row, 0, 16 - j, ptr + j);
		}
		/* 2 */
		if (j <= 16) {
			WordNcDisR(row, 16 - j, 16, ptr + WORD_SIZE);
		} else if (j > 16 && j < 32) {
			WordNcDisR(row, 0, 16 - (j-16), ptr + WORD_SIZE + j - 16);
		}
		/* 3 */
		if (j <= 32) {
			WordNcDisR(row, 32 - j, 16, ptr + 2*WORD_SIZE);
		} else if (j > 32 && j < 48) {
			WordNcDisR(row, 0, 32 - (j-16), ptr + 2*WORD_SIZE + j - 32);
		}
		/* 4 */
		if (j <= 48) {
			WordNcDisR(row, 48 - j, 16, ptr + 3*WORD_SIZE);
		} else if (j > 48) {
			WordNcDisR(row, 0, 48 - (j-16), ptr + 3*WORD_SIZE + j - 48);
		}

		/* right screen */
		/* __到了 roll to the right */
		WordNcDisR(row, i, MIN(WORD_WIDE, 64-i), dl);  /* blank */
		if (64 - i > 16) {
			/* 到 */
			/* i = 46, 44, 42, 40, ..., 4, 2, 0 */
			WordNcDisR(row, i+16, MIN(WORD_WIDE, 48-i), dl+WORD_SIZE);
		}
		if (64 - i > 32) {
			/* 了 */
			/* i = 30, 28, 26, 24, ..., 4, 2, 0 */
			WordNcDisR(row, i+32, MIN(WORD_WIDE, 32-i), dl+2*WORD_SIZE);
		}
		DelayTime();
		if (i != 0)
			LCDClear();
	}
}

/* 进站 */
/* 正正正____到了 roll to the whole screen */
void JZ3DisRoll(u8 row, unsigned char *ptr) {
	u8 i;
	int j;

	/* 正正正 roll to the whole right screen */
	/* i = 62, 60, 58, 56, ..., 4, 2, 0 */
	for (i = 62; i <= 62; i -= 2) {
		WordNcDisR(row, i, MIN(WORD_WIDE, 64-i), ptr);  /* 下 */
		if (64 - i > 16) {
			/* 2 */
			/* i = 46, 44, 42, 40, ..., 4, 2, 0 */
			WordNcDisR(row, i+16, MIN(WORD_WIDE, 48-i), ptr+WORD_SIZE);
		}
		if (64 - i > 32) {
			/* 3 */
			/* i = 30, 28, 26, 24, ..., 4, 2, 0 */
			WordNcDisR(row, i+32, MIN(WORD_WIDE, 32-i), ptr+2*WORD_SIZE);
		}
		DelayTime();
		LCDClear();
	}

	/* 正正正 roll to the left screen and disappear from the right */
	/* __到了 roll to the right screen */
	/* i = 62, 60, 58, 56, ..., 4, 2, 0 */
	for (i = 62, j = 2; i <= 62; i -= 2, j += 2) {
		/* left screen */
		WordNcDisL(row, i, MIN(WORD_WIDE, 64-i), ptr);  /* 1 */
		if (64 - i > 16) {
			/* 2 */
			/* i = 46, 44, 42, 40, ..., 4, 2, 0 */
			WordNcDisL(row, i+16, MIN(WORD_WIDE, 48-i), ptr+WORD_SIZE);
		}
		if (64 - i > 32) {
			/* 3 */
			/* i = 30, 28, 26, 24, ..., 4, 2, 0 */
			WordNcDisL(row, i+32, MIN(WORD_WIDE, 32-i), ptr+2*WORD_SIZE);
		}

		/* right screen */
		/* 正正正 disapear from the right */
		/* 1 */
		if (j <= 16) {
			WordNcDisR(row, 0, 16 - j, ptr + j);
		}
		/* 2 */
		if (j <= 16) {
			WordNcDisR(row, 16 - j, 16, ptr + WORD_SIZE);
		} else if (j > 16 && j < 32) {
			WordNcDisR(row, 0, 16 - (j-16), ptr + WORD_SIZE + j - 16);
		}
		/* 3 */
		if (j <= 32) {
			WordNcDisR(row, 32 - j, 16, ptr + 2*WORD_SIZE);
		} else if (j > 32 && j < 48) {
			WordNcDisR(row, 0, 32 - (j-16), ptr + 2*WORD_SIZE + j - 32);
		}

		/* right screen */
		/* __到了 roll to the right */
		WordNcDisR(row, i, MIN(WORD_WIDE, 64-i), dl);  /* blank */
		if (64 - i > 16) {
			/* 到 */
			/* i = 46, 44, 42, 40, ..., 4, 2, 0 */
			WordNcDisR(row, i+16, MIN(WORD_WIDE, 48-i), dl+WORD_SIZE);
		}
		if (64 - i > 32) {
			/* 了 */
			/* i = 30, 28, 26, 24, ..., 4, 2, 0 */
			WordNcDisR(row, i+32, MIN(WORD_WIDE, 32-i), dl+2*WORD_SIZE);
		}
		DelayTime();
		if (i != 0)
			LCDClear();
	}
}