#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
/**
  * @brief  Init the led
  * @param  None
  * @retval None
  */
void Led_Init(void)
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_3);
}
/**
  * @brief  Blink the led
  * @param  None
  * @retval None
  */
void Led_Reverse(void)
{
	if(GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_3))
	{
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0x0);
	}
	else
	{
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, GPIO_PIN_3);
	}
}


