#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"
#include "data.h"

int16_t lock;
Remote_Command Command_Uint,Command;
Vector g_Acc = {0,0,0};
Vector g_Gyro = {0,0,0};
/**
  * @brief  Get Dt
  * @param  uint16_t* oldtime
  * @retval Dt
  */
float G_GetDt(uint32_t* oldtime)
{
	float New,Old;
	New = TimerValueGet(TIMER0_BASE,TIMER_A);
	Old = *oldtime;
	*oldtime = New;
	if(New > Old)
	{
		return (float)((New-Old)/100000000.0f);
	}
	else
	{
		return (float)((New-Old+0xffffffff+1)/100000000.0f);
	}
}

