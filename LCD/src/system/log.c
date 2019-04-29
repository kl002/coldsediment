//#include "log.h"
//#include "../system/system.h"
//
//char *gAlarmStr[7] = {
//    "",
//    "温度过高",
//    "温度过低",
//    "辐照能量过大",
//    "辐照能量过小",
//    "振荡频率过大",
//    "振荡频率过小"
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
//////全局变量
//structAlarmTbl  g_AlarmTbl;
//structLogTbl    g_LogTbl;
//structAlarmItem g_AlarmItems[MAX_ALARM_CNT];
//structLogItem   g_LogItems[MAX_LOG_CNT];
//    
////  左右翻页按钮的位置
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
//    //一定要最先初始化这两个描述表
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
//    ///避免重复保存
//    if ( s_last_time == gRsltRec.bgtime )
//        return;
//    int j;
//    structLogItem i;
//        for ( j = 0; j < CODE_LEN; j++ ){
//        i.bagCode[j]      = gRsltRec.bagCode[j];            //血袋条码
//        i.oprtrId[j]      = gRsltRec.oprtrId[j];            //操作人员ID
//    }
//    i.date         = gRsltRec.date;                //操作日期
//    i.bgtime       = gRsltRec.bgtime;              //开始时间
//    i.timeLen      = gRsltRec.timeLen;             //操作时长
//    i.wavelength_l  = gRsltRec.wavelength_l;       //波长下限(nm)
//    i.wavelength_h  = gRsltRec.wavelength_h;       //波长上限(nm)
//    i.oscilFreq     = gRsltRec.oscilFreq;          //振荡频率
//    i.energy        = gRsltRec.energy;             //辐照能量(J/ml)
//    i.tempert       = gRsltRec.tempert;            //温度
//    i.productType   = gRsltRec.productType;        //产品类型
//    i.productWeight = gRsltRec.productWeight;      //重量（g）
//    i.HHSweight     = gRsltRec.HHSweight;          //核黄素重量（g）
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
//        //下一步的位置在队列头部、尾部、及中部
////    if ( 0 == g_LogTbl.logItemCnt || 1 == g_LogTbl.logItemCnt ){
////        display_selected_icon(sLastPage_pos.x,sLastPage_pos.y, PIC_LAST_PAGE_DIS);     //翻页键
////        display_selected_icon(sNextPage_pos.x,sNextPage_pos.y, PIC_NEXT_PAGE_DIS);     //翻页键
////    }else if ( sLogCurRIdx == (g_LogTbl.logCurWIdx-1 + MAX_LOG_CNT)%MAX_LOG_CNT ){
////        display_selected_icon(sLastPage_pos.x,sLastPage_pos.y, PIC_LAST_PAGE_DIS);     //翻页键无效       
////    }else if ( sLogCurRIdx == tailIndex ){
////        display_selected_icon(sNextPage_pos.x,sNextPage_pos.y, PIC_NEXT_PAGE_DIS);     //翻页键无效
////    }else{
////        display_selected_icon(sLastPage_pos.x,sLastPage_pos.y, PIC_LAST_PAGE);     //翻页键
////        display_selected_icon(sNextPage_pos.x,sNextPage_pos.y, PIC_NEXT_PAGE);     //翻页键
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
//        //当前位置在队列头部
//        if ( dir > 0 )
//            return;        
//    }
//    else if( sLogCurRIdx == tailIndex ){
//        //当前位置处于尾部
//        if ( dir < 0 )
//            return;     
//    }
//    else{
//        //当前位置处于中间部分
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
////    writeSEE( addr + INT_BYTES*(i++), item->mId );                //机器ID
//    for ( j = 0; j < CODE_LEN; j += 4 ){
//        p = &item->bagCode[j];
//        tmp = *p;
//        tmp = (tmp<<8)&(*(p + 1));
//        tmp = (tmp<<8)&(*(p + 2));
//        tmp = (tmp<<8)&(*(p + 3));
//        
//        writeSEE( addr + INT_BYTES*(i++), tmp );            //血袋条码
//    }
//    for ( j = 0; j < CODE_LEN; j += 4 ){
//        p = &item->oprtrId[j];
//        tmp = *p;
//        tmp = (tmp<<8)&(*(p + 1));
//        tmp = (tmp<<8)&(*(p + 2));
//        tmp = (tmp<<8)&(*(p + 3));
//        writeSEE( addr + INT_BYTES*(i++), tmp );            //操作人员ID
//    }
//            
//    writeSEE( addr + INT_BYTES*(i++), item->date );               //操作日期
//    writeSEE( addr + INT_BYTES*(i++), item->bgtime    );          //开始时间
//    writeSEE( addr + INT_BYTES*(i++), item->timeLen );            //操作时长
//    writeSEE( addr + INT_BYTES*(i++), item->wavelength_l  );       //波长下限(nm)
//    writeSEE( addr + INT_BYTES*(i++), item->wavelength_h );        //波长上限(nm)
//    writeSEE( addr + INT_BYTES*(i++), item->oscilFreq   );         //振荡频率
//    writeSEE( addr + INT_BYTES*(i++), item->energy  );             //辐照能量(J/ml)
//    writeSEE( addr + INT_BYTES*(i++), item->tempert );             //温度
//    writeSEE( addr + INT_BYTES*(i++), item->productType );         //产品类型
//    writeSEE( addr + INT_BYTES*(i++), item->productWeight );       //重量（g）
//    writeSEE( addr + INT_BYTES*(i++), item->HHSweight );           //核黄素重量（g）
//    
////    g_LogItems[cur].mId          = item->mId;                //机器ID
//    for ( j = 0; j < CODE_LEN; j++ ){
//        g_LogItems[cur].bagCode[j]      = item->bagCode[j];            //血袋条码
//        g_LogItems[cur].oprtrId[j]      = item->oprtrId[j];            //操作人员ID
//    }
//    g_LogItems[cur].date         = item->date;                //操作日期
//    g_LogItems[cur].bgtime       = item->bgtime;              //开始时间
//    g_LogItems[cur].timeLen      = item->timeLen;             //操作时长
//    g_LogItems[cur].wavelength_l  = item->wavelength_l;       //波长下限(nm)
//    g_LogItems[cur].wavelength_h  = item->wavelength_h;       //波长上限(nm)
//    g_LogItems[cur].oscilFreq     = item->oscilFreq;          //振荡频率
//    g_LogItems[cur].energy        = item->energy;             //辐照能量(J/ml)
//    g_LogItems[cur].tempert       = item->tempert;            //温度
//    g_LogItems[cur].productType   = item->productType;        //产品类型
//    g_LogItems[cur].productWeight = item->productWeight;      //重量（g）
//    g_LogItems[cur].HHSweight     = item->HHSweight;          //核黄素重量（g）
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
//    //写的顺序一定要跟读出一一对应
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
//    //读的顺序一定要跟写入时一一对应
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
//        val  = readSEE( addr + INT_BYTES*(i++) );           //血袋条码
//        
//        item->bagCode[j+3] = val & 0xff;
//        item->bagCode[j+2] = val>>8 & 0xff;
//        item->bagCode[j+1] = val>>16 & 0xff;
//        item->bagCode[j]   = val>>24 & 0xff; 
//    }
//    for ( j = 0; j < CODE_LEN; j += 4 ){
//        val  = readSEE( addr + INT_BYTES*(i++) );           //操作人员ID
//        
//        item->oprtrId[j+3] = val & 0xff;
//        item->oprtrId[j+2] = val>>8 & 0xff;
//        item->oprtrId[j+1] = val>>16 & 0xff;
//        item->oprtrId[j]   = val>>24 & 0xff; 
//    } 
//    
//    item->date           = readSEE( addr + INT_BYTES*(i++) );   //操作日期
//    item->bgtime         = readSEE( addr + INT_BYTES*(i++) );   //开始时间
//    item->timeLen        = readSEE( addr + INT_BYTES*(i++) );   //操作时长
//    item->wavelength_l   = readSEE( addr + INT_BYTES*(i++) );   //波长下限(nm)
//    item->wavelength_h   = readSEE( addr + INT_BYTES*(i++) );   //波长上限(nm)
//    item->oscilFreq      = readSEE( addr + INT_BYTES*(i++) );   //振荡频率
//    item->energy         = readSEE( addr + INT_BYTES*(i++) );   //辐照能量(J/ml)
//    item->tempert        = readSEE( addr + INT_BYTES*(i++) );   //温度
//    item->productType    = readSEE( addr + INT_BYTES*(i++) );   //产品类型
//    item->productWeight  = readSEE( addr + INT_BYTES*(i++) );   //重量（g）
//    item->HHSweight      = readSEE( addr + INT_BYTES*(i++) );   //核黄素重量（g）
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
////        display_selected_icon(sLastPage_pos.x,sLastPage_pos.y, PIC_LAST_PAGE_DIS);     //翻页键无效
////        display_selected_icon(sNextPage_pos.x,sNextPage_pos.y, PIC_NEXT_PAGE_DIS);     //翻页键无效
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
////        char* tmp = "分离前后母袋量:___";
////        display_Color_String( LogPg[2].pos1.x, LogPg[2].pos1.y, tmp, strlen(tmp), F_COLOR, B_COLOR, FPT, PT  );
////    }
////    else{
////        Ui_display_NoBk_OneRow( LogPg[2].pos1.x, LogPg[2].pos1.y, "分离前后母袋量:", item->bagWeightBf);
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
////        char* tmp = "血浆量:___";
////        display_Color_String( LogPg[3].pos1.x, LogPg[3].pos1.y, tmp, strlen(tmp), F_COLOR, B_COLOR, FPT, PT  );
////    }
////    else{ 
////        Ui_display_NoBk_OneRow( LogPg[3].pos1.x, LogPg[3].pos1.y, "血浆量:", item->plsVlm);
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
////        char* tmp = "二次离心:___";
////        display_Color_String( LogPg[4].pos1.x, LogPg[4].pos1.y, tmp, strlen(tmp), F_COLOR, B_COLOR, FPT, PT  );
////    }
////    else{
////        Ui_display_NoBk_OneRow( LogPg[4].pos1.x, LogPg[4].pos1.y, "二次离心:", item->plsSecCentrifVlm );
////    }
////    
////    if ( Proc_Param_Mask[index]&MSK_sedimentVlm ){
////        char* tmp = "冷沉淀:___";
////        display_Color_String( LogPg[4].pos2.x, LogPg[4].pos2.y, tmp, strlen(tmp), F_COLOR, B_COLOR, FPT, PT  );
////    }
////    else{
////        char *tmpName = ((P13 == index) || (P14 == index))?("白膜量:"):("冷沉淀:");
////        Ui_display_NoBk_OneRow( LogPg[4].pos2.x, LogPg[4].pos2.y, tmpName, item->sedimentVlm );
////    }
////    
////    if ( Proc_Param_Mask[index]&MSK_RBCVlm ){
////        char* tmp = "洗涤红细胞:___";
////        display_Color_String( LogPg[5].pos1.x, LogPg[5].pos1.y, tmp, strlen(tmp), F_COLOR, B_COLOR, FPT, PT  );
////    }
////    else{
////    Ui_display_NoBk_OneRow( LogPg[5].pos1.x, LogPg[5].pos1.y, "洗涤红细胞:", item->RBCVlm);
////    }
////    
////    if ( Proc_Param_Mask[index]&MSK_wasteVlm ){
////        char* tmp = "废液:___";
////        display_Color_String( LogPg[5].pos2.x, LogPg[5].pos2.y, tmp, strlen(tmp), F_COLOR, B_COLOR, FPT, PT  );
////    }
////    else{
////        Ui_display_NoBk_OneRow( LogPg[5].pos2.x, LogPg[5].pos2.y, "废液:", item->wasteVlm);
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