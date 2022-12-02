/*
 * fsm_change.c
 *
 *  Created on: Nov 16, 2022
 *      Author: Lenovo
 */

#include "main.h"
#include "global.h"
#include "fsm_change.h"
#include "button.h"
#include "button2.h"
#include "button3.h"
#include "software_timer.h"
#include "seg7_display.h"
#include "fsm_machine.h"


void blink_RED(){
	if(RED_BLINK_flag == 1){
		setTimer_for_RED_blink(25);
		HAL_GPIO_TogglePin(RED1_GPIO_Port, RED1_Pin);
		HAL_GPIO_TogglePin(RED2_GPIO_Port, RED2_Pin);
	}
	return;
}
void blink_YELLOW(){
	if(YELLOW_BLINK_flag == 1){
		setTimer_for_YELLOW_blink(25);
		HAL_GPIO_TogglePin(PURPLE1_GPIO_Port, PURPLE1_Pin);
		HAL_GPIO_TogglePin(PURPLE2_GPIO_Port, PURPLE2_Pin);
	}
	return;
}
void blink_GREEN(){
	if(GREEN_BLINK_flag == 1){
		setTimer_for_GREEN_blink(25);
		HAL_GPIO_TogglePin(GREEN1_GPIO_Port, GREEN1_Pin);
		HAL_GPIO_TogglePin(GREEN2_GPIO_Port, GREEN2_Pin);
	}
	return;
}


void updateClockBuffer(void){
	seg_index1 = time_for_Traffic1/10;
	seg_index3 = time_for_Traffic2/10;
	seg_index2 = time_for_Traffic1%10;
	seg_index4 = time_for_Traffic2%10;
	return;
}


////CHanged modes seg
//void SEG7_CHANGED_MODE(int seg2){
//	switch(seg2){
//	case 0:
//		turnLEDOFF();
//		display7SEG1(seg_index1);
//		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
////		clockRun();
//		break;
//	case 1:
//		turnLEDOFF();
//		display7SEG1(seg_index2);
//		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);
//		seg_index2--;
//		if(seg_index2 == 0){
//			seg_index2 = seg_buffer1[(++num1)%3];
//		}
//		break;
//	case 2:
//		turnLEDOFF();
//		display7SEG1(seg_index3);
//		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 0);
//		break;
//	case 3:
//		turnLEDOFF();
//		display7SEG1(seg_index4);
//		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 0);
//		seg_index4--;
//		if(seg_index4 == 0){
//			seg_index4 = seg_buffer1[(++num2)%3];
//		}
//		break;
//	default:
//		break;
//	}
//	return;
//}


