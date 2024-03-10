
#ifndef WORD_LIB_H
#define WORD_LIB_H

#define WORD_SIZE 32  /* a Chinese word is 32-byte large */
#define BYTE_SIZE 16  /* an ascii word, i.e. byte, is 16-byte large */

#define WORD_WIDE 16
#define WORD_HIGH 16

#define BYTE_WIDE 8
#define BYTE_HIGH 8

#define FOUR_WORD_LEN 128
#define THREE_WORD_LEN 96

/* "下一站  " length = 128B */
extern unsigned char xyz[];

/* "  到了" length=96B */
extern unsigned char dl[];

/* "火车站" length=96B */
extern unsigned char hcz[];

/* "文海酒店" length=128B */
extern unsigned char whjd[];

/* "张家坊" length=96B */
extern unsigned char zjf[];

/* "赣江大桥" length=128B */
extern unsigned char gjdq[];

/* "岭上村" length=96B */
extern unsigned char lsc[];

/* "天际光电" length=128B */
extern unsigned char tjgd[];

/* "中国石化" length=128B */
extern unsigned char zgsh[];

/* "仁安医院" length=128B */
extern unsigned char rayy[];

#endif
