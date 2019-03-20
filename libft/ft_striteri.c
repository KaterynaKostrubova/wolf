/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkostrub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 14:59:10 by kkostrub          #+#    #+#             */
/*   Updated: 2018/03/29 17:28:22 by kkostrub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *str, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (str != NULL && f != NULL)
	{
		while (*str != '\0')
		{
			f(i, str);
			i++;
			str++;
		}
	}
}
