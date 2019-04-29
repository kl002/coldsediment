#define BAUDRATE6		115200					//设定波特率
#define BAUDRATEREG6 	80000000/16/BAUDRATE6-1	//波特率参数 Fpb=80M

extern void UART6_init();
extern char U6_events();
extern void U6_putbyte ( unsigned char byte );		//U6发送单字节
extern void TestMode_events();

extern unsigned char U6_code;


