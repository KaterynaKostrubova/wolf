/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkostrub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 13:25:08 by kkostrub          #+#    #+#             */
/*   Updated: 2018/04/04 13:27:15 by kkostrub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	end;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen((char*)src));
	while (dst[i] != '\0' && i < dstsize)
		i++;
	end = i;
	while (src[i - end] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i - end];
		i++;
	}
	if (end < dstsize)
		dst[i] = '\0';
	return (end + ft_strlen((char*)src));
}
