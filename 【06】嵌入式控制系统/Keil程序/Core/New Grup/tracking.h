#ifndef __TRACKING_H
#define __TRACKING_H

void track(void);

#define INF_port    GPIOB
#define INF_PIN_1 GPIO_PIN_12
#define INF_PIN_2 GPIO_PIN_13
#define INF_PIN_3 GPIO_PIN_14
#define INF_PIN_4 GPIO_PIN_15

#define BW_4 HAL_GPIO_ReadPin(INF_port,INF_PIN_1)//��1
#define BW_3 HAL_GPIO_ReadPin(INF_port,INF_PIN_2)//��2
#define BW_2 HAL_GPIO_ReadPin(INF_port,INF_PIN_3)//��2
#define BW_1 HAL_GPIO_ReadPin(INF_port,INF_PIN_4)//��1

void linetrack2(); 
