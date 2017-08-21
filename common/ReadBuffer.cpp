//
// Created by Daniela Brozzoni on 17/08/17.
//

#include "ReadBuffer.h"
#define w 133
#define h 100
#define HowMuchParam 4

using namespace std;
vector< unsigned char > pixels( w * h * HowMuchParam * 2);

void WriteFile(char *filename)
{
    FILE *out;
    out = freopen(filename, "w", stdout);

    for(int i = 0; i < w*h*HowMuchParam; i+=HowMuchParam)
    {
        for(int j = 0; j < HowMuchParam; j++)
            cout << (int) pixels[i+j] << " ";
        cout << endl;
    }
}


vector<unsigned char> ReadBuffer(int option, char *filename, bool write)
{
    int cont;
    switch(option)
    {
        default:
            cout << "Wrong parameter" << endl;
        case 0:
            cont = 0;

            for(int x = 0; x < w; x++)
                for(int y = 0; y < h; y++)
                {
                    glReadPixels (x, y, w, h, GL_RGBA, GL_UNSIGNED_BYTE, &pixels[cont]);
                    cont += HowMuchParam;
                }
        break;

        case 1:
            cont = 0;

            for(int y = 0; y < h; y++)
                for(int x = 0; x < w; x++)
                {
                    glReadPixels (x, y, w, h, GL_RGBA, GL_UNSIGNED_BYTE, &pixels[cont]);
                    cont += HowMuchParam;
                }
        break;

        case 2:
            cont = 0;

            for(int x = w - 1; x >= 0; x--)
                for(int y = h - 1; y >= 0; y--)
                {
                    glReadPixels (x, y, w, h, GL_RGBA, GL_UNSIGNED_BYTE, &pixels[cont]);
                    cont += HowMuchParam;
                }
        break;

        case 3:
            cont = 0;

            for(int y = h - 1; y >= 0; y--)
                for(int x = w - 1; x >= 0; x--)
                {
                    glReadPixels (x, y, w, h, GL_RGBA, GL_UNSIGNED_BYTE, &pixels[cont]);
                    cont += HowMuchParam;

                }
        break;

    }

    if(write)
        WriteFile(filename);

    return pixels;

}
