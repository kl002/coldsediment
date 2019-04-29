#include "Scale.h"

void Scale_init()
{
    Scale1_init();
    Scale2_init();
}

void Scale1_init()
{
    ADSK1_TRIS = 0;
    ADDO1_TRIS = 1;
    ADSK1 = 0;
    delay_5us(200);
}

void Scale2_init()
{
    ADSK2_TRIS = 0;
    ADDO2_TRIS = 1;
    ADSK2 = 0;
    delay_5us(200);
}

void delay_5us (int i)  // 实测50us左右
{
    int j;
    for(;i>0;i--)
    {
        for(j=8;j>0;j--)
        {
            ;
        }
    }
}

int Read_Scale1()  // 返回值为32位有符号数，其中24位为有效值，低八位为0 ，如果返回-1 ，则表示读取失败
{
    unsigned char i;
    int count2 =0 ;
    if( ADDO1 == 1 )
        return -1;  // 采集失败
    else
    {
        for(i=0;i<24;i++)       // 开始发送时钟读取串行24bit数据
    {
        ADSK1 = 1;
        delay_5us(1);
        ADSK1 = 0;
        if(ADDO1 == 0)        
        count2=count2<<1;
        else
        {
            count2=count2 << 1 ;
            count2++ ;
        }
        delay_5us(1);
    }
        ADSK1 = 1;
        delay_5us(1);
        ADSK1 = 0;
        delay_5us(1);           //数据读取操作完毕
        count2 <<= 8 ;
        return count2;    
    }
}

int Read_Scale2()  // 返回值为32位有符号数，其中24位为有效值，低八位为0 ，如果返回-1 ，则表示读取失败
{
    unsigned char i;
    int count2 =0 ;
    if( ADDO2 == 1 )
        return -1;  // 采集失败
    else
    {
        for(i=0;i<24;i++)       // 开始发送时钟读取串行24bit数据
    {
        ADSK2 = 1;
        delay_5us(1);
        ADSK2 = 0;
        if(ADDO2 == 0)        
        count2=count2<<1;
        else
        {
            count2=count2 << 1 ;
            count2++ ;
        }
        delay_5us(1);
    }
        ADSK2 = 1;
        delay_5us(1);
        ADSK2 = 0;
        delay_5us(1);           //数据读取操作完毕
        count2 <<= 8 ;
        return count2;    
    }
}