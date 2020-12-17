/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 14:07:28 by zraunio           #+#    #+#             */
/*   Updated: 2020/06/29 13:07:02 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	j;
	size_t	k;

	j = 0;
	if (needle[j] == '\0')
		return ((char*)haystack);
	while (haystack[j] != '\0')
	{
		k = 0;
		while (needle[k] == haystack[j + k])
		{
			k++;
			if (needle[k] == '\0')
				return ((char*)&haystack[j]);
		}
		j++;
	}
	return (0);
}
