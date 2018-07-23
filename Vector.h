/* * * * * * * * * * * * * * * * * * * * * * * * */
/* Vector.h  * * * * * * * * * * * * * * * * * * */
/* Created by Jordan Bonecutter  * * * * * * * * */
/* 21 July 2018  * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>

typedef struct v2 Vector2;
typedef struct v3 Vector3;

struct v2
{
	double x;
	double y;
};

struct v3
{
	double x;
	double y;
	double z;
};

Vector3 vectorCross(Vector3 v1, Vector3 v2);

double vectorDot3(Vector3 v1, Vector3 v2);

Vector3 vectorNormalize3(Vector3 v);

double vectorDot2(Vector2 v1, Vector2 v2);

Vector2 vectorNormalize2(Vector2 v);

#endif
