#ifndef II2C_H_
#define II2C_H_
#include <stdbool.h>
#include <stdint.h>

void IIC_Init(void);

void IIC_Start(void);

void IIC_Stop(void);

uint8_t IIC_Waitack(void);

void IIC_Ack(void);

void IIC_Nack(void);

void IIC_Sendbyte(uint8_t IIC_Text);

uint8_t IIC_Readbyte(uint8_t IIC_ack);





#endif /* II2C_H_ */
