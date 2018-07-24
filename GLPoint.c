/* * * * * * * * * * * * * * * * * * * * * * * * */
/* GLPoint.c * * * * * * * * * * * * * * * * * * */
/* Created by Jordan Bonecutter  * * * * * * * * */
/* 21 July 2018  * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * */

#include "GLPoint.h"

GLPointArr newGLPointArr(GPSRectArr raw)
{
	assert(raw.array);
	
	GLPointArr res;
	res.array = malloc(sizeof(GLPoint) * raw.length);
	res.length = raw.length;

	Vector3 p0, v0, v1;
	p0.x = raw.array[0].x;
	p0.y = raw.array[0].y;
	p0.z = raw.array[0].z;
	
	originateArray(raw);
	v0.x = raw.array[1].x;
	v0.y = raw.array[1].y;
	v0.z = raw.array[1].z;
	v0 = vectorNormalize3(v0);

	v1 = vectorCross(p0, v0);
	v1 = vectorNormalize3(v1);

	unsigned long n;
	for(n = 0; n < raw.length; n++)
	{
		// New vector : <v1 . v, v0 . v>
		res.array[n].raw.x = raw.array[n].x;
		res.array[n].raw.y = raw.array[n].y;
		res.array[n].raw.z = raw.array[n].z;
		res.array[n].speed = raw.array[n].speed_knots;

		res.array[n].pt.x = vectorDot3(v1, res.array[n].raw);
		res.array[n].pt.y = vectorDot3(v0, res.array[n].raw);
	}

	deleteDataGPSRectArr(&raw);
	return res;
}

GLPointArr newGLPointArr_LL(GPSRectArr raw)
{
	assert(raw.array);
	
	GLPointArr res;
	res.array = malloc(sizeof(GLPoint) * raw.length);
	bytes_allocd += sizeof(GLPoint) * raw.length;
	res.length = raw.length;
	Vector2 LaLo0;
	LaLo0.x = raw.array[0].theta_lat;
	LaLo0.y = raw.array[0].theta_lon;

	unsigned long n;
	for(n = 0; n < raw.length; n++)
	{
		res.array[n].raw.x = raw.array[n].x;
		res.array[n].raw.y = raw.array[n].y;
		res.array[n].raw.z = raw.array[n].z;
		res.array[n].speed = raw.array[n].speed_knots;
	
		res.array[n].pt.x = raw.array[n].theta_lon - LaLo0.y;
		res.array[n].pt.y = raw.array[n].theta_lat - LaLo0.x;
		res.array[n].pt.x *= EARTH_RAD_M;
		res.array[n].pt.y *= EARTH_RAD_M * sin(raw.array[n].theta_lon);
	}

	deleteDataGPSRectArr(&raw);

	return res;
}
