#include "basement.h"
#include "global.h"
#include "data.h"
extern Chx_Width Chx;
Mpu6050_Type Mpu_Data;
char i = 200;
void task_loop(void)
{
	static float data_dt;
	static uint32_t update_loop;
	static float print_loopcnt,led_loopcnt,sonar_loopcnt,command_loopcnt;

	data_dt = G_GetDt(&update_loop);

	print_loopcnt += data_dt;
	led_loopcnt += data_dt;
	sonar_loopcnt += data_dt;
	command_loopcnt += data_dt;

	if(print_loopcnt > 0.02)
	{
		print_loopcnt = 0;
		Printf("%f,%f,%f,%f,\r\n",Command.Pitch,Command.Roll,Command.Yaw,Command.Throttle);
		//Printf("%f,%f,%f,%f,\r\n",1.0,2.0,3.0,4.0);

	}

	if(command_loopcnt > 0.02)
	{
		command_loopcnt = 0;
		Remote_CommandGet(&Command);
	}
	if(led_loopcnt > 0.05)
	{
		led_loopcnt = 0;
		Led_Reverse();
	}

	if(sonar_loopcnt > 0.06)
	{
		sonar_loopcnt = 0;
		Sonar_Encourage();
	}

}

int main(void)
{
	Hardware_Init();
	while(1)
	{
		task_loop();
	}
}
void Control_Isr(void)
{
	Exti_quit();
	MPU_Getaccelerometergyroscope(&Mpu_Data);
}

void Exti_Isr(void)
{
	Remote_WidthGet();
}
