//
//#include "system.h"
//
//unsigned flag_alarm;               //报警标志
//unsigned flag_log_alarm; 
//unsigned flag_alarm_display;    //报警显示标志，标志改变显示报警画面
//unsigned flag_alarm_light;      //报警灯标志。 =1激活
//
//static void judgeTempAlarm()
//{
//    float temprt_h, temprt_l;
//    if ( TT_NORM == gParamSet.tempertType ){
//        temprt_h = AL_temprt_high_h;
//        temprt_l = AL_temprt_low_h;
//    }
//    else{
//        temprt_h = AL_temprt_high_l;
//        temprt_l = AL_temprt_low_l;
//    }
//
//    if ( gRTParam.tempert < temprt_l ){
//        gRTParam.alarmT = ALM_temprt_low;
//    }
//    else if ( gRTParam.oscilFreq > temprt_h ){
//        gRTParam.alarmT = ALM_temprt_high;
//    }
//}
//
//static void judgeUVEnergyAlarm()
//{
//    float energy_h, energy_l;
//    
//    switch( gParamSet.productType ){
//        default:
//        case PT_PLSM:
//            energy_h = AL_energy_high_plm;
//            energy_l = AL_energy_low_plm;
//            break;
//        case PT_PLT:
//            energy_h = AL_energy_high_plt;
//            energy_l = AL_energy_low_plt;
//            break;
//        case PT_RBC:
//            energy_h = AL_energy_high_rbc;
//            energy_l = AL_energy_low_rbc;
//            break; 
//    }
//    
//    if ( gRTParam.lightPower < energy_l ){
//        gRTParam.alarmT = ALM_energy_low;
//    }
//    else if ( gRTParam.lightPower > energy_h ){
//        gRTParam.alarmT = ALM_energy_high;
//    }
//}
//
//void alarm_events()
//{
//    if ( State_Procing == gCur_system_state ){
//        // 只在正在灭活时判断
//        // 振荡频率
//        if ( gRTParam.oscilFreq < AL_oscilfreq_low ){
//            gRTParam.alarmT = ALM_oscilfreq_low;
//        }
//        else if ( gRTParam.oscilFreq > AL_oscilfreq_high ){
//            gRTParam.alarmT = ALM_oscilfreq_high;
//        }
//        
//        //温度
//        judgeTempAlarm();
//
//        //光能量
//        judgeUVEnergyAlarm();
//    }
//}
//
//void remind_events()
//{
//    
//}
