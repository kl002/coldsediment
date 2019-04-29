#include "motor.h"

unsigned char Motor_R_Status = M_DISABLE ;
unsigned int Motor_R_Speed = 0 ;
unsigned char Motor_R_Direction = CLOCKWISE ;
unsigned char Motor_R_Step_Status = M_STEP_DISABLE ;
unsigned int Motor_R_Step_Num = 0 ;

unsigned char Last_Motor_R_Status = M_DISABLE ;
unsigned int Last_Motor_R_Speed = 0 ;
unsigned char Last_Motor_R_Direction = CLOCKWISE ;
unsigned char Last_Motor_R_Step_Status = M_STEP_DISABLE ;
unsigned int Last_Motor_R_Step_Num = 0 ;

unsigned int R_Count_Pulses = 0;
unsigned int R_Count_Steps = 0;

char Motor_R_Change();

void Motor_init()
{    
    M_ENA_TRIS = 0;		
    M_ENA_ODC  = 1;                
	M_ENA      = M_DISABLE;
	M_DIR_TRIS = 0;
    M_DIR_ODC  = 1;
	M_DIR      = ANTICLOCKWISE;
	M_PUL_TRIS = 0;
	M_PUL      = 0;
    
    R_ENA_TRIS = 0;		
    R_ENA_ODC = 1;                 
	R_ENA = M_DISABLE;
	R_DIR_TRIS = 0;
    R_DIR_ODC = 1;                
	R_DIR = ANTICLOCKWISE;
	R_PUL_TRIS = 0;
	R_PUL = 0;    
    
    N_ENA_TRIS = 0;		
    N_ENA_ODC = 0;               
	N_ENA = M_DISABLE;
	N_DIR_TRIS = 0;
    N_DIR_ODC = 0;                
	N_DIR = ANTICLOCKWISE;
	N_PUL_TRIS = 0;
	N_PUL = 0;      

	T3CON = 0;				//BP/AP输出PUL定时器
	TMR3 = 0;
	PR3 = BASE_M_TIMER;				//每秒送200脉冲		
	T3CON = 0x8030;			//启动定时器T3,8分频	

	mT3SetIntPriority(7);	//指定所选中断源的优先级
	mT3IntEnable(1);		//使能T3中断   

}

void Motor_R_Run (unsigned int speed, unsigned char direction)
{
    
    if( speed != 0 )
    {
        Motor_R_Status = M_RUNNING ;
        Motor_R_Direction = direction ;
    }
    else
        Motor_R_Status = M_FREE ;
        
}

void Motor_R_Stop()
{
    Motor_R_Status = M_DISABLE ;
}

void Motor_R_Step_Run(unsigned int steps, unsigned int speed, unsigned char direction)
{
    Motor_R_Step_Status = M_STEP_RUNNING ;
    Motor_R_Step_Num = steps ;
    Motor_R_Status = M_RUNNING ;
    Motor_R_Speed = speed ;
    Motor_R_Direction = direction ;
}

void Motor_R_Action()
{
    if( Motor_R_Change() == 1 )
    {
        Last_Motor_R_Status = Motor_R_Status ;
        Last_Motor_R_Speed = Motor_R_Speed ;
        Last_Motor_R_Direction = Motor_R_Direction ;
        Last_Motor_R_Step_Status = Motor_R_Step_Status ;
        Last_Motor_R_Step_Num = Motor_R_Step_Num ;
        
        if( Motor_R_Status == M_FREE )
            R_ENA = 1;
        else 
            R_ENA = M_ENABLE ;    
        if ( Motor_R_Direction == CLOCKWISE)
            R_DIR = CLOCKWISE;
        else
            R_DIR = ANTICLOCKWISE;
        if( Motor_R_Speed == 0 )
        {
            Motor_R_Status = M_DISABLE ;
        }
        else 
            PR3 = BASE_M_TIMER/ Motor_R_Speed;          
    }
    if( Motor_R_Step_Status == M_STEP_RUNNING )
    {
        if( R_Count_Steps >=  Motor_R_Step_Num)
        {
            Motor_R_Step_Status = M_STEP_DONE ;
            Motor_R_Status = M_DISABLE ;
        }
    }
}

char Motor_R_Change()  // 判断是否电机状态发生改变
{
    if( T1_Motor_R_Jitter >50 )
    {
        if( Motor_R_Status != Last_Motor_R_Status)
        {
            T1_Motor_R_Jitter = 0 ;
            return 1;
        }
        if( Motor_R_Speed != Last_Motor_R_Speed)
        {
            T1_Motor_R_Jitter = 0 ;
            return 1;
        }
        if( Motor_R_Direction != Last_Motor_R_Direction)
        {
            T1_Motor_R_Jitter = 0 ;
            return 1;
        }
        if( Motor_R_Step_Status != Last_Motor_R_Step_Status)
        {
            T1_Motor_R_Jitter = 0 ;
            return 1;
        }
        if( Motor_R_Step_Num != Last_Motor_R_Step_Num)
        {
            T1_Motor_R_Jitter = 0 ;
            return 1;
        }
    }
    return 0 ;
}

void __ISR(_TIMER_3_VECTOR, IPL7SOFT) T3Interrupt(void)
{
//	if(flag_M_run != M_DISABLE)				//60RPM/10k
//	{
//		M_PUL = !M_PUL;
//        M_count_pulses++;           //记录脉冲数
//        if( M_count_pulses >= M_STEP_PULSES )       //400步/转
//        {
//          M_count_pulses = 0;
//          M_count_steps++;
//        }
//	}

	if( Motor_R_Status == M_RUNNING )				//60RPM/10k
	{
		R_PUL = !R_PUL;
        R_Count_Pulses++;           //记录脉冲数
        if( R_Count_Pulses >= M_STEP_PULSES )       //400步/转
        {
          R_Count_Pulses = 0;
          R_Count_Steps++;
        }
	}    
    
//    if(flag_N_run != M_DISABLE)				//60RPM/10k
//	{
//		N_PUL = !N_PUL;
//        N_count_pulses++;           //记录脉冲数
//        if( N_count_pulses >= M_STEP_PULSES )       //400步/转
//        {
//          N_count_pulses = 0;
//          N_count_steps++;
//        }
//	}

	IFS0bits.T3IF = 0;	//中断标志清零
}
