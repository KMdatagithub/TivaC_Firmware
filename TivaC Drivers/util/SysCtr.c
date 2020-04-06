/*
 * SysCtr.c
 *
 *  Created on: Apr 5, 2020
 *      Author: Khaled Magdy
 */

#include "../common/registers.h"
#include "SysCtr.h"

extern bool CfgArr[];
extern SysCtr_Clock MySys_CLK;


static void Set_SysCLK(void)
{
    // Enable USERCC2 in RCC2
    SYSCTL_RCC2_R |= 0x80000000; // RCC2[31]=USERCC2
    // Bypass PLL while initializing
    SYSCTL_RCC2_R |= 0x00000800; // RCC2[11]=BYPASS2
    // Set external crystal value and oscillator source for PLL
    SYSCTL_RCC_R = (SYSCTL_RCC_R & ~0x000007C0) + (0x15 << 6);
    SYSCTL_RCC2_R &= ~0x00000070;
    // Clear PWRDN to active PLL
    // RCC2[13]=PWRDN 0:The PLL operate normally
    SYSCTL_RCC2_R &= ~0x00002000;
    // Set system clock
    // RCC2[30]=DIV400 Select 400MHz(from PLL)
    SYSCTL_RCC2_R |= 0x40000000;

    switch(MySys_CLK)
    {
        case SysCLK_80MHz:
        {
            SYSCTL_RCC2_R = (SYSCTL_RCC2_R & ~0x1FC00000) + (0x04 << 22);
            break;
        }
        case SysCLK_50MHz:
        {
            SYSCTL_RCC2_R = (SYSCTL_RCC2_R & ~0x1FC00000) + (0x07 << 22);
            break;
        }
        case SysCLK_40MHz:
        {
            SYSCTL_RCC2_R = (SYSCTL_RCC2_R & ~0x1FC00000) + (0x09 << 22);
            break;
        }
        case SysCLK_20MHz:
        {
            SYSCTL_RCC2_R = (SYSCTL_RCC2_R & ~0x1FC00000) + (0x13 << 22);
            break;
        }
        case SysCLK_16MHz:
        {
            SYSCTL_RCC2_R = (SYSCTL_RCC2_R & ~0x1FC00000) + (0x18 << 22);
            break;
        }
        case SysCLK_8MHz:
        {
            SYSCTL_RCC2_R = (SYSCTL_RCC2_R & ~0x1FC00000) + (0x31 << 22);
            break;
        }
        case SysCLK_4MHz:
        {
            SYSCTL_RCC2_R = (SYSCTL_RCC2_R & ~0x1FC00000) + (0x63 << 22);
            break;
        }
        default:
            break;
    };

    // Wait for PLL to lock by polling PLLLRIS
    while( (SYSCTL_RIS_R & 0x00000040) == 0);
    // Set BYPASS to 0, select PLL as the source of system clock
    SYSCTL_RCC2_R &= ~0x00000800;
}


void SysCtr_init(void)
{
    uint8_t i = ZERO;

    /* Set The Desired System Clock For F_CPU */
    Set_SysCLK();

    /*TODO: Enable Clock Gates */
    for(i=0; i <NUM_OF_PRIPHERALS ;i++)
    {
        //RegisterIndex = f(i)
        //BitIndex = f(i)
        //assign_bit(RegisterAddress,BitIndex, CfgArr[i]);
    }

}


uint32_t Get_Fcpu(void)
{
    uint32_t F_CPU = 0x00;
    switch(MySys_CLK)
    {
        case SysCLK_80MHz:
        {
            F_CPU = 80000000UL;
            break;
        }
        case SysCLK_50MHz:
        {
            F_CPU = 50000000UL;
            break;
        }
        case SysCLK_40MHz:
        {
            F_CPU = 40000000UL;
            break;
        }
        case SysCLK_20MHz:
        {
            F_CPU = 20000000UL;
            break;
        }
        case SysCLK_16MHz:
        {
            F_CPU = 16000000UL;
            break;
        }
        case SysCLK_8MHz:
        {
            F_CPU = 8000000UL;
            break;
        }
        case SysCLK_4MHz:
        {
            F_CPU = 4000000UL;
            break;
        }
        default:
            break;
    };
    return F_CPU;
}
