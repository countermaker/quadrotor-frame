#ifndef LED_H_
#define LED_H_
/**********************#Pin define*********************************/
#define SYSCTL_PERIPH_LED       	SYSCTL_PERIPH_GPIOF
#define GPIO_LED_BASE   			GPIO_PORTF_BASE
#define GPIO_PIN_LED                GPIO_PIN_3
/**********************#Function***********************************/
void Led_Init(void);

void Led_Reverse(void);

#endif
