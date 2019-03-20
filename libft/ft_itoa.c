/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkostrub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 12:45:19 by kkostrub          #+#    #+#             */
/*   Updated: 2018/04/04 13:23:06 by kkostrub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(int n)
{
	size_t		len;

	len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char		*str;
	int			len;
	int			tmp;

	len = get_len(n);
	tmp = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 2147483647)
		return (ft_strdup("2147483647"));
	if (tmp > 0)
		len--;
	if (n < 0)
		tmp = -n;
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = '\0';
	while (--len >= 0)
	{
		str[len] = '0' + (tmp % 10);
		tmp = tmp / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
