///* 
// * File:   log.h
// * Author: slrom
// * ��־��¼��������¼�Ĵ洢����ʾ
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
//// ����¼������־����    
//#define MAX_LOG_CNT     15
//// ����¼������־���� 
//#define MAX_ALARM_CNT   6
//#define MAX_PROC        14
//    
//////��EEPROM��ÿ�δ洢����4byteΪ��λ
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
////    unsigned mId;              //����ID
//        char bagCode[CODE_LEN];       //Ѫ������
//        char oprtrId[CODE_LEN];       //������ԱID
//
//        unsigned  date;            //��������
//        unsigned  bgtime;          //��ʼʱ��
//        unsigned  timeLen;         //����ʱ��
//
//        unsigned  wavelength_l;    //��������
//        unsigned  wavelength_h;    //��������
//        unsigned  oscilFreq;      //��Ƶ��
//        unsigned  energy;          //������
//        signed    tempert;         //�¶�
//        unsigned  productType;     //��Ʒ����
//        unsigned  productWeight;   //����
//        unsigned  HHSweight;       //�˻�������
//    } structLogItem;
//    
//////��һ��y����
//#define Y_1st        90    
//#define ROW_H1       25
//
//extern structUI_AlarmRow AlarmPg[];
//
//#define ROW_H   40
//extern structUI_LogRow LogPg[];
//    
//    ////ȫ�ֱ���
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
