#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"
#include "driverlib/interrupt.h"
#include "inc/hw_ints.h"
#include "exti.h"
extern void Exti_Isr(void);
/**
  * @brief  Get the width of pulse
  * @param  Chx_Width * chx
  * @retval None
  */
void Exti_WidthGet(Chx_Width * chx)
{
	static int32_t cnt,cnt_1,cnt_2, cnt_3,cnt_4, cnt_5,cnt_6, cnt_7,cnt_8, cnt_9,cnt_10, cnt_11,cnt_12;
	unsigned long status;
	status = GPIOIntStatus(GPIO_PORTA_BASE,true);
	cnt = TimerValueGet(TIMER0_BASE,TIMER_A);
	if(status & GPIO_PIN_2)
	{
		if(GPIOPinRead(GPIO_PORTA_BASE,GPIO_PIN_2))
		{
			GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_2,GPIO_FALLING_EDGE);
			cnt_1 = cnt;
		}
		else
		{
			GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_2,GPIO_RISING_EDGE);
			cnt_2 = cnt;
			if(cnt_2>=cnt_1)
			{
				chx->ch1 = (cnt_2-cnt_1) / 67;
			}
			else
			{
				chx->ch1 = (0xffffffff+cnt_2-cnt_1+1) / 67;
			}
		}
	}

	if(status & GPIO_PIN_3)
	{
		if(GPIOPinRead(GPIO_PORTA_BASE,GPIO_PIN_3))
		{
			GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_3,GPIO_FALLING_EDGE);
			cnt_3 = cnt;
		}
		else
		{
			GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_3,GPIO_RISING_EDGE);
			cnt_4 = cnt;
			if(cnt_4>=cnt_3)
			{
				chx->ch2 = (cnt_4-cnt_3) / 67;
			}
			else
			{
				chx->ch2 = (0xffffffff+cnt_4-cnt_3+1) / 67;
			}
		}
	}

	if(status & GPIO_PIN_4) //ch GPIOPin cnt
	{
		if(GPIOPinRead(GPIO_PORTA_BASE,GPIO_PIN_4))
		{
			GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_4,GPIO_FALLING_EDGE);
			cnt_5 = cnt;
		}
		else
		{
			GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_4,GPIO_RISING_EDGE);
			cnt_6 = cnt;
			if(cnt_6 >= cnt_5)
			{
				chx->ch3 = (cnt_6-cnt_5) / 67;
			}
			else
			{
				chx->ch3 = (0xffffffff+cnt_6-cnt_5+1) / 67;
			}
		}
	}

	if(status & GPIO_PIN_5) //ch GPIOPin cnt
	{
		if(GPIOPinRead(GPIO_PORTA_BASE,GPIO_PIN_5))
		{
			GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_5,GPIO_FALLING_EDGE);
			cnt_7 = cnt;
		}
		else
		{
			GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_5,GPIO_RISING_EDGE);
			cnt_8 = cnt;
			if(cnt_8 >= cnt_7)
			{
				chx->ch4 = (cnt_8-cnt_7) / 67;
			}
			else
			{
				chx->ch4 = (0xffffffff+cnt_8-cnt_7+1) / 67;
			}
		}
	}
	if(status & GPIO_PIN_6) //ch GPIOPin cnt
	{
		if(GPIOPinRead(GPIO_PORTA_BASE,GPIO_PIN_6))
		{
			GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_6,GPIO_FALLING_EDGE);
			cnt_9 = cnt;
		}
		else
		{
			GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_6,GPIO_RISING_EDGE);
			cnt_10 = cnt;
			if(cnt_10 >= cnt_9)
			{
				chx->ch5 = (cnt_10-cnt_9) / 67;
			}
			else
			{
				chx->ch5 = (0xffffffff+cnt_10-cnt_9+1) / 67;
			}
		}
	}
	if(status & GPIO_PIN_7) //ch GPIOPin cnt
	{
		if(GPIOPinRead(GPIO_PORTA_BASE,GPIO_PIN_7))
		{
			GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_7,GPIO_FALLING_EDGE);
			cnt_11 = cnt;
		}
		else
		{
			GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_7,GPIO_RISING_EDGE);
			cnt_12 = cnt;
			if(cnt_12 >= cnt_11)
			{
				chx->ch6 = (cnt_12-cnt_11) / 67;
			}
			else
			{
				chx->ch6 = (0xffffffff+cnt_12-cnt_11+1) / 67;
			}
		}
	}
	GPIOIntClear(GPIO_PORTA_BASE,status);
}

