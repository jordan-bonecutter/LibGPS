/* * * * * * * * * * * * * * * * * * * * * * * * */
/* Vector.c  * * * * * * * * * * * * * * * * * * */
/* Created by Jordan Bonecutter  * * * * * * * * */
/* 21 July 2018  * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * */

#include "Vector.h"

Vector3 vectorCross(Vector3 v1, Vector3 v2)
{
	Vector3 res;
	res.x = (v1.y * v2.z) - (v1.z * v2.y);
	res.y = (v1.z * v2.x) - (v1.x * v2.z);
	res.z = (v1.x * v2.y) - (v1.y * v2.x);
	return res;
}

double vectorDot3(Vector3 v1, Vector3 v2)
{
	return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

Vector3 vectorNormalize3(Vector3 v)
{
	double factor = sqrt(vectorDot3(v, v));
	v.x /= factor;
	v.y /= factor;
	v.z /= factor;
	return v;
}

double vectorDot2(Vector2 v1, Vector2 v2)
{
	return (v1.x * v2.x) + (v1.y * v2.y);
}

Vector2 vectorNormalize2(Vector2 v)
{
	double factor = sqrt(vectorDot2(v, v));
	v.x /= factor;
	v.y /= factor;
	return v;
}
