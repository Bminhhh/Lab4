/*
 * software_timer.h
 *
 *  Created on: Nov 6, 2022
 *      Author: Lenovo
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_
#include "main.h"




//INIT Flag variables:
extern int timer_flag1;
extern int timer_flag2;
extern int timer_flag3;


//extern int timer_7seg2;
extern int i;

extern int flag_BLINK;


//Init hàm Timer cho flag
void timerRun(void);



//void timerRun_7seg(void);

//Init setTimer for System
void setTimer1(int timer1);
void setTimer2(int timer2);
void setTimer3(int timer3);

//set Timer for LED blink
void setTimer_for_RED_blink();
void setTimer_for_GREEN_blink();
void setTimer_for_YELLOW_blink();

//EXTERN VARIABLE FOR BLINK LED
extern int RED_BLINK_flag;
extern int YELLOW_BLINK_flag;
extern int GREEN_BLINK_flag;




;
//void turnLEDOFF(void);
//
////void clockRun(void);





#endif /* INC_SOFTWARE_TIMER_H_ */
