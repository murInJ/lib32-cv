#ifndef MATRIX
#define MATRIX 

struct matrix2D
{
    unsigned char** matrix;
    unsigned int H,W;
};

struct matrix3D
{
    unsigned char*** matrix;
    unsigned int H,W,C;
};

struct matrix2D_float
{
    float** matrix;
    unsigned int H,W;
};

struct matrix3D_float
{
    float*** matrix;
    unsigned int H,W,C;
};

struct matrix2D* zeros2D(unsigned int H,unsigned int W);
struct matrix3D* zeros3D(unsigned int H,unsigned int W,unsigned int C);
struct matrix2D_float* zeros2D_float(unsigned int H,unsigned int W);
struct matrix3D_float* zeros3D_float(unsigned int H,unsigned int W,unsigned int C);

void freeMatrix2D(struct matrix2D* matrix);
void freeMatrix3D(struct matrix3D* matrix);
void freeMatrix3D_float(struct matrix3D_float* matrix);
void freeMatrix2D_float(struct matrix2D_float* matrix);

#endif // MATRIX
