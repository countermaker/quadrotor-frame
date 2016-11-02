#include "basement.h"
#include "data.h"
#include "quad_math.h"
#include "global.h"

Mpu6050_Type Mpu6050_Data;
int16_t Acc_Offsetx=-263,Acc_Offsety=-193,Acc_Offsetz=4631;
float Gyro_Offsetx,Gyro_Offsety,Gyro_Offsetz;
float Kaccx,Kaccy,Kaccz;

Chx_Width Chx;
float Sonar_Width;

float Flow_x,Flow_y;
/**
  * @brief  mpu6050 original data handle
  * @param  Mpu6050_Data ax ay az gx gy gz
  * @retval None
  */
void Mpu_DataHandle(Mpu6050_Type*Mpu6050_Data,Vector*acc,Vector*gyro)
{
	float temp_gx,temp_gy,temp_gz;
	temp_gx = Mpu6050_Data->gyro_x;	//radian
	gyro->x = temp_gx / GYRO_SENSITIVITY * AtR - Gyro_Offsetx;
	temp_gy = Mpu6050_Data->gyro_y;	//radian
	gyro->y = temp_gy / GYRO_SENSITIVITY * AtR - Gyro_Offsety;
	temp_gz = Mpu6050_Data->gyro_z;	//radian
	gyro->z = temp_gz / GYRO_SENSITIVITY * AtR - Gyro_Offsetz;

	acc->x = (float)(Mpu6050_Data->acc_x - Acc_Offsetx) / ACC_SENSITIVITY * G_FAB;
	acc->y = (float)(Mpu6050_Data->acc_y - Acc_Offsety) / ACC_SENSITIVITY * G_FAB;
	acc->z = (float)(Mpu6050_Data->acc_z - Acc_Offsetz) / ACC_SENSITIVITY * G_FAB;
}
/**
  * @brief  Offest the Mpu_Acc
  * @param  None
  * @retval None
  */
void Mpu_AccOffest(void)
{
	int16_t cnt_g = 1000;
	Mpu6050_Type Mpu6050_Data;
	static double offset_x1,offset_x2,offset_y1,offset_y2,offset_z1,offset_z2;
	Delay_ms(4000);
//	int16_t Mpu_Temp[3];
	UARTprintf("please correct the z axis.\r\n");
	Delay_ms(6000);
	UARTprintf("Correcting ... ...\r\n");
	while(cnt_g--)
	{
		MPU_Getaccelerometergyroscope(&Mpu6050_Data);
		offset_z1 += Mpu6050_Data.acc_z;
		Delay_ms(10);
	}
	offset_z1 /= 1000.0f;

	UARTprintf("Z1 = %f,\r\n",offset_z1);

	cnt_g = 1000;
	UARTprintf("please overturn.\r\n");
	Delay_ms(6000);
	UARTprintf("Correcting... ...\r\n");
	while(cnt_g--)
	{
		MPU_Getaccelerometergyroscope(&Mpu6050_Data);
		offset_z2 += Mpu6050_Data.acc_z;
		Delay_ms(10);
	}
	offset_z2 /= 1000.0f;

	UARTprintf("Z2 = %f,\r\n",offset_z2);

	cnt_g = 1000;
	UARTprintf("please correct the y axis.\r\n");
	Delay_ms(6000);
	UARTprintf("Correcting... ...\r\n");
	while(cnt_g--)
	{
		MPU_Getaccelerometergyroscope(&Mpu6050_Data);
		offset_y1 += Mpu6050_Data.acc_y;
		Delay_ms(10);
	}
	offset_y1 /= 1000.0f;

	UARTprintf("Y1 = %f,\r\n",offset_y1);

	cnt_g = 1000;
	UARTprintf("please overturn\r\n");
	Delay_ms(6000);
	UARTprintf("Correcting... ...\r\n");
	while(cnt_g--)
	{
		MPU_Getaccelerometergyroscope(&Mpu6050_Data);
		offset_y2 += Mpu6050_Data.acc_y;
		Delay_ms(10);
	}
	offset_y2 /= 1000.0f;

	UARTprintf("Y2 = %f,\r\n",offset_y2);

	cnt_g = 1000;
	UARTprintf("please correct the x axis.\r\n");
	Delay_ms(6000);
	UARTprintf("Correcting... ...\r\n");
	while(cnt_g--)
	{
		MPU_Getaccelerometergyroscope(&Mpu6050_Data);
		offset_x1 += Mpu6050_Data.acc_x;
		Delay_ms(10);
	}
	offset_x1 /= 1000.0f;

	UARTprintf("X1 = %f,\r\n",offset_x1);

	cnt_g = 1000;
	UARTprintf("please overturn.\r\n");
	Delay_ms(6000);
	UARTprintf("Correcting... ...\r\n");
	while(cnt_g--)
	{
		MPU_Getaccelerometergyroscope(&Mpu6050_Data);
		offset_x2 += Mpu6050_Data.acc_x;
		Delay_ms(10);
	}
	offset_x2 /= 1000.0f;

	UARTprintf("X2 = %f,\r\n",offset_x2);

	Kaccx = (float)fabs(offset_x2 - offset_x1) / G_2;
	Kaccy = (float)fabs(offset_y2 - offset_y1) / G_2;
	Kaccz = (float)fabs(offset_z2 - offset_z1) / G_2;

	Acc_Offsetx = (offset_x2+offset_x1) / 2.0f;
	Acc_Offsety = (offset_y2+offset_y1) / 2.0f;
	Acc_Offsetz = (offset_z2+offset_z1) / 2.0f;

	//Mpu_Temp[0]=Acc_Offsetz;
	//Mpu_Temp[1]=Acc_Offsety;
	//Mpu_Temp[2]=Acc_Offsetx;
	UARTprintf("Offsetx:%d,Offsety:%d,Offsetz:%d\r\n",Acc_Offsetx,Acc_Offsety,Acc_Offsetz);//-292,132,4666
	UARTprintf("Kaccx:%f,Kaccy:%f,Kaccz:%f\r\n",Kaccx,Kaccy,Kaccz);//0.999045,0.958949,1.006267
}
/**
  * @brief  Offest the Mpu_Gyo
  * @param  None
  * @retval None
  */
