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
    //if ()
    //ft_frame(info);
  merge_lines(info);
  mlx_clear_window(info->mlx_ptr, info->mlx_win);
        // ft_clear(info);
    // printf("%d\n", key_code);
        return (0);

}