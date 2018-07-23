/* * * * * * * * * * * * * * * * * * * * * * * * */
/* GPSRect.c * * * * * * * * * * * * * * * * * * */
/* Created by Jordan Bonecutter  * * * * * * * * */
/* 18 July 2018  * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * */

#include "GPSRect.h"

GPSRect raw2rect(GPSRaw raw_data)
{
	// Conversion from polar to rectangular coords
	GPSRect res;
	res.theta_lat = getLatitude(raw_data);
	res.theta_lon = getLongitude(raw_data);
	res.x = EARTH_RAD_M * cos(res.theta_lat) * cos(res.theta_lon);
	res.y = EARTH_RAD_M * cos(res.theta_lat) * sin(res.theta_lon);
	res.z = EARTH_RAD_M * sin(res.theta_lat);
	res.speed_knots = raw_data.speed;
	return res;
}
