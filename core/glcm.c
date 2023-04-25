#include"glcm.h"

struct matrix3D_float* fast_glcm(struct Image2D* img, int vmin, int vmax, int nbit, int kernel_size) {
    int mi = vmin, ma = vmax;
    int ks = kernel_size;
    int h = img->matrix->H;
    int w = img->matrix->W;

    // digitize
    int* bins = linspace(mi,ma+1,nbit+1);
    int** gl1 = malloc(h * sizeof(int*));
    for (int i = 0; i < h; i++) {
        gl1[i] = malloc(w * sizeof(int));
    }
    int** gl2 = malloc(h * sizeof(int*));
    for (int i = 0; i < h; i++) {
        gl2[i] = malloc(w * sizeof(int));
        memcpy(gl2[i], gl1[i], (w - 1) * sizeof(int));
        gl2[i][w - 1] = gl1[i][w - 1];
    }

    // make glcm
    struct matrix3D_float* glcm = zeros3D(nbit,nbit,h*w);
    for (int i = 0; i < nbit; i++) {
        for (int j = 0; j < nbit; j++) {
            for (int m = 0; m < h; m++) {
                for (int n = 0; n < w; n++) {
                    if (gl1[m][n] == i && gl2[m][n] == j) {
                        glcm->matrix[i][j][m * w + n] = 1;
                    }
                }
            }
        }
    }

    // smoothing
    int** kernel = (int**)malloc(sizeof(int*)*ks);
    for(int i = 0;i < ks;i++){
        kernel[i] = (int*)malloc(sizeof(int)*ks);
    }
    
    for (int i = 0; i < ks; i++) {
        for (int j = 0; j < ks; j++) {
            kernel[i][j] = 1;
        }
    }
    for (int i = 0; i < nbit; i++) {
        for (int j = 0; j < nbit; j++) {
            filter2D(glcm->matrix[i][j], h, w, kernel); 
        }
    }

    free(bins);
    for (int i = 0; i < h; i++) {
        free(gl1[i]);
        free(gl2[i]);
    }
    for (int i = 0; i < ks; i++) {
        free(kernel[i]);
    }
    free(gl1);
    free(gl2);
    free(kernel);

    return glcm;
}


struct matrix2D_float* fast_glcm_mean(struct Image2D* img, int vmin, int vmax, int nbit, int kernel_size) {
    struct matrix3D_float* glcm = fast_glcm(img, vmin, vmax, nbit, kernel_size);
    
    int h = img->matrix->H;
    int w = img->matrix->W;
    
    struct matrix2D_float* mean = zeros2D_float(h,w);
    
    for (int i = 0; i < nbit; i++) {
        for (int j = 0; j < nbit; j++) {
            for (int m = 0; m < h; m++) {
                for (int n = 0; n < w; n++) {
                    mean->matrix[m][n] += glcm->matrix[i][j][m * w + n] * i / (float)(nbit * nbit);
                }
            }
        }
    }
    
    return mean;
}