#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "led.h"
/**
  * @brief  Init the led
  * @param  None
  * @retval None
  */
void Led_Init(void)
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_LED);
	GPIOPinTypeGPIOOutput(GPIO_LED_BASE, GPIO_PIN_LED);
}
/**
  * @brief  Blink the led
  * @param  None
  * @retval None
  */
void Led_Reverse(void)
{
	if(GPIOPinRead(GPIO_LED_BASE,GPIO_PIN_LED))
	{
		GPIOPinWrite(GPIO_LED_BASE, GPIO_PIN_LED, 0x00);
	}
	else
	{
		GPIOPinWrite(GPIO_LED_BASE, GPIO_PIN_LED, GPIO_PIN_LED);
	}
}
/**
  * @brief  Light the led
  * @param  None
  * @retval None
  */
void Led_On(void)
{
	GPIOPinWrite(GPIO_LED_BASE, GPIO_PIN_LED, GPIO_PIN_LED);
}
/**
  * @brief  Off the led
  * @param  None
  * @retval None
  */
void Led_Off(void)
{
	GPIOPinWrite(GPIO_LED_BASE, GPIO_PIN_LED, 0x00);
}

