#include"numeric.h"
#include<string.h>
#ifndef GLCM
#define GLCM

/**
 * @brief 生成图像的共生矩阵
 * 
 * @param img 
 * @param vmin 0
 * @param vmax 255
 * @param nbit 8
 * @param kernel_size 5 
 * @return struct matrix3D* 图像的共生矩阵
 */
struct matrix3D_float* fast_glcm(struct Image2D* img, int vmin, int vmax, int nbit, int kernel_size);

/**
 * @brief 生成glcm均值
 * 
 * @param img 
 * @param vmin 0
 * @param vmax 255
 * @param nbit 8
 * @param kernel_size 5 
 * @return struct matrix2D_float* 返回glcm均值 
 */
struct matrix2D_float* fast_glcm_mean(struct Image2D* img, int vmin, int vmax, int nbit, int kernel_size);

#endif // !GLCM