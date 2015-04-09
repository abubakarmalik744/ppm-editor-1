#include <stdio.h>
#include <stdlib.h>
#include "ppm.h"
#include "scanner.h"

ppmPic *read(FILE *in) //reads the file in
    {
    ppmPic *myPic = malloc(sizeof(ppmPic));
    readToken(in);   //skips P3 in file header
    myPic->cols = readInt(in);
    myPic->rows = readInt(in);
    myPic->colors = readInt(in);
    myPic->pixels = malloc(sizeof(Pixel *) * (myPic->rows));
    int rowCount = 0;
    int colCount = 0;
    while(rowCount != myPic->rows)
        {
        myPic->pixels[rowCount]= malloc(sizeof(Pixel) * (myPic->cols));
        colCount = 0;
        while(colCount != myPic->cols)
            {
            myPic->pixels[rowCount][colCount].red = readInt(in);
            myPic->pixels[rowCount][colCount].green = readInt(in);
            myPic->pixels[rowCount][colCount].blue = readInt(in);
            colCount++;
            }
        rowCount++;
        }
    return myPic;    
    }

void output(ppmPic *myPic, FILE *out) //outputs the file

    {
    int rowCount = 0;
    int colCount = 0;
    fprintf(out,"P3\n");
    fprintf(out,"%d ",myPic->cols);
    fprintf(out,"%d ",myPic->rows);
    fprintf(out,"%d ",myPic->colors);
    while(rowCount != myPic->rows)
        {
        colCount = 0;
        while(colCount != myPic->cols)
            {
            fprintf(out,"%d ",myPic->pixels[rowCount][colCount].red);
            fprintf(out,"%d ",myPic->pixels[rowCount][colCount].green);
            fprintf(out,"%d ",myPic->pixels[rowCount][colCount].blue);
            colCount++;
            }
        fprintf(out,"\n");    
        rowCount++;
        }
   return;     
   }     

void invert(ppmPic *myPic)   //inverts the photo colors
    {
    int rowCount = 0;
    int colCount = 0;
    while(rowCount != myPic->rows)
        {
        colCount = 0;
        while(colCount != myPic->cols)
            {
            myPic->pixels[rowCount][colCount].red = (myPic->colors - myPic->pixels[rowCount][colCount].red);
            myPic->pixels[rowCount][colCount].green = (myPic->colors - myPic->pixels[rowCount][colCount].green);
            myPic->pixels[rowCount][colCount].blue = (myPic->colors - myPic->pixels[rowCount][colCount].blue);
            colCount++;
            }
        rowCount++;
        }
    return;    
    }

void swap(ppmPic *myPic) //swaps the photo from left to right
    {
    printf("start");
    Pixel temp;
    int rowCount = 0;
    int colCount = 0;
    while(rowCount != myPic->rows)
        {
        colCount = 0;
        while(colCount != myPic->cols/2)
            {
            temp = myPic->pixels[rowCount][colCount];
            myPic->pixels[rowCount][colCount] = myPic->pixels[(rowCount)][myPic->cols - 1 - colCount];
            myPic->pixels[rowCount][myPic->cols - 1 - colCount]= temp;
            //add one to column
            colCount++;
            }
        rowCount++;    
        }
    return;    
    }

void flip(ppmPic *myPic) //flips the photo from top to bottom
    {

    int rowCount = 0;
    Pixel *row;
    while(rowCount < (myPic->rows/2))
        {
        row = myPic->pixels[rowCount];
        myPic->pixels[rowCount] = myPic->pixels[myPic->rows - 1 - rowCount];
        myPic->pixels[myPic->rows - 1 - rowCount] = row;
        rowCount++;    
        }
    return;    
    }

//oh my god what is any of this

ppmPic *rotate(ppmPic *myPic) //rotates the image 90 degrees
    {
    ppmPic *myPicR = malloc(sizeof(ppmPic));
    myPicR->cols = myPic->rows; 
    myPicR->rows = myPic->cols;
    myPicR->colors = myPic->colors;
    myPicR->pixels = malloc(sizeof(Pixel *) * (myPicR->rows));
    int rowCount = 0;
    int colCount = 0;
    while(rowCount != myPicR->rows)
        {
        myPicR->pixels[rowCount]= malloc(sizeof(Pixel) * (myPicR->cols));
        colCount = 0;
        while(colCount != myPicR->cols)
            {
            myPicR->pixels[rowCount][colCount] = myPic->pixels[myPic->rows - 1 - colCount][rowCount];
            colCount++;
            }
        rowCount++;
        }
    return myPicR;    
    }    
