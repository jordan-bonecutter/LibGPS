/*********************************************************************/
/* Homework Assignment 5, for EECS 22, Fall 2017                     */
/*                                                                   */
/* Author: Tim Schmidt (modified by Jordan Bonecutter)               */
/* Date: 06/03/2018                                                  */
/*                                                                   */
/* Image.c: source file for basic image manipulations                */
/*                                                                   */
/*********************************************************************/

#include <stdlib.h>
#include <assert.h>
#include "Image.h"

/* Get the intensity value of the Red channel of pixel (x, y) */
/* in the RGB image */
unsigned char GetPixelR(const IMAGE *image, unsigned int x, unsigned int y)
{
	assert(image);

	assert(x < image->W);
	assert(y < image->H);
    assert(image->Pixels);

	return image->Pixels[x + y * image->W].R;
}

/* Get the intensity value of the Green channel of pixel (x, y) */
/* in the RGB image */
unsigned char GetPixelG(const IMAGE *image, unsigned int x, unsigned int y)
{
	assert(image);

	assert(x < image->W);
	assert(y < image->H);
    assert(image->Pixels);

	return image->Pixels[x + y * image->W].G;
}

/* Get the intensity value of the Blue channel of pixel (x, y) */
/* in the RGB image */
unsigned char GetPixelB(const IMAGE *image, unsigned int x, unsigned int y)
{
	assert(image);

	assert(x < image->W);
	assert(y < image->H);
    assert(image->Pixels);

	return image->Pixels[x + y * image->W].B;
}

/* Get the intensity values of all channels of pixel (x, y) */
/* in the RGB image */
PIXEL GetPixel(const IMAGE *image, unsigned int x, unsigned int y)
{
    assert(image);
    assert(x < image->W);
    assert(y < image->H);
    assert(image->Pixels);

    return image->Pixels[x + y * image->W];
}

/* Set the intensity value of the Red channel of pixel (x, y) */
/* in the RGB image with valueR */
void SetPixelR(IMAGE *image, unsigned int x, unsigned int y,
               unsigned char valueR)
{
	assert(image);

	assert(x < image->W);
	assert(y < image->H);
    assert(image->Pixels);

    image->Pixels[x + y * image->W].R = valueR;
}

/* Set the intensity value of the Green channel of pixel (x, y) */
/* in the RGB image with valueG */
void SetPixelG(IMAGE *image, unsigned int x, unsigned int y,
               unsigned char valueG)
{
	assert(image);

	assert(x < image->W);
	assert(y < image->H);
    assert(image->Pixels);

    image->Pixels[x + y * image->W].G = valueG;
}

/* Set the intensity value of the Blue channel of pixel (x, y) */
/* in the RGB image with valueB */
void SetPixelB(IMAGE *image, unsigned int x, unsigned int y,
               unsigned char valueB)
{
	assert(image);

	assert(x < image->W);
	assert(y < image->H);
    assert(image->Pixels);

    image->Pixels[x + y * image->W].B = valueB;
}

/* Set the intensity value of all channels of pixel (x, y) */
/* in the RGB image with valueB */
void SetPixel(IMAGE *image, unsigned int x, unsigned int y, PIXEL p)
{
    assert(image);

    assert(x < image->W);
    assert(y < image->H);
    assert(image->Pixels);

    image->Pixels[x + y * image->W] = p;
}

/* Allocate the memory space for the RGB image and the memory spaces */
/* for the RGB intensity values. Return the pointer to the RGB image. */
IMAGE *CreateImage(unsigned int width, unsigned int height)
{
	IMAGE *image = (IMAGE *)malloc(sizeof(IMAGE));
	if (image == NULL) {
		return NULL;
	}

	image->W = width;
	image->H = height;
    image->Pixels = (PIXEL *)malloc(sizeof(PIXEL) * width * height);

    return image;
}

