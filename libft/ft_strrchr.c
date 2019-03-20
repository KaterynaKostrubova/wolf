/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkostrub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 16:55:20 by kkostrub          #+#    #+#             */
/*   Updated: 2018/03/27 11:36:28 by kkostrub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		len;
	int		i;

	i = 0;
	len = ft_strlen((char *)str);
	while (len >= i)
	{
		if (str[len - i++] == c)
			return ((char*)&str[len - (i - 1)]);
	}
	return (NULL);
}
