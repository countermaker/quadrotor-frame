#ifndef DATA_H_
#define DATA_H_

#define RtA 		57.2957795f
#define AtR    		0.017453293f
#define Acc_G 		0.0011963
#define G 			-9.8f
#define G2      	-19.6f
#define G_2			16384.0f
#define G_FAB   	9.8f

typedef struct
{
	float x;
	float y;
	float z;
}Vector;

typedef struct
{
	float Throttle;
	unsigned int Extra;
	float Roll;
	float Pitch;
	float Yaw;
	float meter;
}Remote_Command;

void Remote_WidthGet(void);

void Remote_CommandGet(Remote_Command *Command);

#endif /* DATA_H_ */
