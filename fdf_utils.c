#include "include.h"

float ft_maxik(float x, float y)
 {
     return (x > y ? x : y);
 }

 void twoD_to_3D(float *x, float *y, int z)
 {
     *x = (*x-*y) * cos(0.8);
     *y = (*x+*y) * sin(0.8) - z;;
 }

 void ft_zoomik(float *x1, float *y1, float *x2, float *y2, t_info *info)
 {
    info->coefficient = 40;
    *x1 *= info->coefficient;
    *x2 *= info->coefficient;
    *y1 *= info->coefficient;
    *y2 *= info->coefficient;
 }

 void ft_shifting(float *x1, float *y1, float *x2, float *y2)
 {
    *x1+=400;
    *x2+=400;
    *y1+=400;
    *y2+=400;
 }

 void ft_choose_color(int *z, t_info *info)
 {
     if(*z > 0)
        info->color = 0x00ff00;
    else if(*z < 0)
        info->color = 0xff0000;
    else
        info->color = 0x00000ff;
 }