#include "basic.h"

#define VOICE_1_0x00 0x00
#define VOICE_2_0x10 0x10
#define VOICE_3_0x20 0x20
#define VOICE_4_0x30 0x30
#define VOICE_5_0x40 0x40
#define VOICE_6_0x50 0x50
#define VOICE_7_0x60 0x60
#define VOICE_8_0x70 0x70

#define VOICE_AD_0x80 0x80

//��ʱ
void Delay20ms();

//��ʱ0.25s
void Delay_025S();

//��ʱ
void Delay50ms();

//��ʼ��
void initISD();

//ֹͣ¼����
void stopISD();

//����ģʽ
void modeISD(u8 mode);

//����
void playISD(u8 startadr);

//����
void KEY_PLAY(u8 startadr);
