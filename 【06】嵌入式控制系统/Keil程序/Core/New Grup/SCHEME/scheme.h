#ifndef __SCHEME_H
#define __SCHEME_H

#include "linetracking.h"
#include "motor.h"
#include "stm32f1xx_hal.h"
typedef	struct	//����״̬Situation
{
	uint8_t Trend;     	/*��ǰ���	
															����δ��ʼ =0
															ǰ����ת·��1 = 1
															ǰ��T��·��1 	= 2
															��ת�� =        3
															��ͣ��ȡ��	= 4
															��ȡ�Ϸ���	=5
															�����Բ��  =6
															��Բ��    =7
															��ʼͨ��	=8
															����ж�Ͽ�ж��	=9
															����	=10
	
															����T·��T1.2��׼������һȦ  =11
															ǰ��T·��T1.2��׼���ؼ� =12
															�������T·�ڣ�׼���ؼ�	=13
															���ң�ת��ص�ԭ�㣬׼��������
															
	
	
	
	*/

//  uint8_t speed;       /*��֪��̨�ٶ�*/
//  uint16_t distance;        /*��·��*/ 

  uint8_t turn_situ;  /*	��T·���ܱߵ�λ��Flag	
											�¸�·�ڲ�ת=0
											�¸�·��ת  =1
	*/
	uint8_t round_count;/*	���ڼ�������Ȧ��	
											
	*/
	
	
} Situ_InitTypeDef; 

void initilize_suit(void);
#endif
