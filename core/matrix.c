#include "matrix.h"

struct matrix2D* zeros2D(unsigned int H,unsigned int W){
    unsigned int i;
    unsigned char** zeros = (unsigned char**)malloc(sizeof(unsigned char*) * H);
    for(i = 0;i < H;i++){
        zeros[i] = malloc(sizeof(unsigned char) * W);
    }
    
    struct matrix2D* matrix = malloc(sizeof(struct matrix2D));
    matrix->matrix = zeros;
    matrix->H = H;
    matrix->W = W;

    return matrix;
}

struct matrix3D* zeros3D(unsigned int H,unsigned int W,unsigned int C){
    unsigned int i,j;
    unsigned char*** zeros = (unsigned char***)malloc(sizeof(unsigned char**) * H);
    for(i = 0;i < H;i++){
        zeros[i] = malloc(sizeof(unsigned char*) * W);
        for(j=0;j < W;j++){
            zeros[i][j] = malloc(sizeof(unsigned char) * C);
        }
    }
    
    struct matrix3D* matrix = malloc(sizeof(struct matrix3D));
    matrix->matrix = zeros;
    matrix->H = H;
    matrix->W = W;
    matrix->C = C;

    return matrix;
}

struct matrix2D_float* zeros2D_float(unsigned int H,unsigned int W){
    unsigned int i;
    float** zeros = (float**)malloc(sizeof(float*) * H);
    for(i = 0;i < H;i++){
        zeros[i] = malloc(sizeof(float) * W);
    }
    
    struct matrix2D_float* matrix = malloc(sizeof(struct matrix2D_float));
    matrix->matrix = zeros;
    matrix->H = H;
    matrix->W = W;

    return matrix;
}

struct matrix3D_float* zeros3D_float(unsigned int H,unsigned int W,unsigned int C){
    unsigned int i,j;
    float*** zeros = (float***)malloc(sizeof(float**) * H);
    for(i = 0;i < H;i++){
        zeros[i] = malloc(sizeof(float*) * W);
        for(j=0;j < W;j++){
            zeros[i][j] = malloc(sizeof(float) * C);
        }
    }
    
    struct matrix3D_float* matrix = malloc(sizeof(struct matrix3D_float));
    matrix->matrix = zeros;
    matrix->H = H;
    matrix->W = W;
    matrix->C = C;

    return matrix;
}

void freeMatrix2D(struct matrix2D* matrix){
    int i;
    for(i = 0; i < matrix->H;i++){
        free(matrix->matrix[i]);
    }
    free(matrix->matrix);
    free(matrix);
}

void freeMatrix3D(struct matrix3D* matrix){
    int i,j;
    for(i = 0; i < matrix->H;i++){
        for(j = 0; j < matrix->W;j++){
            free(matrix->matrix[i][j]);
        }
        free(matrix->matrix[i]);
    }
    free(matrix->matrix);
    free(matrix);
}

void freeMatrix3D_float(struct matrix3D_float* matrix){
    int i,j;
    for(i = 0; i < matrix->H;i++){
        for(j = 0; j < matrix->W;j++){
            free(matrix->matrix[i][j]);
        }
        free(matrix->matrix[i]);
    }
    free(matrix->matrix);
    free(matrix);
}

void freeMatrix2D_float(struct matrix2D_float* matrix){
    int i;
    for(i = 0; i < matrix->H;i++){
        free(matrix->matrix[i]);
    }
    free(matrix->matrix);
    free(matrix);
}







