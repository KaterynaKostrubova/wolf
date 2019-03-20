/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkostrub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 18:40:50 by kkostrub          #+#    #+#             */
/*   Updated: 2018/06/14 18:44:19 by kkostrub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int const fd, char **line)
{
	static char *keep[FD];
	t_gnl		g;

	MEMALLOC(1);
	ERR(BUFF_SIZE <= 0 || fd < 0 || !line);
	while ((g.rd = read(fd, g.temp, BUFF_SIZE)) > 0)
	{
		RET_1(solve(&keep[fd], g.temp, line));
		FREE_T(1);
		MEMALLOC(1);
	}
	ERR(g.rd < 0);
	RET_1((g.solve_value = solve(&keep[fd], g.temp, line)));
	if (ft_strlen(keep[fd]) > 0)
	{
		*line = ft_strdup(keep[fd]);
		free(keep[fd]);
		keep[fd] = NULL;
		RET_1(1);
	}
	FREE_T(1);
	return (g.solve_value);
}

char	*newmemory(void)
{
	int		i;
	char	*temp;

	i = 0;
	if (!(temp = (char *)malloc(sizeof(char *) * (BUFF_SIZE + 1))))
		return (NULL);
	while (i++ <= BUFF_SIZE)
		temp[i] = 0;
	return (temp);
}

int		solve(char **keep, char *temp, char **line)
{
	t_solve	v;

	v.i = 0;
	v.end = -1;
	v.ptr = (*keep && temp) ? ft_strjoin(*keep, temp) : ft_strdup(temp);
	ft_strdel(keep);
	ft_bzero(temp, BUFF_SIZE + 1);
	*keep = v.ptr;
	v.keep_temp = *keep;
	while (v.keep_temp[v.i] && v.keep_temp[v.i] != '\n')
		v.i++;
	if (v.keep_temp[v.i] == '\n')
	{
		v.keep_temp[v.i] = '\0';
		*keep = v.keep_temp;
		v.end = v.i;
	}
	if (v.end != -1)
	{
		*line = ft_strdup(*keep);
		v.temp_ptr = *keep;
		*keep = ft_strdup(*keep + v.end + 1);
		RET_SOLVE(1);
	}
	return (0);
}
