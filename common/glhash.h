//
// Created by Alekos Filini on 17/08/2017.
//

#ifndef GLHASH_GLHASH_H
#define GLHASH_GLHASH_H

#include <cstddef>
#include <cstdlib>
#include <GL/glew.h>
#include "sha256.h"

const float *getBackgroundColor(unsigned char byte);

float mapBitsToFloat(unsigned char byte, size_t nbits, size_t offset, float min, float max);

GLfloat *getCoordinates(BYTE *input);

#endif //GLHASH_GLHASH_H
