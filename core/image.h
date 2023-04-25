#include "matrix.h"
#ifndef IMAGE
#define IMAGE

enum ImageType
{
  BGR,GRAY,RGB  
};

struct Image2D
{
    struct matrix2D* matrix;
    unsigned char type;
};

struct Image3D
{
    struct matrix3D* matrix;
    unsigned char type;
};

struct Image2D_float
{
    struct matrix2D_float* matrix;
    unsigned char type;
};

struct Image3D_float
{
    struct matrix3D_float* matrix;
    unsigned char type;
};

void BGR2GRAY(struct Image3D* src, struct Image2D* dst);
void BGR2RGB(struct Image3D* src, struct Image3D* dst);

#endif // !IMAGE
