#include"numeric.h"
#include<string.h>
#ifndef GLCM
#define GLCM

struct matrix3D* fast_glcm(struct Image2D* img, int vmin, int vmax, int nbit, int kernel_size);
struct matrix2D_float* fast_glcm_mean(struct Image2D* img, int vmin, int vmax, int nbit, int kernel_size);

#endif // !GLCM