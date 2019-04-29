
#ifndef       UI_H
#define       UI_H

#ifdef	__cplusplus
extern "C" {
#endif

enum BG_PIC 		//背景图片ID,必须从0开始，依次往后加
{
    BG_LOGO = 0
   ,BG_RUNNING
   ,BG_PAUSE
   ,BG_ALARM
   ,BG_SETTING
};

enum ICON_INDEX 	//图标ID
{
    ICON_START  = 0
    ,ICON_PAUSE = 1
    ,ICON_IN    = 2
    ,ICON_UP    = 3
    ,ICON_OPEN  = 4
    ,ICON_DOWN  = 5
    ,ICON_OUT   = 6
    ,ICON_DROP  = 7
    ,ICON_BACK_BG = 8
    ,ICON_READY = 9
};

enum VAR_ID 		//UI变量ID,必须从0开始，依次往后加
{
    ID_RUNNING_INFO = 0
    ,ID_START = 1
    ,ID_CNT = 2
    ,ID_ALARM_CODE = 3
    ,ID_VERSION = 4
    ,ID_1st_DOWN_BOTTOM = 5
    ,ID_SEC_DOWN_BOTTOM = 6
    ,ID_SELFT_UP = 7
    ,ID_SLOW_UP_STEP = 8
    ,ID_RST_UP_STEP = 9
};

enum KEY_VALUE
{
    KEY_START = 1
    ,KEY_QUIT = 2
    ,KEY_CONTINUE = 3
    ,KEY_SETTING  = 4
    ,KEY_CL_CNT   = 5
    ,KEY_FILTER   = 6
    ,KEY_QUIT_SET = 7
       
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