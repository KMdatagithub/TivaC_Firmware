/*
 * Software_Delay.c
 *
 *  Created on: Apr 5, 2020
 *      Author: Khaled Magdy
 */

#include "Software_Delay.h"

// These Functions Are Assuming An F_CPU = 80 MHZ .. So Modifications Can Be Made In The Future !!

void delay_ms(uint32_t ui32Ms)
{
   uint32_t i;
   while (ui32Ms > 0)
   {
       i = 13333;
       while (i > 0)
       {
           i--;
       }
       ui32Ms--;
  }
}

void delay_us(uint32_t ui32Us)
{
    uint32_t i;
    while (ui32Us > 0)
    {
       i = 13;
       while (i > 0)
       {
           i--;
       }
       ui32Us--;
    }
}
