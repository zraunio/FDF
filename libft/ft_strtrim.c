/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 14:02:00 by zraunio           #+#    #+#             */
/*   Updated: 2020/07/09 22:19:53 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	find_start(char const *s)
{
	size_t	start;
	size_t	i;

	i = 0;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i] != '\0')
		i++;
	start = i;
	return (start);
}

static size_t	find_end(char const *s)
{
	size_t	end;
	size_t	i;

	i = ft_strlen(s);
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') || s[i] == '\0')
		i--;
	end = i;
	return (end);
}

char			*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	start;
	size_t	finish;
	char	*p;

	i = 0;
	if (!s)
		return (NULL);
	start = find_start(s);
	if (s[start] == '\0')
		return (ft_strnew(0));
	finish = find_end(s);
	if (!(p = (char*)malloc(sizeof(char) * (finish - start) + 2)))
		return (NULL);
	while (s[start] != '\0' && finish >= start)
	{
		p[i] = s[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return (p);
}
