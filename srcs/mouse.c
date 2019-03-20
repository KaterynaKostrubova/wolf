/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkostrub <kkostrub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:33:47 by kkostrub          #+#    #+#             */
/*   Updated: 2018/11/05 12:34:38 by kkostrub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

static	void	turn_left(t_wolf *w)
{
	w->old_dir_x = w->dir_x;
	w->dir_x = w->dir_x * cos(0.05) - w->dir_y * sin(0.05);
	w->dir_y = w->old_dir_x * sin(0.05) + w->dir_y * cos(0.05);
	w->old_plane_x = w->plane_x;
	w->plane_x = w->plane_x * cos(0.05) - w->plane_y * sin(0.05);
	w->plane_y = w->old_plane_x * sin(0.05) + w->plane_y * cos(0.05);
}

static	void	turn_right(t_wolf *w)
{
	w->old_dir_x = w->dir_x;
	w->dir_x = w->dir_x * cos(-0.05) - w->dir_y * sin(-0.05);
	w->dir_y = w->old_dir_x * sin(-0.05) + w->dir_y * cos(-0.05);
	w->old_plane_x = w->plane_x;
	w->plane_x = w->plane_x * cos(-0.05) - w->plane_y * sin(-0.05);
	w->plane_y = w->old_plane_x * sin(-0.05) + w->plane_y * cos(-0.05);
}

int				mouse(int x, int y, t_wolf *w)
{
	static int	x_s = 0;

	if (x >= 0 && y >= 0 && x <= WIDTH && y <= HEIGHT)
	{
		ft_bzero(w->mlx.img_data_addr, WIDTH * HEIGHT * 5);
		if (x < x_s)
			turn_left(w);
		if (x > x_s)
			turn_right(w);
		x_s = x;
		ft_raycasting(w);
	}
	return (0);
}

int				click(int key)
{
	int fd;

	if (key == LEFT_MOUSE)
	{
		if ((fd = open("sound/pistolet.mp3", O_RDONLY)) >= 0)
			system("afplay sound/pistolet.mp3&");
		close(fd);
	}
	else if (key == RIGHT_MOUSE)
	{
		if ((fd = open("sound/p.mp3", O_RDONLY)) >= 0)
			system("afplay sound/p.mp3&");
		close(fd);
	}
	return (0);
}
