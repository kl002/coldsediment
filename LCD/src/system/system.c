#include "system.h"
#include "../include.h"

#pragma config FSRSSEL = PRIORITY_7     // SRS Select (SRS Priority 7)
#pragma config FMIIEN = ON              // Ethernet RMII/MII Enable (MII Enabled)
#pragma config FETHIO = ON              // Ethernet I/O Pin Select (Default Ethernet I/O)
#pragma config FCANIO = ON              // CAN I/O Pin Select (Default CAN I/O)
#pragma config FUSBIDIO = OFF           // USB USID Selection (Controlled by Port Function)
#pragma config FVBUSONIO = OFF          // USB VBUS ON Selection (Controlled by Port Function)

// DEVCFG2
#pragma config FPLLIDIV = DIV_2         // PLL Input Divider (2x Divider)
#pragma config FPLLMUL = MUL_20         // PLL Multiplier (20x Multiplier)
#pragma config UPLLIDIV = DIV_12        // USB PLL Input Divider (12x Divider)
#pragma config UPLLEN = OFF             // USB PLL Enable (Disabled and Bypassed)
#pragma config FPLLODIV = DIV_1         // System PLL Output Clock Divider (PLL Divide by 1)

// DEVCFG1
#pragma config FNOSC = PRIPLL           // Oscillator Selection Bits (Primary Osc w/PLL (XT+,HS+,EC+PLL))
#pragma config FSOSCEN = OFF            // Secondary Oscillator Enable (Disabled)
#pragma config IESO = OFF               // Internal/External Switch Over (Disabled)
#pragma config POSCMOD = XT             // Primary Oscillator Configuration (XT osc mode)
#pragma config OSCIOFNC = OFF           // CLKO Output Signal Active on the OSCO Pin (Disabled)
#pragma config FPBDIV = DIV_1           // Peripheral Clock Divisor (Pb_Clk is Sys_Clk/1)
#pragma config FCKSM = CSDCMD           // Clock Switching and Monitor Selection (Clock Switch Disable, FSCM Disabled)
#pragma config WDTPS = PS4096           // Watchdog Timer Postscaler (1:4096)
#pragma config FWDTEN = ON             // Watchdog Timer Enable (WDT Enabled)

// DEVCFG0
#pragma config DEBUG = OFF               // Background Debugger Enable (Debugger is enabled)
#pragma config ICESEL = ICS_PGx2        // ICE/ICD Comm Channel Select (ICE EMUC2/EMUD2 pins shared with PGC2/PGD2)
#pragma config PWP = OFF                // Program Flash Write Protect (Disable)
#pragma config BWP = OFF                // Boot Flash Write Protect bit (Protection Disabled)
#pragma config CP = OFF                 // Code Protect (Protection Disabled)

unsigned int T1_Lamp = 0;
unsigned T1_Com = 0;
unsigned int T1_100MS = 0;

unsigned gTimeLen = 0;
unsigned T1_Motor_R_Jitter = 0 ;
unsigned T1_Motor_SS = 0 ;

//电机使能状态
unsigned flag_Motor_Enable = 1;
//当前系统状态
unsigned gCurStatus = 0;
//前一个系统状态
unsigned gPreStatus = 0;

signed timeTicks = 0;
// 重量变化量
signed deltaW = 0;
//电子秤1
unsigned weight1 = 0;
//电子秤2
unsigned weight2 = 0;

int Scan1[30] ;  //存放扫码枪1的数组
int Scan2[30] ; //存放扫码枪2的数组
unsigned flag_gotBarcode1 = 0;
unsigned flag_gotBarcode2 = 0;

void UpdateSetting();

void system_init()
{
    //初始化T1
    PR1 = 0x30D3; //T1为10mS定时器,PBCLK=80M；
    T1CON = 0x8020; //64分频
    mT1SetIntPriority(1); //指定所选中断源的优先级
    INTEnableSystemMultiVectoredInt(); //中断控制模块初始化
    mT1IntEnable(1); //使能T1中断
}

void __ISR(_TIMER_1_VECTOR, IPL1SOFT) T1Interrupt(void) 
{
    T1_Lamp ++ ;
    T1_Com++;
    T1_Motor_R_Jitter ++ ;
    T1_Motor_SS ++ ;
    T1_100MS++;
    IFS0bits.T1IF = 0; //中断标志清零
}

void System_Led_Action()
{
    if(T1_Lamp >50)
    {
        LAMP = ~LAMP ;  
        T1_Lamp = 0 ;
    }
}

void delay10us(unsigned t) //10us延时函数
{
    unsigned x = t * 13;
    while (x--);
}

char timeStr[3];
static void timeLen2BCD(UINT16 len) {
    UINT8 h   = len / 3600;
    UINT8 min = (len % 3600) / 60;
    UINT8 sec = len % 60;
//    UINT16 val = (min / 10) * 16 + (min % 10);
    h = (h / 10) * 16 + (h % 10);
    min = (min / 10) * 16 + (min % 10);
    sec = (sec / 10) * 16 + (sec % 10);
    
//    val = (h << 16) | (val << 8) | (sec / 10) * 16 + (sec % 10);

    timeStr[0] = h;
    timeStr[1] = min;
    timeStr[2] = sec;
}

