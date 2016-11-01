#include <stdbool.h>
#include <stdint.h>
#include "stdio.h"
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "uartstdio.h"
#include <stdarg.h>
/**
  * @brief  Init the uart baud:115200
  * @param  None
  * @retval None
  */
void Uart_Init(void)
{
	/*clock enable*/
	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
	/*configure GPIO*/
	GPIOPinConfigure(GPIO_PA0_U0RX);
	GPIOPinConfigure(GPIO_PA1_U0TX);

	GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
	/*Set clock source and baud*/
	UARTClockSourceSet(UART0_BASE, UART_CLOCK_PIOSC);
	/*baud 115200 one stop bit and no PAR */
    UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 115200,
                        (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
                         UART_CONFIG_PAR_NONE));
}
int fputc(int ch, FILE *f)
{
	UARTCharPut(UART0_BASE,ch);
	return (ch);
}
/*************************printf**************************************/
void UartPutchar(char Txdata)
{
    if(Txdata=='\n')
    {
       while(UARTBusy(UART0_BASE));
       UARTCharPut(UART0_BASE,'\r');
    }
    while(UARTBusy(UART0_BASE));
    UARTCharPut(UART0_BASE,Txdata);
}

void UartSendString(char *pt)
{
    while(*pt)
    {
        UartPutchar(*pt++);
    }
}

void IntToString(int temp,char *pchar)
{
    char ch,*p=pchar;
    while(temp!=0)
    {
       *pchar++=(char)(temp+0x30);
       temp/=10;
    }
    *pchar--='\0';
    while(pchar>p)
    {
       ch=*p;
       *p++=*pchar;
       *pchar--=ch;
    }
}
void Printf(char *fmt,...)
{
    va_list ap;
    char string[256];
    va_start(ap,fmt);
    vsprintf(string,fmt,ap);
    UartSendString(string);
    va_end(ap);
}
