/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araramya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:16:46 by araramya          #+#    #+#             */
/*   Updated: 2021/02/03 17:16:11 by araramya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_cpy;
	unsigned char	*s2_cpy;
	size_t			i;

	i = 0;
	s1_cpy = (unsigned char *)s1;
	s2_cpy = (unsigned char *)s2;
	while (i < n)
	{
		if (*s2_cpy != *s1_cpy)
			return (*s1_cpy - *s2_cpy);
		i++;
		s1_cpy++;
		s2_cpy++;
	}
	if (i != n)
		return (*s1_cpy - *s2_cpy);
	return (0);
}
