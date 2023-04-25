#include"image.h"

#ifndef PLOT
#define PLOT

void applyColorMap_jet(struct Image2D *src, struct Image3D *dst);
struct Image3D *show_cam_on_image(struct Image3D_float *img, struct Image2D_float *mask, int use_rgb, int colormap, float image_weight);


#endif // !PLOT