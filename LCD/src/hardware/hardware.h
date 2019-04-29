//电机相关引脚
#define _SUPPRESS_PLIB_WARNING 1 // 关闭plib报警
#include <xc.h>
#include <plib.h>
#include <sys/attribs.h>



#define M_ENA			LATGbits.LATG0		//电机1使能端口
#define M_ENA_TRIS      TRISGbits.TRISG0	//电机1使能端口方向
#define M_ENA_ODC		ODCGbits.ODCG0
#define M_DIR			LATGbits.LATG1		//电机1方向端口
#define M_DIR_TRIS		TRISGbits.TRISG1	//电机1方向端口方向
#define M_DIR_ODC		ODCGbits.ODCG1
#define M_PUL			LATDbits.LATD5		//电机1脉冲端口
#define M_PUL_TRIS		TRISDbits.TRISD5	//电机1脉冲端口方向

#define R_ENA			LATEbits.LATE1		//电机2使能端口
#define R_ENA_TRIS      TRISEbits.TRISE1	//电机2使能端口方向
#define R_ENA_ODC		ODCEbits.ODCE1
#define R_DIR			LATEbits.LATE0		//电机2方向端口
#define R_DIR_TRIS		TRISEbits.TRISE0	//电机2方向端口方向
#define R_DIR_ODC		ODCEbits.ODCE0
#define R_PUL			LATDbits.LATD6		//电机2脉冲端口
#define R_PUL_TRIS		TRISDbits.TRISD6	//电机2脉冲端口方向

#define N_ENA			LATDbits.LATD1		//电机3使能端口
#define N_ENA_TRIS      TRISDbits.TRISD1	//电机3使能端口方向
#define N_ENA_ODC		ODCDbits.ODCD1
#define N_DIR			LATDbits.LATD2		//电机3方向端口
#define N_DIR_TRIS		TRISDbits.TRISD2	//电机3方向端口方向
#define N_DIR_ODC		ODCDbits.ODCD2
#define N_PUL			LATDbits.LATD3		//电机3脉冲端口
#define N_PUL_TRIS		TRISDbits.TRISD3	//电机3脉冲端口方向

//系统LED相关引脚

#define LAMP_TRIS	TRISGbits.TRISG15	//指示灯方向
#define LAMP		LATGbits.LATG15		//指示灯

//蜂鸣器
#define BUZZER_TRIS	TRISEbits.TRISE4	//
#define BUZZER		LATEbits.LATE4

//NVRAM引脚
#define CS_NVRAM_TRIS 	TRISFbits.TRISF3
#define CS_NVRAM 		LATFbits.LATF3		//定义NVRAM片选端口RF3

