#include "kb_8255.h"
#include "basic.h"

#define INIT8255 0x81  /* 1 000 0 00 1 */

#define IS_PUSHED (~inportb(PC_Addr) & 1)  /* 1 stands some key pushed while 0 stands no */
#define SCAN_A(i) (outportb(PB_Addr, ~((u8)1 << i)))  /* set column Ai to 0 while others are 1 */

/* initialize 8255 */
void init8255() {
	outportb(CON_Addr, INIT8255);
}

void delay(u16 ms)
{
	u16 i;
	while(ms--)
	{
		i = 100;
		do
		{;}while(--i);
	}
}

/* return the negated KL1 value through PC0
 * return 0 when no key is pushed, 1 when some one is pushed.
 */
u8 scan_any_pushed()
{
	u8 i;
	outportb(PB_Addr, 0x0);
	/* return the KL1 value through PC0 */
	i = (~inportb(PC_Addr) & 0x1);
	return i;
}

/* 
 * after scan_any_pushed() == 1, key() scan columns to get the first key pushed.
 * return the pushed key value from 0 to 7.
 * return 0xff, which denotes no key pushed.
 */
u8 get_key_value() {
	u8 i;
	for (i = 0; i < 8; i++) {
		SCAN_A(i);
		if (IS_PUSHED) {
			return i;
		}
	}
	return NO_KEY_PUSHED;
}
