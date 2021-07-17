/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araramya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 04:01:23 by araramya          #+#    #+#             */
/*   Updated: 2021/07/17 06:39:51 by araramya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"
int	key_pressed(int key_code, t_info *info)
{
	if (key_code == K_ESC)
	{
		int i;
		i = 0;
		while(i < info->height)
		{
			free(info->map_matrix[i]);
			free(info->map_colors[i]);
			i++;
		}
		free(info->map_matrix);
		free(info->map_colors);
		exit(0);
	}
	if (key_code == K_W)
		info->move_y -= 15;
	if (key_code == K_S)
		info->move_y += 15;
	if (key_code == K_D)
		info->move_x += 15;
	if (key_code == K_A)
		info->move_x -= 15;
	if (key_code == K_Z)
	{
		if (info->coefficient >= 1900)
			return (0);
		else
			info->coefficient += 1;
	}
	if (key_code == K_X)
	{
		if (info->coefficient == 1)
			return (0);
		else
			info->coefficient -= 1;
	}
	if (key_code == K_UP)
		info->rot_angle += 0.05;
	if (key_code == K_DOWN)
		info->rot_angle -= 0.05;
	return (0);
}
