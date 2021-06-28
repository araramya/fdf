/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araramya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 17:09:59 by araramya          #+#    #+#             */
/*   Updated: 2021/02/01 13:45:26 by araramya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_cpy;
	unsigned char	*s2_cpy;

	s1_cpy = (unsigned char *)s1;
	s2_cpy = (unsigned char *)s2;
	i = 0;
	while (s1_cpy[i] && s2_cpy[i] && i < n)
	{
		if (s2_cpy[i] != s1_cpy[i])
			return (s1_cpy[i] - s2_cpy[i]);
		i++;
	}
	if (i != n)
		return (s1_cpy[i] - s2_cpy[i]);
	return (0);
}
