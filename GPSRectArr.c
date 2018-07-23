/* * * * * * * * * * * * * * * * * * * * * * * * */
/* GPSRectArr.c  * * * * * * * * * * * * * * * * */
/* Created by Jordan Bonecutter  * * * * * * * * */
/* 18 July 2018  * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * */

#include "GPSRectArr.h"

void deleteDataGPSRectArr(GPSRectArr *obj)
{
    // Free mem
    free(obj->array);
    bytes_freed += sizeof(GPSRect) * obj->length;

    // Deref ptrs
    obj->array = NULL;
    obj->length = 0;
}

void originateArray(GPSRectArr obj)
{
	assert(obj.array);
	if(!obj.length)
	{
		return;
	}

	double x0 = obj.array[0].x, y0 = obj.array[0].y, z0 = obj.array[0].z;
	unsigned long n;
	for(n = 0; n < obj.length; n++)
	{
		obj.array[n].x -= x0;
		obj.array[n].y -= y0;
		obj.array[n].z -= z0;
	}
}
