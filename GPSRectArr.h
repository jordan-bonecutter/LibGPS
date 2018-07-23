/* * * * * * * * * * * * * * * * * * * * * * * * */
/* GPSRectArr.h  * * * * * * * * * * * * * * * * */
/* Created by Jordan Bonecutter  * * * * * * * * */
/* 21 July 2018  * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef GPSRECTARR_H
#define GPSRECTARR_H

#include "GPSRect.h"
#include <stdlib.h>

extern unsigned long bytes_freed;
extern unsigned long bytes_allocd;

typedef struct gpsrectarr GPSRectArr;

struct gpsrectarr
{
	unsigned long length;
	GPSRect *array;
};

void deleteDataGPSRectArr(GPSRectArr *obj);

void originateArray(GPSRectArr obj);

#endif
