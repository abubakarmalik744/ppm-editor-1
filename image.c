//created by Luke Zahorik, 2015
#include <stdio.h>
#include <string.h>
#include "ppm.h"


int main(int argc,char **argv)
{
    int i = 1;
    ppmPic *myPic;
    if(argc == 1)
        {
        printf("To use this program, you need to enter your request in the following format: \n");
        printf("./image [command] [any other commands you want] [file name]\n");
        printf("The following commands work for the following functions: \n");
        printf("-i OR --invert to invert the pixels on the image\n");
        printf("-f OR --flip to flip the image from top to bottom\n");
        printf("-s OR --swap to swap the image from left to right\n");
        printf("-r OR --rotate to rotate the image 90 degrees clockwise\n");
        printf("-o OR --output to specify the file name where the modified file should be written\n");
        printf("Note that the last argument is ALWAYS your file you are modifying\n");
        return 0;
        }

    FILE *in = fopen(argv[argc - 1], "r");
    myPic = read(in);
    //close file before writing
    //same statement as above, but with "w" instead
    FILE *out = stdout;
    while(i < argc - 1)
        {
        if(strcmp(argv[i],"-i") == 0 || strcmp(argv[i],"--invert") == 0) //if they type invert cmd
            {
            invert(myPic);
            }
        else if(strcmp(argv[i],"-f") == 0 || strcmp(argv[i],"--flip") == 0) //if they type flip cmd
            {
            flip(myPic);
            }
        else if(strcmp(argv[i],"-s") == 0 || strcmp(argv[i],"--swap") == 0) //if they type swap cmd
            {
            swap(myPic);
            }
        else if(strcmp(argv[i],"-r") == 0 || strcmp(argv[i],"--rotate") == 0) //if they type rotate cmd
            {
            myPic = rotate(myPic);
            }
        else if(strcmp(argv[i],"-o") == 0 || strcmp(argv[i],"--output") == 0) //if they type output cmd
            {
            out = fopen(argv[i+1], "w");
            }
        else
            {
            printf("option %s is an invalid option!\n",argv[i]); //if you type in something not a cmd
            }
        i++;
        }
    //output results of all commands
    output(myPic,out);
    return 0;
}

