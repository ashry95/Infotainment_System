/***************************************************************************************************************
 *************************************
 * Sos.h                             *
 * Author    : AHMED ASHRY           *
 * DATE      : Sep 16, 2019          *
 * VERSION   : 001                   *
 *************************************
 ***************************************************************************************************************/

/*******************************************************************************************************************
 * include(s)
 *******************************************************************************************************************/
#include "Sos.h"

/*******************************************************************************************************************
 * static global variable(s)
 *******************************************************************************************************************/
/* counter variable indicating OS tick */
static volatile uint32 Sos_u32TickCounter = 0;

/* Array of TCBs Grouping all System Tasks Control Blocks */
static StrTCB_t Sos_SystemTasks[NUM_OF_TASKS];


/*******************************************************************************************************************
 * ISR & static function prototype(s)
 *******************************************************************************************************************/
static void Sos_SetISR(void);


/*******************************************************************************************************************
 * ISR & static function definition(s)
 *******************************************************************************************************************/
static void Sos_SetISR(void)
{
	/* Declaration of isr Counter */
	uint8 isr_count;
	/* Update Tick Counter */
	Sos_u32TickCounter++;

	/* Looping all the system tasks */
	for(isr_count = 0 ; isr_count < NUM_OF_TASKS ; isr_count++)
	{
		/* Check Whether the Tick Counter Matches the Period of the Task to Be Called */
		if((Sos_SystemTasks[isr_count].State == Sos_TASK_WAITING)
				&& (!((Sos_u32TickCounter % Sos_SystemTasks[isr_count].Periodicity))))
		{
			/* update task state */
			Sos_SystemTasks[isr_count].State = Sos_TASK_READY;
		}
	}
}

/*******************************************************************************************************************
 * shared function definition(s)
 *******************************************************************************************************************/
/*..................................................................................
 * name:                Sos_Init
 * description:         Function to Initialize OS
 * sync/async:          synchronous
 * reentrancy:          reentrant
 * parameters (in):     none
 * parameters (in/out): none
 * parameters (out):    none
 * return:              none
 * remarks:             none
 * example:             none
 *..................................................................................*/
void Sos_Init(void)
{
	/* Initialize timer 0 */
	TIM0_Init(CTC,PreScaler64);
	/* enable timer 0 interrupt */
	TIM0_IntEnable(CTC);
	/* Set ISR callback */
	TIM0_CTCISRCallBack(Sos_SetISR);
	/* Initialize tick counter */
	Sos_u32TickCounter = 0;
}


/*..................................................................................
 * name:                Sos_Deinit
 * description:         Function to disable OS
 * sync/async:          synchronous
 * reentrancy:          reentrant
 * parameters (in):     none
 * parameters (in/out): none
 * parameters (out):    none
 * return:              none
 * remarks:             none
 * example:             none
 *..................................................................................*/
extern void Sos_Deinit(void)
{
	TIM0_Deinit();
}

/*..................................................................................
 * name:                Sos_Run
 * description:         Function to start OS
 * sync/async:          synchronous
 * reentrancy:          reentrant
 * parameters (in):     none
 * parameters (in/out): none
 * parameters (out):    none
 * return:              none
 * remarks:             none
 * example:             none
 *..................................................................................*/
void Sos_Run(void)
{
	/* Declaration of Tasks Scheduling Counter */
	uint8 SchedulerCounter;

	while(1)
	{
		/* Tasks Scheduling Loop */
		for(SchedulerCounter = 0 ; SchedulerCounter < NUM_OF_TASKS ; SchedulerCounter++)
		{
			/* Check Whether the Tick Counter Matches the Period of the Task to Be Called */
			if((Sos_SystemTasks[SchedulerCounter].State == Sos_TASK_READY)
					/* check if task is deleted */
					&& (Sos_SystemTasks[SchedulerCounter].TaskHandler != ((void*)0)))
			{
				/* Changg the task state to running */
				Sos_SystemTasks[SchedulerCounter].State = Sos_TASK_RUNNING;
				/* Call Desired Task's Handler Function */
				Sos_SystemTasks[SchedulerCounter].TaskHandler();
				/* Change back the task state to waiting */
				Sos_SystemTasks[SchedulerCounter].State = Sos_TASK_WAITING;
			}
		}
	}
}

/*..................................................................................
 * name:                Sos_CreateTask
 * description:         Function to Create a new OS Task
 * sync/async:          synchronous
 * reentrancy:          reentrant
 * parameters (in):     CopyTaskHandler : Pinter to task address
 * 						Periodicity : Task Period
 * 						Priority : Task priority
 * parameters (in/out): none
 * parameters (out):    none
 * return:              none
 * remarks:             none
 * example:             none
 *..................................................................................*/
void Sos_CreateTask(void (*TaskHandler)(void) , uint16 Periodicity , uint8 Priority)
{
	/* Set Task's Handler Function */
	Sos_SystemTasks[Priority].TaskHandler = TaskHandler;
	/* Set Task's Periodicity */
	Sos_SystemTasks[Priority].Periodicity = Periodicity;
	/* Set Task's Priority */
	Sos_SystemTasks[Priority].Priority = Priority;
	/* Set Task's State Initially to be Ready */
	Sos_SystemTasks[Priority].State = Sos_TASK_READY;
}

/*..................................................................................
 * name:                Sos_DeleteTask
 * description:         Function to Delete a specific OS Task
 * sync/async:          synchronous
 * reentrancy:          reentrant
 * parameters (in):     Priority : Unique task parameter, passed to function
 * 								   to specify the task to be deleted
 * parameters (in/out): none
 * parameters (out):    none
 * return:              none
 * remarks:             none
 * example:             none
 *..................................................................................*/
void Sos_DeleteTask(uint8 Priority)
{
	/* Delete task from array of system tasks */
	Sos_SystemTasks[Priority].TaskHandler = ((void*)0);
}
