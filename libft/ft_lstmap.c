/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkostrub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:51:04 by kkostrub          #+#    #+#             */
/*   Updated: 2018/04/10 12:28:15 by kkostrub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*elem;
	t_list	*elem_last;

	if (!lst)
		return (NULL);
	if (!(elem_last = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	elem_last = f(lst);
	elem = elem_last;
	while (lst->next)
	{
		elem->next = f(lst->next);
		elem = elem->next;
		lst = lst->next;
	}
	return (elem_last);
}
