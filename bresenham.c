#include "include.h"
# define MOD(x) ((x < 0) ? -x : x)
# define MAXIK(x, y) (x > y ? x : y)  
 void ft_bresenham_draw_line(float x1, float y1, float x2, float y2, t_info *info)
//void ft_bresenham_draw_line(int x1, int y1, int x2, int y2, t_info *info)
{  
    // int i;
    // int dx;
    // int dy;
    // int x;
    // int y;
    // int pk;

    // dx = x2 - x1;
    // dy = y2 - y1;
    // x = x1;
    // y = y1;

    // //this is the case when slope(m) < 1
    // if(MOD(dx) > MOD(dy)) 
    // {
    //     mlx_pixel_put(info->mlx_ptr, info->mlx_win, x, y, 0xffffff);
    //     pk = (2 * MOD(dy)) - MOD(dx);

    //     i = 0;
    //     while(i < MOD(dx))
    //     {
    //         x = x+1;
    //         if(pk < 0)
    //             pk = pk + (2*MOD(dy));
    //         else
    //         {
    //             y = y + 1;
    //             pk = pk + (2*MOD(dy)) - (2 * MOD(dx));
    //         }
    //        mlx_pixel_put(info->mlx_ptr, info->mlx_win, x, y, 0xffffff);
    //        i++;
    //     }
    // }
    // else
    // {
    //     //this is the case when slope is greater than or equal to 1  i.e: m>=1
    //      mlx_pixel_put(info->mlx_ptr, info->mlx_win, x, y, 0xffffff); //this putpixel is for very first pixel of the line
    //      pk = (2*MOD(dx)) - MOD(dy);
    //      i = 0;
    //      while(i < MOD(dy)) 
    //      {
    //         y = y + 1;
    //         if(pk < 0)
    //             pk = pk + (2 * MOD(dx));
    //         else
    //         {
    //             x = x + 1;
    //             pk = pk + (2*MOD(dx)) - (2 * MOD(dy));
    //         }
    //          mlx_pixel_put(info->mlx_ptr, info->mlx_win, x, y, 0xffffff);
    //          i++;
    //      }
    // }



    // int steep;
    // int dx;
    // int dy;
    // int error;
    // int ystep;



    // steep = (MOD(y2 - y1) > MOD(x2 - x1));
    // if(steep)
    // {
    //     ft_swap(&x1,&y1);
    //     ft_swap(&x2, &y2);
    // }
    // if(x1 > x2)
    // {
    //     ft_swap(&x1, &x2);
    //     ft_swap(&y1, &y2);
    // }
    // dx = x2 - x1;
    // dy = MOD(y2 - y1);
    // error = dx / 2;
    // ystep = (y1 - y2) ? 1 : -1;
    // int y = y1;
    // for (int x = x1; x <= x2; x++)
    // {
    //      mlx_pixel_put(info->mlx_ptr, info->mlx_win, x, y, 0xffffff);
    //      error -= dy;
    //      if(error < 0)
    //      {
    //          y += ystep;
    //          error += dx;
    //      }
    // }

    float x_step;
    float y_step;
    int max;
    x_step = x2 - x1;
    y_step = y2 - y1;
    max = MAXIK(MOD(x_step), MOD(y_step));
    x_step /= max;
    y_step /= max;
    //printf("x_step --- %f\n", x_step);
    //printf("y_step --- %f\n", y_step);

    while((int)(x2-x1) || (int)(y2- y1))
    { 
        mlx_pixel_put(info->mlx_ptr, info->mlx_win, x1, y1, 0xffffff);
        x1 += x_step;
        y1 += y_step; 
        printf("[ %f, %f ]\n", x1, y1);

    } 

    
    // int dx, dy, p, x, y;  
    // dx=x1-x0;  
    // dy=y1-y0;  
    // x=x0;  
    // y=y0;  
    // p=2*dy-dx;  
    // while(x<x1)  
    // {  
    //     if(p>=0)  
    //     {  
    //         //putpixel(x,y,7);
    //         mlx_pixel_put(info->mlx_ptr, info->mlx_win, x1, y1, 0xffffff);  
    //         y=y+1;  
    //         p=p+2*dy-2*dx;  
    //     }  
    //     else  
    //     {  
    //         //putpixel(x,y,7);
    //         mlx_pixel_put(info->mlx_ptr, info->mlx_win, x1, y1, 0xffffff);  
    //         p=p+2*dy;}  
    //         x=x+1;  
    //     }  



 }   