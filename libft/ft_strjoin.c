/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkostrub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 14:03:29 by kkostrub          #+#    #+#             */
/*   Updated: 2018/04/02 14:24:04 by kkostrub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		size;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	join = (char *)malloc(sizeof(char) * size + 1);
	if (join)
	{
		i = -1;
		j = -1;
		while (s1[++i] != '\0')
			join[i] = s1[i];
		while (s2[++j] != '\0')
		{
			join[i] = s2[j];
			i++;
		}
		join[i] = '\0';
		return (join);
	}
	return (NULL);
}
