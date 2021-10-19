/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araramya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 04:00:39 by araramya          #+#    #+#             */
/*   Updated: 2021/07/17 05:04:03 by araramya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void map_check(char *f_name)
{
	int w;
	int w_new;
	char *line;
	int fd;

	fd = open(f_name, O_RDONLY);
	get_next_line(fd, &line);
	w = ft_word_count(line, ' ');
	free(line);
	while(get_next_line(fd, &line))
	{
		w_new = ft_word_count(line, ' ');
		if(w != w_new)
		{
			write(1, "ERROR!\n", 7);
			exit (0);
		}
		free(line);
	}
	close(fd);
}

int	map_height(char *f_name)
{
	int		i;
	char	*line;
	int		fd;

	i = 0;
	fd = open(f_name, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		i++;
		free(line);
	}
	close(fd);
	return (i);
}

int	map_width(char *f_name)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(f_name, O_RDONLY);
	get_next_line(fd, &line);
	i = ft_word_count(line, ' ');
	close(fd);
	free(line);
	return (i);
}

void	get_matrix_info(int *int_line, int *color_line, char *line)
{
	int		i;
	char	**num_char;

	i = 0;
	num_char = ft_split(line, ' ');
	while (num_char[i])
	{
		int_line[i] = ft_atoi(num_char[i]);
		color_line[i] = ft_atoi_base(num_char[i], "0123456789abcdef");
		i++;
	}
	free(num_char);
}

void	get_map_info(char *f_name, t_info *info)
{
	int		i;
	int		fd;
	char	*line;

	info->height = map_height(f_name);
	info->width = map_width(f_name);
	info->map_colors = malloc (sizeof (int *) * info->height);
	i = 0;
	while (i < info->height)
	{
		info->map_colors[i] = malloc (sizeof (int *) * (info->width));
		i++;
	}
	info->map_matrix = malloc (sizeof (int *) * (info->height));
	i = 0;
	while (i < info->height)
	{
		info->map_matrix[i] = malloc (sizeof (int *) * (info->width));
		i++;
	}
	fd = open(f_name, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line))
	{
		get_matrix_info(info->map_matrix[i], info->map_colors[i], line);
		free(line);
		i++;
	}
	close(fd);
	info->map_matrix[i] = 0;
}