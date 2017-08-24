//
// Created by Daniela Brozzoni on 21/08/17.
//
#include <common/readBMP.h>


void readBMP(char* filename, Pixel Backgroundpixels[])
{
    int i;
    FILE* f = fopen(filename, "rb");

    /**
     *  \todo
     *      Decide what to do if filename is an invalid path, exit(0) is a good idea?
     */


    if(f == NULL)
        return;

    unsigned char info[54];
    fread(info, sizeof(unsigned char), 54, f); // read the 54-byte header

    // extract image height and width from header
    int width = *(int*)&info[18];
    int height = *(int*)&info[22];

    int size = 3 * width * height;
    unsigned char* data = new unsigned char[size]; // allocate 3 bytes per pixel
    fread(data, sizeof(unsigned char), (size_t) size, f); // read the rest of the data at once
    fclose(f);

    for(i = 0; i < size; i += 3)
    {
        Backgroundpixels[i].r = data[i+2];
        Backgroundpixels[i].g = data[i+1];
        Backgroundpixels[i].b = data[i];
    }
}

