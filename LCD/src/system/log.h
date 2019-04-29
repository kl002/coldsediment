///* 
// * File:   log.h
// * Author: slrom
// * 日志记录、报警记录的存储与显示
// * Created on November 30, 2016, 2:20 PM
// */
//
#ifndef LOG_H
#define	LOG_H
//
//#ifdef	__cplusplus
//extern "C" {
//#endif
//
//// 最大记录工作日志条数    
//#define MAX_LOG_CNT     15
//// 最大记录报警日志条数 
//#define MAX_ALARM_CNT   6
//#define MAX_PROC        14
//    
//////在EEPROM中每次存储都以4byte为单位
//#define  INT_BYTES    4
//    
//#ifndef CODE_LEN
//#define CODE_LEN  20
//#endif
//    
//   
//    enum ALARM_TYPE{
//        ALM_NONE = 0
//        ,ALM_CLS_PRS = 1
//        ,ALM_OPN_PRS = 2
//        ,ALM_LINE_PRS = 3
//        ,ALM_PLAT_POS = 4
//    };
//extern char *gAlarmStr[7];
//    
//    typedef struct _Point{
//        int x;
//        int y;        
//    } structPoint; 
//    
//    typedef struct _UI_AlarmRow{
//        structPoint pos1;
//        structPoint pos2;   
//    } structUI_AlarmRow; 
//    
//    typedef struct _UI_LogRow{
//        structPoint pos1;
//        structPoint pos2;   
//    } structUI_LogRow; 
//    
//    typedef struct _AlarmTbl{
//        unsigned alarmTblAddr;
//        unsigned alarmItemCnt;
//        unsigned alarmCurWIdx;
//    } structAlarmTbl; 
//    
//    typedef struct _AlarmItem{
//        unsigned date;
//        unsigned time;
//        unsigned alarmT;
//    } structAlarmItem; 
//    
//    typedef struct _LogTbl{
//        unsigned logTblAddr;
//        unsigned logItemCnt;
//        unsigned logCurWIdx;
//    } structLogTbl;
//    
//    typedef struct _LogItem{
////    unsigned mId;              //机器ID
//        char bagCode[CODE_LEN];       //血袋条码
//        char oprtrId[CODE_LEN];       //操作人员ID
//
//        unsigned  date;            //操作日期
//        unsigned  bgtime;          //开始时间
//        unsigned  timeLen;         //操作时长
//
//        unsigned  wavelength_l;    //波长下限
//        unsigned  wavelength_h;    //波长上限
//        unsigned  oscilFreq;      //振荡频率
//        unsigned  energy;          //光能量
//        signed    tempert;         //温度
//        unsigned  productType;     //产品类型
//        unsigned  productWeight;   //重量
//        unsigned  HHSweight;       //核黄素重量
//    } structLogItem;
//    
//////第一行y坐标
//#define Y_1st        90    
//#define ROW_H1       25
//
//extern structUI_AlarmRow AlarmPg[];
//
//#define ROW_H   40
//extern structUI_LogRow LogPg[];
//    
//    ////全局变量
//extern structAlarmTbl  g_AlarmTbl;
//extern structLogTbl    g_LogTbl;
//extern structAlarmItem g_AlarmItems[MAX_ALARM_CNT];
//extern structLogItem   g_LogItems[MAX_LOG_CNT];
//    
//void log_init();
//void saveLog();
//void saveAlarm(int alarmT);
//void clearLogs();
//void clearAlarmRecs();
//
//void showLogRecs();
//void showAlarmRecs();
//
//void showNextLogRecs( signed dir );
//
//#ifdef	__cplusplus
//}
//#endif
//
#endif	/* LOG_H */
//
