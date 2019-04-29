/* 
 * File:   main.c
 * Author: wang
 *
 * Created on August 23, 2018, 2:46 PM
 */

#include "include.h"

#define AVG_NUM 10
#define RATE_1 2048
#define RATE_2 2048

int avg_weigh1;
int avg_weigh2;
int pre_weigh1 = 0;

void Input_All_Update();
void Output_All_Update();
void UpdateUI();
void Stop_Check();
void process_w1( int orignal_weight );
void process_w2( int orignal_weight );
void avg_w1(int w1);
void avg_w2(int w2);

char *strVerson = "1.0.0";

void main()
{
    system_init();
    NVRAM_init();
    Motor_init();
    led_init();
    mcu_adc_init();
    UART5_init();
    UART2_init();
    UART6_init();
    Scale_init();
    
    Ui_Show_Bg(BG_LOGO);
    delay10us(500000);
    
    Ui_Show_Bg(BG_STANDBY);
//    Ui_Show_Str_Var(ID_Ver, strVerson);
    
    sysSetting.lcd_l = readSEE(EE_LCD_Low);
    sysSetting.lcd_h = readSEE(EE_LCD_High);
    if (sysSetting.lcd_l < 10) {
        sysSetting.lcd_l = 30;        
        writeSEE(EE_LCD_Low, sysSetting.lcd_l);
    }
    if (sysSetting.lcd_h < 10) {        
        sysSetting.lcd_h = 60;
        writeSEE(EE_LCD_High, sysSetting.lcd_h);
    }
    
    while(1)
    {
        Input_All_Update();
        Output_All_Update();
        
        if (gCurStatus != gPreStatus)
        {
            switchSysStatus(gPreStatus, gCurStatus);
            gPreStatus = gCurStatus;                
        }
        
        switch (gCurStatus)
        {      
            default:
            case ST_STANDBY:
                break;
            case ST_WEIGH:
                doWeighing();
                break;
            case ST_WEIGH_END:
                break;
        }
        
        if (T1_100MS > 10)
        {
            T1_100MS = 0;
            
            UpdateUI();
            refreshDeltaW();
        }
        
        if(T1_Com >= 100)		//1秒定时
        {
            T1_Com = 0 ;
            WDTCONSET = 0x01;					//喂狗
        }
        
        touch_events();
        doCmd();
    }
}

void Input_All_Update()
{
    int orignal_w1, orignal_w2;
    orignal_w1 = Read_Scale1();
    process_w1( orignal_w1 ) ; // 转换原始值
    orignal_w2 = Read_Scale2();
    process_w2( orignal_w2 ) ;
    weight1 = avg_weigh1;
    weight2 = avg_weigh2;
//    adc_value_update() ;   
}

void Output_All_Update()
{
    System_Led_Action() ;
//        Motor_R_Action() ;
}



void UpdateUI()
{
//    if (Motor_R_Speed < 40 && gCurStatus != TIMING_ST)
//        gTimeLen = 0;
//    //避免到不了最高速度
//    if (Motor_R_Speed > MAX_SPEED-2)
//        Motor_R_Speed = MAX_SPEED;
    
    UpdateWeight();
}

void process_w1( int orignal_weight )
{
    if(orignal_weight == -1)
        ;
    else
    {
        orignal_weight /= 256 ; // 得到采集的24位有效数据
        orignal_weight /= RATE_1 ;
        if(orignal_weight<0)
            orignal_weight = 0; //暂时不考虑负数
        avg_w1(orignal_weight) ;
    }
}

void avg_w1(int w1)
{
    static int w1_array[AVG_NUM] = { 0 };
    static int current_num=0;
    if(current_num <AVG_NUM)
    {
        w1_array[current_num] = w1;
        current_num++ ;
    }
    else
    {
        current_num = 0 ;
        w1_array[current_num] = w1;
        current_num++ ;
    }
    int i=0,sum=0;
    for(;i<AVG_NUM; i++)
    {
        sum+=w1_array[i];
    }
    avg_weigh1 = sum/AVG_NUM ;
}


void process_w2( int orignal_weight )
{
    if(orignal_weight == -1)
        ;
    else
    {
        orignal_weight /= 256 ; // 得到采集的24位有效数据
        orignal_weight /= RATE_2 ;
        if(orignal_weight<0)
            orignal_weight = 0;     //暂时不考虑负数
        avg_w2(orignal_weight) ;
    }
}

void avg_w2(int w2)
{
    static int w2_array[AVG_NUM]= { 0 };
    static int current_num=0;
    if(current_num <AVG_NUM)
    {
        w2_array[current_num] = w2;
        current_num++ ;
    }
    else
    {
        current_num = 0 ;
        w2_array[current_num] = w2;
        current_num++ ;
    }
    int i=0,sum=0;
    for(;i<AVG_NUM; i++)
    {
        sum+=w2_array[i];
    }
    avg_weigh2 = sum/AVG_NUM ;
}