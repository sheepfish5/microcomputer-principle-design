/********************************************************		
*		12864J液晶显示器
*12864J：1.图形点阵液晶显示器，分辨率为128X64。可显示图形
*	   和8×4个(16×16点阵)汉字。
*	 2.采用8位数据总线并行输入输出和8条控制线。
* 	 3.指令简单，7种指令
********************************************************/

#ifndef H12864_H

#define H12864_H

#define WR_COM_AD_L		0x264				//写左半屏指令地址
#define WR_COM_AD_R		0x260				//写右半屏指令地址
#define WR_DATA_AD_L 	0x266				//写左半屏数据地址	
#define WR_DATA_AD_R	0x262				//写右半屏数据地址
#define RD_BUSY_AD 		0x261				//查忙地址
#define RD_DATA_AD 		0x263				//读数据地址

#define X 			0xB8							//起始显示行基址
#define Y			0x40							//起始显示列基址
#define FirstLine	0xC0							//起始显示行

extern void outportb( unsigned int, char);
extern char inportb( unsigned int );


//***************************************
//基本控制		
//***************************************					
//写左半屏控制指令
void WRComL(unsigned char _data);

//写右半屏控制指令
void WRComR(unsigned char _data);

//写左半屏数据
void WRDataL(unsigned char _data);

//写右半屏数据
void WRDataR(unsigned char _data);

//显示左半屏数据，count-显示数据个数
void DisplayL(unsigned char *pt, char count);

//显示右半屏数据，count-显示数据个数
void DisplayR(unsigned char * pt, char count);

//设置左半屏起始显示行列地址,x-X起始行序数(0-7)，y-Y起始列序数(0-63)
void SETXYL(unsigned char x, unsigned char y);

//设置右半屏起始显示行列地址,x:X起始行序数(0-7)，y:Y起始列序数(0-63)
void SETXYR(unsigned char x, unsigned char y);

//***************************************
//显示图形		
//***************************************
//显示左半屏一行图形,A-X起始行序数(0-7)，B-Y起始列地址序数(0-63)
void LineDisL(unsigned char x, unsigned char y, unsigned char * pt);

//显示右半屏一行图形,A-X起始行地址序数(0-7)，B-Y起始列地址序数(0-63)
void LineDisR(unsigned char x, unsigned char y, unsigned char * pt);

//***************************************
//显示字体，显示一个数据要占用X行两行位置
//***************************************
//右半屏显示一个字节/字：x-起始显示行序数X(0-7)；y-起始显示列序数Y(0-63)；pt-显示字数据首地址
void ByteDisR(unsigned char x, unsigned char y,unsigned char * pt);

void WordDisR(unsigned char x, unsigned char y,unsigned char * pt);

/* write a 8x16 char at (x,y) */
//左半屏显示一个字节/字：x-起始显示行序数X(0-7)；y-起始显示列序数Y(0-63)；pt-显示字数据首地址
void ByteDisL(unsigned char x, unsigned char y,unsigned char * pt);

/* write a 16x16 char at (x,y) */
void WordDisL(unsigned char x, unsigned char y,unsigned char * pt);

//清屏
void LCDClear();

//液晶初始化	
void LCD_INIT();

//延时程序
void DelayTime();


#endif
