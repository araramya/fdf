#include "include.h"

void	ft_str_tolower(char *str)
{
	int i;
	i = 0;
	while(str[i])
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		//printf("%c\n", str[i]);
		i++;
	}
}
int		is_color(char *str)
{
	int i;
	i = 0;
	while(str[i])
	{
		if(str[i] == ',')
			return (1);
		i++;
	}
	return (0);
}
int		get_value(char c, char *base)
{
	int i;

	i = 0;
	while (base[i] && base[i] != c)
		i++;
	if (i >= ft_strlen(base))
		return (-1);
	return (i);
}

int		is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int		check_base(char *str)
{
	int i;
	int j;

	if (ft_strlen(str) <= 1)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] > 127 || is_space(str[i]) || str[i] == '-'
				|| str[i] == '+')
			return (0);
		j = i + 1;
		while (str[j])
		{
			if (str[j] == str[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}


int		ft_atoi_base(char *str, char *base)
{
	int		i;
	int		b;
	int		sign;
	long	res;
// 	 void ft_choose_color(int *z, t_info *info)
//  {
//     if(*z > 0)
//         info->color = 0x00ff00;
//     else if(*z < 0)
//         info->color = 0xff0000;
//     else
//         info->color = 0x00000ff;
//  }
	//ft_tolower(*str);
	ft_str_tolower(str);
	//printf("%s\n", str);
	if(!is_color(str))
	{
		if(ft_atoi(str) > 0)
			return (0x00ff00);
		else if(ft_atoi(str) < 0)
			return (0xff0000);
		else
			return (0x0000ff);
	}
	i = 0;
	sign = 1;
	res = 0;
	if (!check_base(base))
		return (0);
	b = ft_strlen(base);
	while (is_space(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
    while(str[i] != 'x')
        i++;
    i++;
	//i+=2;
	while (get_value(str[i], base) >= 0)
	{
		res = res * b + get_value(str[i], base);
		i++;
	}
	return (res * sign);
}

//  int main()
//  {
//      char a[] = "20,0xFF0000";
//      printf("%d\n", ft_atoi_base(a,"0123456789abcdef"));
// }