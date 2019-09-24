/*
 * MACROS.h
 *
 *  Created on: Aug 17, 2019
 *      Author: Ashry
 */

#ifndef MACROS_H_
#define MACROS_H_

#define Set_Bit(Register,Bit)     (Register |= (1<<Bit))
#define Clear_Bit(Register,Bit)   (Register &= (~(1<<Bit)))
#define Toggle_Bit(Register,Bit)  (Register ^= (1<<Bit))
#define Get_Bit(Register,Bit)     ((Register>>Bit) & 1)

#endif /* MACROS_H_ */
