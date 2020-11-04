/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 08:54:50 by zraunio           #+#    #+#             */
/*   Updated: 2020/07/20 15:08:04 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*dest;

	if (ptr && size == 0)
	{
		if (!(dest = (void*)malloc(1)))
			return (NULL);
		ft_memdel(ptr);
		return (dest);
	}
	if (!(dest = (void*)malloc(size)))
		return (NULL);
	if (ptr)
	{
		ft_memcpy(dest, ptr, size);
		ft_memdel(ptr);
	}
	return ((void*)dest);
}
