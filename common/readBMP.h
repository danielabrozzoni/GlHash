//
// Created by Daniela Brozzoni on 21/08/17.
//

#ifndef GLHASH_READBMP_H
#define GLHASH_READBMP_H

struct Pixel
{
    unsigned char r, g, b;
};

Pixel *readBMP(char* filename);

#endif //GLHASH_READBMP_H
