#include "delay.h"
/*
********************************************************************************
* ��������Դ���������https://blog.csdn.net/jiejiemcu/article/details/83932913 *
********************************************************************************
*/
/*ʱ�����ؼĴ�������:

 ��Cortex-M������һ�������DWT(Data Watchpoint and Trace)��
 ��������һ��32λ�ļĴ�����CYCCNT������һ�����ϵļ�������
 ��¼�����ں�ʱ�����еĸ�������ܼ�¼��ʱ��Ϊ��
 10.74s=2��32�η�/400000000
 (�����ں�Ƶ��Ϊ400M���ں���һ�ε�ʱ����Ϊ1/400M=2.5ns)
 ��CYCCNT���֮�󣬻���0���¿�ʼ���ϼ�����
 ʹ��CYCCNT�����Ĳ������裺
 1����ʹ��DWT���裬����������ں˵��ԼĴ���DEMCR��λ24���ƣ�д1ʹ��
 2��ʹ��CYCCNT�Ĵ���֮ǰ������0
 3��ʹ��CYCCNT�Ĵ����������DWT_CTRL(�����Ϻ궨��ΪDWT_CR)��λ0���ƣ�д1ʹ��
 */


#define  DWT_CR      *(__IO uint32_t *)0xE0001000   
#define  DWT_CYCCNT  *(__IO uint32_t *)0xE0001004
#define  DEM_CR      *(__IO uint32_t *)0xE000EDFC


#define  DEM_CR_TRCENA                   (1 << 24)
#define  DWT_CR_CYCCNTENA                (1 <<  0)


/*************************************************************************************
  * @brief  ��ʼ��ʱ���
  * @param  ��
  * @retval HAL_OK
  * @note   ʹ����ʱ����ǰ��������ñ�����
	
	������Ȼ����HAL_StatusTypeDef�������͵ĺ��������������������˱�д�ġ���ǰ��дһ��
	������ʱ���ʼ�ĺ������Ͷ���Ҫôдvoid��Ҫôдuint8_t�ȵȣ���ʾ���������ص�ֵ
	��ʲô���͵ģ����������HAL_StatusTypeDefҲ��һ���������ͣ����������������HAL��
	�Դ��ģ����Բ鿴�䶨�巢�֣��˲���ֻ��HAL_OK,HAL_ERROR,HAL_BUSY,HAL_TIMEOUT��4��ֵ��
	����typedef enum����ϸ�������https://www.cnblogs.com/yaowen/p/4785342.html
  *************************************************************************************/
//HAL_StatusTypeDef HAL_InitTick(uint32_t TickPriority)
void Delay_Init(void)
{
    /* ʹ��DWT���� */
		DEM_CR |= (uint32_t)DEM_CR_TRCENA;  // |=��λ���ֵ,�������λ�������µı�̷���

    /* DWT CYCCNT�Ĵ���������0 */
    DWT_CYCCNT = (uint32_t)0u;

    /* ʹ��Cortex-M DWT CYCCNT�Ĵ��� */
    DWT_CR |= (uint32_t)DWT_CR_CYCCNTENA;

}

/**
  * @brief  ��ȡ��ǰʱ���
  * @param  ��
  * @retval ��ǰʱ�������DWT_CYCCNT�Ĵ�����ֵ
  */
uint32_t CPU_TS_TmrRd(void)
{        
  return ((uint32_t)DWT_CYCCNT);
}


/**
  * @brief  ����CPU���ڲ�����ʵ�־�ȷ��ʱ��32λ������
  * @param  us : �ӳٳ��ȣ���λ1 us
  * @retval ��
  * @note   ʹ�ñ�����ǰ�����ȵ���CPU_TS_TmrInit����ʹ�ܼ�������
            ��ʹ�ܺ�CPU_TS_INIT_IN_DELAY_FUNCTION
            �����ʱֵΪ2^32/(SYSCLK��ֵ)�룬��������2^32/72000000=59.6523(s)
  */
void Delay_us(uint32_t us)
{
  uint32_t ticks;
  uint32_t told,tnow,tcnt=0;

  /* �ں����ڲ���ʼ��ʱ����Ĵ����� */  
#if (CPU_TS_INIT_IN_DELAY_FUNCTION)  
  /* ��ʼ��ʱ��������� */
  Delay_Init();
		
#endif
  
  ticks = us * (GET_CPU_ClkFreq() / 1000000);  /* ��Ҫ�Ľ����� */      
  tcnt = 0;
  told = (uint32_t)CPU_TS_TmrRd();         /* �ս���ʱ�ļ�����ֵ */

  while(1)
  {
    tnow = (uint32_t)CPU_TS_TmrRd();  
    if(tnow != told)
    { 
        /* 32λ�������ǵ��������� */    
      if(tnow > told)
      {
        tcnt += tnow - told;  //tcnt = tcnt + tnow - told
      }
      /* ����װ�� */
      else 
      {
        tcnt += UINT32_MAX - told + tnow; 
      } 
      
      told = tnow;

      /*ʱ�䳬��/����Ҫ�ӳٵ�ʱ��,���˳� */
      if(tcnt >= ticks)break;
    }  
  }
}

/*********************************************END OF FILE**********************/

