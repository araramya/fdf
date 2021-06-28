/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araramya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 14:24:25 by araramya          #+#    #+#             */
/*   Updated: 2021/02/01 12:18:51 by araramya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_len(int num)
{
	int len;

	len = 0;
	if (num < 0)
	{
		len++;
		num *= -1;
	}
	if (num == 0)
		len++;
	while (num)
	{
		len++;
		num /= 10;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	int		length;
	char	*str;
	int		i;
	long	num;

	num = n;
	length = ft_len(num);
	if (!(str = (char*)malloc(sizeof(char) * length + 1)))
		return (NULL);
	i = 0;
	if (num < 0)
	{
		str[i] = '-';
		num *= -1;
	}
	i = length - 1;
	if (num == 0)
		str[i] = '0';
	while (num > 0)
	{
		str[i--] = num % 10 + 48;
		num /= 10;
	}
	str[length] = '\0';
	return (str);
}
