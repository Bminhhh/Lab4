/*
 * seg7_display.h
 *
 *  Created on: Nov 14, 2022
 *      Author: Lenovo
 */

#ifndef SEG7_DISPLAY_H_
#define SEG7_DISPLAY_H_

#include "main.h"
#include "software_timer.h"
#include "fsm_change.h"


extern int seg_index1;
extern int seg_index2;
extern int seg_index3;
extern int seg_index4;
extern int seg;
extern int seg2;

extern int seg_buffer1[3];
extern int seg_buffer2[10];
extern int num1;
extern int num2;


//Segment led components
void zero();
void one();
void two();
void three();
void four();
void five();
void six();
void seven();
void eight();
void nine();

//Segment cases:
void display7SEG1(int num1);
//void display7SEG2(int num2);
void SEG7_NORMAL_MODE(int seg);
void turnLEDOFF(void);
void start7SEG();

//void clockRun(void);

#endif /* SEG7_DISPLAY_H_ */
