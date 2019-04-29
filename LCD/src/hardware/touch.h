
#define TOUCH_BUF_LEN  (64)
// A5 5A LEN Cmd Addr��2�� DataLen   һ��7byte
#define TOUCH_CMD_PREFIX_LEN     (7)
//ʱ�ӼĴ�����ַ
#define TOUCH_DATETIME_R_ADDR    (0x20)

#define TOUCH_LEN_INDEX          (2)
#define TOUCH_CMD_INDEX          (3)

extern unsigned short flag_touch;
extern signed short value_keyboard;
extern unsigned short gKeyValue;

extern unsigned char receive_touch[TOUCH_BUF_LEN];
extern unsigned short gTouchData[TOUCH_BUF_LEN];
extern unsigned char time[6];

extern void touch_events();

enum TOUCH_STATE{
    TS_NULL   = 0
   ,TS_NORM   = 1
//   ,TS_VK     = 2
//   ,TS_CLK    = 3
};

enum TOUCH_REV_STATE{
    _sWaitHead,
    _sWaitLen,
    _sWaitCmd,
    _sWaitAddr,
    _sWaitDataLen,
    _sWaitData1,     //避免跟其它代码定义冲突
};

enum TOUCH_CMD_VAL{
    TR_Head = 0xA55A,
    TR_Cmd = 0x83,
    TR_Rgst_Cmd = 0x81,
};