#include "include.h"

# define MAXIK(x, y) (x > y ? x : y)  //green #00ff00
 

 void twoD_to_3D(float *x, float *y, int z)
 {
     *x = (*x-*y) * cos(0.5);
     *y = (*x+*y) * sin(0.5) - z;
   //  printf("nonono\n");
 }


 void ft_bresenham_draw_line(float x1, float y1, float x2, float y2, t_info *info)
    //void ft_bresenham_draw_line(int x1, int y1, int x2, int y2, t_info *info)
{  
    info->coefficient = 40;

    int z1 = info->map_matrix[(int)y1][(int)x1];
    int z2 = info->map_matrix[(int)y2][(int)x2];
    x1 *= info->coefficient;
    x2 *= info->coefficient;
    y1 *= info->coefficient;
    y2 *= info->coefficient;

    //int z1 = info->map_matrix[(int)y2][(int)x2];
    //printf("map-----[%d]" ,info->map_matrix[(int)y1][(int)x1]);

    float dx;
    float dy;
    float max;
    
    float x_copy;
    float y_copy;
    twoD_to_3D(&x1, &y1, z1);
    twoD_to_3D(&x2, &y2, z2);
    x1+=400;
    x2+=400;
    y1+=400;
    y2+=400;
    dx = x2 - x1;
    dy = y2 - y1;


    

    max = MAXIK(fabs(dx), fabs(dy));
    dx /= max;
    dy /= max;
   //printf("Z---------%d\n", z);
    if(z1)
        info->color = 0x00ff00;
    else
        info->color = 0xffffff;
   // info->color = 0x00ff00;
     
    //printf("x_step --- %f\n", dx);
    //printf("y_step --- %f\n", dy);

    while((int)(x2-x1) || (int)(y2- y1))
    { 
        // x_copy = (x1-y1) * cos(0.8);
        // y_copy = (x1+y1) * sin(0.8) - z1;
        //mlx_pixel_put(info->mlx_ptr, info->mlx_win, x_copy, y_copy, info->color);
        mlx_pixel_put(info->mlx_ptr, info->mlx_win, x1, y1, info->color);
        x1 += dx;
        y1 += dy; 
        
       //printf("[ %f, %f ]\n", x1, y1);
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
