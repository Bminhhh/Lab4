/*
 * seg7_display.c
 *
 *  Created on: Nov 14, 2022
 *      Author: Lenovo
 */


#include "seg7_display.h"
#include "main.h"
//variables for 7SEG

int seg_buffer1[3]={5,3,2};
//int seg_buffer2[10]={0,1,2,3,4,5,6,7,8,9};
int num1 = 0;
int num2 = 1;
int seg_index1;
int seg_index2;
int seg_index3;
int seg_index4;

int seg = 0;

//int seg_buffer[10] = {0,1,2,3,4,5,6,7,8,9};

//7SEG display
//segment case
void zero()
{
	HAL_GPIO_WritePin(PB0_GPIO_Port, PB0_Pin, RESET);
	HAL_GPIO_WritePin(PB1_GPIO_Port, PB1_Pin, RESET);
	HAL_GPIO_WritePin(PB2_GPIO_Port, PB2_Pin, RESET);
	HAL_GPIO_WritePin(PB3_GPIO_Port, PB3_Pin, RESET);
	HAL_GPIO_WritePin(PB4_GPIO_Port, PB4_Pin, RESET);
	HAL_GPIO_WritePin(PB5_GPIO_Port, PB5_Pin, RESET);
	HAL_GPIO_WritePin(PB6_GPIO_Port, PB6_Pin, SET);
	return;
}


void one()
{
	HAL_GPIO_WritePin(PB0_GPIO_Port, PB0_Pin, SET);
	HAL_GPIO_WritePin(PB1_GPIO_Port, PB1_Pin, RESET);
	HAL_GPIO_WritePin(PB2_GPIO_Port, PB2_Pin, RESET);
	HAL_GPIO_WritePin(PB3_GPIO_Port, PB3_Pin, SET);
	HAL_GPIO_WritePin(PB4_GPIO_Port, PB4_Pin, SET);
	HAL_GPIO_WritePin(PB5_GPIO_Port, PB5_Pin, SET);
	HAL_GPIO_WritePin(PB6_GPIO_Port, PB6_Pin, SET);
	return;
}

void two()
{
	HAL_GPIO_WritePin(PB0_GPIO_Port, PB0_Pin, RESET);
	HAL_GPIO_WritePin(PB1_GPIO_Port, PB1_Pin, RESET);
	HAL_GPIO_WritePin(PB2_GPIO_Port, PB2_Pin, SET);
	HAL_GPIO_WritePin(PB3_GPIO_Port, PB3_Pin, RESET);
	HAL_GPIO_WritePin(PB4_GPIO_Port, PB4_Pin, RESET);
	HAL_GPIO_WritePin(PB5_GPIO_Port, PB5_Pin, SET);
	HAL_GPIO_WritePin(PB6_GPIO_Port, PB6_Pin, RESET);
	return;
}

void three()
{
	HAL_GPIO_WritePin(PB0_GPIO_Port, PB0_Pin, RESET);
	HAL_GPIO_WritePin(PB1_GPIO_Port, PB1_Pin, RESET);
	HAL_GPIO_WritePin(PB2_GPIO_Port, PB2_Pin, RESET);
	HAL_GPIO_WritePin(PB3_GPIO_Port, PB3_Pin, RESET);
	HAL_GPIO_WritePin(PB4_GPIO_Port, PB4_Pin, SET);
	HAL_GPIO_WritePin(PB5_GPIO_Port, PB5_Pin, SET);
	HAL_GPIO_WritePin(PB6_GPIO_Port, PB6_Pin, RESET);
	return;
}

void four()
{
	HAL_GPIO_WritePin(PB0_GPIO_Port, PB0_Pin, SET);
	HAL_GPIO_WritePin(PB1_GPIO_Port, PB1_Pin, RESET);
	HAL_GPIO_WritePin(PB2_GPIO_Port, PB2_Pin, RESET);
	HAL_GPIO_WritePin(PB3_GPIO_Port, PB3_Pin, SET);
	HAL_GPIO_WritePin(PB4_GPIO_Port, PB4_Pin, SET);
	HAL_GPIO_WritePin(PB5_GPIO_Port, PB5_Pin, RESET);
	HAL_GPIO_WritePin(PB6_GPIO_Port, PB6_Pin, RESET);
	return;
}


void five()
{
	HAL_GPIO_WritePin(PB0_GPIO_Port, PB0_Pin, RESET);
	HAL_GPIO_WritePin(PB1_GPIO_Port, PB1_Pin, SET);
	HAL_GPIO_WritePin(PB2_GPIO_Port, PB2_Pin, RESET);
	HAL_GPIO_WritePin(PB3_GPIO_Port, PB3_Pin, RESET);
	HAL_GPIO_WritePin(PB4_GPIO_Port, PB4_Pin, SET);
	HAL_GPIO_WritePin(PB5_GPIO_Port, PB5_Pin, RESET);
	HAL_GPIO_WritePin(PB6_GPIO_Port, PB6_Pin, RESET);
	return;
}

