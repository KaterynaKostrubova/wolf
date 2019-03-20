/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkostrub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:03:13 by kkostrub          #+#    #+#             */
/*   Updated: 2018/03/27 11:11:12 by kkostrub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		size;
	char	*res;

	i = 0;
	size = 0;
	while (s1[i] != '\0')
	{
		size++;
		i++;
	}
	res = (char *)malloc(sizeof(char) * (size + 1));
	i = 0;
	if (res)
	{
		while (s1[i] != '\0')
		{
			res[i] = s1[i];
			i++;
		}
		res[i] = '\0';
	}
	return (res);
}
