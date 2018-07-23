/* * * * * * * * * * * * * * * * * * * * * * * * */
/* FileIO.h  * * * * * * * * * * * * * * * * * * */
/* Created by Jordan Bonecutter  * * * * * * * * */
/* 18 July 2018  * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef FILEIO_H
#define FILEIO_H

#include "Globals.h"
#include "GPSRect.h"
#include "GPSRaw.h"
#include "GPSRectArr.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern unsigned long bytes_allocd;
extern unsigned long bytes_freed;

/* Read .rgp file and returns array*/
GPSRectArr readFile(char *fname);

#endif
