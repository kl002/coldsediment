#define CS_NVRAM_TRIS 	TRISFbits.TRISF3
#define CS_NVRAM 		LATFbits.LATF3		//����NVRAMƬѡ�˿�RF3

extern unsigned NVRAM_read_address;		//NVRAM����ַ
extern unsigned char NVRAM_read_data;	//NVRAM������
extern unsigned NVRAM_write_address;		//NVRAMд��ַ
extern unsigned char NVRAM_write_data;	//NVRAMд����

//NVRAM commands
#define SEE_WRSR    1       // write status register	
#define SEE_WRITE   2       // write command
#define SEE_READ    3       // read command
#define SEE_WDI     4       // write disable
#define SEE_STAT    5       // read status register
#define SEE_WEN     6       // write enable

extern int writeSPI( int i);
extern void NVRAM_init( void);
extern int readStatus( void);
extern int readSEE( int address);
extern void writeEnable( void);
extern void writeSEE( int address, int data);

// 冷沉淀重量范围设置
#define      EE_LCD_Low       0x0100         
#define      EE_LCD_High      0x0104 


extern void EE_events();
extern void EE_recover();