/**
  * @brief  init Exti
  * @param  None
  * @retval None
  */
void Exti_Init(void)
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);

	GPIOPadConfigSet(GPIO_PORTA_BASE,GPIO_PIN_2,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPD);
	GPIOPadConfigSet(GPIO_PORTA_BASE,GPIO_PIN_3,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPD);
	GPIOPadConfigSet(GPIO_PORTA_BASE,GPIO_PIN_4,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPD);
	GPIOPadConfigSet(GPIO_PORTA_BASE,GPIO_PIN_5,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPD);
	GPIOPadConfigSet(GPIO_PORTA_BASE,GPIO_PIN_6,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPD);
	GPIOPadConfigSet(GPIO_PORTA_BASE,GPIO_PIN_7,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPD);

	GPIODirModeSet(GPIO_PORTA_BASE,GPIO_PIN_2,GPIO_DIR_MODE_IN);
	GPIODirModeSet(GPIO_PORTA_BASE,GPIO_PIN_3,GPIO_DIR_MODE_IN);
	GPIODirModeSet(GPIO_PORTA_BASE,GPIO_PIN_4,GPIO_DIR_MODE_IN);
	GPIODirModeSet(GPIO_PORTA_BASE,GPIO_PIN_5,GPIO_DIR_MODE_IN);
	GPIODirModeSet(GPIO_PORTA_BASE,GPIO_PIN_6,GPIO_DIR_MODE_IN);
	GPIODirModeSet(GPIO_PORTA_BASE,GPIO_PIN_7,GPIO_DIR_MODE_IN);

	GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_2,GPIO_RISING_EDGE);
	GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_3,GPIO_RISING_EDGE);
	GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_4,GPIO_RISING_EDGE);
	GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_5,GPIO_RISING_EDGE);
	GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_6,GPIO_RISING_EDGE);
	GPIODirModeSet(GPIO_PORTA_BASE,GPIO_PIN_7,GPIO_RISING_EDGE);

	GPIOPadConfigSet(GPIO_PORTB_BASE,GPIO_PIN_1,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPD);
	GPIODirModeSet(GPIO_PORTB_BASE,GPIO_PIN_1,GPIO_DIR_MODE_IN);
	GPIOIntTypeSet(GPIO_PORTB_BASE,GPIO_PIN_1,GPIO_RISING_EDGE);

	IntEnable(INT_GPIOA);
	IntEnable(INT_GPIOB);

	GPIOIntEnable(GPIO_PORTA_BASE,GPIO_INT_PIN_2|GPIO_INT_PIN_3|GPIO_INT_PIN_4|GPIO_INT_PIN_5|GPIO_INT_PIN_6|GPIO_INT_PIN_7);
	GPIOIntEnable(GPIO_PORTB_BASE,GPIO_INT_PIN_1);

	IntPrioritySet(INT_GPIOA,0x00);
	IntPrioritySet(INT_GPIOB,0x01);

	GPIOIntRegister(GPIO_PORTA_BASE,Exti_Isr);
	GPIOIntRegister(GPIO_PORTB_BASE,Control_Isr);
}
/**
  * @brief  quit exti
  * @param  None
  * @retval None
  */
void Exti_quit(void)
{
	static int status;
	status = GPIOIntStatus(GPIO_PORTB_BASE,true);
	GPIOIntClear(GPIO_PORTB_BASE,status);
}


