/*
 * button2.h
 *
 *  Created on: Nov 16, 2022
 *      Author: Lenovo
 */

#ifndef INC_BUTTON2_H_
#define INC_BUTTON2_H_

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

extern int MODIFY_FLAG;
void get_key_Input2();
int is_MODIFY_PRESSED();

#endif /* INC_BUTTON2_H_ */
