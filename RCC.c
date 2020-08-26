/******************************************************/
/* Author   : Romario Basem                           */
/* Date     : 25 AUG 2020                             */
/* Version  : V01                                     */
/******************************************************/
#include "STD_TYPE.h"
#include "MATH_BIT.h"

#include "RCC.h"


/* Options:    RCC_HSE_CRYSTAL
               RCC_HSE_RC
               RCC_HSI
               RCC_PLL			   */
#define RCC_CLOCK_TYPE    RCC_HSE_CRYSTAL



/* Options:     RCC_PLL_HSI_DIV_2
                RCC_PLL_HSE_DIV_2
				RCC_PLL_HSE        */
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_INPUT     RCC_PLL_HSE
#endif


/* Options: 2 to 16 */
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_MUL_VAL   2
#endif



void RCC_voidInitSysClock(void)
{
	#if     RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
		RCC_CR   = 0x00010000; /* Enable HSE with no bypass */
		RCC_CFGR = 0x00000001;

	#elif   RCC_CLOCK_TYPE == RCC_HSE_RC
		RCC_CR   = 0x00050000; /* Enable HSE with bypass */
		RCC_CFGR = 0x00000001;

	#elif   RCC_CLOCK_TYPE == RCC_HSI
		RCC_CR   = 0x00000081; /* Enable HSI + Trimming = 0 */
		RCC_CFGR = 0x00000000;

	#elif   RCC_CLOCK_TYPE == RCC_PLL
		#if   RCC_PLL_INPUT == RCC_PLL_HSI_DIV_2

		#elif RCC_PLL_INPUT == RCC_PLL_HSE_DIV_2

		#elif RCC_PLL_INPUT == RCC_PLL_HSE

		#endif

	#endif
}

void RCC_voidEnableClock (BUS Copy_BUSBus,u8 Copy_u8ID )
{
    if (Copy_u8ID <= 31)
    {
        switch(Copy_BUSBus):
        case RCC_AHB : SET_BIT(RCC_AHBENR   ,Copy_u8ID);   break;
        case RCC_APB1: SET_BIT(RCC_APB1ENR  ,Copy_u8ID);   break;
        case RCC_APB2: SET_BIT(RCC_APB2ENR  ,Copy_u8ID);   break;
    }
}
void RCC_voidDisableClock (BUS Copy_BUSBus,u8 Copy_u8ID )
{
    if (Copy_u8ID <= 31)
    {
        switch(Copy_BUSBus):
        case RCC_AHB : CLR_BIT(RCC_AHBENR   ,Copy_u8ID);   break;
        case RCC_APB1: CLR_BIT(RCC_APB1ENR  ,Copy_u8ID);   break;
        case RCC_APB2: CLR_BIT(RCC_APB2ENR  ,Copy_u8ID);   break;
    }
}

