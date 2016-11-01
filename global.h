/*
 * global.h
 *
 *  Created on: 2016Äê6ÔÂ10ÈÕ
 *      Author: home
 */

#ifndef GLOBAL_H_
#define GLOBAL_H_
#include "data.h"

float G_GetDt(uint32_t* oldtime);

extern int16_t lock;

extern Remote_Command Command_Uint,Command;

extern Vector g_Acc;

extern Vector g_Gyro;

#endif /* GLOBAL_H_ */
