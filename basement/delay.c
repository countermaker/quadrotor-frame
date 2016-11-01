#include <stdbool.h>
#include <stdint.h>
#include "driverlib/sysctl.h"
/**
  * @brief  Delay n ms.
  * @param  nCount : n ms
  * @retval None
  */
void Delay_ms(uint32_t nCount)
{
	int32_t Delay_i;
	uint32_t i;

  for(i = 0;i<nCount;i++){
		Delay_i = 8333;
		while(Delay_i--);
	}
}
/**
  * @brief  Delay n us.
  * @param  nCount : n us
  * @retval None
  */
void Delay_us(uint32_t nCount)
{
	int32_t Delay_i;
	uint32_t i;

  for(i = 0;i<nCount;i++){
		Delay_i = 2;
		while(Delay_i--);
	}
}

