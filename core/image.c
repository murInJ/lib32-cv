#include "image.h"

void BGR2GRAY(struct Image3D* src, struct Image2D* dst)
{
    if(src->type != BGR) return;
    freeMatrix2D(dst->matrix);
    struct matrix2D* zeros = zeros2D(src->matrix->H,src->matrix->W);
    int i,j;
    for(i=0; i<src->matrix->H; i++)
    {
        for(j=0; j<src->matrix->W; j++)
        {
            zeros->matrix[i*src->matrix->W+j] = (unsigned char)(0.299*src->matrix->matrix[i][j][2] +  
                                             0.587*src->matrix->matrix[i][j][1] +  
                                             0.114*src->matrix->matrix[i][j][0]);
        }
    }
    dst->type = GRAY;
    dst->matrix = zeros;
}

void BGR2RGB(struct Image3D* src, struct Image3D* dst)
{
    int i, j;
    freeMatrix3D_float(dst->matrix);
    struct matrix3D* zeros = zeros3D(src->matrix->H,src->matrix->W,src->matrix->C);
    for(i=0; i<src->matrix->H; i++) {
        for(j=0; j<src->matrix->W; j++) {
            dst->matrix->matrix[i][j][0]  = src->matrix->matrix[i][j][2];
            dst->matrix->matrix[i][j][1]  = src->matrix->matrix[i][j][1];
            dst->matrix->matrix[i][j][2]  = src->matrix->matrix[i][j][0];
        }
    }
    dst->type = RGB;
}