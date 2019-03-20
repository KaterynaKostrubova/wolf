/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkostrub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 13:27:28 by kkostrub          #+#    #+#             */
/*   Updated: 2018/03/27 15:08:39 by kkostrub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*tmp1;
	char		*tmp2;

	i = 0;
	tmp1 = dst;
	tmp2 = (char *)src;
	while (i < n)
	{
		tmp1[i] = tmp2[i];
		i++;
	}
	return (dst);
}
