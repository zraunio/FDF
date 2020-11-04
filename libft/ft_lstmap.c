/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 11:59:53 by zraunio           #+#    #+#             */
/*   Updated: 2020/07/20 15:23:06 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*temp;

	if (!lst || !f)
		return (0);
	new = f(lst);
	if (new == NULL)
		return (NULL);
	if (!(temp = ft_lstnew(new->content, new->content_size)))
		return (NULL);
	temp = new;
	while (lst->next)
	{
		lst = lst->next;
		temp->next = f(lst);
		if (temp->next == NULL)
			return (NULL);
		temp = temp->next;
	}
	return (new);
}