void switchSysStatus(unsigned pre, unsigned cur)
{
    switch (gCurStatus)
    {                
        default:
        case ST_STANDBY:
            Ui_Show_Bg(BG_STANDBY);
            break;
        case ST_WEIGH:
            Ui_Show_Bg(BG_WEIGH);
            break;
        case ST_WEIGH_END:
            Ui_Show_Bg(BG_WEIGH_END);
            break;
    }
}

void doWeighing()
{
    sysData.weigh_lcd   = weight1 - sysData.tare1;
    if(sysData.weigh_lcd < 0)
        sysData.weigh_lcd = 0;
    sysData.weigh_plasm = weight2 - sysData.tare2;
    if(sysData.weigh_plasm < 0)
        sysData.weigh_plasm = 0;
    
    //冷沉淀重量在合法范围，血浆量稳定，则完成
    if (sysSetting.lcd_l <= sysData.weigh_lcd &&
        sysSetting.lcd_h >= sysData.weigh_lcd &&
            deltaW < 5 &&
            flag_gotBarcode1 == 1) //&&               //已扫码冷沉淀袋
//            flag_gotBarcode2 == 1)                 //已扫码血浆袋
    {
        gCurStatus = ST_WEIGH_END;
    }
}

void doCmd()
{
    switch (gKeyValue){
        case KEY_START:
        case KEY_NEXT:
            sysData.tare1 = weight1;
            sysData.tare2 = weight2;   //记录皮重
            flag_gotBarcode1 = 0;      //清零扫码标志位
            flag_gotBarcode2 = 0;
            
            gCurStatus = ST_WEIGH;
            break;
            
        case KEY_BACK:
            gCurStatus = ST_STANDBY;
            break;
            
        case KEY_QUIT:
            Ui_Show_Bg(BG_STANDBY);
            gCurStatus = ST_STANDBY;
            break;
            
        case KEY_SETTING:
            Ui_Show_Bg(BG_SETTING);
            UpdateSetting();
            break;
            
        case KEY_LCD_LOW_MINUS:
            sysSetting.lcd_l -= 5;
            if (sysSetting.lcd_l < 10)
                sysSetting.lcd_l = 10;
            
            writeSEE(EE_LCD_Low, sysSetting.lcd_l); 
            UpdateSetting();
            break;
            
        case KEY_LCD_LOW_PLUS:
            sysSetting.lcd_l += 5;
            if (sysSetting.lcd_l > sysSetting.lcd_h)
                sysSetting.lcd_l = sysSetting.lcd_h;
            
            writeSEE(EE_LCD_Low, sysSetting.lcd_l);  
            UpdateSetting();
            break;
            
        case KEY_LCD_HIGH_MINUS:
            sysSetting.lcd_h -= 5;
            if (sysSetting.lcd_h < sysSetting.lcd_l + 5)
                sysSetting.lcd_h = sysSetting.lcd_l + 5;
            
            writeSEE(EE_LCD_High, sysSetting.lcd_h); 
            UpdateSetting();
            break;
            
        case KEY_LCD_HIGH_PLUS:
            sysSetting.lcd_h += 5;
            if (sysSetting.lcd_h > 100)
                sysSetting.lcd_h = 100;
            
            writeSEE(EE_LCD_High, sysSetting.lcd_h); 
            UpdateSetting();
            break;
            
        default:
            break;
    }
}

void UpdateWeight()
{
    unsigned tmp = sysData.weigh_lcd/100;
    Ui_Show_Icon(ID_LWeigh1, tmp);
    tmp = (sysData.weigh_lcd % 100) / 10;
    Ui_Show_Icon(ID_LWeigh2, tmp);
    tmp = sysData.weigh_lcd % 10;    
    Ui_Show_Icon(ID_LWeigh3, tmp);
    
    tmp = sysData.weigh_plasm/1000;
    Ui_Show_Icon(ID_PWeigh1, tmp);
    tmp = (sysData.weigh_plasm % 1000) / 100;
    Ui_Show_Icon(ID_PWeigh2, tmp);
    tmp = (sysData.weigh_plasm % 100) / 10;
    Ui_Show_Icon(ID_PWeigh3, tmp);
    tmp = sysData.weigh_plasm % 10;    
    Ui_Show_Icon(ID_PWeigh4, tmp);
}

void UpdateSetting()
{
    Ui_Show_Num_Var(ID_LCDSet_Low, sysSetting.lcd_l);
    Ui_Show_Num_Var(ID_LCDSet_High, sysSetting.lcd_h);
}

void refreshDeltaW()
{
    static int cnt = 0;
    static judge_cnt = 0;
    static unsigned w = 0;
    
    if ( cnt++ > 20) // 2s时间更新一次变化值
    {
        cnt = 0;
        if(sysSetting.lcd_l <= sysData.weigh_lcd &&
        sysSetting.lcd_h >= sysData.weigh_lcd )
        {
            deltaW = pre_weigh1- weight1;
            if(deltaW < 0)
                deltaW= 0 - deltaW;
            if(deltaW <5 )
            {
                judge_cnt++;
                if(judge_cnt <3)
                    deltaW=0xffff;
                else
                {
                    judge_cnt = 0;
                }
            }
            else
            {
                judge_cnt = 0;
            }
            pre_weigh1 = weight1;
        }
        else
           deltaW = 0xffff; 
    }
}