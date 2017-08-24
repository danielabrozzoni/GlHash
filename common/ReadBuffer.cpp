//
// Created by Daniela Brozzoni on 17/08/17.
//

#include "ReadBuffer.h"

#define HowMuchParam 4          // If it equals 4 we're using RGBA, RGB otherwise

using namespace std;
vector< unsigned char > pixels( Window_Width * Window_Height * HowMuchParam * 2);

void WriteFile(char *filename)
{
    FILE *out;
    out = freopen(filename, "w", stdout);

    for(int i = 0; i < Window_Width* Window_Height * HowMuchParam; i+=HowMuchParam)
    {
        for(int j = 0; j < HowMuchParam; j++)
            printf("%d ", (int) pixels[i+j]);
        printf("\n");
    }
}


vector<unsigned char> ReadBuffer(int option, char *filename, bool write, Pixel Backgroundpixels[])
{
    int cont;

    /**
     *  I'M DESPERATE I CAN'T WRITE IT BETTER I'M SORRY SOMEONE HELP ME PLZ
     *  \todo
     *      find a way to delete switch(option)
     *      find a way to store pixels in a struct using glReadPixels
     */

    switch(option)
    {
        default:
            cout << "Wrong parameter" << endl;
        case 0:
            cont = 0;

            for(int x = 0; x < Window_Width; x++)
                for(int y = 0; y < Window_Height; y++)
                {
                    glReadPixels (x, y, Window_Width, Window_Height, GL_RGBA, GL_UNSIGNED_BYTE, &pixels[cont]);
                    if(pixels[cont+3] == 0)     // background
                    {
                        pixels[cont] = Backgroundpixels[cont/HowMuchParam].r;
                        pixels[cont+1] = Backgroundpixels[cont/HowMuchParam].g;
                        pixels[cont+2] = Backgroundpixels[cont/HowMuchParam].b;
                        pixels[cont+3] = 255;
                    }
                    cont += HowMuchParam;
                }
        break;

        case 1:
            cont = 0;

            for(int y = 0; y < Window_Height; y++)
                for(int x = 0; x < Window_Width; x++)
                {
                    glReadPixels (x, y, Window_Width, Window_Height, GL_RGBA, GL_UNSIGNED_BYTE, &pixels[cont]);
                    cont += HowMuchParam;
                    if(pixels[cont+3] == 0)     // background
                    {
                        pixels[cont] = Backgroundpixels[cont/HowMuchParam].r;
                        pixels[cont+1] = Backgroundpixels[cont/HowMuchParam].g;
                        pixels[cont+2] = Backgroundpixels[cont/HowMuchParam].b;
                        pixels[cont+3] = 255;
                    }
                }
        break;

        case 2:
            cont = 0;

            for(int x = Window_Width - 1; x >= 0; x--)
                for(int y = Window_Height - 1; y >= 0; y--)
                {
                    glReadPixels (x, y, Window_Width, Window_Height, GL_RGBA, GL_UNSIGNED_BYTE, &pixels[cont]);
                    cont += HowMuchParam;
                    if(pixels[cont+3] == 0)     // background
                    {
                        pixels[cont] = Backgroundpixels[cont/HowMuchParam].r;
                        pixels[cont+1] = Backgroundpixels[cont/HowMuchParam].g;
                        pixels[cont+2] = Backgroundpixels[cont/HowMuchParam].b;
                        pixels[cont+3] = 255;
                    }
                }
        break;

        case 3:
            cont = 0;

            for(int y = Window_Height - 1; y >= 0; y--)
                for(int x = Window_Width - 1; x >= 0; x--)
                {
                    glReadPixels (x, y, Window_Width, Window_Height, GL_RGBA, GL_UNSIGNED_BYTE, &pixels[cont]);
                    cont += HowMuchParam;
                    if(pixels[cont+3] == 0)     // background
                    {
                        pixels[cont] = Backgroundpixels[cont/HowMuchParam].r;
                        pixels[cont+1] = Backgroundpixels[cont/HowMuchParam].g;
                        pixels[cont+2] = Backgroundpixels[cont/HowMuchParam].b;
                        pixels[cont+3] = 255;
                    }
                }
        break;

    }

    if(write)
        WriteFile(filename);


    return pixels;

}
