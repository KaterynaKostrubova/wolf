/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkostrub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:03:57 by kkostrub          #+#    #+#             */
/*   Updated: 2018/04/09 16:05:41 by kkostrub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	char *new;

	if (!size && ptr)
	{
		new = (char *)malloc(1);
		if (!new)
			return (NULL);
		ft_memdel(&ptr);
		return (new);
	}
	new = (char *)malloc(size);
	if (!new)
		return (NULL);
	if (ptr)
	{
		ft_memcpy(new, ptr, size);
		ft_memdel(&ptr);
	}
	return (new);
}
