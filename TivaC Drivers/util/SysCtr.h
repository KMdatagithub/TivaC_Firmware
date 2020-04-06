/*
 * SysCtr.h
 *
 *  Created on: Apr 5, 2020
 *      Author: Khaled Magdy
 */

#ifndef UTIL_SYSCTR_H_
#define UTIL_SYSCTR_H_

#include "../common/std_types.h"

#define NUM_OF_PRIPHERALS      11

typedef enum{
    SysCLK_80MHz = 0,
    SysCLK_50MHz,
    SysCLK_40MHz,
    SysCLK_20MHz,
    SysCLK_16MHz,
    SysCLK_8MHz,
    SysCLK_4MHz,
}SysCtr_Clock;

void SysCtr_init(void);
void SysCtr_Privileged_Mode();
void SysCtr_User_Mode();
uint32_t Get_Fcpu(void);

#endif /* UTIL_SYSCTR_H_ */
