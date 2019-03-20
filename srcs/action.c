/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkostrub <kkostrub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:07:20 by kkostrub          #+#    #+#             */
/*   Updated: 2018/11/05 13:08:43 by kkostrub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

static	void	down_up(t_wolf *w)
{
	if (w->up == 1)
	{
		if (w->map.map[(int)(w->pos_x + w->dir_x * w->collision)]
						[(int)(w->pos_y)] == 0)
			w->pos_x += w->dir_x * w->speed;
		if (w->map.map[(int)(w->pos_x)]
			[(int)(w->pos_y + w->dir_y * w->collision)] == 0)
			w->pos_y += w->dir_y * w->speed;
	}
	if (w->down == 1)
	{
		if (w->map.map[(int)(w->pos_x - w->dir_x * w->collision)]
						[(int)(w->pos_y)] == 0)
			w->pos_x -= w->dir_x * w->speed;
		if (w->map.map[(int)(w->pos_x)]
						[(int)(w->pos_y - w->dir_y * w->collision)] == 0)
			w->pos_y -= w->dir_y * w->speed;
	}
}

static	void	turn_left_right(t_wolf *w)
{
	if (w->left == 1)
	{
		w->old_dir_x = w->dir_x;
		w->dir_x = w->dir_x * cos(0.05) - w->dir_y * sin(0.05);
		w->dir_y = w->old_dir_x * sin(0.05) + w->dir_y * cos(0.05);
		w->old_plane_x = w->plane_x;
		w->plane_x = w->plane_x * cos(0.05) - w->plane_y * sin(0.05);
		w->plane_y = w->old_plane_x * sin(0.05) + w->plane_y * cos(0.05);
	}
	if (w->right == 1)
	{
		w->old_dir_x = w->dir_x;
		w->dir_x = w->dir_x * cos(-0.05) - w->dir_y * sin(-0.05);
		w->dir_y = w->old_dir_x * sin(-0.05) + w->dir_y * cos(-0.05);
		w->old_plane_x = w->plane_x;
		w->plane_x = w->plane_x * cos(-0.05) - w->plane_y * sin(-0.05);
		w->plane_y = w->old_plane_x * sin(-0.05) + w->plane_y * cos(-0.05);
	}
}

int				action(t_wolf *w)
{
	ft_bzero(w->mlx.img_data_addr, WIDTH * HEIGHT * 5);
	down_up(w);
	turn_left_right(w);
	ft_raycasting(w);
	return (0);
}

void			menu(t_wolf *w)
{
	mlx_string_put(w->mlx_ptr, w->win_ptr,
			10, 30, 0xffffff, "W / ^ : GO ahead");
	mlx_string_put(w->mlx_ptr, w->win_ptr,
			10, 50, 0xffffff, "S / v : GO back");
	mlx_string_put(w->mlx_ptr, w->win_ptr,
			10, 70, 0xffffff, "A / <- / mouse : turn left");
	mlx_string_put(w->mlx_ptr, w->win_ptr,
			10, 90, 0xffffff, "W / ->  / mouse : turn right");
	mlx_string_put(w->mlx_ptr, w->win_ptr,
			10, 110, 0xffffff, "Left/Right button of mouse : shot");
}
