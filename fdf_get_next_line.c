/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araramya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 14:29:47 by araramya          #+#    #+#             */
/*   Updated: 2021/07/17 05:13:55 by araramya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	get_next_line(int fd, char **line)
{
	int			BUFFER_SIZE;
	char		*buffer;
	int			readed;
	static char	*rem_line;

	BUFFER_SIZE = 10;
	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL)
		return (-1);
	if (!(buffer = malloc((sizeof(char) * BUFFER_SIZE) + 1)))
		return (-1);
	while ((readed = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[readed] = '\0';
		rem_line = ft_strjoin_gnl(rem_line, buffer);
		if (ft_str_endline_gnl(rem_line))
			break ;
	}
	free(buffer);
	if (readed < 0)
		return (-1);
	*line = ft_remline_gnl(rem_line);
	rem_line = ft_clearrem_gnl(rem_line);
	if (readed == 0 && !rem_line)
		return (0);
	return (1);
}