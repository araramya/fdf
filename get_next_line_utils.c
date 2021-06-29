/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araramya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 14:55:54 by araramya          #+#    #+#             */
/*   Updated: 2021/02/22 19:51:52 by araramya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int		ft_strlen_gnl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *rem_line, char *buffer)
{
	int		i;
	int		j;
	char	*str_join;

	if (!(str_join = malloc((sizeof(char) *
		(ft_strlen_gnl(rem_line) + ft_strlen_gnl(buffer))) + 1)))
		return (NULL);
	i = 0;
	j = 0;
	if (rem_line)
		while (rem_line[i])
			str_join[j++] = rem_line[i++];
	i = 0;
	if (buffer)
		while (buffer[i])
			str_join[j++] = buffer[i++];
	str_join[j] = '\0';
	free(rem_line);
	return (str_join);
}

int		ft_str_endline_gnl(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_remline_gnl(char *rem_line)
{
	char	*tmp;
	int		i;

	i = 0;
	while (rem_line && rem_line[i] != '\0' && rem_line[i] != '\n')
		i++;
	if (!(tmp = malloc((sizeof(char) * i) + 1)))
		return (NULL);
	i = 0;
	while (rem_line && rem_line[i] != '\0' && rem_line[i] != '\n')
	{
		tmp[i] = rem_line[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_clearrem_gnl(char *rem_line)
{
	char	*tmp;
	int		len;
	int		i;
	int		j;

	i = 0;
	if (!rem_line)
		return (NULL);
	while (rem_line[i] != '\0' && rem_line[i] != '\n')
		i++;
	if (rem_line[i] == '\0')
	{
		free(rem_line);
		return (NULL);
	}
	len = ft_strlen_gnl(rem_line) - i;
	if (!(tmp = malloc((sizeof(char) * len) + 1)))
		return (NULL);
	i++;
	j = 0;
	while (rem_line[i] != '\0')
		tmp[j++] = rem_line[i++];
	tmp[j] = '\0';
	free(rem_line);
	return (tmp);
}
