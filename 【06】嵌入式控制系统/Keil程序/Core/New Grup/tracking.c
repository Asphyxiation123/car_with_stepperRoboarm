#include "linetracking.h"
#include "motor.h"
#include "stm32f1xx_hal.h"

#define WL 0
#define BL 1

uint8_t take_dir(uint8_t book){
	if(BW_1==WL && BW_2==WL && BW_3==BL && BW_4==WL) {send_go_ahead();
																										send_left_adj(book,0);}			//��ֱ��

	if(BW_1==WL && BW_2==BL && BW_3==BL && BW_4==WL)  send_left_adj(book,5);			//ƫ��1
	if(BW_1==WL && BW_2==BL && BW_3==WL && BW_4==WL)  send_left_adj(book,10);			//ƫ��2
	
	if(BW_1==WL && BW_2==WL && BW_3==BL && BW_4==BL) 	send_righ_adj(book,5);			//ƫ��1
	if(BW_1==WL && BW_2==WL && BW_3==WL && BW_4==BL) 	send_righ_adj(book,10);			//ƫ��2
	
	if(BW_1==BL && BW_2==BL && BW_3==BL	&& BW_4==BL&&
				Situ.T_situ==1) //�⵽�س�T·��,��־����ʻ��
	{while(!(BW_1==WL && BW_2==WL && BW_3==BL && BW_4==WL))
		{	take_turn_cross_right(40,20);Situ.T_situ=3;}
			Situ.T_situ=6;	
			send_go_ahead();
			}
