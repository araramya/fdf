#include "include.h"

 void ft_bresenham_draw_line(float x1, float y1, float x2, float y2, t_info *info)
{  
    float dx;
    float dy;
    float max;
    int z1; 
    int z2;

    z1 = info->map_matrix[(int)y1][(int)x1];
    z2 = info->map_matrix[(int)y2][(int)x2];
    ft_zoomik(&x1,  &y1, &x2, &y2, info);
    twoD_to_3D(&x1, &y1, z1);
    twoD_to_3D(&x2, &y2, z2);
    dx = x2 - x1;
    dy = y2 - y1;
    ft_shifting(&x1, &y1, &x2, &y2, info);
    max = ft_maxik(fabs(dx), fabs(dy));
    dx /= max;
    dy /= max;
    ft_choose_color(&z1, info);
     
   
    while(((int)(x2-x1) || (int)(y2- y1)))
    { 
    //                                               mlx_pixel_put(info->mlx_ptr, info->mlx_win, x1, y1, info->color);
        if( (y1 < WIN_H ) && (x1 < WIN_L ))
        {  // printf("{%f,       %f}\n", x1, y1);
            if(x1 >= 0 && y1 >=0)
                 my_mlx_pixel_put(&info->image, x1, y1, info->color);
        }
        x1 += dx;
        y1 += dy; 
       // mlx_put_image_to_window(info->mlx_ptr, info->mlx_win, info->image.img, 0, 0);
    }
 }


void merge_lines(t_info *info)
{
    int x;
    int y;
    y = 0;

    while((y < info ->height))
    {
        x = 0;
        while(x < info->width)
        {
            if(x < info->width - 1)
                ft_bresenham_draw_line(x, y, x + 1, y, info);
            if(y < info->height - 1)
                ft_bresenham_draw_line(x, y, x, y + 1, info);
            x++;
        }
        y++;
    }
}
