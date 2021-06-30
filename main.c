#include "include.h"

int main(int argc, char **argv)
{
    int i;
    int j;

    t_info *info;
    info = (t_info*)malloc(sizeof(t_info));
   // get_map_info (argv[1],info);
   // printf("hi\n");
    info->mlx_ptr = mlx_init();
    info->mlx_win = mlx_new_window(info->mlx_ptr, 1000, 1000, "FDF");
    ft_bresenham_draw_line(10, 10, 500, 500, info);
   // mlx_key_hook(info->mlx_win, deal_key, NULL)
    mlx_loop(info->mlx_ptr); 
    // i = 0;
    // while(i < info->height)
    // {
    //     j = 0;
    //     while(j < info->width)
    //     {
    //         printf("%3d", info->map_matrix[i][j]);
    //         j++;
    //     }
    //     printf("\n");
    //     i++;
    // }

}