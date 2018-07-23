/*********************************************************************/
/* Homework Assignment 5, for EECS 22, Fall 2017                     */
/*                                                                   */
/* Author: Tim Schmidt (modified by Jordan Bonecutter)               */
/* Date: 06/03/2018                                                  */
/*                                                                   */
/* Image.h: header file for basic image manipulations                */
/*                                                                   */
/*********************************************************************/

#ifndef IMAGE_H
#define IMAGE_H

/* Holds the R, G, and B intensity values for a pixel*/
typedef struct {
    unsigned char R;
    unsigned char G;
    unsigned char B;
} PIXEL;

typedef struct {
	unsigned int W;       /* Image width */
	unsigned int H;       /* Image height */
	
	PIXEL *Pixels;              
            /* all the Pixel values */
} IMAGE;

/* Get the intensity value of the Red channel of pixel (x, y) */
/* in the RGB image */
unsigned char GetPixelR(const IMAGE *image, unsigned int x, unsigned int y);

/* Get the intensity value of the Green channel of pixel (x, y) */
/* in the RGB image */
unsigned char GetPixelG(const IMAGE *image, unsigned int x, unsigned int y);

/* Get the intensity value of the Blue channel of pixel (x, y) */
/* in the RGB image */
unsigned char GetPixelB(const IMAGE *image, unsigned int x, unsigned int y);

/* Get the PIXEL struct at a certain location in the image */
/* The pixel is in RGB */
PIXEL GetPixel(const IMAGE *image, unsigned int x, unsigned int y);

/* Set the intensity value of the Red channel of pixel (x, y) */
/* in the RGB image with valueR */
void SetPixelR(IMAGE *image, unsigned int x, unsigned int y,
               unsigned char valueR);

/* Set the intensity value of the Green channel of pixel (x, y) */
/* in the RGB image with valueG */
void SetPixelG(IMAGE *image, unsigned int x, unsigned int y,
               unsigned char valueG);

/* Set the intensity value of the Blue channel of pixel (x, y) */
/* in the RGB image with valueB */
void SetPixelB(IMAGE *image, unsigned int x, unsigned int y,
               unsigned char valueB);

/* Takes in a PIXEL struct and sets the pixel at (x, y) */
/* to be the same as PIXEL p */
void SetPixel(IMAGE *image, unsigned int x, unsigned int y, PIXEL p);

/* Allocate the memory space for the RGB image and the memory spaces */
/* for the RGB intensity values. Return the pointer to the RGB image. */
IMAGE *CreateImage(unsigned int width, unsigned int height);

/* Allocate the memory space for the copied RGB image and the memory spaces */
/* for the RGB intensity values. Return the pointer to the new RGB image*/
IMAGE *CopyImage(const IMAGE *image);

/* Returns image width */
unsigned int ImageHeight(IMAGE *image);

/* Returns image height*/
unsigned int ImageWidth(IMAGE *image);

/* Release the memory spaces for the RGB intensity values. */
/* Release the memory space for the RGB image. */
void DeleteImage(IMAGE *image);

/* Holds the Y, U, and V intensity values for a YUV pixel*/
typedef struct{
    unsigned char Y;
    unsigned char U;
    unsigned char V;
}YUVPIXEL;

typedef struct {
	unsigned int W;       /* Image width */
	unsigned int H;       /* Image height */
    YUVPIXEL *Pixels;
} YUVIMAGE;

/* Get the intensity value of the Y channel of pixel (x, y) */
/* in the YUV image */
unsigned char GetPixelY(const YUVIMAGE *YUVimage, unsigned int x, unsigned int y);

/* Get the intensity value of the U channel of pixel (x, y) */
/* in the YUV image */
unsigned char GetPixelU(const YUVIMAGE *YUVimage, unsigned int x, unsigned int y);

/* Get the intensity value of the V channel of pixel (x, y) */
/* in the YUV image */
unsigned char GetPixelV(const YUVIMAGE *YUVimage, unsigned int x, unsigned int y);

YUVPIXEL GetYUVPixel(const YUVIMAGE *YUVimage, unsigned int x, unsigned int y);

/* Set the intensity value of the Y channel of pixel (x, y) */
/* in the YUV image with valueY */
void SetPixelY(YUVIMAGE *YUVimage, unsigned int x, unsigned int y,
               unsigned char valueY);

/* Set the intensity value of the U channel of pixel (x, y) */
/* in the YUV image with valueU */
void SetPixelU(YUVIMAGE *YUVimage, unsigned int x, unsigned int y,
               unsigned char valueU);

/* Set the intensity value of the V channel of pixel (x, y) */
/* in the YUV image with valueV */
void SetPixelV(YUVIMAGE *YUVimage, unsigned int x, unsigned int y,
               unsigned char valueV);

void SetYUVPixel(YUVIMAGE *YUVimage, unsigned int x, unsigned int y, YUVPIXEL p);

/* Allocate the memory space for the YUV image and the memory spaces */
/* for the YUV intensity values. Return the pointer to the YUV image. */
YUVIMAGE *CreateYUVImage(unsigned int width, unsigned int height);

/* Release the memory spaces for the YUV intensity values. */
/* Release the memory space for the YUV image. */
void DeleteYUVImage(YUVIMAGE *YUVimage);

/* Convert an RGB image to a YUV image */
YUVIMAGE *ConvertToYUV(IMAGE *image);

#endif
