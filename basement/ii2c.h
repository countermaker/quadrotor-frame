#ifndef II2C_H_
#define II2C_H_
#include <stdbool.h>
#include <stdint.h>
/**********************#Pin define*********************************/
#define GPIO_SCL_BASE 		GPIO_PORTE_BASE
#define GPIO_SDA_BASE 		GPIO_PORTE_BASE
#define GPIO_PIN_SCL		GPIO_PIN_4
#define GPIO_PIN_SDA    	GPIO_PIN_5
#define SYSCTL_PERIPH_IIC 	SYSCTL_PERIPH_GPIOE

#define IIC_SCL_1 			GPIOPinWrite(GPIO_SCL_BASE, GPIO_PIN_SCL, GPIO_PIN_SCL)
#define IIC_SDA_1 			GPIOPinWrite(GPIO_SDA_BASE, GPIO_PIN_SDA, GPIO_PIN_SDA)
#define IIC_SCL_0 			GPIOPinWrite(GPIO_SCL_BASE, GPIO_PIN_SCL, 0)
#define IIC_SDA_0 			GPIOPinWrite(GPIO_SDA_BASE, GPIO_PIN_SDA, 0)
#define IIC_SDA_OUT 		GPIOPinTypeGPIOOutput(GPIO_SCL_BASE, GPIO_PIN_SDA)
#define IIC_SDA_IN  		GPIOPinTypeGPIOInput(GPIO_SDA_BASE, GPIO_PIN_SDA)
#define IIC_READ_SDA 		GPIOPinRead(GPIO_SDA_BASE,GPIO_PIN_SDA)
/**********************#Function***********************************/
void IIC_Init(void);

void IIC_Start(void);

void IIC_Stop(void);

uint8_t IIC_Waitack(void);

void IIC_Ack(void);

void IIC_Nack(void);

void IIC_Sendbyte(uint8_t IIC_Text);

uint8_t IIC_Readbyte(uint8_t IIC_ack);
#endif
