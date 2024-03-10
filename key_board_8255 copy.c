#define PA_Addr		0x270
#define PB_Addr		0x271
#define PC_Addr		0x272
#define	CON_Addr	0x273

#define u8	unsigned char 
#define u16	unsigned int 

extern char inportb( unsigned int );								//��I/O
extern void outportb( unsigned int, char);

u8 buffer[8] = {0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10};	//����ʾ��������ֵ

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

//ɨ�������
void DIR()
{
	u8 i, dig = 0xfe;
	u8 SegArray[]={0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8,
			   0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E, 0xFF}; 

	for (i = 0 ; i < 8; i++)
	{
		outportb(PA_Addr, SegArray[buffer[i]]);		//������
		outportb(PB_Addr, dig);						//ѡ�������
		delay(3);									//�ӳ�3ms
		outportb(PB_Addr, 0xff);
		dig = ((dig << 1) | 1);
	}
}

u8 scan_any_pushed()
{
	u8 i;
	outportb(PB_Addr, 0x0);
	i = (~inportb(PC_Addr) & 0x3);
	return i;
}

u8 key()
{
	u8 i, j, keyResult;
	u8 bNoKey = 1;
	while(bNoKey)
	{
		if (scan_any_pushed() == 0)		//���������ޱպϼ�����
		{
			DIR();
			DIR();
			continue;
		}
		DIR();
		DIR();
		if (scan_any_pushed() == 0)		//���������ޱպϼ�����
			continue;
		i = 0xfe;
		keyResult = 0;
		do
		{
			outportb(PB_Addr, i);
			j = ~inportb(PC_Addr);
			if (j & 3)
			{
				bNoKey = 0;
				if (j & 2)				//1���м��պ�
					keyResult += 8;
			}
			else						//û�м�����
			{
				keyResult++;			//�м�������1
				i = ((i << 1) | 1);
			}
		}while(bNoKey  && (i != 0xff));
	}
	if (!bNoKey)
	{
		while(scan_any_pushed())		//�ж��ͷŷ�
		{
			DIR();
		}
	}
	return keyResult;
}

void main()
{
	u8 pos = 0;
	outportb(CON_Addr, 0x89);	//PA��PB�����PC����
	while(1)
	{
		buffer[pos++] = key();
		pos &= 0x7;
	}
}