void Mpu_GyroOffest(void)
{
	const int32_t cnt_g=500;
	int16_t i;
	float offset_temp1,offset_temp2,offset_temp3;
	Mpu6050_Type Mpu6050Data;

	do
	{
		offset_temp1 = offset_temp2 = offset_temp3 =0;
		Gyro_Offsetx = Gyro_Offsety = Gyro_Offsetz = 0;
		for(i=0;i<cnt_g;i++){
			MPU_Getaccelerometergyroscope(&Mpu6050Data);
			offset_temp1 = (float)Mpu6050Data.gyro_x / GYRO_SENSITIVITY * AtR;
			offset_temp2 = (float)Mpu6050Data.gyro_y / GYRO_SENSITIVITY * AtR;
			offset_temp3 = (float)Mpu6050Data.gyro_z / GYRO_SENSITIVITY * AtR;

			Gyro_Offsetx += offset_temp1;
			Gyro_Offsety += offset_temp2;
			Gyro_Offsetz += offset_temp3;
			Delay_ms(5);
		}
		Gyro_Offsetx /= (float)cnt_g;
		Gyro_Offsety /= (float)cnt_g;
		Gyro_Offsetz /= (float)cnt_g;

		offset_temp1 = offset_temp2 = offset_temp3 =0;

		for(i=0;i<cnt_g;i++){
			MPU_Getaccelerometergyroscope(&Mpu6050Data);
			offset_temp1 += (float)Mpu6050Data.gyro_x / GYRO_SENSITIVITY*AtR - Gyro_Offsetx;
			offset_temp2 += (float)Mpu6050Data.gyro_y / GYRO_SENSITIVITY*AtR - Gyro_Offsety;
			offset_temp3 += (float)Mpu6050Data.gyro_z / GYRO_SENSITIVITY*AtR - Gyro_Offsetz;
			Delay_ms(5);
		}
	}while((fabs(offset_temp1) > 0.15f) || (fabs(offset_temp2) > 0.15f) || (fabs(offset_temp3) > 0.15f));
}
/**
  * @brief  ReceiveData Normzation
  * @param  Remote_Command *Command,Chx_Width *p
  * @retval None
  */
void ReceiveData_Norm(Remote_Command *Command,Chx_Width *p)
{
	Command->Roll= 			Constraint_f((p->ch1-1011)/999.0f,0.0,1.0);//1015
	Command->Pitch=			Constraint_f((p->ch2-1011)/999.0f,0.0,1.0);
	Command->Throttle=		Constraint_f((p->ch3-1011)/999.0f,0.0,1.0);
	Command->Yaw=			Constraint_f((p->ch4-1011)/999.0f,0.0,1.0);

}
/**
  * @brief  ReceiveData transform
  * @param  Remote_Command *Command_Uint,Remote_Command *Command
  * @retval None
  */
void ReceiveData_Convert(Remote_Command *Command_Uint,Remote_Command *Command)
{
	Command->Throttle=	(Command_Uint->Throttle);
	Command->Pitch   =	(Command_Uint->Pitch - 0.5f) * PI / 6.0 * 2.0f;
	Command->Roll    =	(Command_Uint->Roll - 0.5f) * PI / 6.0 * 2.0f;

	if(!lock&&Command->Throttle>0.2)
		Command->Yaw = Constraint_f(Command->Yaw + 0.0025*(Command_Uint->Yaw-0.5f) * PI * 2.0f,-PI,PI);
}
/**
  * @brief  Get control data from remote control
  * @param  Remote_Command *Command
  * @retval None
  */
void Remote_CommandGet(Remote_Command *Command)
{
	ReceiveData_Norm(&Command_Uint,&Chx);
	ReceiveData_Convert(&Command_Uint,Command);
}
void Remote_WidthGet(void)
{
	Exti_WidthGet(&Chx);
}
/**
  * @brief  Get imu data from sensor
  * @param  Vector*acc,Vector*gyro
  * @retval None
  */
void Imu_DataGet(Vector*acc,Vector*gyro)
{
	MPU_Getaccelerometergyroscope(&Mpu6050_Data);
	Mpu_DataHandle(&Mpu6050_Data,acc,gyro);
	g_Acc = *acc;
	g_Gyro = *gyro;
}
