/*
 * scheduler_function.c
 *
 *  Created on: 20 thg 11, 2022
 *      Author: Lenovo
 */
#include "schedule_function.h"
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
sTask sub_for_Correct_Task;					//Sub variable for *TaskInput
static int numOfTaskNow = 0;




//Init the system tasks
void SCH_Init ( void )
{
unsigned char i ;
for ( i = 0; i < SCH_MAX_TASKS; i ++)
	{
		SCH_Delete_Task( i ) ;
	}
// Reset the global error variable
// âˆ’ SCH_Delete_Task () w ill generate an error code ,
// ( because the task array i s empty)
//	Error_code_G = 0;
//	Timer_init();
//	Watchdog_init () ;
}



//move everything to right
void moveToRight(int Start,int numOfTaskNow)
{
    for (int i = numOfTaskNow; i >= Start ;i--)
    {
        SCH_tasks_G[i+1]=SCH_tasks_G[i];
    }
}


//Correct the working order:
void correctOrder(sTask *TaskInput, int numOfTaskNow){
	  // nothing to compare
	    if(SCH_tasks_G[0].pTask==0)
	    {
	        SCH_tasks_G[0]=(*TaskInput);
	        return;
	    }

	    //less than first element
	    if((*TaskInput).Delay<=SCH_tasks_G[0].Delay)
	    {
	             sub_for_Correct_Task=*TaskInput;
	        //delete task to moveToRight
	        	(*TaskInput).pTask = 0x0000 ;
	        	(*TaskInput).Delay = 0;
	        	(*TaskInput).Period = 0;
	        	(*TaskInput).RunMe = 0;
	        moveToRight(0,numOfTaskNow);
	        SCH_tasks_G[0] = sub_for_Correct_Task;
	        if(SCH_tasks_G[1].pTask!=0)
	        {
	            SCH_tasks_G[1].Delay =SCH_tasks_G[1].Delay- SCH_tasks_G[0].Delay;
	        }
	        return;
	    }

	    //More than all elements
	    int sum_of_Delay = 0;
	    for(int i = 0; i < numOfTaskNow; i++){
	    	if(SCH_tasks_G[i].pTask != 0)
	    	{
	    	sum_of_Delay = sum_of_Delay + SCH_tasks_G[i].Delay;
	    	}
	    }
	    if((*TaskInput).Delay >= sum_of_Delay)
	    {
	    	SCH_tasks_G[numOfTaskNow].Delay = SCH_tasks_G[numOfTaskNow].Delay - sum_of_Delay;
	    return;
	    }

	    //Between 2 tasks
	    int previous_task_delay = 0;
	    int after_task_delay = 0;
	    for(int i = 0; i < numOfTaskNow; i++){
	    	if(i >= 1){
	    	previous_task_delay = previous_task_delay + SCH_tasks_G[i].Delay;
	    	}else
	    	{
	    	previous_task_delay = 0;
	    	}
	    	after_task_delay = after_task_delay + SCH_tasks_G[i+1].Delay;
	    	if(SCH_tasks_G[i].pTask != 0){
	    		if(((*TaskInput).Delay >= previous_task_delay)&&((*TaskInput).Delay <= after_task_delay))
		{
			sub_for_Correct_Task=*TaskInput;
			//delete task to moveToRight
				(*TaskInput).pTask = 0x0000 ;
				(*TaskInput).Delay = 0;
				(*TaskInput).Period = 0;
				(*TaskInput).RunMe = 0;
			moveToRight(i,numOfTaskNow);
			SCH_tasks_G[i]=sub_for_Correct_Task;
			SCH_tasks_G[i].Delay = SCH_tasks_G[i].Delay - previous_task_delay;
			if(SCH_tasks_G[i+1].pTask != 0)
			{
				SCH_tasks_G[i+1].Delay -= SCH_tasks_G[i].Delay;
			}
		return;
	     }
	    }
	 }
}

