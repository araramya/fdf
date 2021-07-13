#include "include.h"
int key_pressed(int key_code, t_info *info)
{
    if (key_code == k_esc)
        exit(0);
    if (key_code == k_W)
        info->move_y -=15;
     if (key_code == k_S)
        info->move_y += 15;
     if (key_code == k_D)
        info->move_x += 15;
     if (key_code == k_A)
        info->move_x -= 15;
     if (key_code == k_Z)
        info->coefficient += 5;
     if (key_code == k_X)
        info->coefficient -= 5;
      //                                         mlx_pixel_put(info->mlx_ptr, info->mlx_win, info->move_x, info->move_y, info->color);
        return (0);
}