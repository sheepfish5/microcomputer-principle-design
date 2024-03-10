
#ifndef KEY_BOARD_8255_H

#define KEY_BOARD_8255_H

#define PA_Addr		0x270
#define PB_Addr		0x271
#define PC_Addr		0x272
#define	CON_Addr	0x273

#define u8	unsigned char 
#define u16	unsigned int 

#define NO_KEY_PUSHED 0xff

/* delay the specific millisecond */
void delay(u16 ms);

/* scan any key pushed */
u8 scan_any_pushed();

/* query the key board and return the pushed key value */
u8 get_key_value(); 

#endif