//Update function
void SCH_Update( void )
{
	if((SCH_tasks_G[0].Delay>0)&&(SCH_tasks_G[0].RunMe == 0))
	{
		SCH_tasks_G[0].Delay--;
	}

	if(SCH_tasks_G[0].Delay==0)
	{
		SCH_tasks_G[0].RunMe = 1;
		//delete task and set run me = 0 in another function
	}
}


////swap function for sort Process
//void swap_Index(sTask *a, sTask *b)
//{
//	sTask temp = *a;
//	*a = *b;
//	*b = temp;
//}




unsigned char SCH_Add_Task( void (* pFunction)() , unsigned int DELAY, unsigned int PERIOD)
{

	unsigned char Index = 0;
	// First find a gap in the array ( if there is one)
	while (( SCH_tasks_G[Index].pTask != 0) && (Index < SCH_MAX_TASKS))
	{
		Index++;
	}
	// let we know numOfTaskNow
	numOfTaskNow++;
	// If we're here , there is a space in the task array
	SCH_tasks_G[Index].pTask = pFunction ;
	SCH_tasks_G[Index].Delay = DELAY;
	SCH_tasks_G[Index].Period = PERIOD;
	SCH_tasks_G[Index].RunMe = 0;

	//correctDelay here
	correctOrder((&SCH_tasks_G[Index]), numOfTaskNow);
	// return position of task ( to allow later deletion )
	return Index ;
}


void SCH_Dispatch_Tasks( void )
{

	unsigned char Index ;
	// Dispatches ( runs ) the next task ( if one is ready )
//	for ( Index = 0; Index < 1; Index++) {
		if (SCH_tasks_G[0].RunMe > 0) {
			(* SCH_tasks_G[0].pTask) () ; // Run the task
			SCH_tasks_G[0].RunMe = 0; // Reset / reduce RunMe flag
			// Periodic tasks w ill automatically run again
			// âˆ’ if this is a â€™one shot â€™ task , remove it from the array
			if ( SCH_tasks_G[0].Period == 0)
			{
				SCH_Delete_Task(0);
			}
			if((SCH_tasks_G[0].Period>0)&&(SCH_tasks_G[0].Delay==0))
    		{
                sub_for_Correct_Task=SCH_tasks_G[0];
                SCH_Delete_Task(0);
                SCH_Add_Task(sub_for_Correct_Task.pTask,sub_for_Correct_Task.Period,sub_for_Correct_Task.Period);
    		}

		}
}

void SCH_Delete_Task( const int TASK_INDEX) //tByte here
{
	for (int i = TASK_INDEX;i<(numOfTaskNow);i++)
	    {
	        SCH_tasks_G[i]=SCH_tasks_G[i+1];
	    }
	    	SCH_tasks_G[numOfTaskNow].pTask = 0x0000 ;
	    	SCH_tasks_G[numOfTaskNow].Delay = 0;
	    	SCH_tasks_G[numOfTaskNow].Period = 0;
	    	SCH_tasks_G[numOfTaskNow].RunMe = 0;
	    	numOfTaskNow--;
}


////void SCH_Go_To_Sleep ()
//{
//	//todo : Optional
//}
//
//void SCH_Report_Status ( void )
//{
//#ifdef SCH_REPORT_ERRORS //if SCH_REPORT_ERRORS is defined already, then redefine it
//	// ONLY APPLIES IF WE ARE REPORTING ERRORS
//	// Check for a new error code
//	if ( Error_code_G != Last_error_code_G ) {
//		// Negative logic on LEDs assumed
//		Error_port = 255 Error_code_G ;
//		Last_error_code_G = Error_code_G ;
//		if ( Error_code_G != 0) {
//			Error_tick_count_G = 60000;
//		} else {
//			Error_tick_count_G = 0;
//		}
//	} else {
//		if ( Error_tick_count_G != 0) {
//			if (Error_tick_count_G == 0) {
//				Error_code_G = 0; // Reset error code
//			}
//		}
//	}
//#endif
//}
