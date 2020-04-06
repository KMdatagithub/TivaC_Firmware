/*
 * SysCtr_lcfg.c
 *
 *  Created on: Apr 6, 2020
 *      Author: Khaled Magdy
 */

#include "../common/std_types.h"
#include "SysCtr.h"

SysCtr_Clock MySys_CLK = SysCLK_8MHz;

/* Clock Gates */

bool CfgArr[NUM_OF_PRIPHERALS] =
{
    /*GpioA  */   ENABLED,
    /*GpioB  */   DISABLED,
    /*GpioC  */   ENABLED,
    /*GpioD  */   DISABLED,
    /*GpioE  */   ENABLED,
    /*GpioF  */   ENABLED,
    /*TIMER0 */   DISABLED,
    /*TIMER1 */   DISABLED,
    /*TIMER2 */   DISABLED,
    /*TIMER3 */   DISABLED,
    /*TIMER4 */   ENABLED
};
