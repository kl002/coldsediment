#include <xc.h>
#include <plib.h>
#include <sys/attribs.h>
#include <p32xxxx.h>

#define BAUDRATE6		9600					//设定波特率
#define BAUDRATEREG6 	80000000/16/BAUDRATE6-1	//波特率参数 Fpb=80M

#define BAUDRATE2		9600					//设定波特率
#define BAUDRATEREG2 	80000000/16/BAUDRATE6-1	//波特率参数 Fpb=80M

extern void UART2_init();
extern void UART6_init();
extern int Scan1[30] ;
extern int Scan2[30] ;