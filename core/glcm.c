// unsigned char*** fast_glcm(unsigned char** img, int vmin, int vmax, int nbit, int kernel_size) {
//     int mi = vmin, ma = vmax;
//     int ks = kernel_size;
//     int h = sizeof(img) / sizeof(img[0]);
//     int w = sizeof(img[0]) / sizeof(img[0][0]);

//     // digitize
//     int* bins = malloc((nbit + 1) * sizeof(int));
//     for (int i = 0; i <= nbit; i++) {
//         bins[i] = mi + i * (ma - mi) / nbit;
//     }
//     int** gl1 = malloc(h * sizeof(int*));
//     for (int i = 0; i < h; i++) {
//         gl1[i] = malloc(w * sizeof(int));
//     }
//     int** gl2 = malloc(h * sizeof(int*));
//     for (int i = 0; i < h; i++) {
//         gl2[i] = malloc(w * sizeof(int));
//         memcpy(gl2[i], gl1[i], (w - 1) * sizeof(int));
//         gl2[i][w - 1] = gl1[i][w - 1];
//     }

//     // make glcm
//     unsigned char*** glcm = malloc(nbit * sizeof(unsigned char**));
//     for (int i = 0; i < nbit; i++) {
//         glcm[i] = malloc(nbit * sizeof(unsigned char*));
//         for (int j = 0; j < nbit; j++) {
//             glcm[i][j] = malloc(h * w * sizeof(unsigned char));
//         }
//     }
//     for (int i = 0; i < nbit; i++) {
//         for (int j = 0; j < nbit; j++) {
//             for (int m = 0; m < h; m++) {
//                 for (int n = 0; n < w; n++) {
//                     if (gl1[m][n] == i && gl2[m][n] == j) {
//                         glcm[i][j][m * w + n] = 1;
//                     }
//                 }
//             }
//         }
//     }

//     // smoothing
//     int kernel[ks][ks];
//     for (int i = 0; i < ks; i++) {
//         for (int j = 0; j < ks; j++) {
//             kernel[i][j] = 1;
//         }
//     }
//     for (int i = 0; i < nbit; i++) {
//         for (int j = 0; j < nbit; j++) {
//             glcm[i][j] = filter2D(glcm[i][j], h, w, kernel); 
//         }
//     }

//     return glcm;
// }
