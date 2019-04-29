#ifndef STATUSDEFINE_H
#define STATUSDEFINE_H

typedef enum _ControlSystemStatus //����ϵͳ״ֵ̬����
{
    CSS_unknown = 0,                  //δ֪
    CSS_standby,                      //����
    CSS_debug,                        //����
    CSS_calib_check,                  //Ƥ�ؼ��
    CSS_calib_waiting,                //�ȴ�У׼
    CSS_calib_success,                //У׼�ɹ�
    CSS_calib_fail,                   //У׼ʧ��
    CSS_selftest_begin,
    CSS_bloodAD_checking=CSS_selftest_begin, //ѪҺ��̽���ڼ��(�Լ�)
    CSS_bloodAD_passed,                      //ѪҺ��̽���ͨ��(�Լ�)
    CSS_bloodAD_failed,                      //ѪҺ��̽���ʧ��(�Լ�)
    CSS_acdAD_checking,                      //��������̽���ڼ��(�Լ�)
    CSS_acdAD_passed,                        //��������̽���ͨ��(�Լ�)
    CSS_acdAD_failed,                        //��������̽���ʧ��(�Լ�)
    CSS_AD1_checking,                        //��Ա��̽1���ڼ��(�Լ�)
    CSS_AD1_passed,                          //��Ա��̽1���ͨ��(�Լ�)
    CSS_AD1_failed,                          //��Ա��̽1���ʧ��(�Լ�)
    CSS_AD2_checking,                        //��Ա��̽2(�Լ�)
    CSS_AD2_passed,
    CSS_AD2_failed,
    CSS_bloodV_checking,              //ѪҺ��(�Լ�)
    CSS_bloodV_passed,
    CSS_bloodV_failed,
    CSS_plasmaV_checking,             //Ѫ����(�Լ�)
    CSS_plasmaV_passed,
    CSS_plasmaV_failed,
    CSS_naclV_checking,               //��ˮ��(�Լ�)
    CSS_naclV_passed,
    CSS_naclV_failed,
    CSS_acdP_checking,                //��������
    CSS_acdP_passed,
    CSS_acdP_failed,
    CSS_bloodP_checking,              //Ѫ��
    CSS_bloodP_passed,
    CSS_bloodP_failed,
    CSS_line_checking,                //�����·��ȫ���
    CSS_line_passed,
    CSS_line_failed,
    CSS_CF_checking,                  //���Ļ�
    CSS_CF_passed,
    CSS_CF_failed,
    CSS_PD_checking,                  //ѹ�������
    CSS_PD_passed,
    CSS_PD_failed,
    CSS_Scale_checking,               //���ӳ�
    CSS_Scale_passed,
    CSS_Scale_failed,					//45
    CSS_leak_checking,                //©Һ
    CSS_leak_passed,
    CSS_leak_failed,
    CSS_open_waiting,                 //���Ļ���
    CSS_close_waiting,
    CSS_cover_passed,
    CSS_cover_failed,
    CSS_selftest_stopping,            //�Լ����ڽ���54
    CSS_selftest_over,                //�Լ����
    CSS_collect_begin,                //(�ɼ�ģʽ��ʼ)
    CSS_CLT_bloodAD_checking=CSS_collect_begin,  //ѪҺ��̽���ڼ��(�ɼ�)
    CSS_CLT_bloodAD_passed,                      //ѪҺ��̽���ͨ��(�ɼ�)
    CSS_CLT_bloodAD_failed,                      //ѪҺ��̽���ʧ��(�ɼ�)
    CSS_CLT_acdAD_checking,                      //��������̽���ڼ��(�ɼ�)
    CSS_CLT_acdAD_passed,                        //��������̽���ͨ��(�ɼ�)
    CSS_CLT_acdAD_failed,                        //��������̽���ʧ��(�ɼ�)
    CSS_CLT_AD1_checking,                        //��Ա��̽1���ڼ��(�ɼ�)
    CSS_CLT_AD1_passed,                          //��Ա��̽1���ͨ��(�ɼ�)
    CSS_CLT_AD1_failed,                          //��Ա��̽1���ʧ��(�ɼ�)
    CSS_CLT_AD2_checking,                        //��Ա��̽2(�ɼ�)
    CSS_CLT_AD2_passed,
    CSS_CLT_AD2_failed,
    CSS_CLT_bloodV_checking,              //ѪҺ��(�ɼ�)
    CSS_CLT_bloodV_passed,
    CSS_CLT_bloodV_failed,
    CSS_CLT_plasmaV_checking,             //Ѫ����(�ɼ�)
    CSS_CLT_plasmaV_passed,
    CSS_CLT_plasmaV_failed,
    CSS_CLT_naclV_checking,               //��ˮ��(�ɼ�)
    CSS_CLT_naclV_passed,
    CSS_CLT_naclV_failed,
    CSS_cup_waiting,                  //�ȴ����ı���װ
    CSS_line_ready,                   //�ȴ���·��װȷ��
    CSS_acd_waiting,                  //�ȴ�����������
    CSS_filling,                      //��Һ
    CSS_filling_failed,               //��Һʧ��
    CSS_install_finished,             //��װ���
    CSS_alarm_paused,                 //������ͣ82
    CSS_collect_preparing,            //�ɼ�׼��
    CSS_drawing,                      //���ڲ�Ѫ
    CSS_returning,                    //���ڻ�Ѫ
    CSS_draw_preparing,               //��Ѫ׼������Ѫ�������ѭ����Ѫ��ʼ��
    CSS_return_preparing,             //��Ѫ׼������Ѫ�������Ѫ��ʼ��
    CSS_collect_paused,               //�ɼ���ͣ
    CSS_collect_stopping,             //�ɼ�������ֹ
    CSS_collect_over,                 //�ɼ�����

} ControlSystemStatus ;

#endif // STATUSDEFINE_H
