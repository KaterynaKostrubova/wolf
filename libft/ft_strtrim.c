/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkostrub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 14:14:16 by kkostrub          #+#    #+#             */
/*   Updated: 2018/04/05 16:29:45 by kkostrub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		len;
	int		i;
	char	*trim;

	i = -1;
	if (s == NULL)
		return (NULL);
	len = ft_strlen((char*)s);
	while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n' || s[len] == '\0')
		len--;
	while (s[++i] == ' ' || s[i] == '\t' || s[i] == '\n')
		len--;
	if (++len < 0)
		len = 0;
	trim = (char*)malloc(sizeof(char) * len + 1);
	if (trim)
	{
		s = s + i;
		i = -1;
		while (++i < len)
			trim[i] = *s++;
		trim[i] = '\0';
		return (trim);
	}
	return (NULL);
}
