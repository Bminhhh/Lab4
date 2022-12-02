/*
 * schedule_function.h
 *
 *  Created on: Nov 20, 2022
 *      Author: Lenovo
 */

#ifndef INC_SCHEDULE_FUNCTION_H_
#define INC_SCHEDULE_FUNCTION_H_


#include "global.h"

void SCH_Init ( void );
void SCH_Update( void ) ;
unsigned char SCH_Add_Task( void (* pFunction)() , unsigned int DELAY, unsigned int PERIOD);
void SCH_Dispatch_Tasks( void );
void SCH_Delete_Task( const int TASK_INDEX) ;
void SCH_Go_To_Sleep () ;
void SCH_Report_Status ( void ) ;
void moveToRight();
void correctOrder();

#endif /* INC_SCHEDULE_FUNCTION_H_ */
