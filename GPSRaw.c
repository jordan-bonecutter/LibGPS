/* * * * * * * * * * * * * * * * * * * * * * * * */
/* GPSRaw.c  * * * * * * * * * * * * * * * * * * */
/* Created by Jordan Bonecutter  * * * * * * * * */
/* 18 July 2018  * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * */

#include "GPSRaw.h"

double getLatitude(GPSRaw data)
{
	return 0.017453293*((double)data.lat + ((double)data.lat_min/600000.0));
}

double getLongitude(GPSRaw data)
{
	return 0.017453293*((double)data.lon + ((double)data.lon_min/600000.0));
}

double getSpeedMPH(GPSRaw data)
{
	return KNTS2MPH(data.speed);
}

double getSpeedMS(GPSRaw data)
{
	return KNTS2MS(data.speed);
}

double getSpeedKPH(GPSRaw data)
{
	return KNTS2KPH(data.speed);
}

double getSpeedFPS(GPSRaw data)
{
	return KNTS2FPS(data.speed);
}
