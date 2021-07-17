/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araramya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 03:52:29 by araramya          #+#    #+#             */
/*   Updated: 2021/07/17 04:18:58 by araramya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	ft_bresenham_draw_line(float x1, float y1, float x2,
		float y2, t_info *info)
{
	float	dx;
	float	dy;
	float	max;
	int		z1;
	int		z2;

	z1 = info->map_matrix[(int)y1][(int)x1];
	z2 = info->map_matrix[(int)y2][(int)x2];
	info->color = info->map_colors[(int)y1][(int)x1];
	ft_zoomik(&x1, &y1, &x2, &y2, info);
	twoD_to_3D(&x1, &y1, z1, info);
	twoD_to_3D(&x2, &y2, z2, info);
	dx = x2 - x1;
	dy = y2 - y1;
	ft_shifting(&x1, &y1, &x2, &y2, info);
	max = ft_maxik(fabs(dx), fabs(dy));
	dx /= max;
	dy /= max;
	while (((int)(x2 - x1) || (int)(y2 - y1)))
	{
		if ((y1 < WIN_H) && (x1 < WIN_L))
		{
			if (x1 >= 0 && y1 >= 0)
				my_mlx_pixel_put(&info->image, x1, y1, info->color);
		}
		x1 += dx;
		y1 += dy;
	}
}

void	merge_lines(t_info *info)
{
	int	x;
	int	y;

	y = 0;
	while ((y < info->height))
	{
		x = 0;
		while (x < info->width)
		{
			if (x < info->width - 1)
				ft_bresenham_draw_line(x, y, x + 1, y, info);
			if (y < info->height - 1)
				ft_bresenham_draw_line(x, y, x, y + 1, info);
			x++;
		}
		y++;
	}
}
