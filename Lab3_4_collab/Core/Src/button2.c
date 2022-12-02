/*
 * button2.c
 *
 *  Created on: Nov 16, 2022
 *      Author: Lenovo
 */

#include "button2.h"

//#define N 100;
//declare amount of pressed button for debouncing
int keyReg0_MODIFY = NORMAL_STATE;
int keyReg1_MODIFY = NORMAL_STATE;
int keyReg2_MODIFY= NORMAL_STATE;
int keyReg3_MODIFY= NORMAL_STATE;
int MODIFY_FLAG = 0;



int Timer_for_key_Press2 = 200 ;				//set Timer for nhaans def


void sub_for_Process2(){
	MODIFY_FLAG = 1;
}

int is_MODIFY_PRESSED(){
	if(MODIFY_FLAG == 1){
		MODIFY_FLAG = 0;
		return 1;
	}
	return 0;
}


void get_key_Input2(){
	keyReg0_MODIFY = keyReg1_MODIFY;
	keyReg1_MODIFY = keyReg2_MODIFY;
	keyReg2_MODIFY = HAL_GPIO_ReadPin(MODIFY_GPIO_Port, MODIFY_Pin);
	if(keyReg0_MODIFY == keyReg1_MODIFY && keyReg1_MODIFY == keyReg2_MODIFY){
		if(keyReg3_MODIFY != keyReg2_MODIFY){
			keyReg3_MODIFY = keyReg2_MODIFY;
			if(keyReg2_MODIFY == PRESSED_STATE){					//Nhaans tha?
				//TOdo for press 1 time
				sub_for_Process2();
				Timer_for_key_Press2 = 200;
			}
		}
		else{
			Timer_for_key_Press2--;
			if(Timer_for_key_Press2 == 0){
				if(keyReg2_MODIFY == PRESSED_STATE){
					//Todo for always pressed
					sub_for_Process2();
				}
				Timer_for_key_Press2 = 200;
			}
			}
		}
	}
