/* * * * * * * * * * * * * * * * * * * * * * * * */
/* GPSRaw.h  * * * * * * * * * * * * * * * * * * */
/* Created by Jordan Bonecutter  * * * * * * * * */
/* 18 July 2018  * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef GPSRAW_H
#define GPSRAW_H

#include "Globals.h"
#include <stdlib.h>

typedef struct gpsraw GPSRaw;

struct gpsraw
{
	int32_t curr_time;
	int32_t lat;
	int32_t lat_min;
	int32_t lon;
	int32_t lon_min;
	int32_t speed;
};

/* Returns latitude in radians */
double getLatitude(GPSRaw data);

/* Returns longitude in radians */
double getLongitude(GPSRaw data);

/* Returns speed in mph */
double getSpeedMPH(GPSRaw data);

/* Returns speed in kph */
double getSpeedKPH(GPSRaw data);

/* Returns speed in ms */
double getSpeedMS(GPSRaw data);

/* Returns speed in fps */
double getSpeedFPS(GPSRaw data);

#endif
