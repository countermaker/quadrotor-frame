#include <stdbool.h>
#include <stdint.h>
#include "driverlib/sysctl.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"
/**
  * @brief  Init the system clock (100MHZ pll)
  * @param  uint16_t* oldtime
  * @retval Dt
  */
void System_ClockInit(void)
{
	SysCtlClockSet(SYSCTL_SYSDIV_2 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN |            /*200 / 2 Mhz*/
	                   SYSCTL_XTAL_16MHZ);
	IntMasterEnable();
}



