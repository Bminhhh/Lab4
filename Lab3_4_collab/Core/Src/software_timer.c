/*
 * software_timer.c
 *
 *  Created on: Nov 6, 2022
 *      Author: Lenovo
 */


#include "main.h"
#include "software_timer.h"

#define number_LED 4


//declare timer counter
int counter1;
int counter2;
int counter3;
int counter4;
int counter5;

//declare timer flag
int timer_flag1;
int timer_flag2;
int timer_flag3;


//setTimer for Traffic light ngang
void setTimer1(int duration1){
	counter1 = duration1;
	timer_flag1 = 0;
}

//setTimer for Traffic light ngang
void setTimer2(int duration2){
	counter2 = duration2;
	timer_flag2 = 0;
}

//setTimer for 7SEG
void setTimer3(int duration3){
	counter3 = duration3;
	timer_flag3 = 0;
}


//Led blink in change mode
int RED_BLINK_counter = 0;
int RED_BLINK_flag = 0;
void setTimer_for_RED_blink(int duration){
	RED_BLINK_counter = duration;
	RED_BLINK_flag = 0;
}

int GREEN_BLINK_counter = 0;
int GREEN_BLINK_flag = 0;
void setTimer_for_GREEN_blink(int duration){
	GREEN_BLINK_counter = duration;
	GREEN_BLINK_flag = 0;
}

int YELLOW_BLINK_counter = 0;
int YELLOW_BLINK_flag = 0;
void setTimer_for_YELLOW_blink(int duration){
	YELLOW_BLINK_counter = duration;
	YELLOW_BLINK_flag = 0;
}

//TimerRun for system
void timerRun(){
	if(counter1 > 0){
		counter1--;
	}
	if(counter1 <= 0){
		timer_flag1 = 1;
	}
	if(counter2 > 0){
		counter2--;
	}
	if(counter2 <= 0){
		timer_flag2 = 1;
	}
	if(counter3 > 0){
		counter3--;
	}
	if(counter3 <= 0){
		timer_flag3 = 1;
	}
	if(RED_BLINK_counter > 0){
		RED_BLINK_counter--;
	}
	if(RED_BLINK_counter <= 0){
		RED_BLINK_flag = 1;
	}
	if(YELLOW_BLINK_counter > 0){
		YELLOW_BLINK_counter--;
	}
	if(YELLOW_BLINK_counter <= 0){
		YELLOW_BLINK_flag = 1;
	}
	if(GREEN_BLINK_counter > 0){
		GREEN_BLINK_counter--;
	}
	if(GREEN_BLINK_counter <= 0){
		GREEN_BLINK_flag = 1;
	}
}

////Turn ALL LED
//void turnLEDOFF(void){
//	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);//tat den led 2
//	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);//tat den led 3
//	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);//tat den led 4
//	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);//tat den led 1
//}

