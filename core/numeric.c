#include"numeric.h"

void filter2D(float** img, int h, int w, int** kernel){
    int ks = sizeof(kernel) / sizeof(kernel[0]);
    int half_ks = ks / 2;
    
    unsigned char** temp = malloc((h + ks - 1) * sizeof(unsigned char*));
    for (int i = 0; i < h + ks - 1; i++) {
        temp[i] = malloc((w + ks - 1) * sizeof(unsigned char));
    }
    
    // padding
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            temp[i + half_ks][j + half_ks] = img-[i][j]; 
        }
    }
    
    // filtering
    for (int i = half_ks; i < h + half_ks; i++) {
        for (int j = half_ks; j < w + half_ks; j++) {
            int sum = 0;
            for (int m = 0; m < ks; m++) {
                for (int n = 0; n < ks; n++) {
                    sum += kernel[m][n] * temp[i - half_ks + m][j - half_ks + n];
                }
            }
            img[i - half_ks][j - half_ks] = sum / ks / ks;
        }
    }
    
    for (int i = 0; i < h + ks - 1; i++) {
        free(temp[i]);
    }
    free(temp);
}

int* linspace(int start,int end,int num){
    int* bins = malloc((num + 1) * sizeof(int));
    for (int i = 0; i <= num; i++) {
        bins[i] = start + i * (end - start) / num;
    }
    return bins;
}
