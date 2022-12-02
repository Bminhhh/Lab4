/*
 * button.c
 *
 *  Created on: Nov 8, 2022
 *      Author: Lenovo
 */


#include"button.h"
#include"main.h"

//#define N 100;
//declare amount of pressed button for debouncing
int keyReg0_SELECT = NORMAL_STATE;
int keyReg1_SELECT = NORMAL_STATE;
int keyReg2_SELECT= NORMAL_STATE;
int keyReg3_SELECT= NORMAL_STATE;
int SELECT_FLAG = 0;


int Timer_for_key_Press1 = 200 ;				//set Timer for nhaans def



int is_SELECT_PRESSED(){
	if(SELECT_FLAG == 1){
		SELECT_FLAG = 0;
		return 1;
	}
	return 0;
}


void sub_for_Process(){
	SELECT_FLAG = 1;
//	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, 1);
}

void get_key_Input(){
	keyReg0_SELECT = keyReg1_SELECT;
	keyReg1_SELECT = keyReg2_SELECT;
	keyReg2_SELECT = HAL_GPIO_ReadPin(SELECT_GPIO_Port, SELECT_Pin);
	if(keyReg0_SELECT == keyReg1_SELECT && keyReg1_SELECT == keyReg2_SELECT){
		if(keyReg3_SELECT != keyReg2_SELECT){
			keyReg3_SELECT = keyReg2_SELECT;
			if(keyReg2_SELECT == PRESSED_STATE){					//Nhaans tha?
				//TOdo for press 1 time
				sub_for_Process();
				Timer_for_key_Press1 = 200;
			}
		}
		else{
			Timer_for_key_Press1--;
			if(Timer_for_key_Press1 == 0){
				if(keyReg2_SELECT == PRESSED_STATE){
					//Todo for always pressed
					sub_for_Process();
				}
				Timer_for_key_Press1 = 200;
			}
			}
		}
	}
