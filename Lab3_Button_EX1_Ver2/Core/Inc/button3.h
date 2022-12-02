/*
 * button3.h
 *
 *  Created on: Nov 16, 2022
 *      Author: Lenovo
 */

#ifndef INC_BUTTON3_H_
#define INC_BUTTON3_H_

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET


extern int SET_FLAG;
int is_SET_PRESSED();
void get_key_Input3();

#endif /* INC_BUTTON3_H_ */
