#include "basic.h"

#ifndef KEY_BOARD_8255_H

#define KEY_BOARD_8255_H

#define PA_Addr		0x270
#define PB_Addr		0x271
#define PC_Addr		0x272
#define	CON_Addr	0x273

#define NO_KEY_PUSHED 0xff

/* initialize 8255 */
void init8255();

/* delay the specific millisecond */
void delay(u16 ms);

/* scan any key pushed */
u8 scan_any_pushed();

/* query the key board and return the pushed key value */
u8 get_key_value(); 

#endif
