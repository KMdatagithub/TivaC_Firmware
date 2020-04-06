/*
 * std_types.h
 *
 *  Created on: Apr 5, 2020
 *      Author: Khaled Magdy
 */

#ifndef COMMON_STD_TYPES_H_
#define COMMON_STD_TYPES_H_

/************************************************************************/
/*                   typedefs for standard types                        */
/************************************************************************/

#define     NULL                        ((void *)0)
typedef     unsigned char               uint8_t;
typedef     unsigned int                uint16_t;
typedef     unsigned long int           uint32_t;
typedef     unsigned long long          uint64_t;
typedef     signed char                 sint8_t;
typedef     signed int                  sint16_t;
typedef     signed long int             sint32_t;
typedef     signed long long            sint64_t;
typedef     volatile uint8_t* const     reg_type8_t;
typedef     volatile uint16_t* const    reg_type16_t;
typedef     void (*FunPtr)(void);


/************************************************************************/
/*                      defining boolean values                         */
/************************************************************************/

typedef uint8_t bool;

#define FALSE       0   // defines boolean false
#define TRUE        1   // defines boolean true

#define ENABLED     1
#define DISABLED    0


/************************************************************************/
/*                       LOW/HIGH defines                               */
/************************************************************************/

#define LOW  0x00   // defines LOW value for a bit
#define HIGH 0xFF   // defines HIGH value for a bit
#define ZERO 0


/************************************************************************/
/*                   Bit Manipulation Macro defines                     */
/************************************************************************/

#define SET_BIT(r, b)                    (r |=  ((uint32_t)1<<b))
#define CLEAR_BIT(r, b)                  (r &= ~((uint32_t)1<<b))
#define TOGGLE_BIT(r, b)                 (r)^=(uint32_t)(b)
#define GET_BIT(r, b)                    (((r)>>(b))&(uint32_t)1)
#define GET_REG(BASE_ADDR, REG_OFFSET)   (*((volatile uint32_t*)(BASE_ADDR+REG_OFFSET)))

/************************************************************************/
/*                       defining error status                          */
/************************************************************************/

#define ERROR_STATUS    uint16_t
#define E_OK            0
#define E_NOK           1

/************************************************************************/
/*                          Bit Masks defines                           */
/************************************************************************/

#define BIT0   0x00000001
#define BIT1   0x00000002
#define BIT2   0x00000004
#define BIT3   0x00000008
#define BIT4   0x00000010
#define BIT5   0x00000020
#define BIT6   0x00000040
#define BIT7   0x00000080

#define BIT8   0x00000100
#define BIT9   0x00000200
#define BIT10  0x00000400
#define BIT11  0x00000800
#define BIT12  0x00001000
#define BIT13  0x00002000
#define BIT14  0x00004000
#define BIT15  0x00008000

#define BIT16  0x00010000
#define BIT17  0x00020000
#define BIT18  0x00040000
#define BIT19  0x00080000
#define BIT20  0x00100000
#define BIT21  0x00200000
#define BIT22  0x00400000
#define BIT23  0x00800000

#define BIT24  0x01000000
#define BIT25  0x02000000
#define BIT26  0x04000000
#define BIT27  0x08000000
#define BIT28  0x10000000
#define BIT29  0x20000000
#define BIT30  0x40000000
#define BIT31  0x80000000


#endif /* COMMON_STD_TYPES_H_ */
