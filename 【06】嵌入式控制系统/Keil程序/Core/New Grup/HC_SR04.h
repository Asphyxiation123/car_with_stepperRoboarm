#ifndef _HC_SR04_H
#define _HC_SR04_H

#include "tim.h"

//����ʹ�õĶ�ʱ���Ͳ���ͨ��
#define HCSR04_TIM 		 		  TIM2
#define HCSR04_TIM_HAL 			htim2
#define HCSR04_TIM_CHANNEL  TIM_CHANNEL_1

//����HC-SR04������ģ��Trig���Ŷ�Ӧ�Ķ˿�
#define TRIG_Pin         GPIO_PIN_8
#define TRIG_GPIO_Port   GPIOA

//����һ��״̬ö�ٳ���
typedef enum Run_State
{
	TRIG_WAIT = 0,
	RISING,
	FALLING,
	OVER
}Run_State;
//�����ṹ�巽�㴫��ʹ������
typedef struct 
{
	Run_State STATE;
	int buf[2];
	float len;
}HCSR04;
//����һ�»ص�����
extern void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim);
#endif /*_HC_SR04_H*/
