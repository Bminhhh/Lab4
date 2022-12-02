/*
 * fsm_change.h
 *
 *  Created on: Nov 16, 2022
 *      Author: Lenovo
 */

#ifndef INC_FSM_CHANGE_H_
#define INC_FSM_CHANGE_H_

#include "main.h"
#include "software_timer.h"
#include "seg7_display.h"

void fsm_Changed_SEG();
void updateClockBuffer(void);
//CHANGED MODE OF BLINK LED
void blink_RED();
void blink_GREEN();
void blink_YELLOW();
#endif /* INC_FSM_CHANGE_H_ */
