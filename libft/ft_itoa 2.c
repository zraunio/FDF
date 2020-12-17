/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 10:46:20 by zraunio           #+#    #+#             */
/*   Updated: 2020/07/09 17:39:14 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digit(int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i = i + 1;
		if (n == -2147483648)
			n = 2147483647;
	}
	while (n >= 10)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int		num;
	int		dig;
	char	*s;

	num = ft_count_digit(n);
	if (!(s = (char*)malloc(sizeof(char) * num + 2)))
		return (NULL);
	if (n < 0)
	{
		n = -n;
		s[0] = '-';
	}
	s[num + 1] = '\0';
	if (n == 0)
		s[num] = '0';
	while (n)
	{
		dig = n % 10;
		s[num--] = ft_abs(dig) + '0';
		n = n / 10;
	}
	return (s);
}
