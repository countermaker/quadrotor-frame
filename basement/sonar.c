#include "basement.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "inc/hw_memmap.h"
/**
  * @brief  Init the sonar
  * @param  None
  * @retval None
  */
void Sonar_GpioInit(void)
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1);
}
/**
  * @brief  Delay 10us
  * @param  None
  * @retval None
  */
void Sonar_Delay10us(void)
{
	int32_t Delay_i;
	uint32_t i;
	  for(i = 0;i<10;i++)
	  {
		Delay_i = 7;
		while(Delay_i--);
	  }
}
/**
  * @brief  Drive the sonar
  * @param  None
  * @retval None
  */
void Sonar_Encourage(void)
{
	GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, GPIO_PIN_1);
	Sonar_Delay10us();
	GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0x0);
}
/**
  * @brief  Get the distance
  * @param  None
  * @retval None
  */
void Sonar_GetDist(float*sonar_width,float*distance)
{
	*distance = 340.0f*((*sonar_width)/1000000.0f)/2.0f; /* unit: m */
}
