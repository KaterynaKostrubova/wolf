/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkostrub <kkostrub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:44:46 by kkostrub          #+#    #+#             */
/*   Updated: 2018/11/20 13:16:28 by kkostrub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

static void		ident_text(t_wolf *w)
{
	if (w->text.side_text == 1)
		w->color = w->text.t[3][w->text.h * w->text_y + w->text_x];
	if (w->text.side_text == 2)
		w->color = w->text.t[4][w->text.h * w->text_y + w->text_x];
	if (w->text.side_text == 3)
		w->color = w->text.t[5][w->text.h * w->text_y + w->text_x];
	if (w->text.side_text == 4)
		w->color = w->text.t[6][w->text.h * w->text_y + w->text_x];
	if (w->side == 1)
		w->color = (w->color >> 1) & 8355711;
}

static void		ident_side_and_xcoord(t_wolf *w)
{
	w->text_x = (int)(w->wall_x * (double)w->text.w);
	if (w->side == 0 && w->ray_dir_x > 0)
	{
		w->text_x = w->text.w - w->text_x - 1;
		w->text.side_text = 3;
	}
	if (w->side == 1 && w->ray_dir_y < 0)
	{
		w->text_x = w->text.w - w->text_x - 1;
		w->text.side_text = 4;
	}
	if (w->side == 0 && w->ray_dir_x < 0)
		w->text.side_text = 1;
	if (w->side == 1 && w->ray_dir_y > 0)
		w->text.side_text = 2;
}

void			texturing_calc_wall(t_wolf *w)
{
	w->num = w->map.map[w->map_x][w->map_y] - 1;
	if (w->side == 0)
		w->wall_x = w->pos_y + w->perp_wall_dist * w->ray_dir_y;
	else
		w->wall_x = w->pos_x + w->perp_wall_dist * w->ray_dir_x;
	w->wall_x -= floor((w->wall_x));
	ident_side_and_xcoord(w);
	while (w->draw_start < w->draw_end)
	{
		w->text_y = ((((w->draw_start - 1) * 256 - HEIGHT * 128 +
						w->height_line * 128) * 64) / w->height_line) / 256;
		ident_text(w);
		if (w->x >= 0 && w->x < WIDTH && w->draw_start >= 0
			&& w->draw_start < HEIGHT)
			*(int*)(w->mlx.img_data_addr +
			((w->x + w->draw_start * WIDTH) * 4)) = w->color;
		w->draw_start++;
	}
}

static void		draw(t_wolf *w)
{
	while ((w->draw_end + 1) < HEIGHT)
	{
		w->current_dist = HEIGHT / (2.0 * (w->draw_end + 1) - HEIGHT);
		w->weight = (w->current_dist - w->dist_player) /
					(w->dist_wall - w->dist_player);
		w->current_floor_x = w->weight * w->floor_x_wall +
					(1.0 - w->weight) * w->pos_x;
		w->current_floor_y = w->weight * w->floor_y_wall +
					(1.0 - w->weight) * w->pos_y;
		w->floor_x = (int)(w->current_floor_x * w->text.w) % w->text.w;
		w->floor_y = (int)(w->current_floor_y * w->text.h) % w->text.h;
		w->color = (w->text.t[2][w->text.w * w->floor_x + w->floor_y] >> 1)
					& 8355711;
		if (w->x >= 0 && w->x < WIDTH && w->draw_start >= 0
			&& w->draw_start < HEIGHT)
			*(int*)(w->mlx.img_data_addr +
			((w->x + w->draw_end * WIDTH) * 4)) = w->color;
	// 	w->color = w->text.t[1][WIDTH * w->floor_x + w->floor_y];
	// 	if (w->x >= 0 && w->x < WIDTH && w->draw_start >= 0
	// 		&& w->draw_start < HEIGHT)
	// 		*(int*)(w->mlx.img_data_addr +
	// 		((w->x + (HEIGHT - w->draw_end) * WIDTH) * 4)) = w->color;
	 	w->draw_end++;
	 }
}

void			texturing_calc_floor(t_wolf *w)
{
	if (w->side == 0 && w->ray_dir_x > 0)
	{
		w->floor_x_wall = w->map_x;
		w->floor_y_wall = w->map_y + w->wall_x;
	}
	else if (w->side == 0 && w->ray_dir_x < 0)
	{
		w->floor_x_wall = w->map_x + 1.0;
		w->floor_y_wall = w->map_y + w->wall_x;
	}
	else if (w->side == 1 && w->ray_dir_y > 0)
	{
		w->floor_x_wall = w->map_x + w->wall_x;
		w->floor_y_wall = w->map_y;
	}
	else
	{
		w->floor_x_wall = w->map_x + w->wall_x;
		w->floor_y_wall = w->map_y + 1.0;
	}
	w->dist_wall = w->perp_wall_dist;
	w->dist_player = 0.0;
	if (w->draw_end < 0)
		w->draw_end = HEIGHT;
	draw(w);
}
