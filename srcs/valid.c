/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkostrub <kkostrub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 15:34:31 by kkostrub          #+#    #+#             */
/*   Updated: 2018/11/01 17:22:20 by kkostrub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

static	void	check_border(t_wolf *valid)
{
	int x;
	int y;

	x = 0;
	while (x < valid->map.rows)
	{
		y = 0;
		while (y < valid->map.cols)
		{
			if (x == (valid->map.rows - 1) || y == (valid->map.cols - 1) ||
				x == 0 || y == 0)
				if (valid->map.map[x][y] == 0)
					ft_error(8);
			y++;
		}
		x++;
	}
}

static	void	check_empty_square(t_wolf *valid)
{
	int empty;
	int x;
	int y;

	x = 0;
	empty = 0;
	while (x < valid->map.rows)
	{
		y = 0;
		while (y < valid->map.cols)
		{
			if (valid->map.map[x][y] == 0)
				empty++;
			y++;
		}
		x++;
	}
	if (empty == 0)
		ft_error(9);
}

static	void	ft_parser2(char *str, t_wolf *valid)
{
	int		j;
	int		i;

	j = -1;
	valid->map.map = (int **)malloc(sizeof(int *) * valid->map.rows);
	valid->map.fd = open(str, O_RDONLY);
	while (get_next_line(valid->map.fd, &valid->map.line) == 1)
	{
		i = -1;
		if (!(valid->map.arr = ft_strsplit(valid->map.line, ' ')))
			ft_error(0);
		if (!(valid->map.map[++j] = (int *)malloc(sizeof(int)
						* valid->map.cols)))
			ft_error(1);
		while (++i < valid->map.cols)
			valid->map.map[j][i] = ft_atoi(valid->map.arr[i]);
		if (valid->map.line)
		{
			free(valid->map.line);
			valid->map.line = NULL;
		}
		free_arr(valid);
	}
}

static	int		ft_validate(t_wolf *valid)
{
	int		i;

	i = 0;
	if (!(valid->map.arr = ft_strsplit(valid->map.line, ' ')))
		ft_error(14);
	while (valid->map.arr[i] != 0)
	{
		if (ft_strlen(valid->map.arr[i]) > 1)
			ft_error(10);
		if (!(ft_atoi(valid->map.arr[i]) > 0 &&
				ft_atoi(valid->map.arr[i]) <= 9) &&
				!(is_zero(valid->map.arr[i])))
			ft_error(11);
		valid->map.len_line++;
		i++;
	}
	(valid->map.cols == -1) ? valid->map.first_line = valid->map.len_line : 0;
	(valid->map.len_line < 3) ? ft_error(12) : 0;
	(valid->map.len_line > 100) ? ft_error(14) : 0;
	(valid->map.len_line != valid->map.first_line) ? ft_error(13) : 0;
	valid->map.len_line = 0;
	free_arr(valid);
	return (valid->map.first_line);
}

void			ft_parser(char *str, t_wolf *valid)
{
	valid->map.rows = 0;
	valid->map.cols = -1;
	valid->map.len_line = 0;
	if ((valid->map.fd = open(str, O_RDONLY)) < 0)
		ft_error(0);
	while (get_next_line(valid->map.fd, &valid->map.line) == 1)
	{
		valid->map.rows++;
		valid->map.cols = ft_validate(valid);
		if (valid->map.line)
		{
			free(valid->map.line);
			valid->map.line = NULL;
		}
	}
	(valid->map.rows < 3) ? ft_error(12) : 0;
	(valid->map.rows > 100) ? ft_error(14) : 0;
	close(valid->map.fd);
	ft_parser2(str, valid);
	check_border(valid);
	check_empty_square(valid);
}
