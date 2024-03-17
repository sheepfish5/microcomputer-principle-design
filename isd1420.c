#include "basic.h"

#define ISDCOMM		PA_Addr	  		//¼������ַ/����ģʽ�����ַ,linked to PA, 8255
#define I8255_PC	PC_Addr			//ISD1420���������

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

u8 KeepMode;						//����REC��PLAYE��PLAYL��ǰֵ

/* mode must be from 0 to 7 */
void write_mode(u8 mode) {
	SET_REC(mode & 0x1);
	SET_PLAYE((mode & 0x2) >> 1);
	SET_PLAYL((mode & 0x4) >> 2);
}

//��ʱ
void Delay20ms()
{
	u16 i = 1320;
	while (--i)
	{;}
}

//��ʱ0.25s�����м��̼�⹦�ܣ�
void Delay_025S()
{
	u16 i = 16000;
	while (i--) {;}
	i = 16000;
	while (i--) {;}
}

//��ʱ
void Delay50ms()
{
	u16 i = 6600;
	while (--i) {;}
}

//��ʼ��
void initISD()
{
	/* set REC, PLAYE, PLAYL to 1 */
	SET_REC(1);		//����ģ���ʼ�����ر�¼��������
	SET_PLAYE(1);
	SET_PLAYL(1);

	KeepMode = 7;							
	outportb(ISDCOMM, 0);	//�����ֶ�¼����,��A6,A7Ϊ��ʱ���޷��ֶ�����
}

//ֹͣ¼����
void stopISD()
{
	u8 i = (KeepMode & 0xfb);  /* set PLAYL bit to 0 */
	write_mode(i);					//PLAYL:һ��������ֹͣ����
	i |= 4;
	write_mode(i);
	i |= 3;				
	/* set REC PLAYE PLAYL to 1 */	
	write_mode(i);					//1->REC,PLAYE, �ر����в���ָ��
	KeepMode = i;  
	outportb(ISDCOMM, 0);					//�����ֶ�¼����,��A6,A7Ϊ��ʱ���޷��ֶ�����
	Delay50ms();
	Delay50ms();
	Delay50ms();
}

//����ģʽ
void modeISD(u8 mode)
{
	u8 i;
	stopISD();								//��ʼ��,REC,PLAYE,PLAYL��λ�����ò���ģʽ
	outportb(ISDCOMM, mode);				//���ò���ģʽ������mode��
	i = KeepMode & 0xfb;
	write_mode(i);					//��PLAYLһ��������,��������
	i |= 4;
	write_mode(i);
	KeepMode = i;
}

//����
void playISD(u8 startadr)
{
	u8 i;
	stopISD();								//��֮ͣǰ��¼��������
	outportb(ISDCOMM, startadr);			//���÷�����ʼ��ַ
	i = KeepMode & 0xfd;
	write_mode(i);					//0->PLAYE ��ʼ����,���ط���ģʽ
	i |= 2;
	write_mode(i);
	KeepMode = i;
}

//play for 2 sec
void KEY_PLAY(u8 startadr)
{
	u16 count = 8;  /* release the voice for 2 sec */
	playISD(startadr);							//����¼���ӳ���
	while (count--)
	{
		Delay_025S();					//��ʱ
	}
}

//play for 4 sec
void KEY_PLAY4(u8 startadr)
{
	u16 count = 16;  /* release the voice for 4 sec */
	playISD(startadr);							//����¼���ӳ���
	while (count--)
	{
		Delay_025S();					//��ʱ
	}
}
