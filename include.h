/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araramya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 04:01:06 by araramya          #+#    #+#             */
/*   Updated: 2021/07/17 05:31:47 by araramya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h> 
# include <stdio.h>
# include <math.h>
# include "minilibx_macos/mlx.h"
# define K_ESC 53
# define K_W 13
# define K_S 1
# define K_A 0
# define K_D 2
# define K_Z 6
# define K_X 7
# define K_UP 126
# define K_DOWN 125
# define K_RIGHT 124
# define K_LEFT 123
# define WIN_H 1080
# define WIN_L 1920

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bbp;
	int			line_len;
	int			endian;
}				t_img;

typedef struct s_info
{
	t_img		image;
	void		*mlx_ptr;
	void		*mlx_win;
	int			height;
	int			width;
	int			**map_matrix;
	int			**map_colors;
	int			coefficient;
	int			color;
	int			move_x;
	int			move_y;
	float		rot_angle;

}				t_info;
void map_check(char *f_name);
int			get_next_line(int fd, char **line);
int			ft_strlen_gnl(char *str);
char		*ft_strjoin_gnl(char *rem_line, char *buffer);
char		*ft_strnew_gnl(size_t size);
int			ft_str_endline_gnl(char *str);
char		*ft_remline_gnl(char *rem_line);
char		*ft_clearrem_gnl(char *rem_line);
int			ft_word_count(char const *s, char c);
int			ft_atoi_base(char *str, char *base);
long		ft_atoi(const char *str);
char		**ft_split(char const *s, char c);
int			ft_strlen(const char *s);
float		ft_maxik(float x, float y);
void		get_map_info( char *f_name, t_info *info);
void		twoD_to_3D(float *x, float *y, int z, t_info *info);
void		ft_bresenham_draw_line(float x1, float y1, float x2,
				float y2, t_info *info);
void		ft_zoomik(float *x1, float *y1, float *x2, float *y2, t_info *info);
void		ft_shifting(float *x1, float *y1, float *x2,
				float *y2, t_info *info);
void		merge_lines(t_info *info);
void		ft_choose_color(int *z, t_info *info);
int			key_pressed(int key_code, t_info *info);
void		ft_clear(t_info *data);
int			ft_frame(t_info *info);
void		my_mlx_pixel_put(t_img *data, int x, int y, int color);
int			key_pressed_bonuses(int key_code, t_info *info);
#endif
