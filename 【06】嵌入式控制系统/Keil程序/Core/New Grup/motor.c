#include "motor.h"
#include "tim.h"
//��ת����
/*  ע���������IO��1��ʾ��ת��0��ʾ��ת
				PWM������0--1000ֵ�����ٶȵ���
*/

void LEFTTURN(int C_COUNTER_L,int C_COUNTER_R,int TIME_L)
{     //����
	 //HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_2);                                    //����������pwm��ѹ
	 __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, C_COUNTER_L);                    //�趨������ռ�ձ�=C_COUNTER/1000
	 HAL_GPIO_WritePin(LEFT_MOTOR_GPIO , LEFT_MOTOR_PIN, GPIO_PIN_RESET); //������ת      /* �趨IO��ֵʹ��ת�����ת��ת  */  

		//�ҵ��
	//	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_3);                                   //�����ҵ����pwm��ѹ 
	 __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, C_COUNTER_R*1.2);                     //�趨�ҵ����ռ�ձ�=C_COUNTER/1000
	 HAL_GPIO_WritePin(RIGHT_MOTOR_GPIO, RIGHT_MOTOR_PIN, GPIO_PIN_RESET);        /* �趨IO��ֵʹ��ת�����ת��ת  */ 
	//�趨����ʱ��
	   HAL_Delay(TIME_L);
	
//	   HAL_TIM_PWM_Stop(&htim4,TIM_CHANNEL_2);    //�ر�������pwm�������ֹ��������
//	   HAL_TIM_PWM_Stop(&htim3,TIM_CHANNEL_3);    //�ر��ҵ����pwm�������ֹ��������
}



//��ת����

void RIGHTTURN(int C_COUNTER_L,int C_COUNTER_R,int TIME_R)
{     //����
    // HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_2);                                    //����������pwm��ѹ
		 __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, C_COUNTER_L);                    //�趨������ռ�ձ�=C_COUNTER/1000
     HAL_GPIO_WritePin(LEFT_MOTOR_GPIO , LEFT_MOTOR_PIN, GPIO_PIN_RESET);       /* �趨IO��ֵʹ��ת�����ת��ת  */  
	
	    //�ҵ��
	  //  HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_3);                                   //�����ҵ����pwm��ѹ 
		 __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, C_COUNTER_R*1.12);                     //�趨�ҵ����ռ�ձ�=C_COUNTER/1000
     HAL_GPIO_WritePin(RIGHT_MOTOR_GPIO, RIGHT_MOTOR_PIN, GPIO_PIN_RESET);        /* �趨IO��ֵʹ��ת�����ת��ת  */ 
	//�趨����ʱ��
	   HAL_Delay(TIME_R);
	
//	   HAL_TIM_PWM_Stop(&htim4,TIM_CHANNEL_2);    //�ر�������pwm�������ֹ��������
//	   HAL_TIM_PWM_Stop(&htim3,TIM_CHANNEL_3);    //�ر��ҵ����pwm�������ֹ��������

}



//ǰ������

void FORWARD(int C_COUNTER,int TIME)
{     //����
     //HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_2);                                    //����������pwm��ѹ
		 __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, C_COUNTER);                    //�趨������ռ�ձ�=C_COUNTER/1000
     HAL_GPIO_WritePin(LEFT_MOTOR_GPIO , LEFT_MOTOR_PIN, GPIO_PIN_RESET);       /* �趨IO��ֵʹ��ת�����ת��ת  */  
	
	    //�ҵ��
	 //  HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_3);                                   //�����ҵ����pwm��ѹ 
		 __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, C_COUNTER*1.12);                     //�趨�ҵ����ռ�ձ�=C_COUNTER/1000
     HAL_GPIO_WritePin(RIGHT_MOTOR_GPIO, RIGHT_MOTOR_PIN, GPIO_PIN_RESET);        /* �趨IO��ֵʹ��ת�����ת��ת  */ 
	//�趨����ʱ��
	   HAL_Delay(TIME);
	
	  // HAL_TIM_PWM_Stop(&htim4,TIM_CHANNEL_2);    
	  // HAL_TIM_PWM_Stop(&htim3,TIM_CHANNEL_3);    //�ر����ҵ����pwm�������ֹ��������
}


//���˺���


void BACK(int C_COUNTER,int TIME)
{     //����
     //HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_2);                                    //����������pwm��ѹ
		 __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, C_COUNTER);                    //�趨������ռ�ձ�=C_COUNTER/1000
     HAL_GPIO_WritePin(LEFT_MOTOR_GPIO , LEFT_MOTOR_PIN, GPIO_PIN_SET);       /* �趨IO��ֵʹ��ת�����ת��ת  */  
	
	    //�ҵ��
	 //  HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_3);                                   //�����ҵ����pwm��ѹ 
		 __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, C_COUNTER*1.12);                     //�趨�ҵ����ռ�ձ�=C_COUNTER/1000
     HAL_GPIO_WritePin(RIGHT_MOTOR_GPIO, RIGHT_MOTOR_PIN, GPIO_PIN_SET);        /* �趨IO��ֵʹ��ת�����ת��ת  */ 
	//�趨����ʱ��
	   HAL_Delay(TIME);
	
	  // HAL_TIM_PWM_Stop(&htim4,TIM_CHANNEL_2);    
	  // HAL_TIM_PWM_Stop(&htim3,TIM_CHANNEL_3);    //�ر����ҵ����pwm�������ֹ��������
}



