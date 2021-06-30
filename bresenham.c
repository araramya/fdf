#include "include.h"
#  define MOD(x) ((x<0) ? -x : x)
void ft_swap(int *x, int *y)
{
    int *temp;
    temp = x;
    x = y;
    y = temp;
}
void ft_bresenham_draw_line(int x1, int y1, int x2, int y2, t_info *info)
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



//     int steep;
//     int dx;
//     int dy;
//     int error;
//     int ystep;



//     steep = (MOD(y2 - y1) > MOD(x2 - x1));
//     if(steep)
//     {
//         ft_swap(&x1,&y1);
//         ft_swap(&x2, &y2);
//     }
//     if(x1 > x2)
//     {
//         ft_swap(&x1, &x2);
//         ft_swap(&y1, &y2);
//     }
//     dx = x2 - x1;
//     dy = MOD(y2 - y1);
//     error = dx / 2;
//     ystep = (y1 - y2) ? 1 : -1;
//     int y = y1;
//     for (int x = x1; x <= x2; x++)
//     {
//          mlx_pixel_put(info->mlx_ptr, info->mlx_win, x, y, 0xffffff);
//          error -= dy;
//          if(error < 0)
//          {
//              y += ystep;
//              error += dx;
//          }
//     }



 }   