
#ifndef       UI_H
#define       UI_H

#ifdef	__cplusplus
extern "C" {
#endif

enum BG_PIC 		//�������
{
    BG_LOGO = 0
   ,BG_STANDBY      
   ,BG_WEIGH
   ,BG_WEIGH_END
   ,BG_SETTING
//   ,BG_ALARM
//   ,BG_SETTING
};

enum ICON_INDEX 	//
{
    ICON_2F_TIMING     = 0
    ,ICON_F_TIMING     = 1
    ,ICON_F_TIMING_END = 2
};

enum VAR_ID 		//���������
{
    ID_Ver = 0        
    ,ID_LWeigh1
    ,ID_LWeigh2
    ,ID_LWeigh3
    ,ID_Lgiht
    ,ID_PWeigh1
    ,ID_PWeigh2
    ,ID_PWeigh3
    ,ID_PWeigh4
    ,ID_LCDSet_Low
    ,ID_LCDSet_High
};

enum KEY_VALUE
{
    KEY_START = 1
    ,KEY_QUIT = 2
    ,KEY_BACK = 3
    ,KEY_NEXT = 4
    ,KEY_SETTING = 5
    ,KEY_LCD_LOW_MINUS  = 6
    ,KEY_LCD_LOW_PLUS   = 7
    ,KEY_LCD_HIGH_MINUS = 8
    ,KEY_LCD_HIGH_PLUS  = 9
       
    ,KEY_NONE = 0xFFFF 
};

typedef struct{
    unsigned short bg_pic;
    unsigned short pic;
}stBGPic;

typedef struct{
    unsigned short id;
    unsigned short addr;
}stVarAddr;

typedef struct{
    unsigned short keyvalue;
    unsigned short x1;
    unsigned short x2;
    unsigned short y1;
    unsigned short y2;
}Button;    
  

#ifdef	__cplusplus
}
#endif

#endif	/* UI_H */