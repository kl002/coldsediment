#ifndef STATUSDEFINE_H
#define STATUSDEFINE_H

typedef enum _ControlSystemStatus //控制系统状态值定义
{
    CSS_unknown = 0,                  //未知
    CSS_standby,                      //待机
    CSS_debug,                        //调试
    CSS_calib_check,                  //皮重检查
    CSS_calib_waiting,                //等待校准
    CSS_calib_success,                //校准成功
    CSS_calib_fail,                   //校准失败
    CSS_selftest_begin,
    CSS_bloodAD_checking=CSS_selftest_begin, //血液空探正在检查(自检)
    CSS_bloodAD_passed,                      //血液空探检查通过(自检)
    CSS_bloodAD_failed,                      //血液空探检查失败(自检)
    CSS_acdAD_checking,                      //抗凝剂空探正在检查(自检)
    CSS_acdAD_passed,                        //抗凝剂空探检查通过(自检)
    CSS_acdAD_failed,                        //抗凝剂空探检查失败(自检)
    CSS_AD1_checking,                        //浆员空探1正在检查(自检)
    CSS_AD1_passed,                          //浆员空探1检查通过(自检)
    CSS_AD1_failed,                          //浆员空探1检查失败(自检)
    CSS_AD2_checking,                        //浆员空探2(自检)
    CSS_AD2_passed,
    CSS_AD2_failed,
    CSS_bloodV_checking,              //血液阀(自检)
    CSS_bloodV_passed,
    CSS_bloodV_failed,
    CSS_plasmaV_checking,             //血浆阀(自检)
    CSS_plasmaV_passed,
    CSS_plasmaV_failed,
    CSS_naclV_checking,               //盐水阀(自检)
    CSS_naclV_passed,
    CSS_naclV_failed,
    CSS_acdP_checking,                //抗凝剂泵
    CSS_acdP_passed,
    CSS_acdP_failed,
    CSS_bloodP_checking,              //血泵
    CSS_bloodP_passed,
    CSS_bloodP_failed,
    CSS_line_checking,                //回输管路安全检查
    CSS_line_passed,
    CSS_line_failed,
    CSS_CF_checking,                  //离心机
    CSS_CF_passed,
    CSS_CF_failed,
    CSS_PD_checking,                  //压力监测器
    CSS_PD_passed,
    CSS_PD_failed,
    CSS_Scale_checking,               //电子称
    CSS_Scale_passed,
    CSS_Scale_failed,					//45
    CSS_leak_checking,                //漏液
    CSS_leak_passed,
    CSS_leak_failed,
    CSS_open_waiting,                 //离心机盖
    CSS_close_waiting,
    CSS_cover_passed,
    CSS_cover_failed,
    CSS_selftest_stopping,            //自检正在结束54
    CSS_selftest_over,                //自检结束
    CSS_collect_begin,                //(采集模式开始)
    CSS_CLT_bloodAD_checking=CSS_collect_begin,  //血液空探正在检查(采集)
    CSS_CLT_bloodAD_passed,                      //血液空探检查通过(采集)
    CSS_CLT_bloodAD_failed,                      //血液空探检查失败(采集)
    CSS_CLT_acdAD_checking,                      //抗凝剂空探正在检查(采集)
    CSS_CLT_acdAD_passed,                        //抗凝剂空探检查通过(采集)
    CSS_CLT_acdAD_failed,                        //抗凝剂空探检查失败(采集)
    CSS_CLT_AD1_checking,                        //浆员空探1正在检查(采集)
    CSS_CLT_AD1_passed,                          //浆员空探1检查通过(采集)
    CSS_CLT_AD1_failed,                          //浆员空探1检查失败(采集)
    CSS_CLT_AD2_checking,                        //浆员空探2(采集)
    CSS_CLT_AD2_passed,
    CSS_CLT_AD2_failed,
    CSS_CLT_bloodV_checking,              //血液阀(采集)
    CSS_CLT_bloodV_passed,
    CSS_CLT_bloodV_failed,
    CSS_CLT_plasmaV_checking,             //血浆阀(采集)
    CSS_CLT_plasmaV_passed,
    CSS_CLT_plasmaV_failed,
    CSS_CLT_naclV_checking,               //盐水阀(采集)
    CSS_CLT_naclV_passed,
    CSS_CLT_naclV_failed,
    CSS_cup_waiting,                  //等待离心杯安装
    CSS_line_ready,                   //等待管路安装确认
    CSS_acd_waiting,                  //等待抗凝剂穿刺
    CSS_filling,                      //充液
    CSS_filling_failed,               //充液失败
    CSS_install_finished,             //安装完成
    CSS_alarm_paused,                 //报警暂停82
    CSS_collect_preparing,            //采集准备
    CSS_drawing,                      //正在采血
    CSS_returning,                    //正在回血
    CSS_draw_preparing,               //采血准备（回血完成至下循环采血开始）
    CSS_return_preparing,             //回血准备（采血完成至回血开始）
    CSS_collect_paused,               //采集暂停
    CSS_collect_stopping,             //采集正在终止
    CSS_collect_over,                 //采集结束

} ControlSystemStatus ;

#endif // STATUSDEFINE_H