//�ƶ�����

void STOP(int C_COUNTER,int TIME)
{     //����
	//HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_2);     //����������pwm��ѹ	  
	//HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_3);     //�����ҵ����pwm��ѹ     
                          
	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, C_COUNTER);   //�趨������ռ�ձ�=C_COUNTER/1000	
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, C_COUNTER);   //�趨�ҵ����ռ�ձ�=C_COUNTER/1000
	 HAL_Delay(TIME);
	// HAL_TIM_PWM_Stop(&htim4,TIM_CHANNEL_2);    //�ر�������pwm�������ֹ��������
	 //HAL_TIM_PWM_Stop(&htim3,TIM_CHANNEL_3);    //�ر��ҵ����pwm�������ֹ��������
}
void left_90(int C_COUNTER_L,int C_COUNTER_R,int TIME)
{     //����
	//HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_2);     //����������pwm��ѹ	  
	//HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_3);     //�����ҵ����pwm��ѹ     
  HAL_GPIO_WritePin(LEFT_MOTOR_GPIO , LEFT_MOTOR_PIN, GPIO_PIN_SET); //���ַ�ת      /* �趨IO��ֵʹ��ת�����ת  */  
	HAL_GPIO_WritePin(RIGHT_MOTOR_GPIO, RIGHT_MOTOR_PIN, GPIO_PIN_RESET);        /* �趨IO��ֵʹ��ת�����ת  */ 
	
	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, C_COUNTER_L);   //�趨������ռ�ձ�=C_COUNTER/1000	
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, C_COUNTER_R*1.12);   //�趨�ҵ����ռ�ձ�=C_COUNTER/1000

	HAL_Delay(TIME);
	// HAL_TIM_PWM_Stop(&htim4,TIM_CHANNEL_2);    //�ر�������pwm�������ֹ��������
	 //HAL_TIM_PWM_Stop(&htim3,TIM_CHANNEL_3);    //�ر��ҵ����pwm�������ֹ��������
}
void right_90(int C_COUNTER_L,int C_COUNTER_R,int TIME)
{     //����
	//HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_2);     //����������pwm��ѹ	  
	//HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_3);     //�����ҵ����pwm��ѹ     
  HAL_GPIO_WritePin(LEFT_MOTOR_GPIO , LEFT_MOTOR_PIN, GPIO_PIN_RESET); //���ַ�ת      /* �趨IO��ֵʹ��ת�����ת  */  
	HAL_GPIO_WritePin(RIGHT_MOTOR_GPIO, RIGHT_MOTOR_PIN, GPIO_PIN_SET);        /* �趨IO��ֵʹ��ת�����ת  */ 
                        
	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, C_COUNTER_L);   //�趨������ռ�ձ�=C_COUNTER/1000	
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, C_COUNTER_R);   //�趨�ҵ����ռ�ձ�=C_COUNTER/1000

	HAL_Delay(TIME);
	// HAL_TIM_PWM_Stop(&htim4,TIM_CHANNEL_2);    //�ر�������pwm�������ֹ��������
	 //HAL_TIM_PWM_Stop(&htim3,TIM_CHANNEL_3);    //�ر��ҵ����pwm�������ֹ��������
}

void rotate_180(int C_COUNTER_L,int C_COUNTER_R,int TIME)
{     //����
	//HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_2);     //����������pwm��ѹ	  
	//HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_3);     //�����ҵ����pwm��ѹ     
  HAL_GPIO_WritePin(LEFT_MOTOR_GPIO , LEFT_MOTOR_PIN, GPIO_PIN_RESET); //���ַ�ת      /* �趨IO��ֵʹ��ת�����ת  */  
	HAL_GPIO_WritePin(RIGHT_MOTOR_GPIO, RIGHT_MOTOR_PIN, GPIO_PIN_SET);        /* �趨IO��ֵʹ��ת�����ת  */                         
	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, C_COUNTER_L);   //�趨������ռ�ձ�=C_COUNTER/1000	
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, C_COUNTER_R);   //�趨�ҵ����ռ�ձ�=C_COUNTER/1000

	HAL_Delay(TIME);
	// HAL_TIM_PWM_Stop(&htim4,TIM_CHANNEL_2);    //�ر�������pwm�������ֹ��������
	 //HAL_TIM_PWM_Stop(&htim3,TIM_CHANNEL_3);    //�ر��ҵ����pwm�������ֹ��������
}



