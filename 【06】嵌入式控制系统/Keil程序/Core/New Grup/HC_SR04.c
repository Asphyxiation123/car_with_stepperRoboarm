/***************************************************************************************************
*			������Դ��https://blog.csdn.net/qq_45396672/article/details/119619269?spm=1001.2014.3001.5501
*	�����ο����ϣ�https://blog.csdn.net/as480133937/article/details/99407485��HAL���µĶ�ʱ�����벶�����ã�
* 				���ڣ�2021��11��22��
****************************************************************************************************/

#include "HC_SR04.h"

//����һ��ģ������ݽṹ��
HCSR04 hcsr04;
//���±�д���벶��ص�����
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	
	if(htim->Instance == HCSR04_TIM)
	{
		//��������ؼ��
		if(hcsr04.STATE == RISING)
		{
			//���ö�ʱ��CNTΪ0
			__HAL_TIM_SET_COUNTER(&HCSR04_TIM_HAL,0);
		  //��ȡ������ʱ��CNTֵ��buf
			hcsr04.buf[0] = __HAL_TIM_GetCounter(&HCSR04_TIM_HAL);
			//������һ������Ϊ�½���
			__HAL_TIM_SET_CAPTUREPOLARITY(&HCSR04_TIM_HAL,HCSR04_TIM_CHANNEL,TIM_ICPOLARITY_FALLING); 
			//�ı�����ģʽ
			hcsr04.STATE=FALLING;
		}else if(hcsr04.STATE == FALLING)//����½��ؼ��
		{
			//��ȡ��ǰ��CNT��buf2�������ߵ�ƽά�ֵ�ʱ�䳤�Ⱦͼ�¼��
			hcsr04.buf[1] = __HAL_TIM_GetCounter(&HCSR04_TIM_HAL);
			//�����б�־����Ϊ���
			hcsr04.STATE=OVER; 
			
		}
	}
	
}
