#ifndef INCLUDE_H
# define INCLUDE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h> 
# include <stdio.h>
# include <math.h>

#include "libft/libft.h"
#include "minilibx_macos/mlx.h"

#define k_esc 53 //close key
                //for rotating
#define k_W 13
#define k_S 1
#define k_A 0
#define k_D 2


//for zooming and antizooming;
#define k_Z 6
#define k_X 7


//for rotating map i thing;

#define k_UP 126
#define k_DOWN 125
#define k_RIGHT 124
#define k_LEFT 123

#define WIN_H 1080
#define WIN_L 1920
typedef struct s_img
{
    void *img;
    char *addr;
    int bbp;
    int line_len;
    int endian;
}              t_img;

typedef struct s_info
{   t_img image;
    void *mlx_ptr;
    void *mlx_win;
    int height;
    int width;
    int **map_matrix;
    int coefficient;
    int color;
    int move_x;
    int move_y;

}              t_info;

//gnl functions
int			get_next_line(int fd, char **line);
int			ft_strlen_gnl(char *str);
char		*ft_strjoin_gnl(char *rem_line, char *buffer);
char		*ft_strnew_gnl(size_t size);
int			ft_str_endline_gnl(char *str);
char		*ft_remline_gnl(char *rem_line);
char		*ft_clearrem_gnl(char *rem_line);

//libft_functions
int	ft_word_count(char const *s, char c);
//fdf functions
float ft_maxik(float x, float y);
void get_map_info( char *f_name, t_info *info);
void twoD_to_3D(float *x, float *y, int z);
//void ft_bresenham_draw_line(int x1, int y1, int x2, int y2, t_info *info);
void ft_bresenham_draw_line(float x1, float y1, float x2, float y2, t_info *info);
void ft_zoomik(float *x1, float *y1, float *x2, float *y2, t_info *info);
void ft_shifting(float *x1, float *y1, float *x2, float *y2, t_info *info);
void merge_lines(t_info *info);
void ft_choose_color(int *z, t_info *info);
int key_pressed(int key_code, t_info *info);
void	ft_clear(t_info *data);
int ft_frame(t_info *info);
void            my_mlx_pixel_put(t_img *data, int x, int y, int color);
#endif