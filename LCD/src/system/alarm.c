//
//#include "system.h"
//
//unsigned flag_alarm;               //������־
//unsigned flag_log_alarm; 
//unsigned flag_alarm_display;    //������ʾ��־����־�ı���ʾ��������
//unsigned flag_alarm_light;      //�����Ʊ�־�� =1����
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
//        // ֻ���������ʱ�ж�
//        // ��Ƶ��
//        if ( gRTParam.oscilFreq < AL_oscilfreq_low ){
//            gRTParam.alarmT = ALM_oscilfreq_low;
//        }
//        else if ( gRTParam.oscilFreq > AL_oscilfreq_high ){
//            gRTParam.alarmT = ALM_oscilfreq_high;
//        }
//        
//        //�¶�
//        judgeTempAlarm();
//
//        //������
//        judgeUVEnergyAlarm();
//    }
//}
//
//void remind_events()
//{
//    
//}
