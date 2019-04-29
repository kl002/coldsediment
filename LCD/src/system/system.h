#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include "../hardware/hardware.h"
#include "../hardware/NVRAM.h"

extern unsigned T1_Com;
extern unsigned gTimeLen;
extern unsigned T1_Motor_SS;
extern unsigned int T1_100MS;

extern void UpdateTimer();
extern void UpdateSpeed();
extern unsigned T1_Motor_R_Jitter;

//电机使能状态
extern unsigned flag_Motor_Enable;

extern unsigned gCurStatus;
extern unsigned gPreStatus;
extern signed timeTicks;

//电子秤1
extern unsigned weight1;
//电子秤2
extern unsigned weight2;

extern int Scan1[30];  //存放扫码枪1的数组
extern int Scan2[30]; //存放扫码枪2的数组
extern unsigned flag_gotBarcode1;
extern unsigned flag_gotBarcode2;
extern int pre_weigh1;

//普通模式
enum STATUS_M{
    ST_STANDBY = 0    //待机
    ,ST_WEIGH         //正在称重，冷沉淀重量在合法范围，血浆量稳定，则完成
    ,ST_WEIGH_END     //称重结束，可返回待机，或下一例
};

typedef struct 
{
    signed weigh_lcd;      //冷沉淀重量
    signed weigh_plasm;   //浆袋重量
    unsigned tare1;          //皮重
    unsigned tare2;    
} stSysData;

stSysData sysData;

typedef struct 
{
    unsigned lcd_l;     //冷沉淀合格重量下限
    unsigned lcd_h;     //冷沉淀合格重量上限
} stSysSetting;

stSysSetting sysSetting;
#endif