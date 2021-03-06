/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araramya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 04:00:08 by araramya          #+#    #+#             */
/*   Updated: 2021/07/17 04:28:18 by araramya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

float	ft_maxik(float x, float y)
{
	if (x > y)
		return (x);
	else
		return (y);
}

void	twoD_to_3D(float *x, float *y, int z, t_info *info)
{
	 *x = (*x - *y) * cos(info->rot_angle);
	 *y = (*x + *y) * sin(info->rot_angle) - z;
}

void	ft_zoomik(float *x1, float *y1, float *x2, float *y2, t_info *info)
{
	 *x1 *= info->coefficient;
	 *x2 *= info->coefficient;
	 *y1 *= info->coefficient;
	 *y2 *= info->coefficient;
}

void	ft_shifting(float *x1, float *y1, float *x2, float *y2, t_info *info)
{
	 *x1 += info->move_x;
	 *x2 += info->move_x;
	 *y1 += info->move_y;
	 *y2 += info->move_y;
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bbp / 8));
	*(unsigned int *)dst = color;
}