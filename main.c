#include "include.h"

int main(int argc, char **argv)
{
    int x;
    int y;
    t_info *info;
    info = (t_info*)malloc(sizeof(t_info));
    get_map_info (argv[1],info);
    info->mlx_ptr = mlx_init();
    info->mlx_win = mlx_new_window(info->mlx_ptr, 1920, 1080, "FDF");

    y = 0;
    while(y < info->height)
    {
        x = 0;
        while(x < info->width)
        {
            printf("%3d", info->map_matrix[y][x]);
            x++;
        }
        printf("\n");
        y++;
    }
    merge_lines(info);
    mlx_loop(info->mlx_ptr); 

}