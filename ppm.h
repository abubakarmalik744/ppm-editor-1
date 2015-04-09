#include <stdio.h>
#ifndef PPM_STRUCT
#define RGB_STRUCT

typedef struct pixel
{
    int red; //red value
    int green; //green value
    int blue; //blue value
} Pixel;

#endif
#ifndef PPM_STRUCT
#define PPM_STRUCT

typedef struct ppm
{
    int rows; //number of rows
    int cols; //number of columns
    int colors; //number of colors
    Pixel **pixels; //actual pixel data
} ppmPic;

#endif
ppmPic *read(FILE*);
void output(ppmPic*,FILE*);
void invert(ppmPic*);
void swap(ppmPic*);
void flip(ppmPic*);
ppmPic *rotate(ppmPic*);

