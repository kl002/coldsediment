#define BAUDRATE6		115200					//�趨������
#define BAUDRATEREG6 	80000000/16/BAUDRATE6-1	//�����ʲ��� Fpb=80M

extern void UART6_init();
extern char U6_events();
extern void U6_putbyte ( unsigned char byte );		//U6���͵��ֽ�
extern void TestMode_events();

extern unsigned char U6_code;


