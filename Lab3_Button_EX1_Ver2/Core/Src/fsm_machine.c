/*
 * fsm_machine.c
 *
 *  Created on: Nov 13, 2022
 *      Author: Lenovo
 */


#include "main.h"
#include "fsm_machine.h"
#include "software_timer.h"
#include "seg7_display.h"
#include "global.h"
#include "button.h"
#include "button2.h"
#include "button3.h"
#include "fsm_change.h"

int status_traffic1 = 1;
int status_traffic2 = 1;
int time_for_Traffic1;
int time_for_Traffic2;
//int seg_index1 = 5;
//int seg_index2 = 3;
//int seg = 0;


void TRAFFIC_NORMAL1(){
	switch(status_traffic1){
	case 1:
		updateClockBuffer();
		HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RESET);
		HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
		HAL_GPIO_WritePin(PURPLE1_GPIO_Port, PURPLE1_Pin, SET);
		if(timer_flag1 == 1){
			setTimer1(100);      //red
			time_for_Traffic1--;
			if(time_for_Traffic1 == 0){
				status_traffic1 = 2;
				time_for_Traffic1 = seg_buffer1[1];
			}
		}
		break;
	case 2:
		updateClockBuffer();
		HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
		HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, RESET);
		HAL_GPIO_WritePin(PURPLE1_GPIO_Port, PURPLE1_Pin, SET);
		if(timer_flag1 == 1){
			setTimer1(100);      //green
			time_for_Traffic1--;
			if(time_for_Traffic1 == 0){
				status_traffic1 = 3;
				time_for_Traffic1 = seg_buffer1[2];
			}
		}
		break;

	case 3:
		updateClockBuffer();
		HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
		HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
		HAL_GPIO_WritePin(PURPLE1_GPIO_Port, PURPLE1_Pin, RESET);
		if(timer_flag1 == 1){
			setTimer1(100);      //YELLOW
				time_for_Traffic1--;
				if(time_for_Traffic1 == 0){
					status_traffic1 = 1;
					time_for_Traffic1 = seg_buffer1[0];
				}
		}
		break;
	default:
		break;
	}
}



void TRAFFIC_NORMAL2(){
	switch(status_traffic2){
	case 1:
		updateClockBuffer();
		HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
		HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, RESET);
		HAL_GPIO_WritePin(PURPLE2_GPIO_Port, PURPLE2_Pin, SET);
		if(timer_flag2 == 1){
			setTimer2(100);      //green
			time_for_Traffic2--;
			if(time_for_Traffic2 == 0){
					status_traffic2 = 2;
					time_for_Traffic2 = seg_buffer1[2];
				}
		}
		break;
	case 2:
		updateClockBuffer();
		HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
		HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
		HAL_GPIO_WritePin(PURPLE2_GPIO_Port, PURPLE2_Pin, RESET);
		if(timer_flag2 == 1){
			setTimer2(100);
			time_for_Traffic2--;
			if(time_for_Traffic2 == 0){
				time_for_Traffic2 = seg_buffer1[0];
				status_traffic2 = 3;
			}
		}
		break;
	case 3:
		updateClockBuffer();
		HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, RESET);
		HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, SET);
		HAL_GPIO_WritePin(PURPLE2_GPIO_Port, PURPLE2_Pin, SET);
		if(timer_flag2 == 1){
			setTimer2(100);
			time_for_Traffic2--;
			if(time_for_Traffic2 == 0){
				time_for_Traffic2 = seg_buffer1[1];
				status_traffic2 = 1;
			}
		}
		break;
	default:
		break;
	}
	return;
}

void OFF_ALL_LED2(){
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, 1);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, 1);
	HAL_GPIO_WritePin(PURPLE2_GPIO_Port, PURPLE2_Pin, 1);
}

void OFF_ALL_LED1(){
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, 1);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, 1);
	HAL_GPIO_WritePin(PURPLE1_GPIO_Port, PURPLE1_Pin, 1);
}


void ON_ALL_LED2(){
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, 0);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, 0);
	HAL_GPIO_WritePin(PURPLE2_GPIO_Port, PURPLE2_Pin, 0);
}

void ON_ALL_LED1(){
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, 0);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, 0);
	HAL_GPIO_WritePin(PURPLE1_GPIO_Port, PURPLE1_Pin, 0);
}



void start_SEG7(){
	 time_for_Traffic1 = seg_buffer1[0];
	 time_for_Traffic2 = seg_buffer1[1];
}


//FSM_MACHINE_SYSTEM

void fsm_Suy_Exercise(){
	switch(status_BUTTONS){
	case 0:

		TRAFFIC_NORMAL1();
		TRAFFIC_NORMAL2();
		if(is_SELECT_PRESSED() == 1){
			status_BUTTONS = 1;
			seg_index4 = 2;
			seg_index3 = 0;
			OFF_ALL_LED1();
			OFF_ALL_LED2();
		}
		break;
	case 1:
		blink_RED();
		seg_index1 = seg_buffer1[0]/10;
		seg_index2 = seg_buffer1[0]%10;
		if(is_SELECT_PRESSED() == 1){
			status_BUTTONS = 2;
			seg_index4 ++;
			OFF_ALL_LED1();
			OFF_ALL_LED2();
		}
		if(is_SET_PRESSED() == 1){
			status_BUTTONS = 0;
		}
		if(is_MODIFY_PRESSED() == 1){
			if(seg_buffer1[0]<99){
				seg_buffer1[0]=seg_buffer1[0]+1;//1-99
				} else {
					seg_buffer1[0]=1;
			}
		}
//		if(is_MODIFY_PRESSED() == 1){
//
//			}
		break;
	case 2:
		seg_index1 = seg_buffer1[2]/10;
		seg_index2 = seg_buffer1[2]%10;
		blink_YELLOW();
		if((is_SELECT_PRESSED() == 1)){
			status_BUTTONS = 3;
			seg_index4++;
			OFF_ALL_LED1();
			OFF_ALL_LED2();
		}
		if(is_MODIFY_PRESSED() == 1){
			if(seg_buffer1[2]<99){
				seg_buffer1[2]=seg_buffer1[2]+1;//1-99
				} else {
					seg_buffer1[2]=1;
				}
		}
		if(is_SET_PRESSED() == 1){
			status_BUTTONS = 0;
		}
		break;
	case 3:
		seg_index1 = seg_buffer1[1]/10;
		seg_index2 = seg_buffer1[1]%10;
		blink_GREEN();
		if(is_SELECT_PRESSED() == 1){
					status_BUTTONS = 1;
				}
		if(is_MODIFY_PRESSED() == 1){
			if(seg_buffer1[1]<99){
				seg_buffer1[1]=seg_buffer1[1]+1;//1-99
				} else {
					seg_buffer1[1]=1;
				}
		}
		if(is_SET_PRESSED() == 1){
					status_BUTTONS = 0;
				}
		break;
	default:
		break;
	}
	return;
}

