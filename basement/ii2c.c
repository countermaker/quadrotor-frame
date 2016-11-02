#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "delay.h"
#include "ii2c.h"

void IIC_Init(void)
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_IIC);
	GPIOPinTypeGPIOOutput(GPIO_SCL_BASE, GPIO_PIN_SCL);
	GPIOPinTypeGPIOOutput(GPIO_SDA_BASE, GPIO_PIN_SDA);

	GPIOPinWrite(GPIO_SCL_BASE, GPIO_PIN_SCL, GPIO_PIN_SCL);
	GPIOPinWrite(GPIO_SDA_BASE, GPIO_PIN_SDA, GPIO_PIN_SDA);
}
/**
  * @brief  IIC Start
  * @param  None
  * @retval None
  */
void IIC_Start(void)
{
	IIC_SDA_OUT;
	IIC_SDA_1;	
	IIC_SCL_1;	
	Delay_us(2);
	IIC_SDA_0;
	Delay_us(2);
	IIC_SCL_0;
}
/**
  * @brief  IIC Stop
  * @param  None
  * @retval None
  */
void IIC_Stop(void)
{
	IIC_SDA_OUT;
	IIC_SCL_0;
	IIC_SDA_0;
	Delay_us(2);
	IIC_SCL_1;	
	IIC_SDA_1;
	Delay_us(2);
}
/**
  * @brief  IIC Waitack
  * @param  None
  * @retval None
  */
uint8_t IIC_Waitack(void)
{
	uint8_t IIC_Waitlimit=0;
	IIC_SDA_IN;
	IIC_SDA_1;	
	Delay_us(1);
	IIC_SCL_1;	
	Delay_us(1);
	while(IIC_READ_SDA)
	{
		IIC_Waitlimit++;
		if(IIC_Waitlimit>250)
		{
			IIC_Stop();
			return 1;
		}
	}
	IIC_SCL_0;
	return 0;
}
/**
  * @brief  IIC inspire ack
  * @param  None
  * @retval None
  */
void IIC_Ack(void)
{
	IIC_SCL_0;
	IIC_SDA_OUT;
	IIC_SDA_0;
	Delay_us(2);
	IIC_SCL_1;
	Delay_us(2);
	IIC_SCL_0;
}
/**
  * @brief  IIC inspire no ack
  * @param  None
  * @retval None
  */
void IIC_Nack(void)
{
	IIC_SCL_0;
	IIC_SDA_OUT;
	IIC_SDA_1;
	Delay_us(2);
	IIC_SCL_1;
	Delay_us(2);
	IIC_SCL_0;
}
/**
  * @brief  IIC Send a byte
  * @param  IIC_Text: a byte which will be sent
  * @retval None
  */
void IIC_Sendbyte(uint8_t IIC_Text)
{
	uint8_t IIC_Temp;
	IIC_SDA_OUT;
	IIC_SCL_0;
	for(IIC_Temp=0;IIC_Temp<8;IIC_Temp++)
	{
		if(IIC_Text&0x80)
			IIC_SDA_1;
		else
			IIC_SDA_0;
		IIC_Text<<=1;
		Delay_us(1);
		IIC_SCL_1;
		Delay_us(1);
		IIC_SCL_0;
		Delay_us(1);
	}
}
/**
  * @brief  IIC read a byte
  * @param  IIC_ack :1:ack
	*									 0:no ack
  * @retval IIC_Reseave
  */
uint8_t IIC_Readbyte(uint8_t IIC_ack)
{
	uint8_t IIC_Temp,IIC_Reseave=0;
	IIC_SDA_IN;
	for(IIC_Temp=0;IIC_Temp<8;IIC_Temp++)
	{
		IIC_SCL_0;
		Delay_us(1);
		IIC_SCL_1;
		IIC_Reseave<<=1;
		if(IIC_READ_SDA)
			IIC_Reseave++;
		Delay_us(1);
	}
	if(!IIC_ack)
		IIC_Nack();
	else
		IIC_Ack();
	return IIC_Reseave;
}



