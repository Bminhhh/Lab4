/*
 * global.h
 *
 *  Created on: Nov 6, 2022
 *      Author: Lenovo
 */

#include <button2.h>
#include "button.h"
#include "button3.h"
#include "main.h"
#include "software_timer.h"

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define NORMAL_MODE 0
#define RED_LED_MODIFY 1
#define PURPLE_LED_MODIFY 2
#define GREEN_LED_MODIFY 3


//Modes in change after press SELECT button
#define MODE1 11
#define MODE2 12
#define MODE3 13

extern int mode;
extern int ex;

#endif /* INC_GLOBAL_H_ */
