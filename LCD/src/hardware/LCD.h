#ifndef LCD_H
#define	LCD_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#define BAUDRATE5		115200					//�趨������
#define BAUDRATEREG5 	80000000/16/BAUDRATE5-1	//�����ʲ��� Fpb=80M

// ������Э�� ֡ͷ
#define LCD_START       (0xA55A)
//��д�Ĵ���ָ��    
#define LCD_W_REG       (0x80)    
#define LCD_R_REG       (0x81) 
//��д�����洢��ָ��    
#define LCD_W_VAR_ROM   (0x82)    
#define LCD_R_VAR_ROM   (0x83)      
#define LCD_CMD         (0x85)
//�л�����ͼƬ�Ĵ���    
#define LCD_REG_BG      (0x03)
    

extern void UART5_init();

extern void LCD_Bee(unsigned short t10mS);
extern void LCD_show_BG(unsigned short index);
extern void LCD_show_Icon(unsigned short addr, unsigned short index);
extern void LCD_Update_Num_Var(unsigned short addr, unsigned short value);
extern void LCD_Update_LNum_Var(unsigned short addr, const char* s, unsigned char len);
extern void LCD_Update_Str_Var(unsigned short addr, const char* s);	//���±���
extern void LCD_Read_Var(unsigned short addr, unsigned char len);
//���������⺯������LCDΨһ��ȫ��ʹ��
extern void LCD_Get_DateTime();
#ifdef	__cplusplus
}
#endif

#endif	/* LCD_H */