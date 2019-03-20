/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkostrub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:06:03 by kkostrub          #+#    #+#             */
/*   Updated: 2018/04/09 16:08:26 by kkostrub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_int_tab(int arr[], int begin, int end)
{
	int p;
	int pivot;
	int i;
	int j;

	pivot = arr[end];
	i = (begin - 1);
	j = begin;
	if (begin < end)
	{
		while (j <= end - 1)
		{
			if (arr[j] <= pivot)
			{
				i++;
				ft_swap(&arr[i], &arr[j]);
			}
			j++;
		}
		ft_swap(&arr[i + 1], &arr[end]);
		p = i + 1;
		ft_sort_int_tab(arr, begin, p - 1);
		ft_sort_int_tab(arr, p + 1, end);
	}
}
