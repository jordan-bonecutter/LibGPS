/* * * * * * * * * * * * * * * * * * * * * * * * */
/* Main.c  * * * * * * * * * * * * * * * * * * * */
/* Created by Jordan Bonecutter  * * * * * * * * */
/* 21 July 2018  * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * */

#include "Globals.h"
#include "GPSRaw.h"
#include "GPSRect.h"
#include "FileIO.h"
#include "GPSRectArr.h"
#include "GLPoint.h"
#include "Image.h"
#include "FileIOIm.h"
#include <stdio.h>
#include <math.h>

PIXEL interpolateColors(double curr, double max, double min)
{
	double len = max - min;
	double tlen = max - curr;
	PIXEL res;
	res.B = 0;

	if(tlen/len >= 0.5)
	{
		res.R = 0xFF;
		res.G = 2*((len-tlen)/len)*255;
	}
	else
	{
		res.R = 2*((tlen)/len)*255;
		res.G = 255;
	}

	return res;
}

double sqrd(double x)
{
	return x * x;
}

int main()
{
	GPSRectArr t = readFile("test.rgp");
	GLPointArr gparr = newGLPointArr_LL(t);
	t.array = NULL;
	GLPoint last = gparr.array[gparr.length-1];
	printf("Displacement = %lf miles\n\n", 0.000621371*sqrt(last.pt.x*last.pt.x + last.pt.y*last.pt.y)); 

	IMAGE *test = CreateImage(2500, 2500);
	unsigned long n, x, y;
	const PIXEL BLACK = {0, 0, 0};
	PIXEL RED; 
	
	double max_speed = 0, min_speed = 100, integral_distance = 0.0, temp, max_step = 0.0;
	Vector2 delta[2];
	delta[0].x = gparr.array[0].pt.x;
	delta[0].y = gparr.array[0].pt.y;

	for(x = 0; x < 2500; x++)
	{
		for(y = 0; y < 2500; y++)
		{
			SetPixel(test, x, y, BLACK);
		}
	}

	for(n = 1; n < gparr.length; n++)
	{
		if(max_speed < gparr.array[n].speed)
		{
			max_speed = gparr.array[n].speed;
		}
		if(min_speed > gparr.array[n].speed)
		{
			min_speed = gparr.array[n].speed;
		}
		delta[1] = gparr.array[n].pt;
		temp = sqrd(gparr.array[n].pt.x - gparr.array[n-1].pt.x) + sqrd(gparr.array[n].pt.y - gparr.array[n-1].pt.y); 
		temp = sqrt(temp);
		delta[0] = delta[1];
		if(temp > max_step)
		{
			max_step = temp;
			printf("Max step = %lf at %d\n", max_step, n);
		}
		if(temp > 0.5)
		{
			integral_distance += temp;
		}
	}

	printf("Distance traveled = %lf meters\n\n", integral_distance);

	for(n = 0; n < gparr.length; n++)
	{
		x = (unsigned long)(gparr.array[n].pt.x * -0.25);
		y = (unsigned long)(gparr.array[n].pt.y * -0.25);

		SetPixel(test, x, y, RED);
		if(x+3 < 10000 && y+3 < 10000)
		{
			RED = interpolateColors(gparr.array[n].speed, max_speed, min_speed);

			SetPixel(test, x+3, y+3, RED);
			SetPixel(test, x+3, y+2, RED);
			SetPixel(test, x+3, y+1, RED);
			SetPixel(test, x+3, y, RED);

			SetPixel(test, x+2, y+3, RED);
			SetPixel(test, x+2, y+2, RED);
			SetPixel(test, x+2, y+1, RED);
			SetPixel(test, x+2, y, RED);

			SetPixel(test, x+1, y+3, RED);
			SetPixel(test, x+1, y+2, RED);
			SetPixel(test, x+1, y+1, RED);
			SetPixel(test, x+1, y, RED);

			SetPixel(test, x, y+3, RED);
			SetPixel(test, x, y+2, RED);
			SetPixel(test, x, y+1, RED);
			SetPixel(test, x, y, RED);
		}
	}

	SaveImage("testnoll", test);
	DeleteImage(test);
	free(gparr.array);
	return 0;
}
