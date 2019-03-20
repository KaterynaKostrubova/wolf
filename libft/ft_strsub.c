/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkostrub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 14:13:07 by kkostrub          #+#    #+#             */
/*   Updated: 2018/04/02 14:26:05 by kkostrub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	sub = (char *)malloc(sizeof(char) * len + 1);
	if (sub)
	{
		while (len != 0)
		{
			sub[i] = s[start];
			i++;
			start++;
			len--;
		}
		sub[i] = '\0';
		return (sub);
	}
	return (NULL);
}
