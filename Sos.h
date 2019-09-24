/***************************************************************************************************************
 *************************************
 * Sos.h                             *
 * Author    : AHMED ASHRY           *
 * DATE      : Sep 16, 2019          *
 * VERSION   : 001                   *
 *************************************
 ***************************************************************************************************************/

/***************************************************************************************************************
*  HEADER FILE GUARDIAN
****************************************************************************************************************/
#ifndef SOS_H_
#define SOS_H_


/***************************************************************************************************************
 * include(s)
 ***************************************************************************************************************/
#include "TIM0.h"
#include "STD_TYPES.h"


/***************************************************************************************************************
 * definition(s)
 ***************************************************************************************************************/
#define NUM_OF_TASKS      (3)
#define TICK_TIME_us      (1000)


/***************************************************************************************************************
 * type definition(s)
 ***************************************************************************************************************/
/* Create A New Enum Data Type Holds Tasks States */
typedef enum
{
	Sos_TASK_DELETED,
	Sos_TASK_WAITING,
	Sos_TASK_READY,
	Sos_TASK_RUNNING
}enTASK_STATE_t;

/* Create A New Struct Data Type Holds Tasks Control Block */
typedef struct
{
	void (*TaskHandler)(void);
	uint16 Periodicity;
    uint8  Priority;
    enTASK_STATE_t State;
}StrTCB_t;


/***************************************************************************************************************
 * external function prototype(s)
 ***************************************************************************************************************/
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
extern void Sos_Init(void);

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
extern void Sos_Deinit(void);

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
extern void Sos_Run(void);

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
extern void Sos_CreateTask(void (*TaskHandler)(void),
        					uint16 Periodicity,
							uint8  Priority);

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
extern void Sos_DeleteTask(uint8 Priority);


#endif /* SOS_H_ */
