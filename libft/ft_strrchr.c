/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araramya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 19:25:16 by araramya          #+#    #+#             */
/*   Updated: 2021/02/03 20:31:41 by araramya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*string_cpy;
	unsigned char	c_cpy;
	int				i;

	i = 0;
	string_cpy = (char*)s;
	c_cpy = (unsigned char)c;
	while (*string_cpy != '\0')
	{
		string_cpy++;
		i++;
	}
	while (i >= 0)
	{
		if (*string_cpy == c_cpy)
			return (string_cpy);
		i--;
		string_cpy--;
	}
	return (NULL);
}
