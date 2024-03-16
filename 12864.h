/********************************************************		
*		12864JҺ����ʾ��
*12864J��1.ͼ�ε���Һ����ʾ�����ֱ���Ϊ128X64������ʾͼ��
*	   ��8��4��(16��16����)���֡�
*	 2.����8λ�������߲������������8�������ߡ�
* 	 3.ָ��򵥣�7��ָ��
********************************************************/

#include "basic.h"

#ifndef H12864_H

#define H12864_H

#define WR_COM_AD_L		0x264				//д�����ָ���ַ
#define WR_COM_AD_R		0x260				//д�Ұ���ָ���ַ
#define WR_DATA_AD_L 	0x266				//д��������ݵ�ַ	
#define WR_DATA_AD_R	0x262				//д�Ұ������ݵ�ַ
#define RD_BUSY_AD 		0x261				//��æ��ַ
#define RD_DATA_AD 		0x263				//�����ݵ�ַ

#define X 			0xB8			/* instruction: y+Y, set the Y coordinate to y */
#define Y			0x40			/* instruction: x+X, set the X coordinate to x */
#define FirstLine	0xC0			/* instruction: set Z to 0 */

#define LEFT_SCREEN 1
#define RIGHT_SCREEN 0

//***************************************
//��������		
//***************************************					
//д���������ָ��
void WRComL(unsigned char _data);

//д�Ұ�������ָ��
void WRComR(unsigned char _data);

//д���������
void WRDataL(unsigned char _data);

//д�Ұ�������
void WRDataR(unsigned char _data);

//��ʾ��������ݣ�count-��ʾ���ݸ���
void DisplayL(unsigned char *pt, char count);

//��ʾ�Ұ������ݣ�count-��ʾ���ݸ���
void DisplayR(unsigned char * pt, char count);

//�����������ʼ��ʾ���е�ַ,x-X��ʼ������(0-7)��y-Y��ʼ������(0-63)
void SETXYL(unsigned char x, unsigned char y);

//�����Ұ�����ʼ��ʾ���е�ַ,x:X��ʼ������(0-7)��y:Y��ʼ������(0-63)
void SETXYR(unsigned char x, unsigned char y);

//***************************************
//��ʾͼ��		
//***************************************
//��ʾ�����һ��ͼ��,A-X��ʼ������(0-7)��B-Y��ʼ�е�ַ����(0-63)
void LineDisL(unsigned char x, unsigned char y, unsigned char * pt);

//��ʾ�Ұ���һ��ͼ��,A-X��ʼ�е�ַ����(0-7)��B-Y��ʼ�е�ַ����(0-63)
void LineDisR(unsigned char x, unsigned char y, unsigned char * pt);

//***************************************
//��ʾ���壬��ʾһ������Ҫռ��X������λ��
//***************************************
//�Ұ�����ʾһ���ֽ�/�֣�x-��ʼ��ʾ������X(0-7)��y-��ʼ��ʾ������Y(0-63)��pt-��ʾ�������׵�ַ
void ByteDisR(unsigned char x, unsigned char y,unsigned char * pt);

void WordDisR(unsigned char x, unsigned char y,unsigned char * pt);

/* write a 8x16 char at (x,y) */
//�������ʾһ���ֽ�/�֣�x-��ʼ��ʾ������X(0-7)��y-��ʼ��ʾ������Y(0-63)��pt-��ʾ�������׵�ַ
void ByteDisL(unsigned char x, unsigned char y,unsigned char * pt);

/* write a 16x16 char at (x,y) */
void WordDisL(unsigned char x, unsigned char y,unsigned char * pt);

//����
void LCDClear();

//Һ����ʼ��	
void LCD_INIT();

//��ʱ����
void DelayTime();

/* Display "��һվ  " on the left 2nd row */
void DisXYZ();

/* 
 * (x,y): start coordinate, y can be set to 0
 * wordSize: FOUR_WORD_LEN or THREE_WORD_LEN
 * flagLR: LEFT_SCREEN or RIGHT_SCREEN
 * ptr: point to the content
 */
void Dis(u8 x, u8 y, u8 flagLR, u8 wordSize, unsigned char *ptr);

/* Display "  ����" on the right 2nd row */
void DisDL();

/* ��һվ__ roll to the right screen */
void XYZDisRollR();

/* ��һվ__ roll to the whole screen */
void XYZDisRoll();

/* ��վ */
/* ��һվ__�������� roll to the whole screen */
void CZ4DisRoll(u8 row, unsigned char *ptr);

/* ��վ */
/* ��һվ__������__ roll to the whole screen */
void CZ3DisRoll(u8 row, unsigned char *ptr);

/* ��վ */
/* ��������__���� roll to the whole screen */
void JZ4DisRoll(u8 row, unsigned char *ptr);

/* ��վ */
/* ������____���� roll to the whole screen */
void JZ3DisRoll(u8 row, unsigned char *ptr); 

/* general function: Display a image on the left LCD */
void DisIMGl(unsigned char *img);

/* general function: Display a image on the right LCD */
void DisIMGr(unsigned char *img);

/* Display a image on the left LCD */
void DisIMG1();

/* Display a image on the right LCD */
void DisIMG2();

#endif