/* Copies an image */
IMAGE *CopyImage(const IMAGE *image)
{
    assert(image);
    assert(image->W);
    assert(image->H);
    assert(image->Pixels);

    unsigned int WIDTH = image->W;
    unsigned int HEIGHT = image->H;
    IMAGE *copy = CreateImage(WIDTH, HEIGHT);
    unsigned int x, y;
    for(y = 0; y < HEIGHT; y++)
    {
        for(x = 0; x < WIDTH; x++)
        {
            SetPixel(copy, x, y, GetPixel(image, x, y));
        }
    }
    return copy;
}

/* Release the memory spaces for the RGB intensity values. */
/* Release the memory space for the RGB image. */
void DeleteImage(IMAGE *image)
{
	assert(image);
    assert(image->Pixels);
    free(image->Pixels);
    image->Pixels = NULL;

    free(image);
}

/* Get the intensity value of the Y channel of pixel (x, y) */
/* in the YUV image */
unsigned char GetPixelY(const YUVIMAGE *YUVimage, unsigned int x, unsigned int y)
{
	assert(YUVimage);

	assert(x < YUVimage->W);
	assert(y < YUVimage->H);
#if 0
	assert(YUVimage->Y);
	assert(YUVimage->U);
	assert(YUVimage->V);
#endif
    assert(YUVimage->Pixels);
	return YUVimage->Pixels[x + y * YUVimage->W].Y;
}

/* Get the intensity value of the U channel of pixel (x, y) */
/* in the YUV image */
unsigned char GetPixelU(const YUVIMAGE *YUVimage, unsigned int x, unsigned int y)
{
	assert(YUVimage);

	assert(x < YUVimage->W);
	assert(y < YUVimage->H);
#if 0
	assert(YUVimage->Y);
	assert(YUVimage->U);
	assert(YUVimage->V);
#endif
    assert(YUVimage->Pixels);
	return YUVimage->Pixels[x + y * YUVimage->W].U;
}

/* Get the intensity value of the V channel of pixel (x, y) */
/* in the YUV image */
unsigned char GetPixelV(const YUVIMAGE *YUVimage, unsigned int x, unsigned int y)
{
	assert(YUVimage);

	assert(x < YUVimage->W);
	assert(y < YUVimage->H);
#if 0
	assert(YUVimage->Y);
	assert(YUVimage->U);
	assert(YUVimage->V);
#endif
    assert(YUVimage->Pixels);
	return YUVimage->Pixels[x + y * YUVimage->W].V;
}

/* Get the intensity value of all channels of pixel (x, y) */
/* in the YUV image */
YUVPIXEL GetYUVPixel(const YUVIMAGE *YUVimage, unsigned int x, unsigned int y)
{
    assert(YUVimage);

    assert(x < YUVimage->W);
    assert(y < YUVimage->H);

    assert(YUVimage->Pixels);
    return YUVimage->Pixels[x + y * YUVimage->W];
}

/* Set the intensity value of the Y channel of pixel (x, y) */
/* in the YUV image with valueY */
void SetPixelY(YUVIMAGE *YUVimage, unsigned int x, unsigned int y,
               unsigned char valueY)
{
	assert(YUVimage);

	assert(x < YUVimage->W);
	assert(y < YUVimage->H);
#if 0
	assert(YUVimage->Y);
	assert(YUVimage->U);
	assert(YUVimage->V);
#endif
    assert(YUVimage->Pixels);
	YUVimage->Pixels[x + y * YUVimage->W].Y = valueY;
}

/* Set the intensity value of the U channel of pixel (x, y) */
/* in the YUV image with valueU */
void SetPixelU(YUVIMAGE *YUVimage, unsigned int x, unsigned int y,
               unsigned char valueU)
{
	assert(YUVimage);

	assert(x < YUVimage->W);
	assert(y < YUVimage->H);
#if 0
	assert(YUVimage->Y);
	assert(YUVimage->U);
	assert(YUVimage->V);
#endif
    assert(YUVimage->Pixels);
	YUVimage->Pixels[x + y * YUVimage->W].U = valueU;
}

