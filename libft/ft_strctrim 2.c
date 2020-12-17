/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strctrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 13:00:01 by zraunio           #+#    #+#             */
/*   Updated: 2020/11/04 13:00:03 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	find_start(char const *s, char c)
{
	size_t	start;

	start = 0;
	while (s[start] != '\0' && s[start] == c)
		start++;
	return (start);
}

static size_t	find_end(char const *s, char c)
{
	size_t	end;

	end = ft_strlen(s);
	while (s[end] == '\0' || s[end] == c)
		end--;
	return (end);
}

char			*ft_strctrim(char const *s, char c)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*p;

	if (!s)
		return (NULL);
	start = find_start(s, c);
	if (s[start] == '\0')
		return (ft_strnew(0));
	end = find_end(s, c);
	if (!(p = (char*)malloc(sizeof(char) * (end - start) + 2)))
		return (NULL);
	i = 0;
	while (s[start] != '\0' && end >= start)
	{
		p[i] = s[start];
		i++;
		start++;
	}
	p[i] = '\0';
	free((void*)s);
	return (p);
}
