
#ifndef BASIC_H
#define BASIC_H

#define u8 unsigned char
#define u16	unsigned int 

#define PA_Addr		0x270
#define PB_Addr		0x271
#define PC_Addr		0x272
#define	CON_Addr	0x273

#define MIN(x,y)  ((x) > (y) ? (y) : (x))

extern void outportb( unsigned int, char);
extern char inportb( unsigned int );
extern void enable( void );										//���ж�
extern void disable( void );									//���ж�
extern void setvect( int, void interrupt(*isr)( void ) );		//д�ж�����
extern void interrupt( far *  getvect( int __interruptno ))( );	//���ж�����

#endif