/* Set the intensity value of the V channel of pixel (x, y) */
/* in the YUV image with valueV */
void SetPixelV(YUVIMAGE *YUVimage, unsigned int x, unsigned int y,
               unsigned char valueV)
{
	assert(YUVimage);

	assert(x < YUVimage->W);
	assert(y < YUVimage->H);
#if 0
	assert(YUVimage->Y);
	assert(YUVimage->U);
	assert(YUVimage->V);
#endif
    assert(YUVimage->Pixels);
	YUVimage->Pixels[x + y * YUVimage->W].V = valueV;
}

/* Set the intensity value of all channels of pixel (x, y) */
/* in the YUV image with valueV */
void SetYUVPixel(YUVIMAGE *YUVimage, unsigned int x, unsigned int y, YUVPIXEL p)
{
    assert(YUVimage);

    assert(x < YUVimage->W);
    assert(y < YUVimage->H);

    assert(YUVimage->Pixels);
    YUVimage->Pixels[x + y * YUVimage->W] = p;
}

/* Allocate the memory space for the YUV image and the memory spaces */
/* for the YUV intensity values. Return the pointer to the YUV image. */
YUVIMAGE *CreateYUVImage(unsigned int width, unsigned int height)
{
	YUVIMAGE *YUVimage = (YUVIMAGE *)malloc(sizeof(YUVIMAGE));
	if (YUVimage == NULL) {
		return NULL;
	}

	YUVimage->W = width;
	YUVimage->H = height;
    YUVimage->Pixels = (YUVPIXEL *)malloc(width * height * sizeof(YUVPIXEL));
	return YUVimage;
}

/* Release the memory spaces for the YUV intensity values. */
/* Release the memory space for the YUV image. */
void DeleteYUVImage(YUVIMAGE *YUVimage)
{
	assert(YUVimage);
    assert(YUVimage->Pixels);
    free(YUVimage->Pixels);
    YUVimage->Pixels = NULL;
	free(YUVimage);
}

/* Converts an RGB pixel to a YUV pixel */
YUVPIXEL ConvertToYUVPIXEL(PIXEL p)
{
    YUVPIXEL res;
    int roundval = (((66*p.R + 129*p.G + 25*p.B + 128)>>8) + 16);
    roundval = roundval > 255 ? 255 : roundval;
    roundval = roundval < 0 ? 0 : roundval;
    res.Y = roundval;

    roundval = (((-38*p.R - 74*p.G + 112*p.B + 128)>>8) + 128);
	roundval = roundval > 255 ? 255 : roundval;
	roundval = roundval < 0 ? 0 : roundval;
    res.U = roundval;

	roundval = (((112*p.R - 94*p.G - 18*p.B + 128)>>8) + 128);
	roundval = roundval > 255 ? 255 : roundval;
	roundval = roundval < 0 ? 0 : roundval;
    res.V = roundval;

    return res;
}

/* Convert an RGB image to a YUV image */
YUVIMAGE *ConvertToYUV(IMAGE *image)
{
	const short WIDTH = image->W;
	const short HEIGHT = image->H;
	int x, y;
    YUVIMAGE *new = CreateYUVImage(WIDTH, HEIGHT);
	
	for(x = 0; x < WIDTH; x++)
	{
		for(y = 0; y < HEIGHT; y++)
		{
            SetYUVPixel(new, x, y, ConvertToYUVPIXEL(GetPixel(image, x, y)));
        }//rof
	}//rof
	return new;
}

/* Returns the width of an image */
unsigned int ImageWidth(IMAGE *image)
{
    return image->W;
}

/* Returns the height of an image */
unsigned int ImageHeight(IMAGE *image)
{
    return image->H;
}

/* EOF */
