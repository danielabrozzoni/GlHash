//
// Created by Daniela Brozzoni on 17/08/17.
//



#ifndef GLHASH_READBUFFER_H
#define GLHASH_READBUFFER_H

#include <GL/glew.h>
#include <vector>
#include <OpenGL/OpenGL.h>
#include <iostream>

std::vector<unsigned char> ReadBuffer(int opt, char *filename, bool);

#endif //GLHASH_READBUFFER_H
