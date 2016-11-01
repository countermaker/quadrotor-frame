/*
 * exti.h
 *
 *  Created on: 2016Äê7ÔÂ17ÈÕ
 *      Author: home
 */

#ifndef EXTI_H_
#define EXTI_H_


void Exti_Init(void);

typedef struct
{
	int16_t ch1;
	int16_t ch2;
	int16_t ch3;
	int16_t ch4;
	int16_t ch5;
	int16_t ch6;
	int16_t ch7;
	int16_t ch8;

}Chx_Width;

void Exti_Init(void);

void Control_Isr(void);

void Exti_quit(void);

void Exti_WidthGet(Chx_Width * chx);

#endif /* EXTI_H_ */
