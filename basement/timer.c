#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"
/**
  * @brief  initialise Timer
  * @param  period_num
  * @retval None
  */
void Timer_Init(unsigned int period_num)
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
	TimerConfigure(TIMER0_BASE, TIMER_CFG_PERIODIC_UP);
	TimerLoadSet(TIMER0_BASE, TIMER_A, period_num);
}
/**
  * @brief  Control Timer
  * @param  sta 1 ON
	*	 	0 OFF
  * @retval None
  */
void Timer_Control(unsigned char sta)
{
	if(sta == 1)
		TimerEnable(TIMER0_BASE, TIMER_A);
	if(sta == 0)
		TimerDisable(TIMER0_BASE, TIMER_A);
}
/**
  * @brief  Init the timer capture
  * @param  None
  * @retval None
  */
void Timer_CaptureInit(void)
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER0);
	TimerConfigure(WTIMER0_BASE, TIMER_CFG_PERIODIC_UP);
}
