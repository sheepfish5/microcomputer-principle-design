
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

/* "��һվ  " length = 128B */
extern unsigned char xyz[];

/* "  ����" length=96B */
extern unsigned char dl[];

/* "��վ" length=96B */
extern unsigned char hcz[];

/* "�ĺ��Ƶ�" length=128B */
extern unsigned char whjd[];

/* "�żҷ�" length=96B */
extern unsigned char zjf[];

/* "�ӽ�����" length=128B */
extern unsigned char gjdq[];

/* "���ϴ�" length=96B */
extern unsigned char lsc[];

/* "��ʹ��" length=128B */
extern unsigned char tjgd[];

/* "�й�ʯ��" length=128B */
extern unsigned char zgsh[];

/* "�ʰ�ҽԺ" length=128B */
extern unsigned char rayy[];

/* "��ӭʹ�ñ�վ��" length=224B */
extern unsigned char hysybzq[];

/* logo image 64x64 */
extern unsigned char myImg[];

/* another image 64x64 */
extern unsigned char myImg2[];

#endif
