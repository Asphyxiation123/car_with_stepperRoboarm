#ifndef __MOTOR_H_
#define __MOTOR_H_
#include "main.h"

//����˶�����
void LEFTTURN(int C_COUNTER_L,int C_COUNTER_R,int TIME_L);    /* ��ת����-����Ϊռ�ձ���ֵ��ռ�ձ�= C_COUNTER/1000, TIME_LΪ��ת��Ҫ��ʱ��*/
void RIGHTTURN(int C_COUNTER,int C_COUNTER_R,int TIME_R);     /* ��ת����-����Ϊռ�ձ���ֵ��ռ�ձ�= C_COUNTER/1000, TIME_RΪ��ת��Ҫ��ʱ��*/
void FORWARD(int C_COUNTE , int TIME);      /* ǰ������-����Ϊռ�ձ���ֵ��ռ�ձ�= C_COUNTER/1000, TIME_FΪ�������е�ʱ��*/
void BACK(int C_COUNTE , int TIME);           /* ���˺���-����Ϊռ�ձ���ֵ��ռ�ձ�= C_COUNTER/1000, TIME_BΪ�������е�ʱ��*/
void STOP(int C_COUNTER,int TIME);           /* �ƶ�����-����Ϊռ�ձ���ֵ��ռ�ձ�= C_COUNTER/1000, TIME_SΪ�������е�ʱ��*/
void left_90(int C_COUNTER_L,int C_COUNTER_R,int TIME);
void right_90(int C_COUNTER_L,int C_COUNTER_R,int TIME);
void rotate_180(int C_COUNTER_L,int C_COUNTER_R,int TIME);
	//  ����ӿ�IO�ڷ���
//����������IO����
//����1��IO
#define LEFT_MOTOR_PIN             GPIO_PIN_4      
#define LEFT_MOTOR_GPIO            GPIOA

//�ҵ��������IO����
//�ҵ��1��IO
#define RIGHT_MOTOR_PIN             GPIO_PIN_10
#define RIGHT_MOTOR_GPIO            GPIOB





















#endif

