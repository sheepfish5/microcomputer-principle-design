

/* "下一站  " length = 128B */
unsigned char xyz[] = {
    /* 下 */
    0x02,0x02,0x02,0x02,0x02,0x02,0xFE,0x02,0x02,0x42,0x82,0x02,0x02,0x02,0x02,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x01,0x06,0x00,0x00,0x00,

    /* 一 */
    0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

    /* 站 */
    0x00,0xC8,0x08,0x09,0x0E,0xE8,0x08,0x00,0x00,0x00,0xFF,0x10,0x10,0x10,0x10,0x00,
    0x10,0x30,0x17,0x10,0x0E,0x09,0x08,0xFF,0x41,0x41,0x41,0x41,0x41,0xFF,0x00,0x00,

    /* 16x16 blank */
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

/* "  到了" length=96B */
unsigned char dl[] = {
    /* 16x16 blank */
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

    /* 到 */
    0x42,0x62,0x52,0x4A,0xC6,0x42,0x52,0x62,0xC2,0x00,0xF8,0x00,0x00,0xFF,0x00,0x00,
    0x40,0xC4,0x44,0x44,0x7F,0x24,0x24,0x24,0x20,0x00,0x0F,0x40,0x80,0x7F,0x00,0x00,

    /* 了 */
    0x00,0x02,0x02,0x02,0x02,0x02,0x02,0xE2,0x22,0x12,0x0A,0x06,0x02,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

/* "火车站" length=96B */
unsigned char hcz[] = {
    /*--  文字:  火  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x00,0x00,0xC0,0x38,0x00,0x00,0x00,0xFF,0x00,0x00,0x40,0x20,0x18,0x00,0x00,0x00,
    0x80,0x81,0x40,0x20,0x10,0x0C,0x03,0x00,0x03,0x0C,0x10,0x20,0x40,0x80,0x80,0x00,

    /*--  文字:  车  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x00,0x08,0x88,0x48,0x28,0x18,0x0F,0xE8,0x08,0x08,0x08,0x08,0x08,0x08,0x00,0x00,
    0x08,0x08,0x09,0x09,0x09,0x09,0x09,0xFF,0x09,0x09,0x09,0x09,0x09,0x08,0x08,0x00,

    /*--  文字:  站  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x00,0xC8,0x08,0x09,0x0E,0xE8,0x08,0x00,0x00,0x00,0xFF,0x10,0x10,0x10,0x10,0x00,
    0x10,0x30,0x17,0x10,0x0E,0x09,0x08,0xFF,0x41,0x41,0x41,0x41,0x41,0xFF,0x00,0x00
};

/* "文海酒店" length=128B */
unsigned char whjd[] = {
    /*--  文字:  文  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x08,0x08,0x08,0x38,0xC8,0x08,0x09,0x0E,0x08,0x08,0xC8,0x38,0x08,0x08,0x08,0x00,
    0x80,0x80,0x40,0x40,0x20,0x11,0x0A,0x04,0x0A,0x11,0x20,0x40,0x40,0x80,0x80,0x00,

    /*--  文字:  海  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x10,0x60,0x02,0x0C,0xC0,0x10,0x08,0xF7,0x14,0x54,0x94,0x14,0xF4,0x04,0x00,0x00,
    0x04,0x04,0x7C,0x03,0x00,0x01,0x1D,0x13,0x11,0x55,0x99,0x51,0x3F,0x11,0x01,0x00,

    /*--  文字:  酒  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x20,0xC2,0x0C,0x80,0x02,0xF2,0x12,0x12,0xFE,0x12,0xFE,0x12,0x12,0xF2,0x02,0x00,
    0x04,0x04,0x7E,0x01,0x00,0xFF,0x4A,0x49,0x48,0x48,0x48,0x49,0x49,0xFF,0x00,0x00,

    /*--  文字:  店  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x00,0x00,0xFC,0x04,0x04,0x04,0x04,0x05,0xFE,0x44,0x44,0x44,0x44,0x44,0x04,0x00,
    0x40,0x30,0x0F,0x00,0x00,0xFE,0x42,0x42,0x43,0x42,0x42,0x42,0xFE,0x00,0x00,0x00
};

/* "张家坊" length=96B */
unsigned char zjf[] = {
    /*--  文字:  张  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x02,0xE2,0x22,0x22,0x3E,0x80,0x80,0xFF,0x80,0xA0,0x90,0x88,0x86,0x80,0x80,0x00,
    0x00,0x43,0x82,0x42,0x3E,0x00,0x00,0xFF,0x40,0x21,0x06,0x08,0x10,0x20,0x40,0x00,

    /*--  文字:  家  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x10,0x2C,0x24,0x24,0xA4,0xA4,0x65,0xA6,0x24,0x24,0x24,0x24,0xA4,0x34,0x0C,0x00,
    0x40,0x49,0x49,0x29,0x24,0x14,0x52,0x89,0x7F,0x04,0x0A,0x11,0x10,0x20,0x20,0x00,

    /*--  文字:  坊  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x20,0x20,0x20,0xFF,0x20,0x20,0x08,0x08,0xF8,0x89,0x8E,0x88,0x88,0x88,0x08,0x00,
    0x10,0x30,0x10,0x0F,0x08,0x88,0x40,0x30,0x0F,0x00,0x40,0x80,0x40,0x3F,0x00,0x00
};

/* "赣江大桥" length=128B */
unsigned char gjdq[] = {
    /*--  文字:  赣  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x12,0xD6,0x5A,0x53,0x5A,0xD6,0x12,0x28,0x64,0x57,0xCA,0x56,0x52,0x20,0x20,0x00,
    0x10,0x17,0x15,0xFD,0x15,0x17,0x10,0x81,0xBD,0x45,0x35,0x45,0xBD,0x01,0x00,0x00,

    /*--  文字:  江  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x10,0x60,0x02,0x0C,0xC0,0x04,0x04,0x04,0x04,0xFC,0x04,0x04,0x04,0x04,0x00,0x00,
    0x04,0x04,0x7C,0x03,0x20,0x20,0x20,0x20,0x20,0x3F,0x20,0x20,0x20,0x20,0x20,0x00,

    /*--  文字:  大  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x20,0x20,0x20,0x20,0x20,0x20,0x20,0xFF,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x00,
    0x80,0x80,0x40,0x20,0x10,0x0C,0x03,0x00,0x03,0x0C,0x10,0x20,0x40,0x80,0x80,0x00,

    /*--  文字:  桥  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x10,0x90,0xFF,0x90,0x10,0x20,0x24,0xA4,0x64,0x3E,0x62,0xA3,0x22,0x20,0x20,0x00,
    0x06,0x01,0xFF,0x00,0x01,0x82,0x61,0x1E,0x00,0x00,0x00,0xFE,0x01,0x02,0x02,0x00
};

/* "岭上村" length=96B */
unsigned char lsc[] = {
    /*--  文字:  岭  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x00,0xF0,0x00,0xFF,0x00,0xF0,0x40,0x20,0x10,0x0C,0x23,0xCC,0x10,0x20,0x40,0x00,
    0x00,0x1F,0x10,0x0F,0x08,0x1F,0x00,0x01,0x09,0x11,0x21,0xD1,0x0D,0x03,0x00,0x00,

    /*--  文字:  上  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,
    0x40,0x40,0x40,0x40,0x40,0x40,0x7F,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,

    /*--  文字:  村  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x10,0x10,0xD0,0xFF,0x90,0x10,0x00,0x10,0x10,0x10,0x10,0xFF,0x10,0x10,0x10,0x00,
    0x04,0x03,0x00,0xFF,0x00,0x03,0x00,0x01,0x06,0x40,0x80,0x7F,0x00,0x00,0x00,0x00
};

/* "天际光电" length=128B */
unsigned char tjgd[] = {
    /*--  文字:  天  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x40,0x40,0x42,0x42,0x42,0x42,0x42,0xFE,0x42,0x42,0x42,0x42,0x42,0x40,0x40,0x00,
    0x80,0x80,0x40,0x20,0x10,0x0C,0x03,0x00,0x03,0x0C,0x10,0x20,0x40,0x80,0x80,0x00,

    /*--  文字:  际  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x00,0xFE,0x22,0x5A,0x86,0x00,0x20,0x22,0x22,0x22,0xE2,0x22,0x22,0x22,0x20,0x00,
    0x00,0xFF,0x04,0x08,0x07,0x10,0x0C,0x03,0x40,0x80,0x7F,0x00,0x01,0x06,0x18,0x00,

    /*--  文字:  光  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x40,0x40,0x42,0x44,0x58,0xC0,0x40,0x7F,0x40,0xC0,0x50,0x48,0x46,0x40,0x40,0x00,
    0x80,0x80,0x40,0x20,0x18,0x07,0x00,0x00,0x00,0x3F,0x40,0x40,0x40,0x40,0x78,0x00,

    /*--  文字:  电  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x00,0x00,0xF8,0x88,0x88,0x88,0x88,0xFF,0x88,0x88,0x88,0x88,0xF8,0x00,0x00,0x00,
    0x00,0x00,0x1F,0x08,0x08,0x08,0x08,0x7F,0x88,0x88,0x88,0x88,0x9F,0x80,0xF0,0x00
};

unsigned char zgsh[] = {
    /*--  文字:  中  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x00,0x00,0xF0,0x10,0x10,0x10,0x10,0xFF,0x10,0x10,0x10,0x10,0xF0,0x00,0x00,0x00,
    0x00,0x00,0x0F,0x04,0x04,0x04,0x04,0xFF,0x04,0x04,0x04,0x04,0x0F,0x00,0x00,0x00,

    /*--  文字:  国  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x00,0xFE,0x02,0x12,0x92,0x92,0x92,0xF2,0x92,0x92,0x92,0x12,0x02,0xFE,0x00,0x00,
    0x00,0xFF,0x40,0x48,0x48,0x48,0x48,0x4F,0x48,0x4A,0x4C,0x48,0x40,0xFF,0x00,0x00,

    /*--  文字:  石  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x02,0x02,0x02,0x02,0xC2,0xB2,0x8E,0x82,0x82,0x82,0x82,0x82,0x82,0x02,0x02,0x00,
    0x08,0x04,0x02,0x01,0xFF,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0xFF,0x00,0x00,0x00,

    /*--  文字:  化  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x00,0x80,0x60,0xF8,0x07,0x00,0x00,0x00,0xFF,0x40,0x20,0x10,0x08,0x04,0x00,0x00,
    0x01,0x00,0x00,0xFF,0x00,0x04,0x02,0x01,0x3F,0x40,0x40,0x40,0x40,0x40,0x78,0x00
};

/* "仁安医院" length=128B */
unsigned char rayy[] = {
    /*--  文字:  仁  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x00,0x80,0x60,0xF8,0x07,0x00,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x00,0x00,
    0x01,0x00,0x00,0xFF,0x00,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00,

    /*--  文字:  安  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x80,0x90,0x8C,0x84,0x84,0x84,0xF5,0x86,0x84,0x84,0x84,0x84,0x94,0x8C,0x80,0x00,
    0x00,0x80,0x80,0x84,0x46,0x49,0x28,0x10,0x10,0x2C,0x23,0x40,0x80,0x00,0x00,0x00,

    /*--  文字:  医  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x00,0xFE,0x02,0xA2,0x92,0x9E,0x92,0x92,0xF2,0x92,0x92,0x92,0x92,0x82,0x00,0x00,
    0x00,0x7F,0x40,0x50,0x50,0x48,0x44,0x42,0x41,0x42,0x44,0x48,0x50,0x40,0x40,0x00,

    /*--  文字:  院  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x00,0xFE,0x22,0x5A,0x86,0x10,0x0C,0x24,0x24,0x25,0x26,0x24,0x24,0x14,0x0C,0x00,
    0x00,0xFF,0x04,0x08,0x07,0x80,0x41,0x31,0x0F,0x01,0x01,0x3F,0x41,0x41,0x71,0x00
};

