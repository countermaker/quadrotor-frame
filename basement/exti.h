#ifndef EXTI_H_
#define EXTI_H_
/**********************#Pin define*********************************/
#define GPIO_CH1 			GPIO_PIN_2
#define GPIO_CH2 			GPIO_PIN_3
#define GPIO_CH3 			GPIO_PIN_4
#define GPIO_CH4 			GPIO_PIN_5
#define GPIO_CH5 			GPIO_PIN_6
#define GPIO_CH6 			GPIO_PIN_7
#define INT_CHX 			INT_GPIOA
#define GPIO_CHX_BASE		GPIO_PORTA_BASE

#define GPIO_MPU_INT 		GPIO_PIN_1
#define GPIO_MPU_BASE 		GPIO_PORTB_BASE
#define INT_MPU				INT_GPIOB
/**********************#Data type***********************************/
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
/**********************#Function***********************************/
void Exti_Init(void);

void Exti_Init(void);

void Control_Isr(void);

void Exti_quit(void);

void Exti_WidthGet(Chx_Width * chx);

#endif
