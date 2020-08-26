/******************************************************/
/* Author   : Romario Basem                           */
/* Date     : 25 AUG 2020                             */
/* Version  : V01                                     */
/******************************************************/
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H


/* Buses */
#typedef enum
{
 RCC_AHB
 RCC_APB1
 RCC_APB2
} BUS ;

/* Register Definitions */
#define RCC_CR         *((u32*)0x40021000)
#define RCC_CFGR       *((u32*)0x40021004)
#define RCC_CIR        *((u32*)0x40021008)
#define RCC_APB2RSTR   *((u32*)0x4002100C)
#define RCC_APB1RSTR   *((u32*)0x40021010)
#define RCC_AHBENR     *((u32*)0x40021014)
#define RCC_APB2ENR    *((u32*)0x40021018)
#define RCC_APB1ENR    *((u32*)0x4002101C)
#define RCC_BDCR       *((u32*)0x40021020)
#define RCC_CSR        *((u32*)0x40021024)

/* clock types */
#define RCC_HSE_CRYSTAL      0
#define RCC_HSE_RC           1
#define RCC_HSI              2
#define RCC_PLL              3

/* PLL Options */
#define RCC_PLL_HSI_DIV_2  0
#define RCC_PLL_HSE_DIV_2  1
#define RCC_PLL_HSE        2

void RCC_voidInitSysClock(void);
void RCC_voidEnableClock (BUS Copy_BUSBus,u8 Copy_u8ID );
void RCC_voidDisableClock (BUS Copy_BUSBus,u8 Copy_u8ID );



#endif

