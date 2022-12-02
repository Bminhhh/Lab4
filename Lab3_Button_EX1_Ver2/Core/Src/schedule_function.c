/*
 * scheduler_function.c
 *
 *  Created on: 20 thg 11, 2022
 *      Author: Lenovo
 */
#include "schedule_function.h"
#include "stdint.h"
unsigned char Error_code_G = 0;// for 2.3.9
enum ErrorCode
{
	ERROR_SCH_TOO_MANY_TASKS,
	ERROR_SCH_WAITING_FOR_SLAVE_TO_ACK,
	ERROR_SCH_WAITING_FOR_START_COMMAND_FROM_MASTER,
	ERROR_SCH_ONE_OR_MORE_SLAVES_DID_NOT_START,
	ERROR_SCH_LOST_SLAVE,
	ERROR_SCH_CAN_BUS_ERROR,
	ERROR_I2C_WRITE_BYTE_AT24C64,
	ERROR_SCH_CANNOT_DELETE_TASK,
	RETURN_ERROR,
	RETURN_NORMAL,
};

typedef struct
{
	// Pointer to the task (must be a â€™ void ( void ) â€™ function )
	void ( * pTask) ( void ) ;
	// Delay ( ticks ) until the function will ( next ) be run
	uint32_t Delay ;
	// Interval ( ticks ) between subsequent runs .
	uint32_t Period ;
	// Incremented ( by scheduler ) when task is due to execute
	uint8_t RunMe;
	// This i s a hint to solve the question below .
	uint32_t TaskID ;
} sTask ;

// MUST BE ADJUSTED FOR EACH NEW PROJECT
#define SCH_MAX_TASKS 40
#define NO_TASK_ID 0
sTask SCH_tasks_G[SCH_MAX_TASKS];





void SCH_Update( void )
{
unsigned char Index ;
// NOTE: calculations are in *TICKS* ( not milliseconds )
for ( Index = 0; Index < SCH_MAX_TASKS; Index++)
	{
// Check i f there i s a task at this location
	if (SCH_tasks_G[Index].pTask)//if pTask != 0 then run
		{
		if ( SCH_tasks_G[Index].Delay == 0)
			{
				// The task is due to run
				// Inc the â€™RunMeâ€™ flag
				SCH_tasks_G[Index].RunMe += 1;//flag
				if (SCH_tasks_G[Index].Period) //if Period != 0 then run
					{
						// Schedule periodic tasks to run again
						SCH_tasks_G[Index].Delay = SCH_tasks_G[Index].Period ;
					}
			} else {
						// Not yet ready to run : just decrement the delay
						SCH_tasks_G[Index].Delay -=1;
					}
		}
	}
}


//swap function for sort Process
void swap_Index(sTask *a, sTask *b)
{
	sTask temp = *a;
	*a = *b;
	*b = temp;
}

//Reorder the index task with proper period value
void sort_Task(sTask arr[])
{
	for(int N = 0; N < SCH_MAX_TASKS; N++){
		for(int i = 0; i < SCH_MAX_TASKS-1; i++){
			if(SCH_tasks_G[i].Delay > SCH_tasks_G[i+1].Delay){
				swap_Index(&(SCH_tasks_G[i]), &(SCH_tasks_G[i+1]));
			}
		}
	}
	int sum_Task_Delay = 0;
	for(int u = 0; u < SCH_MAX_TASKS; u++){
		sum_Task_Delay = sum_Task_Delay + SCH_tasks_G[u].Delay;
		SCH_tasks_G[u+1].Delay=SCH_tasks_G[u+1].Delay-sum_Task_Delay;

	}
}


void SCH_Init ( void )
{
unsigned char i ;
for ( i = 0; i < SCH_MAX_TASKS; i ++)
	{
		sort_Task(SCH_tasks_G);
		SCH_Delete_Task( i ) ;
	}
// Reset the global error variable
// âˆ’ SCH_Delete_Task () w ill generate an error code ,
// ( because the task array i s empty)
//	Error_code_G = 0;
//	Timer_init();
//	Watchdog_init () ;
}



unsigned char SCH_Add_Task( void (* pFunction)() , unsigned int DELAY, unsigned int PERIOD)
{

	unsigned char Index = 0;
	// First find a gap in the array ( if there is one)
	while (( SCH_tasks_G[Index].pTask != 0) && (Index < SCH_MAX_TASKS))
	{
		Index++;
	}

	// Have we reached the end of the list ?
	if ( Index == SCH_MAX_TASKS)
	{
		// Task list is full
		// Set the global error variable
		Error_code_G = ERROR_SCH_TOO_MANY_TASKS;
		// Also return an error code
		return SCH_MAX_TASKS;
	}
	// If we're here , there is a space in the task array
	SCH_tasks_G[Index].pTask = pFunction ;
	SCH_tasks_G[Index].Delay = DELAY;
	SCH_tasks_G[Index].Period = PERIOD;
	SCH_tasks_G[Index].RunMe = 0;
	// return position of task ( to allow later deletion )
	return Index ;
}


void SCH_Dispatch_Tasks( void )
{

	unsigned char Index ;
	// Dispatches ( runs ) the next task ( if one is ready )
	for ( Index = 0; Index < SCH_MAX_TASKS; Index++) {

		if (SCH_tasks_G[Index].RunMe > 0) {
			(* SCH_tasks_G[Index].pTask) () ; // Run the task
			SCH_tasks_G[Index].RunMe -= 1; // Reset / reduce RunMe flag
			// Periodic tasks w ill automatically run again
			// âˆ’ if this is a â€™one shot â€™ task , remove it from the array
			if ( SCH_tasks_G[Index].Period == 0)
			{
				SCH_Delete_Task(Index);
				sort_Task(SCH_tasks_G);
			}
		}
	}
	// Report system status
	SCH_Report_Status () ;
	// The scheduler enters idle mode at thi s point
	SCH_Go_To_Sleep() ;
}

unsigned char SCH_Delete_Task( const int TASK_INDEX) //tByte here
{
	unsigned char Return_code ;
		if ( SCH_tasks_G[TASK_INDEX ] . pTask == 0) {
			// No task at thi s location . . .
			//
			// Set the global error variable
			Error_code_G = ERROR_SCH_CANNOT_DELETE_TASK;
			// . . . also return an error code
			Return_code = RETURN_ERROR;
			} else {
				Return_code = RETURN_NORMAL;
			}
			SCH_tasks_G[TASK_INDEX].pTask = 0x0000 ;
			SCH_tasks_G[TASK_INDEX].Delay = 0;
			SCH_tasks_G[TASK_INDEX].Period = 0;
			SCH_tasks_G[TASK_INDEX].RunMe = 0;
			return Return_code ; // return status
}


void SCH_Go_To_Sleep ()
{
	//todo : Optional
}

void SCH_Report_Status ( void )
{
#ifdef SCH_REPORT_ERRORS //if SCH_REPORT_ERRORS is defined already, then redefine it
	// ONLY APPLIES IF WE ARE REPORTING ERRORS
	// Check for a new error code
	if ( Error_code_G != Last_error_code_G ) {
		// Negative logic on LEDs assumed
		Error_port = 255 âˆ’ Error_code_G ;
		Last_error_code_G = Error_code_G ;
		if ( Error_code_G != 0) {
			Error_tick_count_G = 60000;
		} else {
			Error_tick_count_G = 0;
		}
	} else {
		if ( Error_tick_count_G != 0) {
			if (âˆ’âˆ’Error_tick_count_G == 0) {
				Error_code_G = 0; // Reset error code
			}
		}
	}
#endif
}
