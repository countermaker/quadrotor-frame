#include "basement.h"
/**
  * @brief  Init the hardware
  * @param  None
  * @retval None
  */
void Hardware_Init(void)
{
	System_ClockInit();

	Led_Init();

	Pwm_init();

	Uart_Init();

	Sonar_GpioInit();

	MPU_Init();

	Timer_Init(0xffffffff);

	Timer_Control(1);

	Exti_Init();
}
