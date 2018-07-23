/* * * * * * * * * * * * * * * * * * * * * * * * */
/* GLPoint.h * * * * * * * * * * * * * * * * * * */
/* Created by Jordan Bonecutter  * * * * * * * * */
/* 21 July 2018  * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef GLPOINT_H
#define GLPOINT_H

#include "Vector.h"
#include "GPSRect.h"
#include "GPSRectArr.h"

typedef struct glpoint GLPoint;
typedef struct glpointarr GLPointArr;

struct glpoint
{
	Vector3 raw;
	Vector2 pt;
	double speed;
};

struct glpointarr
{
	unsigned long length;
	GLPoint *array;
};

GLPointArr newGLPointArr(GPSRectArr arr);
GLPointArr newGLPointArr_LL(GPSRectArr arr);

#endif
