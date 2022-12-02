/*
 * button.h
 *
 *  Created on: Nov 8, 2022
 *      Author: Lenovo
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

extern int SELECT_FLAG;
int is_SELECT_PRESSED();
void get_key_Input();

#endif /* INC_BUTTON_H_ */
