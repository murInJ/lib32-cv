#include"plot.h"

struct Image3D *show_cam_on_image(struct Image3D_float *img, struct Image2D_float *mask, int use_rgb, int colormap, float image_weight) 
{
    struct Image3D *heatmap;
    heatmap->matrix = zeros3D(img->matrix->H,img->matrix->W,img->matrix->C);
    heatmap->type = BGR;
    applyColorMap_jet(mask, heatmap);
    
    if (use_rgb) {
        struct Image3D *tmp;
        tmp->matrix = zeros3D(img->matrix->H,img->matrix->W,img->matrix->C);
        BGR2RGB(heatmap,tmp);
        freeMatrix3D(heatmap);
        heatmap = tmp;
    }
    
    int i,j,k;

    struct matrix3D_float* cam;
    cam->matrix = zeros3D_float(img->matrix->H,img->matrix->W,img->matrix->C);
    for (i = 0; i < img->matrix->H; i++) {
        for (j = 0; j < img->matrix->W; j++){
            for (k = 0; k < img->matrix->C; k++){
                cam->matrix[i][j][k] = heatmap->matrix->matrix[i][j][k] / 255.0;
            }
        }
    }
    
    if (max(img) > 1) {
        printf("输入图像应为np.float32,范围为[0,1]");
    }
    
    if (image_weight < 0 || image_weight > 1) {
        printf("image_weight应在[0,1]范围内。当前值为:%f", image_weight);
    }
    
    float max_value = (1 - image_weight) * cam->matrix[0][0][0] + image_weight * img->matrix->matrix[0][0][0];
    for(i = 0;i < img->matrix->H;i++){
        for(j = 0;j < img->matrix->W;j++){
            for(k = 0;k < img->matrix->C;k++){
                cam->matrix[i][j][k] = (1 - image_weight) * cam->matrix[i][j][k] 
                           + image_weight * img->matrix->matrix[i][j][k]; 
                if (cam->matrix[i][j][k] > max_value) max_value = cam->matrix[i][j][k];
            }   
        }   
    }

    struct Image3D* CAM;
    CAM->type = RGB;
    CAM->matrix = zeros3D(img->matrix->H,img->matrix->W,img->matrix->C);
    for(i = 0;i < img->matrix->H;i++){
        for(j = 0;j < img->matrix->W;j++){
            for(k = 0;k < img->matrix->C;k++){
                CAM->matrix->matrix[i][j][k] = (unsigned char)(cam->matrix[i][j][k] / max_value * 255);
            }   
        }   
    }
    
    freeMatrix3D(heatmap->matrix);
    free(heatmap);
    freeMatrix3D_float(cam);

    return CAM;
}

void applyColorMap_jet(struct Image2D *src, struct Image3D *dst)
{
    int i, j;
    unsigned char b, g, r;
    
    for(i=0; i<src->matrix->H; i++) {
        for(j=0; j<src->matrix->W; j++) {
            unsigned char intensity = src->matrix->matrix[i][j];  //获取当前像素强度
            
            if (intensity < 63) {        //黑色到蓝色
                b = intensity * 4;
                g = 0;
                r = 255 - intensity * 4;
            } else if (intensity < 127) { //蓝色到绿色
                b = 255;
                g = (intensity - 63) * 4; 
                r = 0;
            } else if (intensity < 191) { //绿色到红色
                b = 255 - (intensity - 127) * 4;
                g = 255; 
                r = 0;       
            } else {                    //红色
                b = 0;
                g = 255 - (intensity - 191) * 4;
                r = 255; 
            } 
            
            dst->matrix->matrix[i][j][0] = b;  
            dst->matrix->matrix[i][j][1] = g; 
            dst->matrix->matrix[i][j][2] = r;  
        }
    }
}