#include "hardware.h"
#include "../system/system.h"


#define M_ENABLE		0   // 电机锁定不动
#define M_DISABLE       1   // 电机不运行状态
#define M_FREE		    3	// 电机不受控，不使能，可以省电
#define M_RUNNING		2	// 电机正在运行

//电机步进计数功能未进行
#define M_STEP_DISABLE  0
//电机步进功能正在进行中
#define M_STEP_RUNNING	1	
//电机已完成所设定目标步数
#define M_STEP_DONE		2

#define CLOCKWISE		0	//定义电机运转方向
#define ANTICLOCKWISE	1

#define M_PULSE_PER_REV 400  //定义电机每转动一圈需要的脉冲数
#define R_PULSE_PER_REV 400  //定义电机每转动一圈需要的脉冲数
#define N_PULSE_PER_REV 400  //定义电机每转动一圈需要的脉冲数

#define M_STEP_PULSES         (400 * M_XIFEN_NUM / CTR_ACCURACY) 
#define M_XIFEN_NUM 20 //如果安装伺服电机，则细分值为20，步进电机为32
#define BASE_M_TIMER ( 1500000 / M_XIFEN_NUM )
#define CTR_ACCURACY 100

#define MAX_SPEED 120
#define FACTOR 1

extern void Motor_init();

extern void Motor_R_Action();
extern void Motor_R_Run (unsigned int speed, unsigned char direction);
extern void Motor_R_Stop();
extern void Motor_R_Step_Run(unsigned int steps, unsigned int speed, unsigned char direction);


extern unsigned char Motor_R_Status ;
extern unsigned int Motor_R_Speed  ;
extern unsigned char Motor_R_Direction ;
extern unsigned char Motor_R_Step_Status  ;
extern unsigned int Motor_R_Step_Num  ;

extern unsigned char Last_Motor_R_Status  ;
extern unsigned int Last_Motor_R_Speed  ;
extern unsigned char Last_Motor_R_Direction  ;
extern unsigned char Last_Motor_R_Step_Status  ;
extern unsigned int Last_Motor_R_Step_Num  ;
