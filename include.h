#ifndef INCLUDE_H
# define INCLUDE_H

#include "libft/libft.h"
#include "minilibx_macos/mlx.h"


typedef struct s_info
{
    int height;
    int width;
    int **h_matrix;
}              t_info;

void get_map_info(t_info *info);

#endif