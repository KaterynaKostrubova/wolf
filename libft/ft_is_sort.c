/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkostrub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:00:52 by kkostrub          #+#    #+#             */
/*   Updated: 2018/04/09 16:03:33 by kkostrub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int len, int (*f)(int, int))
{
	int i;
	int res;

	res = 0;
	i = 0;
	if (len < 2)
		return (1);
	while (i < len - 1 && res <= 0)
	{
		res = f(tab[i], tab[i + 1]);
		i++;
	}
	if (res <= 0)
		res = 1;
	else
		res = 0;
	return (res);
}
