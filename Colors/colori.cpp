#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	FILE *out;
	out = freopen("GlHash/Colors/coloriSfondo.txt", "w", stdout);
	srand(time(NULL));

	for(int i = 0; i < 256; i++)
		printf("{%.4ff, %.4ff, %.4ff},\n", (rand()%10000)/10000.0, (rand()%10000)/10000.0, (rand()%10000)/10000.0);
}