#include "system.h"
#include "../include.h"

enum PIC_INDEX 		//����
{
    PIC_LOGO       = 0
   ,PIC_STANDBY    = 1
   ,PIC_WEIGH      = 2
   ,PIC_WEIGH_END  = 3
   ,PIC_SETTING    = 4         
};

static stBGPic sBGPics[] ={
    {BG_LOGO,      PIC_LOGO},
    {BG_STANDBY,   PIC_STANDBY},
    {BG_WEIGH,     PIC_WEIGH},
    {BG_WEIGH_END, PIC_WEIGH_END},    
    {BG_SETTING,   PIC_SETTING},
};

enum VAR_ADDR 		//������LCD��
{
    LAdd_Ver  = 0x0020     //�   
    ,LAdd_LWeigh1 = 0x0030        //�
    ,LAdd_LWeigh2 = 0x0031        //�
    ,LAdd_LWeigh3 = 0x0032        //�
    ,LAdd_Light   = 0x0033        //        �   
    ,LAdd_PWeigh1 = 0x0034        //�
    ,LAdd_PWeigh2 = 0x0035        //�
    ,LAdd_PWeigh3 = 0x0036        //�   
    ,LAdd_PWeigh4 = 0x0037        //�
    ,LAdd_Rv_Timer = 0x0040  
    ,LAdd_LCDlow   = 0x0041       //�冷沉淀重量低限
    ,LAdd_LCDhgigh = 0x0042       //�冷沉淀重量高限
    ,LAdd_Key = 0x00F0  
};
 
static stVarAddr sVarAddrs[] = {
    {ID_Ver, LAdd_Ver},    
    {ID_LWeigh1, LAdd_LWeigh1},
    {ID_LWeigh2, LAdd_LWeigh2},
    {ID_LWeigh3, LAdd_LWeigh3},
    {ID_Lgiht,   LAdd_Light},
    {ID_PWeigh1, LAdd_PWeigh1},
    {ID_PWeigh2, LAdd_PWeigh2},
    {ID_PWeigh3, LAdd_PWeigh3},
    {ID_PWeigh4, LAdd_PWeigh4},
    {ID_LCDSet_Low,  LAdd_LCDlow},
    {ID_LCDSet_High, LAdd_LCDhgigh},    
};

void Ui_Show_Bg( unsigned short id )
{
    unsigned short pic = sBGPics[id].pic;
    LCD_show_BG(pic);
}

void Ui_Show_Num_Var( unsigned short id, unsigned short value )
{
    unsigned short addr = sVarAddrs[id].addr;
    LCD_Update_Num_Var(addr, value);
}

void Ui_Show_NumArray_Var( unsigned short id, unsigned char* value, unsigned char len )
{
    unsigned short addr = sVarAddrs[id].addr;
    LCD_Update_LNum_Var(addr, value, len);
}

void Ui_Show_Str_Var( unsigned short id, char* s )
{
    unsigned short addr = sVarAddrs[id].addr;
    LCD_Update_Str_Var(addr, s);
}

void Ui_Show_Icon( unsigned short id, unsigned index )
{
    unsigned short addr = sVarAddrs[id].addr;
    LCD_show_Icon(addr, index);    
}

void Ui_Get_Num_Val( unsigned short id, unsigned char len )
{
    unsigned short addr = sVarAddrs[id].addr;
    LCD_Read_Var(addr, len);
}    
    
void onTouchCmd( unsigned short addr, unsigned char len )
{
    switch ( addr )
    {
        case LAdd_Key:
            gKeyValue        = gTouchData[0];
            break;
//        case LAdd_1st_DBStep:
//            gDown_Bottom_Cnt = gTouchData[0];
//            writeSEE(EE_Motor_1stDown_Step, gDown_Bottom_Cnt);
//            break; 
//        case LAdd_Sec_DBStep:
//            gTest_Down_Cnt   = gTouchData[0];
//            writeSEE(EE_Motor_SecDown_Step, gTest_Down_Cnt);
//            break; 
//        case LAdd_SelfT_UpStep:
//            gTest_Move_Cnt   = gTouchData[0];
//            writeSEE(EE_Motor_SelfTUp_Step, gTest_Move_Cnt);
//            break; 
//        case LAdd_Slow_UpStep:
//            gSlow_StepUp_Cnt = gTouchData[0];
//            writeSEE(EE_Motor_SlowTUp_Step, gSlow_StepUp_Cnt);
//            break; 
//        case LAdd_RST_UpStep:
//            gRST_Up_Cnt      = gTouchData[0];
//            writeSEE(EE_Motor_RSTUp_Step,   gRST_Up_Cnt);
//            break;
            
        default:
            break;
    }
}    