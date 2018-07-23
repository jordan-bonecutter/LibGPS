/* * * * * * * * * * * * * * * * * * * * * * * * */
/* Globals.h * * * * * * * * * * * * * * * * * * */
/* Created by Jordan Bonecutter  * * * * * * * * */
/* 18 July 2018  * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef GLOBALS_H
#define GLOBALS_H

#include <assert.h>

static unsigned long bytes_allocd;
static unsigned long bytes_freed;

#define EARTH_RAD_M		6378100.00			// Radius of earth in meters
#define EARTH_RAD_FT	20925525.0			// Radius of earth in feet
#define EARTH_RAD_MI	3963.16700			// Radius of earth in miles
#define DEG2RAD(x)		(x * 0.017453293)	// Convert degrees to radians
#define RAD2DEG(x)		(x * 57.29577951)	// Convert radians to degrees
#define KNTS2MPH(x)		(x * 1.150780000)	// Convert knots to mph
#define KNTS2MS(x)		(x * 0.514440000)	// Convert knots to m/s
#define KNTS2KPH(x)		(x * 1.852000000)	// Convert knots to kph
#define KNTS2FPS(x)		(x * 1.687810000)	// Convert knots to fps

#endif
