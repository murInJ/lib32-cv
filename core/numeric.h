#include "image.h"
#ifndef NUMERIC
#define NUMERIC

void filter2D(float** img, int h, int w, int** kernel);
int* linspace(int start,int end,int num);
#endif // !NUMERIC