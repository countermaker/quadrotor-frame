#ifndef SONAR_H_
#define SONAR_H_
/**********************#Pin define*********************************/
#define SYSCTL_PERIPH_SONAR SYSCTL_PERIPH_GPIOF
#define GPIO_SONAR_BASE GPIO_PORTF_BASE
#define GPIO_PIN_SONAR GPIO_PIN_1
/**********************#Function***********************************/
void Sonar_GpioInit(void);

void Sonar_Encourage(void);

#endif
