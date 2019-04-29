//#include "log.h"
//#include "../system/system.h"
//
//char *gAlarmStr[7] = {
//    "",
//    "�¶ȹ���",
//    "�¶ȹ���",
//    "������������",
//    "����������С",
//    "��Ƶ�ʹ���",
//    "��Ƶ�ʹ�С"
//};
//
//structUI_AlarmRow AlarmPg[] ={
//    { {32,Y_1st},          {72,Y_1st}   },
//    { {32,Y_1st+ROW_H1},   {72,Y_1st+ROW_H1} },
//    { {32,Y_1st+ROW_H1*2}, {72,Y_1st+ROW_H1*2} },
//    { {32,Y_1st+ROW_H1*3}, {72,Y_1st+ROW_H1*3} },
//    { {32,Y_1st+ROW_H1*4}, {72,Y_1st+ROW_H1*4} },
//    { {32,Y_1st+ROW_H1*5}, {72,Y_1st+ROW_H1*5} },
//    { {32,Y_1st+ROW_H1*6}, {72,Y_1st+ROW_H1*6} },
//    { {32,Y_1st+ROW_H1*7}, {72,Y_1st+ROW_H1*7} },
//    { {32,Y_1st+ROW_H1*8}, {72,Y_1st+ROW_H1*8} },
//    { {32,Y_1st+ROW_H1*9}, {72,Y_1st+ROW_H1*9} },
//    { {32,Y_1st+ROW_H1*10},{72,Y_1st+ROW_H1*10} },
//    { {32,Y_1st+ROW_H1*11},{72,Y_1st+ROW_H1*11} }
//};
//
//structUI_LogRow LogPg[] ={
//    { {32,Y_1st},         {192,Y_1st}   },
//    { {32,Y_1st+ROW_H},   {192,Y_1st+ROW_H} },
//    { {32,Y_1st+ROW_H*2}, {192,Y_1st+ROW_H*2} },
//    { {32,Y_1st+ROW_H*3}, {162,Y_1st+ROW_H*3} },
//    { {32,Y_1st+ROW_H*4}, {162,Y_1st+ROW_H*4} },
//    { {32,Y_1st+ROW_H*5}, {162,Y_1st+ROW_H*5} },
//    { {32,Y_1st+ROW_H*6}, {162,Y_1st+ROW_H*6} },
//    { {32,Y_1st+ROW_H*7}, {162,Y_1st+ROW_H*7} }
//};
//
//////ȫ�ֱ���
//structAlarmTbl  g_AlarmTbl;
//structLogTbl    g_LogTbl;
//structAlarmItem g_AlarmItems[MAX_ALARM_CNT];
//structLogItem   g_LogItems[MAX_LOG_CNT];
//    
////  ���ҷ�ҳ��ť��λ��
//static structPoint sLastPage_pos = {70, 413};
//static structPoint sNextPage_pos = {137, 413};
//
//static int sLogCurRIdx;
//
//static void initAlarmItems();
//static void initAlarmTbl();
//static void initLogTbl();
//static void initLogItems();
//static void readAlarmItem( structAlarmItem *item, int addr );
//static void readLogItem( structLogItem *item, int addr );
//static void Ui_displayAlarm( int i, structAlarmItem *item );
//static void Ui_displayLog( structLogItem *item );
//
//static void writeLogRec( structLogItem *item );
//static void writeAlarmRec( structAlarmItem *item );
//
//void log_init()
//{
//    //һ��Ҫ���ȳ�ʼ��������������
//    initAlarmTbl();
//    initLogTbl();    
//        
////    sAlarmCurRIdx = g_AlarmTbl.alarmCurWIdx;
//    if ( 0 == g_LogTbl.logItemCnt ){
//        sLogCurRIdx = 0;
//    }else{
//        sLogCurRIdx = g_LogTbl.logCurWIdx - 1; 
//        sLogCurRIdx = (sLogCurRIdx + MAX_LOG_CNT)%MAX_LOG_CNT;
//    }
//  
//    initAlarmItems();
//    initLogItems();
//}
//
//static unsigned s_last_time = 0;
//void saveLog()
//{
//    ///�����ظ�����
//    if ( s_last_time == gRsltRec.bgtime )
//        return;
//    int j;
//    structLogItem i;
//        for ( j = 0; j < CODE_LEN; j++ ){
//        i.bagCode[j]      = gRsltRec.bagCode[j];            //Ѫ������
//        i.oprtrId[j]      = gRsltRec.oprtrId[j];            //������ԱID
//    }
//    i.date         = gRsltRec.date;                //��������
//    i.bgtime       = gRsltRec.bgtime;              //��ʼʱ��
//    i.timeLen      = gRsltRec.timeLen;             //����ʱ��
//    i.wavelength_l  = gRsltRec.wavelength_l;       //��������(nm)
//    i.wavelength_h  = gRsltRec.wavelength_h;       //��������(nm)
//    i.oscilFreq     = gRsltRec.oscilFreq;          //��Ƶ��
//    i.energy        = gRsltRec.energy;             //��������(J/ml)
//    i.tempert       = gRsltRec.tempert;            //�¶�
//    i.productType   = gRsltRec.productType;        //��Ʒ����
//    i.productWeight = gRsltRec.productWeight;      //������g��
//    i.HHSweight     = gRsltRec.HHSweight;          //�˻���������g��
//    
//    writeLogRec(&i);
//    
//    s_last_time = gRsltRec.bgtime;
//}
//
//void saveAlarm(int alarmT)
//{
//    structAlarmItem i;
//    
//    i.alarmT = alarmT;
//    i.time   = gRsltRec.bgtime;
//    i.date   = gRsltRec.date;
//    
//    writeAlarmRec(&i);
//}
//
//void clearLogs()
//{
//    g_LogTbl.logCurWIdx = 0;
//    g_LogTbl.logItemCnt = 0;
//    
//    writeSEE( EE_LOG_TBL_BASE, g_LogTbl.logItemCnt );
//    writeSEE( EE_LOG_TBL_BASE + INT_BYTES, g_LogTbl.logCurWIdx );
//}
//
//void clearAlarmRecs()
//{
//    g_AlarmTbl.alarmCurWIdx = 0;
//    g_AlarmTbl.alarmItemCnt = 0;
//    
//    writeSEE( EE_ALARM_TBL_BASE, g_AlarmTbl.alarmItemCnt );
//    writeSEE( EE_ALARM_TBL_BASE + INT_BYTES, g_AlarmTbl.alarmCurWIdx );
//}
//
//static void showCurrentLog()
//{
//    int maxCnt = ( MAX_LOG_CNT > g_LogTbl.logItemCnt ) ? g_LogTbl.logItemCnt : MAX_LOG_CNT;
//
//    int tailIndex = 0;
//    if ( maxCnt >= MAX_LOG_CNT )
//       tailIndex = g_LogTbl.logCurWIdx;
//    
//        //��һ����λ���ڶ���ͷ����β�������в�
////    if ( 0 == g_LogTbl.logItemCnt || 1 == g_LogTbl.logItemCnt ){
////        display_selected_icon(sLastPage_pos.x,sLastPage_pos.y, PIC_LAST_PAGE_DIS);     //��ҳ��
////        display_selected_icon(sNextPage_pos.x,sNextPage_pos.y, PIC_NEXT_PAGE_DIS);     //��ҳ��
////    }else if ( sLogCurRIdx == (g_LogTbl.logCurWIdx-1 + MAX_LOG_CNT)%MAX_LOG_CNT ){
////        display_selected_icon(sLastPage_pos.x,sLastPage_pos.y, PIC_LAST_PAGE_DIS);     //��ҳ����Ч       
////    }else if ( sLogCurRIdx == tailIndex ){
////        display_selected_icon(sNextPage_pos.x,sNextPage_pos.y, PIC_NEXT_PAGE_DIS);     //��ҳ����Ч
////    }else{
////        display_selected_icon(sLastPage_pos.x,sLastPage_pos.y, PIC_LAST_PAGE);     //��ҳ��
////        display_selected_icon(sNextPage_pos.x,sNextPage_pos.y, PIC_NEXT_PAGE);     //��ҳ��
////    }
//    
//    Ui_displayLog( &g_LogItems[sLogCurRIdx] );
//}
//
//void showLogRecs()
//{
//    sLogCurRIdx = g_LogTbl.logCurWIdx - 1;
//    sLogCurRIdx = (sLogCurRIdx + MAX_LOG_CNT)%MAX_LOG_CNT;
//    
//    showCurrentLog();
//}
//
//void showAlarmRecs()
//{
//    int i,j;
//    for ( i = 0; i < g_AlarmTbl.alarmItemCnt; i++ )
//    {
//        j = (g_AlarmTbl.alarmCurWIdx - i  - 1 + MAX_ALARM_CNT) % MAX_ALARM_CNT;
//        Ui_displayAlarm( i, &g_AlarmItems[j] );
//    }
//}
//
//void showNextLogRecs( int dir )
//{
//    int maxCnt = ( MAX_LOG_CNT > g_LogTbl.logItemCnt ) ? g_LogTbl.logItemCnt : MAX_LOG_CNT;  
//    
//    if ( 0 == maxCnt || 1 == maxCnt )
//        return;
//    
//    int tailIndex = 0;
//    if ( maxCnt >= MAX_LOG_CNT )
//       tailIndex = g_LogTbl.logCurWIdx;
//    
//    int inc = (dir > 0) ? 1 : -1;
//    
//    if ( sLogCurRIdx == (g_LogTbl.logCurWIdx-1 + MAX_LOG_CNT)%MAX_LOG_CNT ){
//        //��ǰλ���ڶ���ͷ��
//        if ( dir > 0 )
//            return;        
//    }
//    else if( sLogCurRIdx == tailIndex ){
//        //��ǰλ�ô���β��
//        if ( dir < 0 )
//            return;     
//    }
//    else{
//        //��ǰλ�ô����м䲿��
//    }    
//    
//    sLogCurRIdx += inc;    
//    
//    if ( sLogCurRIdx >= maxCnt ){
//        sLogCurRIdx -= maxCnt;
//    }
//    if ( sLogCurRIdx < 0 ){
//        sLogCurRIdx += maxCnt;
//    }
//
//    showCurrentLog();   
//}
//
//static void writeLogTbl()
//{     
//    writeSEE( EE_LOG_TBL_BASE, g_LogTbl.logItemCnt ); 
//    writeSEE( EE_LOG_TBL_BASE + INT_BYTES , g_LogTbl.logCurWIdx ); 
//}
//
//static void writeAlarmTbl()
//{
//    writeSEE( EE_ALARM_TBL_BASE, g_AlarmTbl.alarmItemCnt ); 
//    writeSEE( EE_ALARM_TBL_BASE + INT_BYTES , g_AlarmTbl.alarmCurWIdx ); 
//}
//
//static void writeLogRec( structLogItem *item )
//{
//    int addr, cur, j, tmp, i = 0;
//    unsigned char *p;
//    
//    cur = g_LogTbl.logCurWIdx;
//    addr = EE_LOG_RECS_BASE + ( cur* sizeof(structLogItem));
//
////    writeSEE( addr + INT_BYTES*(i++), item->mId );                //����ID
//    for ( j = 0; j < CODE_LEN; j += 4 ){
//        p = &item->bagCode[j];
//        tmp = *p;
//        tmp = (tmp<<8)&(*(p + 1));
//        tmp = (tmp<<8)&(*(p + 2));
//        tmp = (tmp<<8)&(*(p + 3));
//        
//        writeSEE( addr + INT_BYTES*(i++), tmp );            //Ѫ������
//    }
//    for ( j = 0; j < CODE_LEN; j += 4 ){
//        p = &item->oprtrId[j];
//        tmp = *p;
//        tmp = (tmp<<8)&(*(p + 1));
//        tmp = (tmp<<8)&(*(p + 2));
//        tmp = (tmp<<8)&(*(p + 3));
//        writeSEE( addr + INT_BYTES*(i++), tmp );            //������ԱID
//    }
//            
//    writeSEE( addr + INT_BYTES*(i++), item->date );               //��������
//    writeSEE( addr + INT_BYTES*(i++), item->bgtime    );          //��ʼʱ��
//    writeSEE( addr + INT_BYTES*(i++), item->timeLen );            //����ʱ��
//    writeSEE( addr + INT_BYTES*(i++), item->wavelength_l  );       //��������(nm)
//    writeSEE( addr + INT_BYTES*(i++), item->wavelength_h );        //��������(nm)
//    writeSEE( addr + INT_BYTES*(i++), item->oscilFreq   );         //��Ƶ��
//    writeSEE( addr + INT_BYTES*(i++), item->energy  );             //��������(J/ml)
//    writeSEE( addr + INT_BYTES*(i++), item->tempert );             //�¶�
//    writeSEE( addr + INT_BYTES*(i++), item->productType );         //��Ʒ����
//    writeSEE( addr + INT_BYTES*(i++), item->productWeight );       //������g��
//    writeSEE( addr + INT_BYTES*(i++), item->HHSweight );           //�˻���������g��
//    
////    g_LogItems[cur].mId          = item->mId;                //����ID
//    for ( j = 0; j < CODE_LEN; j++ ){
//        g_LogItems[cur].bagCode[j]      = item->bagCode[j];            //Ѫ������
//        g_LogItems[cur].oprtrId[j]      = item->oprtrId[j];            //������ԱID
//    }
//    g_LogItems[cur].date         = item->date;                //��������
//    g_LogItems[cur].bgtime       = item->bgtime;              //��ʼʱ��
//    g_LogItems[cur].timeLen      = item->timeLen;             //����ʱ��
//    g_LogItems[cur].wavelength_l  = item->wavelength_l;       //��������(nm)
//    g_LogItems[cur].wavelength_h  = item->wavelength_h;       //��������(nm)
//    g_LogItems[cur].oscilFreq     = item->oscilFreq;          //��Ƶ��
//    g_LogItems[cur].energy        = item->energy;             //��������(J/ml)
//    g_LogItems[cur].tempert       = item->tempert;            //�¶�
//    g_LogItems[cur].productType   = item->productType;        //��Ʒ����
//    g_LogItems[cur].productWeight = item->productWeight;      //������g��
//    g_LogItems[cur].HHSweight     = item->HHSweight;          //�˻���������g��
//    
//    g_LogTbl.logCurWIdx = (cur + 1)%MAX_LOG_CNT;
//    sLogCurRIdx = cur;
//    g_LogTbl.logItemCnt++;
//    if ( MAX_LOG_CNT < g_LogTbl.logItemCnt ){
//        g_LogTbl.logItemCnt = MAX_LOG_CNT;
//    }
//    writeLogTbl();
//}
//
//static void writeAlarmRec( structAlarmItem *item )
//{
//    int  addr, cur, i = 0;
//    
//    cur = g_AlarmTbl.alarmCurWIdx;
//    addr = EE_ALARM_RECS_BASE + ( cur * sizeof(structAlarmItem));
//
//    //д��˳��һ��Ҫ������һһ��Ӧ
//    writeSEE( addr + INT_BYTES*(i++), item->date );
//    writeSEE( addr + INT_BYTES*(i++), item->time );
//    writeSEE( addr + INT_BYTES*(i++), item->alarmT );
//    
//    g_AlarmItems[cur].date = item->date;
//    g_AlarmItems[cur].time = item->time;
//    g_AlarmItems[cur].alarmT = item->alarmT;
//    
//    g_AlarmTbl.alarmCurWIdx = (cur + 1) % MAX_ALARM_CNT;
//    g_AlarmTbl.alarmItemCnt++;
//    if ( MAX_ALARM_CNT < g_AlarmTbl.alarmItemCnt ){
//        g_AlarmTbl.alarmItemCnt = MAX_ALARM_CNT;
//    }
//    writeAlarmTbl();
//}
//
//static void initAlarmTbl()
//{
//    g_AlarmTbl.alarmTblAddr = EE_ALARM_TBL_BASE;
//    
//    g_AlarmTbl.alarmItemCnt = readSEE( EE_ALARM_TBL_BASE );
//    g_AlarmTbl.alarmCurWIdx = readSEE( EE_ALARM_TBL_BASE + INT_BYTES );
//}
//
//static void initLogTbl()
//{
//    g_LogTbl.logTblAddr = EE_LOG_TBL_BASE;
//    
//    g_LogTbl.logItemCnt = readSEE( EE_LOG_TBL_BASE );
//    g_LogTbl.logCurWIdx = readSEE( EE_LOG_TBL_BASE + INT_BYTES );
//}
//
//static void initAlarmItems()
//{
//    int i, len;
//    len = sizeof( structAlarmItem );
//    
//    for ( i = 0; i < g_AlarmTbl.alarmItemCnt; i++ )
//    {
//        readAlarmItem( &g_AlarmItems[i], EE_ALARM_RECS_BASE + i*len );
//    }
//}
//
//static void initLogItems()
//{
//    int i,len;
//    len = sizeof( structLogItem );
//    
//    for ( i = 0; i < g_LogTbl.logItemCnt; i++ )
//    {
//        readLogItem( &g_LogItems[i], EE_LOG_RECS_BASE + i*len );
//    }
//}
//
//static void readAlarmItem( structAlarmItem *item, int addr )
//{
//    int  i = 0;
//    //����˳��һ��Ҫ��д��ʱһһ��Ӧ
//    item->date = readSEE( addr + INT_BYTES*(i++) );
//    item->time = readSEE( addr + INT_BYTES*(i++) );
//    item->alarmT = readSEE( addr + INT_BYTES*(i++) );
//}
//
//static void readLogItem( structLogItem *item, int addr )
//{
//    int j, val, i = 0;
//
//    for ( j = 0; j < CODE_LEN; j += 4 ){
//        val  = readSEE( addr + INT_BYTES*(i++) );           //Ѫ������
//        
//        item->bagCode[j+3] = val & 0xff;
//        item->bagCode[j+2] = val>>8 & 0xff;
//        item->bagCode[j+1] = val>>16 & 0xff;
//        item->bagCode[j]   = val>>24 & 0xff; 
//    }
//    for ( j = 0; j < CODE_LEN; j += 4 ){
//        val  = readSEE( addr + INT_BYTES*(i++) );           //������ԱID
//        
//        item->oprtrId[j+3] = val & 0xff;
//        item->oprtrId[j+2] = val>>8 & 0xff;
//        item->oprtrId[j+1] = val>>16 & 0xff;
//        item->oprtrId[j]   = val>>24 & 0xff; 
//    } 
//    
//    item->date           = readSEE( addr + INT_BYTES*(i++) );   //��������
//    item->bgtime         = readSEE( addr + INT_BYTES*(i++) );   //��ʼʱ��
//    item->timeLen        = readSEE( addr + INT_BYTES*(i++) );   //����ʱ��
//    item->wavelength_l   = readSEE( addr + INT_BYTES*(i++) );   //��������(nm)
//    item->wavelength_h   = readSEE( addr + INT_BYTES*(i++) );   //��������(nm)
//    item->oscilFreq      = readSEE( addr + INT_BYTES*(i++) );   //��Ƶ��
//    item->energy         = readSEE( addr + INT_BYTES*(i++) );   //��������(J/ml)
//    item->tempert        = readSEE( addr + INT_BYTES*(i++) );   //�¶�
//    item->productType    = readSEE( addr + INT_BYTES*(i++) );   //��Ʒ����
//    item->productWeight  = readSEE( addr + INT_BYTES*(i++) );   //������g��
//    item->HHSweight      = readSEE( addr + INT_BYTES*(i++) );   //�˻���������g��
//}
//
////static char FPT = FLIB_16_16;
////static char PT = FDOT_16_16;
//static unsigned F_COLOR = 0xFFFF;
//static unsigned B_COLOR = 0x020A;
//static void getDateTimeStr( unsigned date, unsigned time, char out[] )
//{
//    char i = 0;
////    sprintf( &out[i], "%4d", ((date>>16)&0xff)+2000 ); i += 4;
////    out[i] = '-'; i += 1;
////    
////    sprintf( &out[i], "%02d", (date>>8)&0xff ); i += 2;
////    out[i] = '-'; i += 1;
////    sprintf( &out[i], "%02d", date&0xff ); i += 2;
////    out[i] = ' '; i += 1;
////    
////    sprintf( &out[i], "%02d", (time>>16)&0xff ); i += 2;
////    out[i] = ':'; i += 1;
////    sprintf( &out[i], "%02d", (time>>8)&0xff ); i += 2;
////    out[i] = ':'; i += 1;
////    sprintf( &out[i], "%02d", time&0xff ); i += 2;
//}
//
//static void Ui_displayAlarm( int i, structAlarmItem *item )
//{
//    char str[20], index;
//    getDateTimeStr( item->date, item->time, str );
//    
////    index = item->proc;
////    if ( item->proc >= P_MAX ){
////        index = P_MAX;
////    }
////    display_Color_String( AlarmPg[2*i].pos1.x, AlarmPg[2*i].pos1.y, 
////            str, strlen(str), F_COLOR, B_COLOR,
////            FPT, PT  );
////    display_Color_String( AlarmPg[2*i + 1].pos1.x, AlarmPg[2*i + 1].pos1.y, 
////            gAlarmProcStr[index], strlen(gAlarmProcStr[index]),  F_COLOR, B_COLOR,
////            FPT, PT  );
////    display_Color_String( AlarmPg[2*i + 1].pos2.x, AlarmPg[2*i + 1].pos2.y, 
////            gAlarmStr[item->alarmT], strlen(gAlarmStr[item->alarmT]), F_COLOR, B_COLOR,  
////            FPT, PT  );
//}
//
//static void Ui_display_NoBk_OneRow( unsigned short x,unsigned short y, const char *str, unsigned val )
//{
//    char tmp[30];
////    char len = strlen(str);
////    strncpy( &tmp[0], str, len );
////    
////    sprintf( &tmp[len], "%3d", val); 
////    display_Color_String( x, y, tmp, strlen(tmp), F_COLOR, B_COLOR, FPT, PT  );
//}
//
//#define ROW_LEN   (35)  
//static void Ui_clearLogPage()
//{
//    char str[ROW_LEN], i, row;
//    
//    for ( i = 0; i < ROW_LEN; i++ ){
//        str[i] = ' ';
//    }
//    
//    row = sizeof(LogPg) / sizeof(structUI_LogRow);
//    for( i = 0; i < row; i++ ){
////        display_Color_String( LogPg[i].pos1.x, LogPg[i].pos1.y, str, ROW_LEN, F_COLOR, B_COLOR,  FPT, PT  );
//    }
//}
//static void Ui_displayLog( structLogItem *item )
//{
//    Ui_clearLogPage();
//    
//    char str[20], index;
//    
//    int maxCnt = ( MAX_LOG_CNT > g_LogTbl.logItemCnt ) ? g_LogTbl.logItemCnt : MAX_LOG_CNT; 
//    
////    if ( 0 == maxCnt ){
////        display_selected_icon(sLastPage_pos.x,sLastPage_pos.y, PIC_LAST_PAGE_DIS);     //��ҳ����Ч
////        display_selected_icon(sNextPage_pos.x,sNextPage_pos.y, PIC_NEXT_PAGE_DIS);     //��ҳ����Ч
////        
////        strncpy( str, "0/0", 5 );          
////    }else{
////        index  = (g_LogTbl.logCurWIdx - sLogCurRIdx + maxCnt) % maxCnt;
////        index  = ( index == 0 ) ? maxCnt : index;
////        sprintf( &str[0], "%02d", index ); 
////        str[2] = '/';
////        sprintf( &str[3], "%02d", maxCnt ); 
////    }
////    
////    display_Color_String( LogPg[7].pos2.x, LogPg[7].pos2.y, str, strlen(str), F_COLOR, B_COLOR, FLIB_24_24, PT  );
//    
//    if ( maxCnt <= 0 )
//        return;
//    
////    getDateTimeStr( item->sepDate, item->bgtime, str );
////    display_Color_String( LogPg[0].pos1.x, LogPg[0].pos1.y, str, strlen(str), F_COLOR, B_COLOR, FPT, PT  );
////    sprintf( &str[0], "%3d", item->timeLen); 
////    display_Color_String( LogPg[0].pos2.x, LogPg[0].pos2.y, str, strlen(str), F_COLOR, B_COLOR, FPT, PT  );
////
////    index = item->proc;
////    if ( item->proc >= P_MAX ){
////        index = 0;
////    }    
////    display_Color_String( LogPg[1].pos1.x, LogPg[1].pos1.y, gProcStr[index], strlen(gProcStr[index]), F_COLOR, B_COLOR,  FPT, PT  );
//////    display_String( LogPg[1].pos2.x, LogPg[1].pos2.y, item->timeLen, sizeof(item->timeLen), FPT, PT  );
////    
////    if ( Proc_Param_Mask[index]&MSK_bagWeightBf ){
////        char* tmp = "����ǰ��ĸ����:___";
////        display_Color_String( LogPg[2].pos1.x, LogPg[2].pos1.y, tmp, strlen(tmp), F_COLOR, B_COLOR, FPT, PT  );
////    }
////    else{
////        Ui_display_NoBk_OneRow( LogPg[2].pos1.x, LogPg[2].pos1.y, "����ǰ��ĸ����:", item->bagWeightBf);
////    }
//////    display_Color_String( LogPg[2].pos1.x, LogPg[2].pos1.y, str, strlen(str), F_COLOR, B_COLOR, FPT, PT  );
////    if ( Proc_Param_Mask[index]&MSK_bagWeightAt ){
////        char* tmp = "___";
////        display_Color_String( LogPg[2].pos2.x, LogPg[2].pos2.y, tmp, strlen(tmp), F_COLOR, B_COLOR, FPT, PT  );
////    }
////    else{
////        sprintf( &str[0], "%3d", item->bagWeightAt); 
////        display_Color_String( LogPg[2].pos2.x, LogPg[2].pos2.y, str, strlen(str), F_COLOR, B_COLOR, FPT, PT  );
////    }
////    
////   if ( Proc_Param_Mask[index]&MSK_plsVlm ){
////        char* tmp = "Ѫ����:___";
////        display_Color_String( LogPg[3].pos1.x, LogPg[3].pos1.y, tmp, strlen(tmp), F_COLOR, B_COLOR, FPT, PT  );
////    }
////    else{ 
////        Ui_display_NoBk_OneRow( LogPg[3].pos1.x, LogPg[3].pos1.y, "Ѫ����:", item->plsVlm);
////    }
////    
////    if ( Proc_Param_Mask[index]&MSK_solutionVlm ){
////        char* tmp = "SAGM:___";
////        display_Color_String( LogPg[3].pos2.x, LogPg[3].pos2.y, tmp, strlen(tmp), F_COLOR, B_COLOR, FPT, PT  );
////    }
////    else{
////        Ui_display_NoBk_OneRow( LogPg[3].pos2.x, LogPg[3].pos2.y, "SAGM:", item->solutionVlm);
////    }
////    
////    if ( Proc_Param_Mask[index]&MSK_plsSecCentrifVlm ){
////        char* tmp = "��������:___";
////        display_Color_String( LogPg[4].pos1.x, LogPg[4].pos1.y, tmp, strlen(tmp), F_COLOR, B_COLOR, FPT, PT  );
////    }
////    else{
////        Ui_display_NoBk_OneRow( LogPg[4].pos1.x, LogPg[4].pos1.y, "��������:", item->plsSecCentrifVlm );
////    }
////    
////    if ( Proc_Param_Mask[index]&MSK_sedimentVlm ){
////        char* tmp = "�����:___";
////        display_Color_String( LogPg[4].pos2.x, LogPg[4].pos2.y, tmp, strlen(tmp), F_COLOR, B_COLOR, FPT, PT  );
////    }
////    else{
////        char *tmpName = ((P13 == index) || (P14 == index))?("��Ĥ��:"):("�����:");
////        Ui_display_NoBk_OneRow( LogPg[4].pos2.x, LogPg[4].pos2.y, tmpName, item->sedimentVlm );
////    }
////    
////    if ( Proc_Param_Mask[index]&MSK_RBCVlm ){
////        char* tmp = "ϴ�Ӻ�ϸ��:___";
////        display_Color_String( LogPg[5].pos1.x, LogPg[5].pos1.y, tmp, strlen(tmp), F_COLOR, B_COLOR, FPT, PT  );
////    }
////    else{
////    Ui_display_NoBk_OneRow( LogPg[5].pos1.x, LogPg[5].pos1.y, "ϴ�Ӻ�ϸ��:", item->RBCVlm);
////    }
////    
////    if ( Proc_Param_Mask[index]&MSK_wasteVlm ){
////        char* tmp = "��Һ:___";
////        display_Color_String( LogPg[5].pos2.x, LogPg[5].pos2.y, tmp, strlen(tmp), F_COLOR, B_COLOR, FPT, PT  );
////    }
////    else{
////        Ui_display_NoBk_OneRow( LogPg[5].pos2.x, LogPg[5].pos2.y, "��Һ:", item->wasteVlm);
////    }
////    
////    if ( Proc_Param_Mask[index]&MSK_HCT ){
////        char* tmp = "HCT(%):___";
////        display_Color_String( LogPg[6].pos1.x, LogPg[6].pos1.y, tmp, strlen(tmp), F_COLOR, B_COLOR, FPT, PT  );
////    }
////    else{
////        Ui_display_NoBk_OneRow( LogPg[6].pos1.x, LogPg[6].pos1.y, "HCT(%):", item->HCT);
////    }
//}