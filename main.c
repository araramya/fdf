/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araramya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 04:01:34 by araramya          #+#    #+#             */
/*   Updated: 2021/07/17 06:53:51 by araramya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	ft_clear(t_info *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_H)
	{
		j = 0;
		while (j < WIN_L)
		{
			my_mlx_pixel_put(&data->image, j, i, 0x000000);
			j++;
		}
		i++;
	}
}

int	ft_frame(t_info *info)
{
	ft_clear(info);
	merge_lines(info);
	mlx_put_image_to_window(info->mlx_ptr,
		info->mlx_win, info->image.img, 0, 0);
	mlx_do_sync(info->mlx_ptr);
	return (1);
}

void	ft_initizilation(t_info *info)
{
	info->coefficient = 20;
	info->rot_angle = 0.8;
	info->move_x = WIN_L / 2;
	info->move_y = WIN_H / 2;
}

int	main(int argc, char **argv)
{
	int		fd;
	t_info	*info;

	if (argc == 1 || argc > 2)
	{
		write(1, "ERROR!\n", 7);
		exit(0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(1, "ERROR!\n", 7);
		exit(0);
	}
	else
		close(fd);
	info = (t_info *)malloc(sizeof(t_info));
	map_check(argv[1]);
	get_map_info (argv[1], info);
	ft_initizilation(info);
	info->mlx_ptr = mlx_init();
	info->mlx_win = mlx_new_window(info->mlx_ptr, WIN_L, WIN_H, "FDF");
	info->image.img = mlx_new_image(info->mlx_ptr, WIN_L, WIN_H);
	info->image.addr = mlx_get_data_addr(info->image.img, &info->image.bbp,
			&info->image.line_len, &info->image.endian);
	mlx_hook(info->mlx_win, 2, 0, key_pressed, info);
	mlx_loop_hook(info->mlx_ptr, ft_frame, info);
	mlx_loop(info->mlx_ptr);
}