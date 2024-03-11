
#ifndef BASIC_H
#define BASIC_H

#define u8 unsigned char
#define u16	unsigned int 

#define MIN(x,y)  ((x) > (y) ? (y) : (x))

extern void outportb( unsigned int, char);
extern char inportb( unsigned int );

#endif