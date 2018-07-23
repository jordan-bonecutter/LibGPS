/* * * * * * * * * * * * * * * * * * * * * * * * */
/* GPSRect.h * * * * * * * * * * * * * * * * * * */
/* Created by Jordan Bonecutter  * * * * * * * * */
/* 18 July 2018  * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef GPSRECT_H
#define GPSRECT_H

#include "Globals.h"
#include "GPSRaw.h"
#include <math.h>

typedef struct gpsrect GPSRect;

struct gpsrect
{
	double x;
	double y;
	double z;
	double theta_lat;
	double theta_lon;
	double speed_knots;
};

/* Convert raw gps data to rect gps data */
GPSRect raw2rect(GPSRaw raw_data);

#endif
