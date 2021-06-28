/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araramya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:55:51 by araramya          #+#    #+#             */
/*   Updated: 2021/01/30 15:16:02 by araramya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_cpy;
	unsigned char	c_cpy;

	s_cpy = (unsigned char*)s;
	c_cpy = (unsigned char)c;
	while (n > 0)
	{
		if (*s_cpy == c_cpy)
			return (s_cpy);
		s_cpy++;
		n--;
	}
	return (NULL);
}
