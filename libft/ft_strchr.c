/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araramya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 16:04:16 by araramya          #+#    #+#             */
/*   Updated: 2021/01/26 16:04:36 by araramya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*string_cpy;

	string_cpy = (char*)s;
	while (*string_cpy != c)
	{
		if (*string_cpy == '\0')
			return (NULL);
		string_cpy++;
	}
	return (string_cpy);
}
