/*
 * button3.c
 *
 *  Created on: Nov 16, 2022
 *      Author: Lenovo
 */

#include "button3.h"

//#define N 100;
//declare amount of pressed button for debouncing
int keyReg0_SET = NORMAL_STATE;
int keyReg1_SET = NORMAL_STATE;
int keyReg2_SET= NORMAL_STATE;
int keyReg3_SET= NORMAL_STATE;
int SET_FLAG = 0;




int Timer_for_key_Press3 = 200 ;				//set Timer for nhaans def


void sub_for_Process3(){
	SET_FLAG = 1;
}
int is_SET_PRESSED(){
	if(SET_FLAG == 1){
		SET_FLAG = 0;
		return 1;
	}
	return 0;
}

void get_key_Input3(){
	keyReg0_SET = keyReg1_SET;
	keyReg1_SET = keyReg2_SET;
	keyReg2_SET = HAL_GPIO_ReadPin(SET_GPIO_Port, SET_Pin);
	if(keyReg0_SET == keyReg1_SET && keyReg1_SET == keyReg2_SET){
		if(keyReg3_SET != keyReg2_SET){
			keyReg3_SET = keyReg2_SET;
			if(keyReg2_SET == PRESSED_STATE){					//Nhaans tha?
				//TOdo for press 1 time
				sub_for_Process3();
				Timer_for_key_Press3 = 200;
			}
		}
		else{
			Timer_for_key_Press3--;
			if(Timer_for_key_Press3 == 0){
				if(keyReg2_SET == PRESSED_STATE){
					//Todo for always pressed
					sub_for_Process3();
				}
				Timer_for_key_Press3 = 200;
			}
			}
		}
	}
