/***************************************************************************************************************
 *************************************
 * KPAD_Cfg.h                        *
 * Author    : AHMED ASHRY           *
 * DATE      : Sep 23, 2019          *
 * VERSION   : 001                   *
 *************************************
 ***************************************************************************************************************/

#ifndef KPAD_CFG_H_
#define KPAD_CFG_H_

/*******************************************************************************************************************
 * include(s)
 *******************************************************************************************************************/
#include "DIO.h"


/***************************************************************************************************************
 * definition(s)
 ***************************************************************************************************************/
#define NUM_OF_COL   (3u)
#define NUM_OF_ROW   (3u)


/***************************************************************************************************************
 * type definition(s)
 ***************************************************************************************************************/
typedef enum {
	COL_1 = PIN18,
	COL_2,
	COL_3
}enCOL_t;


typedef enum {
	ROW_1 = PIN21,
	ROW_2,
	ROW_3
}enROW_t;

#endif /* KPAD_CFG_H_ */