void six()
{
	HAL_GPIO_WritePin(PB0_GPIO_Port, PB0_Pin, RESET);
	HAL_GPIO_WritePin(PB1_GPIO_Port, PB1_Pin, SET);
	HAL_GPIO_WritePin(PB2_GPIO_Port, PB2_Pin, RESET);
	HAL_GPIO_WritePin(PB3_GPIO_Port, PB3_Pin, RESET);
	HAL_GPIO_WritePin(PB4_GPIO_Port, PB4_Pin, RESET);
	HAL_GPIO_WritePin(PB5_GPIO_Port, PB5_Pin, RESET);
	HAL_GPIO_WritePin(PB6_GPIO_Port, PB6_Pin, RESET);
	return;
}

void seven()
{
	HAL_GPIO_WritePin(PB0_GPIO_Port, PB0_Pin, RESET);
	HAL_GPIO_WritePin(PB1_GPIO_Port, PB1_Pin, RESET);
	HAL_GPIO_WritePin(PB2_GPIO_Port, PB2_Pin, RESET);
	HAL_GPIO_WritePin(PB3_GPIO_Port, PB3_Pin, SET);
	HAL_GPIO_WritePin(PB4_GPIO_Port, PB4_Pin, SET);
	HAL_GPIO_WritePin(PB5_GPIO_Port, PB5_Pin, SET);
	HAL_GPIO_WritePin(PB6_GPIO_Port, PB6_Pin, SET);
	return;
}


void eight()
{
	HAL_GPIO_WritePin(PB0_GPIO_Port, PB0_Pin, RESET);
	HAL_GPIO_WritePin(PB1_GPIO_Port, PB1_Pin, RESET);
	HAL_GPIO_WritePin(PB2_GPIO_Port, PB2_Pin, RESET);
	HAL_GPIO_WritePin(PB3_GPIO_Port, PB3_Pin, RESET);
	HAL_GPIO_WritePin(PB4_GPIO_Port, PB4_Pin, RESET);
	HAL_GPIO_WritePin(PB5_GPIO_Port, PB5_Pin, RESET);
	HAL_GPIO_WritePin(PB6_GPIO_Port, PB6_Pin, RESET);
	return;
}

void nine()
{
	HAL_GPIO_WritePin(PB0_GPIO_Port, PB0_Pin, RESET);
	HAL_GPIO_WritePin(PB1_GPIO_Port, PB1_Pin, RESET);
	HAL_GPIO_WritePin(PB2_GPIO_Port, PB2_Pin, RESET);
	HAL_GPIO_WritePin(PB3_GPIO_Port, PB3_Pin, RESET);
	HAL_GPIO_WritePin(PB4_GPIO_Port, PB4_Pin, SET);
	HAL_GPIO_WritePin(PB5_GPIO_Port, PB5_Pin, RESET);
	HAL_GPIO_WritePin(PB6_GPIO_Port, PB6_Pin, RESET);
	return;
}


//display7SEG
void display7SEG1(int num){
	switch (num)
		{
		case 0:
			zero();
				break;
		case 1:
			one();
				break;
		case 2:
			two();
				break;
		case 3:
			three();
				break;
		case 4:
			four();
				break;
		case 5:
			five();
				break;
		case 6:
			six();
				break;
		case 7:
			seven();
				break;
		case 8:
			eight();
				break;
		case 9:
			nine();
				break;
		default:
				break;
		}
		return;
	}


//Turn ALL LED
void turnLEDOFF(void){
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);//tat den led 2
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);//tat den led 3
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);//tat den led 4
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);//tat den led 1

}



//change_7SEG_status in NORMAL_MODE

void SEG7_NORMAL_MODE(int seg){
	switch(seg){
	case 0:
		turnLEDOFF();
		display7SEG1(seg_index1);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
//		clockRun();
		break;
	case 1:
		turnLEDOFF();
		display7SEG1(seg_index2);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);
		break;
	case 2:
		turnLEDOFF();
		display7SEG1(seg_index3);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 0);
		break;
	case 3:
		turnLEDOFF();
		display7SEG1(seg_index4);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 0);
		break;
	default:
		break;
	}
	return;
}


////CHanged modes seg
//void SEG7_CHANGED_MODE(int seg){
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

void to_do_7SEG(){
	if(timer_flag3 == 1){
	  setTimer3(25);
	  SEG7_NORMAL_MODE(seg);
	  seg = (seg+1)%4;
	}
}
