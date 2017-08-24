//
// Created by Daniela Brozzoni on 17/08/17.
//



#ifndef GLHASH_READBUFFER_H
#define GLHASH_READBUFFER_H




#include <GL/glew.h>
#include <vector>
#include <OpenGL/OpenGL.h>
#include <iostream>
#include <common/definitions.h>

std::vector<unsigned char> ReadBuffer(int opt, char *filename, bool, Pixel BackgroundPixel[]);

#endif //GLHASH_READBUFFER_H
