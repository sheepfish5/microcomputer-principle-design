

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

/* "欢迎使用报站器" length=224B */
unsigned char hysybzq[] = {
    /*--  文字:  欢  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x04,0x24,0x44,0x84,0x64,0x9C,0x40,0x30,0x0F,0xC8,0x08,0x08,0x28,0x18,0x00,0x00,
    0x10,0x08,0x06,0x01,0x82,0x4C,0x20,0x18,0x06,0x01,0x06,0x18,0x20,0x40,0x80,0x00,

    /*--  文字:  迎  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x40,0x40,0x42,0xCC,0x00,0x00,0xFC,0x04,0x02,0x00,0xFC,0x04,0x04,0xFC,0x00,0x00,
    0x00,0x40,0x20,0x1F,0x20,0x40,0x4F,0x44,0x42,0x40,0x7F,0x42,0x44,0x43,0x40,0x00,

    /*--  文字:  使  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x80,0x60,0xF8,0x07,0x04,0xE4,0x24,0x24,0x24,0xFF,0x24,0x24,0x24,0xE4,0x04,0x00,
    0x00,0x00,0xFF,0x00,0x80,0x81,0x45,0x29,0x11,0x2F,0x41,0x41,0x81,0x81,0x80,0x00,

    /*--  文字:  用  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x00,0x00,0xFE,0x22,0x22,0x22,0x22,0xFE,0x22,0x22,0x22,0x22,0xFE,0x00,0x00,0x00,
    0x80,0x60,0x1F,0x02,0x02,0x02,0x02,0x7F,0x02,0x02,0x42,0x82,0x7F,0x00,0x00,0x00,

    /*--  文字:  报  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x10,0x10,0x10,0xFF,0x10,0x90,0x00,0xFE,0x82,0x82,0x82,0x92,0xA2,0x9E,0x00,0x00,
    0x04,0x44,0x82,0x7F,0x01,0x00,0x00,0xFF,0x80,0x43,0x2C,0x10,0x2C,0x43,0x80,0x00,

    /*--  文字:  站  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x00,0xC8,0x08,0x09,0x0E,0xE8,0x08,0x00,0x00,0x00,0xFF,0x10,0x10,0x10,0x10,0x00,
    0x10,0x30,0x17,0x10,0x0E,0x09,0x08,0xFF,0x41,0x41,0x41,0x41,0x41,0xFF,0x00,0x00,

    /*--  文字:  器  --*/
    /*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
    0x80,0x80,0x9E,0x92,0x92,0x92,0x9E,0xE0,0x80,0x9E,0xB2,0xD2,0x92,0x9E,0x80,0x00,
    0x08,0x08,0xF4,0x94,0x92,0x92,0xF1,0x00,0x01,0xF2,0x92,0x94,0x94,0xF8,0x08,0x00
};

/* logo image: 64x64 */
unsigned char myImg[] = {
    /*--  调入了一幅图像：C:\Users\sheepfish5\Desktop\logo.bmp  --*/
    /*--  宽度x高度=64x64  --*/
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0xE0,0xE0,0xF0,0xF0,0xF8,0xF8,0xF8,0xF8,0xFC,
    0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xF8,0xF8,0xF8,0xF8,0xF0,
    0xF0,0xF0,0xE0,0xE0,0xC0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x10,0x08,
    0x04,0x04,0x02,0x01,0x03,0x01,0x01,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,
    0x81,0x81,0x83,0x83,0x83,0x83,0x83,0x03,0x03,0x07,0x07,0x07,0x07,0x0F,0x0F,0x0F,
    0x1F,0x1F,0x1F,0x1F,0x7F,0x8F,0x1F,0x7F,0xFC,0xF8,0xE0,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE3,0x92,0x4E,
    0x26,0x32,0x12,0x12,0x22,0x61,0xC1,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x60,
    0x10,0x18,0x08,0x0C,0x04,0x04,0x0C,0x09,0x09,0x11,0x72,0xC2,0x04,0x04,0x08,0x10,
    0x20,0x60,0x80,0x20,0x20,0x2D,0x00,0x00,0x81,0x7F,0x3F,0x80,0x80,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x7F,0x83,0x00,0x00,
    0x00,0x0C,0x1E,0x1E,0x1C,0x80,0x71,0x1F,0x00,0x00,0x00,0x00,0x00,0x7F,0xE1,0x80,
    0x00,0x00,0x04,0x1E,0x1F,0x1F,0x1E,0x04,0x00,0x00,0x80,0xF7,0x3F,0x00,0x00,0x00,
    0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x1F,0x10,0x10,0x10,0x10,0x0F,0x0F,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2E,0xC1,0x00,0x81,0xC1,0xE2,
    0xE2,0xE2,0xE2,0xE2,0xC3,0x91,0x82,0x87,0xCF,0x7F,0xCF,0x86,0x80,0x90,0x80,0x81,
    0xE1,0x23,0x02,0x02,0x02,0x02,0x02,0x02,0x03,0x01,0x01,0x00,0x00,0x00,0x00,0x00,
    0x00,0x80,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x38,0x7C,0xEF,0xDF,0xBF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xFC,0xF8,0xF0,0xE0,0xC0,0xC0,0x40,0x40,0x40,0x40,
    0x40,0x40,0x60,0x20,0x00,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,
    0x32,0xC1,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x07,0x8F,
    0x7F,0x3F,0x1F,0x0F,0x07,0x07,0x03,0x87,0xFF,0xFF,0xFF,0xFF,0xFE,0xFC,0xF8,0xF0,
    0x30,0x18,0x0C,0x06,0x03,0x01,0x00,0x00,0xC0,0x60,0x38,0x08,0x00,0x00,0x00,0x00,
    0x00,0x03,0x7C,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x1F,0x21,
    0xE0,0x60,0x20,0x30,0x18,0x0C,0x07,0x0F,0x1F,0x3F,0x3F,0x1F,0x0F,0x07,0x03,0x0C,
    0x08,0x18,0x18,0x18,0x08,0x04,0x06,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0xFF,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

unsigned char myImg2[] = {
    /*--  调入了一幅图像：C:\Users\sheepfish5\Desktop\微机原理课程设计\p13.bmp  --*/
    /*--  宽度x高度=64x64  --*/
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x80,0x40,0x40,0x20,0x20,0x10,0x10,0x10,0x00,0x00,0x10,0x08,0x08,0x08,
    0x08,0x08,0x08,0x08,0x08,0x00,0x10,0xD8,0x24,0x36,0x26,0x46,0xC3,0x43,0x41,0x01,
    0x21,0x80,0xC0,0xC0,0xC0,0xC0,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x40,0x30,0x18,0x0C,0x86,
    0x43,0x21,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,
    0xC0,0x40,0x00,0x00,0x01,0x02,0x02,0x00,0x00,0x38,0xCE,0x03,0x32,0x30,0x31,0x61,
    0xC3,0x82,0x04,0x08,0x10,0x20,0xC0,0x01,0x01,0x03,0x02,0x04,0x00,0x00,0x00,0x00,
    0x00,0x00,0x80,0xC0,0x30,0x98,0x48,0x1C,0x0E,0x03,0x81,0x20,0x08,0x06,0x01,0xC0,
    0x20,0x00,0x00,0x00,0x00,0xC0,0x30,0x08,0x04,0x02,0x01,0x80,0x60,0x18,0x06,0x01,
    0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x0F,0x38,0xC0,0x02,0x04,
    0x10,0x01,0x03,0x0C,0x38,0xE0,0x00,0x03,0x0C,0x70,0xC0,0x00,0x00,0x00,0x00,0x00,
    0x1E,0x87,0x61,0x18,0x86,0x01,0x00,0x60,0x18,0x02,0x00,0x00,0xE0,0x18,0x02,0x00,
    0x00,0x00,0x00,0x88,0xC3,0xF0,0x0C,0x01,0x00,0x20,0x00,0x01,0x00,0x80,0x00,0x00,
    0x80,0xF0,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x78,0x00,
    0x00,0x00,0xF8,0xC0,0x00,0x01,0x0F,0xFC,0xC0,0x00,0xBF,0xFE,0xF0,0xC0,0x00,0x00,
    0x0E,0xED,0xFE,0xC7,0x70,0x0C,0x83,0xC0,0xE0,0xF8,0xFC,0x1F,0x01,0x00,0x00,0x00,
    0x00,0x00,0x00,0x1F,0x7F,0xFE,0x00,0x00,0xE0,0xD8,0xC0,0xF0,0xFE,0xE7,0xE0,0xFC,
    0xC7,0xC4,0xC4,0x0C,0x38,0x80,0x00,0xE0,0x00,0x00,0xFE,0xF8,0xBE,0x07,0x03,0xC9,
    0xE0,0xB8,0x9F,0xF7,0xF0,0xFF,0x3F,0x7F,0xBF,0xE0,0xFF,0xFF,0x0E,0x78,0xC1,0x00,
    0x1B,0xFF,0xCF,0x8C,0xFE,0x03,0xE9,0xFF,0x7F,0x1F,0xC1,0x70,0xFE,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0xFC,0x01,0x01,0x00,0xC0,0xF7,0x0F,0x1F,0x1F,0x1F,0x1F,0x0F,
    0x00,0x01,0x03,0x00,0x00,0x01,0x03,0x00,0x03,0x07,0x00,0xF0,0x03,0x07,0x03,0x01,
    0x01,0x01,0x01,0xFB,0xFF,0x0F,0x00,0x00,0x07,0xFF,0xFF,0xFF,0x00,0x00,0xFF,0xFC,
    0x00,0x00,0x01,0x03,0x07,0x0F,0x19,0x19,0x3F,0x71,0xE0,0x7C,0xFF,0xE0,0x80,0x00,
    0x00,0x00,0xE0,0xFF,0xFF,0x00,0x00,0xE0,0xFF,0x2F,0xFE,0xC0,0x80,0x00,0x00,0x00,
    0x00,0x70,0xF8,0x98,0x18,0x10,0x10,0x30,0xF0,0xF8,0x30,0x01,0x00,0x80,0xC0,0x60,
    0x18,0x0C,0xEF,0xFF,0xFF,0x00,0x80,0x00,0x00,0xC1,0x7F,0xFF,0x38,0x08,0x0F,0x03,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x03,0x07,0x1C,
    0x38,0x3C,0x0F,0x0F,0xFF,0x78,0x1E,0x07,0x0F,0x18,0x1F,0x31,0x21,0x63,0x66,0x46,
    0xCC,0x8C,0x18,0x19,0x31,0x31,0x31,0xE1,0xF1,0xF8,0xFC,0x5E,0x71,0x79,0x4F,0x78,
    0x38,0x4F,0x03,0x01,0x7F,0x7C,0x5F,0xC1,0x83,0x01,0x00,0x0F,0x00,0x00,0x00,0x00
};

unsigned char myImg3[] = {
    /*--  调入了一幅图像：C:\Users\sheepfish5\Desktop\微机原理课程设计\vb4.bmp  --*/
    /*--  宽度x高度=64x64  --*/
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xE0,0x70,0xD0,0xC0,
    0x60,0x30,0x90,0x98,0x18,0x18,0x9C,0x86,0x86,0x86,0x0C,0x08,0x18,0x18,0x70,0xC0,
    0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xBF,0xFF,0x3C,0x98,0xDC,
    0x0E,0x03,0x01,0x81,0x01,0x01,0x81,0x81,0x99,0x33,0x27,0x06,0x02,0x22,0xF6,0xFE,
    0x88,0x83,0xFE,0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0xF8,0x9C,0x06,0x06,0xE6,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x81,0xC0,0xE1,0xC3,
    0x88,0x9E,0x97,0x81,0xC0,0xC0,0xE0,0xE1,0xC1,0x03,0x00,0x00,0x00,0x0C,0x0F,0x0F,
    0xBF,0xFF,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x38,0xFC,0x44,0x66,0x66,0x67,0x66,0x44,0xCC,0xF9,0x72,0x04,0x9C,0xF0,0xF0,0x30,
    0x20,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x61,0x27,0x3C,0x39,0xF1,
    0x63,0x46,0xC6,0x86,0x83,0x81,0x81,0x01,0x81,0xB0,0xF0,0x78,0x1C,0x1E,0xF3,0x71,
    0x21,0x60,0x40,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x01,0x1F,0x3E,0x66,0x66,0x66,0xE6,0xE4,0xE4,0xFD,0xF7,0xF2,0xFF,0xB1,0x9F,0x80,
    0x80,0x80,0x80,0xC0,0xC0,0xC0,0x40,0x40,0x60,0xF0,0xF0,0x00,0x00,0x00,0x00,0x83,
    0xFE,0x18,0x01,0x01,0x01,0x03,0xF3,0x31,0x11,0x19,0x08,0x0C,0x06,0x03,0x01,0x00,
    0x00,0x00,0x00,0x00,0x01,0x01,0x07,0x06,0x0C,0x18,0x30,0x60,0xC0,0x80,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0x00,0x00,0x00,0x00,0xFF,
    0x0F,0x00,0x00,0x00,0x00,0xFE,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x03,
    0x06,0xF6,0x7C,0x0C,0xCC,0x78,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0xC3,0x7E,0x08,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0x04,0x0C,0x08,0x1F,
    0x0C,0x00,0x00,0x00,0x00,0x1F,0x3F,0x20,0x30,0x30,0x30,0x30,0x10,0x10,0x18,0x18,
    0xFF,0xFF,0x3C,0x77,0xE1,0xC0,0x80,0x80,0x80,0xE0,0x70,0x1C,0x07,0x01,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0x02,0x06,0x06,
    0x04,0x0C,0x0C,0x0C,0x0C,0x08,0x08,0x0C,0x0C,0x0C,0x0C,0x0C,0x04,0x04,0x06,0x06,
    0x07,0x1F,0xF8,0xF0,0xB0,0x30,0x2F,0x3D,0x3B,0x1F,0x00,0x00,0x00,0x00,0x00,0x00
};

unsigned char myImg4[] = {
    /*--  调入了一幅图像：C:\Users\sheepfish5\Desktop\微机原理课程设计\vb3.bmp  --*/
    /*--  宽度x高度=64x64  --*/
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xCF,0xFE,0xF8,0xE0,0x80,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x20,0x70,0x70,0x78,0x28,
    0x28,0x3C,0x1C,0x0C,0x0C,0x74,0xF6,0xFE,0xFE,0xFE,0xFE,0x9E,0xFC,0xE0,0x80,0x80,
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x60,0xE0,0xF8,0xFE,0xFF,0x7F,0x0F,0x0F,0x0E,0x39,
    0xE7,0x9C,0xF0,0xC0,0x00,0x00,0x80,0x40,0x20,0x20,0x3F,0xFE,0xF0,0xF0,0xF0,0xF0,
    0xF0,0xF0,0xF8,0xF8,0xFC,0xFC,0x7E,0x7F,0x3F,0x3F,0x3F,0xFF,0xFF,0xFF,0xF7,0xFF,
    0x9F,0xFF,0x0F,0x0F,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0x60,0x30,0x10,0x98,0xC8,0xCC,0xEC,
    0xF4,0xFF,0xFC,0xFB,0xFE,0xF8,0xE1,0xC6,0x04,0x0C,0x08,0xF8,0x18,0x31,0x71,0x71,
    0x31,0xB1,0xF1,0x31,0x18,0x18,0x0C,0x3C,0x3E,0x1F,0x03,0x01,0x00,0x07,0x1F,0x07,
    0x1F,0xFF,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x0E,0x0F,0x0F,0x0F,0x07,0x07,0x37,0xFB,
    0x8F,0xB1,0x61,0x61,0x7F,0x7F,0x7F,0xFF,0xF6,0xC0,0x80,0x83,0xCF,0xF8,0xE0,0xC8,
    0x98,0x08,0x29,0x2B,0x6C,0xE4,0x24,0x14,0x12,0x06,0x8C,0xC0,0xE0,0xF8,0x7E,0xE6,
    0xC3,0xC1,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x1E,0x3E,0x3E,
    0xFF,0xFF,0xF6,0xF6,0xFA,0xFC,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7C,0x1E,0x8F,0x01,
    0x8F,0xFD,0x71,0x02,0x06,0xCE,0xEE,0x6E,0x6E,0x7E,0x36,0x37,0x1B,0x1C,0x0F,0x0F,
    0x1F,0x3F,0xFF,0xFF,0xFF,0xFE,0xFC,0xF8,0xE0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x01,0x07,0x0F,0x1F,0x3F,0x3F,0x3F,0xFF,0xFF,0x3F,0x0F,0x03,0x00,0xE0,0x79,0x1E,
    0x07,0x81,0xF0,0x7C,0x8F,0x83,0xF0,0x3C,0x00,0x00,0x00,0x00,0xFC,0xFC,0xFC,0xF0,
    0xE0,0x9C,0xF8,0x63,0x1F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF8,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x80,0xF0,0x3E,0x1F,0x19,0x18,0x18,0x18,0x0F,0x03,0x00,0x00,
    0x1C,0x1F,0x33,0x3E,0x3F,0x6F,0x7F,0xD0,0xC0,0xF0,0x7C,0xFF,0xBF,0x1F,0x4F,0x07,
    0x83,0xC0,0xE0,0xF0,0xFE,0xFF,0xFF,0xFF,0x7F,0x3F,0x0F,0x03,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x80,0xF8,0x7F,0x09,0x08,0x0C,0x0C,0xC8,0xF8,0xF8,0xF8,0xF8,0xF8,0xF0,
    0xF0,0xB0,0xB0,0x60,0x60,0x42,0xC3,0xC1,0xF0,0xFC,0xFE,0x26,0xCD,0xDF,0x7E,0x1F,
    0x0F,0x0F,0x0F,0x07,0x07,0x03,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

unsigned char myImg5[] = {
    /*--  调入了一幅图像：C:\Users\sheepfish5\Desktop\微机原理课程设计\gz03.bmp  --*/
    /*--  宽度x高度=64x64  --*/
    0x00,0x00,0x00,0x00,0xC0,0x60,0x30,0x18,0x18,0x1C,0x1C,0x14,0x14,0xA4,0xEC,0xF8,
    0xE0,0xE0,0xF0,0xF8,0x78,0x2C,0x0C,0x06,0x06,0x02,0x02,0x02,0x03,0x03,0x01,0x01,
    0x01,0x01,0x01,0x01,0x01,0x03,0x03,0x03,0x02,0x06,0x06,0x04,0x0C,0x0C,0x18,0x18,
    0x30,0x60,0xE0,0xC0,0x80,0xC0,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xE0,0x38,0x0C,0x07,0x03,0x01,0x00,0x7F,
    0xFF,0xFF,0x19,0x31,0x41,0xC1,0x71,0x1C,0x06,0x83,0xE1,0xF0,0xFC,0x06,0x03,0x01,
    0x00,0xC0,0x60,0x00,0x00,0x00,0xE0,0x60,0x00,0x00,0x00,0x80,0xE0,0xE0,0x80,0x00,
    0x01,0x83,0x02,0x05,0x0B,0x17,0xBF,0x79,0xE3,0x86,0x0C,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0x1F,0x01,0x00,0x00,0x00,0x00,0x00,0xF0,0xF0,
    0xFF,0xFF,0xFE,0xF8,0x7E,0x07,0x00,0x00,0xFE,0xFF,0x1F,0x03,0x00,0x00,0xE0,0xFC,
    0x1F,0x01,0xC0,0xF0,0xFC,0xFF,0x01,0x00,0x80,0xF8,0x1E,0x07,0x07,0x0F,0x1F,0x1E,
    0x1F,0xFF,0xFF,0x00,0x08,0xE0,0x83,0x3E,0x01,0xFF,0xFE,0xC0,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0xFC,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,
    0xEF,0x63,0xFF,0xFF,0x00,0x00,0x00,0x00,0x0F,0xFF,0x7F,0xFF,0x78,0x1F,0x07,0xFF,
    0xFE,0x3F,0x07,0x06,0xFF,0xFD,0xFE,0xFF,0xFF,0x08,0x00,0x00,0x00,0x80,0xC0,0x40,
    0xC0,0xFF,0xFF,0xC0,0xFE,0xFF,0x1F,0xE0,0xFC,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,
    0x80,0xB8,0xFF,0x01,0xFC,0xFC,0x00,0x00,0xE0,0xFF,0x04,0x04,0x06,0x06,0x06,0x07,
    0x07,0x0C,0x0C,0x04,0x00,0x03,0x00,0x00,0x01,0x00,0x00,0xC0,0xC0,0xC1,0xC0,0xF0,
    0x3F,0x1F,0xCF,0x7F,0x3F,0x1F,0x0F,0x0F,0xFF,0x00,0xC1,0xFF,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xC0,0xF0,0x00,0x00,0x00,0xFC,0xF8,0xFF,0xFF,
    0x01,0xFF,0xE3,0x3F,0xFF,0xFF,0x00,0x00,0xFF,0xFF,0x80,0x00,0x00,0x00,0x00,0xC0,
    0x40,0x40,0x40,0xC0,0xC0,0x80,0x80,0x00,0x00,0x10,0x0E,0x00,0x00,0x00,0xC0,0xE1,
    0xFB,0xFF,0xF9,0x00,0x00,0x00,0xFC,0xFE,0x1F,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x80,0xC0,0x80,0x01,0xFF,0xFF,0xFF,
    0x0E,0x83,0xE1,0x3F,0x27,0x2F,0xFF,0xC0,0xFF,0xFF,0xFF,0xF8,0x10,0x20,0x40,0xC0,
    0x80,0x00,0x00,0x80,0xC3,0xE1,0x60,0x30,0x18,0x18,0xFC,0xCC,0x06,0x03,0xE1,0xFC,
    0x1F,0xFF,0x3F,0x00,0xC0,0xFC,0x3F,0xFF,0xE0,0xF8,0xFF,0xFF,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x80,0x40,0x3F,0x3F,0x18,0x13,0x3F,0xF9,0xFF,0xFE,0xFF,0x07,0x0F,
    0x1F,0x01,0x08,0x10,0x20,0x40,0x01,0x1F,0xFF,0xFF,0x00,0x01,0x03,0x02,0x02,0x04,
    0x08,0x88,0x70,0x1F,0x03,0x63,0xC7,0x8C,0x1C,0x3C,0xCF,0x1F,0x6C,0x8F,0x8F,0x8C,
    0x8C,0xEF,0xFC,0x3C,0x0F,0x0C,0x08,0x11,0x7F,0xFF,0x1F,0x03,0x00,0x00,0x00,0x00
};

unsigned char myImg6[] = {
    /*--  调入了一幅图像：C:\Users\sheepfish5\Desktop\微机原理课程设计\ciel03.bmp  --*/
    /*--  宽度x高度=64x64  --*/
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,
    0x40,0x60,0x30,0x10,0x08,0x08,0x24,0x14,0x12,0x12,0x02,0x03,0x01,0x01,0x01,0x01,
    0x01,0x01,0x01,0x01,0x03,0x02,0x02,0x06,0x0C,0x0C,0x1C,0x38,0x38,0x10,0x10,0x20,
    0x40,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xE0,0xF8,0x6E,0x33,0x01,0x00,
    0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0xF0,0xC4,0x18,
    0x60,0xC0,0x01,0x02,0x04,0x18,0xE0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0xFF,0xFF,0xFF,0xCC,0x00,0x00,0x00,
    0x00,0xFC,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFC,0x60,0x80,
    0x3E,0xF8,0xC0,0x00,0x00,0x01,0x87,0x3C,0xF0,0x80,0x18,0xE0,0xC0,0xFC,0xF7,0xFF,
    0xFC,0xFF,0xFF,0xD8,0x20,0x80,0x00,0x03,0xFC,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFC,0x00,0x00,
    0x00,0xFF,0x7F,0xF0,0x38,0xFC,0xC0,0x00,0x00,0x00,0x00,0x00,0x03,0xFF,0x00,0x07,
    0xBC,0xFF,0xC3,0x06,0x78,0xE0,0xC3,0x60,0xEF,0xFF,0xF0,0x6F,0xFF,0xFF,0xFF,0xF3,
    0xFF,0xFF,0x03,0xFF,0xC0,0x7F,0xDE,0xF0,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xFF,0xFF,0xFF,0x1F,0x7F,0xFF,0xFF,
    0xF8,0xFF,0x08,0x01,0x0F,0xBF,0xEF,0x8E,0xB8,0xF8,0xF2,0x90,0x80,0x8F,0xFF,0xC1,
    0x61,0x3F,0x3E,0x78,0x18,0x5F,0xFF,0x3E,0x7F,0x3D,0xBF,0xFE,0xFF,0x0B,0x01,0xFF,
    0xFF,0xFF,0x80,0x0F,0xFF,0xC0,0x7F,0xFF,0x80,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xC3,0xF1,0xFE,0x04,0x01,0x1F,
    0xFF,0xF7,0xC9,0x81,0x87,0x9F,0x2F,0xCF,0xEF,0x63,0x33,0x1F,0x03,0x83,0x07,0x07,
    0x04,0x0C,0x08,0x08,0x08,0x08,0x08,0x0D,0x04,0x06,0x03,0x01,0xFD,0xF0,0xFF,0xFF,
    0xFF,0xFF,0x63,0xF0,0xFF,0xFF,0x00,0xE7,0x0F,0xFB,0xF0,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x7F,0x03,0x01,0x1E,0xE0,0x80,
    0x0F,0xFF,0x3F,0xFF,0xFC,0x30,0x60,0xC0,0xC0,0x80,0x00,0x00,0x00,0x03,0x20,0x20,
    0x20,0x00,0x00,0x20,0x10,0x10,0x00,0x00,0x00,0x00,0x80,0xF0,0x3F,0x07,0xFF,0xFF,
    0xFF,0x8F,0x7C,0x03,0x07,0x7F,0xF9,0x00,0x00,0x00,0x03,0x02,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x07,
    0x18,0xE7,0xF0,0x00,0x07,0xBF,0xC0,0xFF,0x43,0x38,0xF7,0x73,0x1A,0x0E,0x84,0x8C,
    0x00,0x08,0x00,0x10,0x00,0x08,0x04,0x00,0x02,0x01,0x00,0x03,0x00,0x7C,0x1F,0x03,
    0x82,0xCF,0x38,0x10,0x10,0x20,0xC1,0x43,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00
};