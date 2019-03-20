/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkostrub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 14:07:43 by kkostrub          #+#    #+#             */
/*   Updated: 2018/04/02 14:22:38 by kkostrub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	int		size;
	int		i;

	if (s != NULL && f != NULL)
	{
		i = 0;
		size = ft_strlen((char *)s);
		res = (char *)malloc(sizeof(char) * size + 1);
		if (res)
		{
			while (s[i] != '\0')
			{
				res[i] = f(s[i]);
				i++;
			}
			res[i] = '\0';
		}
		return (res);
	}
	return (NULL);
}
