/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkostrub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 13:27:48 by kkostrub          #+#    #+#             */
/*   Updated: 2018/04/04 13:34:06 by kkostrub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_word(char const *s, char c)
{
	int word;
	int i;

	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			word++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (word);
}

static char		*copy_word(char const *s, char c)
{
	int		i;
	int		len;
	char	*word;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	word = (char *)malloc(sizeof(char) * len + 1);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		num;
	char	**arr;

	if (!s)
		return (NULL);
	num = count_word(s, c);
	arr = (char **)malloc(sizeof(char *) * num + 1);
	if (!s || !arr)
		return (NULL);
	i = -1;
	while (*s)
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != c && *s != '\0')
			arr[++i] = copy_word(s, c);
		while (*s != c && *s != '\0')
			s++;
	}
	arr[++i] = 0;
	return (arr);
}
