#include "include.h"
#  define MOD(a) ((a<0) ? -a : a)
void ft_bresenham_draw_line(float x1, float y1, float x2, float y2, t_info *info)
{  
    int i;
    int dx;
    int dy;
    int x;
    int y;
    int pk;

    dx = x2 - x1;
    dy = y2 - y1;
    x = x1;
    y = y1;

    //this is the case when slope(m) < 1
    if(MOD(dx) > MOD(dy)) 
    {
        mlx_pixel_put(info->mlx_ptr, info->mlx_win, x, y, 0xffffff);
        pk = (2 * MOD(dy)) - MOD(dx);

        i = 0;
        while(i < MOD(dx))
        {
            x = x+1;
            if(pk < 0)
                pk = pk + (2*MOD(dy));
            else
            {
                y = y + 1;
                pk = pk + (2*MOD(dy)) - (2 * MOD(dx));
            }
           mlx_pixel_put(info->mlx_ptr, info->mlx_win, x, y, 0xffffff);
           i++;
        }
    }
    else
    {
        //this is the case when slope is greater than or equal to 1  i.e: m>=1
         mlx_pixel_put(info->mlx_ptr, info->mlx_win, x, y, 0xffffff); //this putpixel is for very first pixel of the line
         pk = (2*MOD(dx)) - MOD(dy);
         i = 0;
         while(i < MOD(dy)) 
         {
            y = y + 1;
            if(pk < 0)
                pk = pk + (2 * MOD(dx));
            else
            {
                x = x + 1;
                pk = pk + (2*MOD(dx)) - (2 * MOD(dy));
            }
             mlx_pixel_put(info->mlx_ptr, info->mlx_win, x, y, 0xffffff);
             i++;
         }
    }
}   