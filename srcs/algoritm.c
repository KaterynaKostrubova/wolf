/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkostrub <kkostrub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 15:56:06 by kkostrub          #+#    #+#             */
/*   Updated: 2018/11/20 15:37:49 by kkostrub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

static	void	ft_init_casting(t_wolf *w)
{
	w->cam = 2 * w->x / (double)(WIDTH) - 1;
	w->ray_dir_x = w->dir_x + w->plane_x * w->cam;
	w->ray_dir_y = w->dir_y + w->plane_y * w->cam;
	w->map_x = (int)w->pos_x;
	w->map_y = (int)w->pos_y;
	w->delta_dist_x = ((1 / w->ray_dir_x) < 0) ?
		((1 / w->ray_dir_x) * -1) : ((1 / w->ray_dir_x) * 1);
	w->delta_dist_y = ((1 / w->ray_dir_y) < 0) ?
		((1 / w->ray_dir_y) * -1) : ((1 / w->ray_dir_y) * 1);
}

static	void	ft_start(t_wolf *w)
{
	if (w->ray_dir_x < 0)
	{
		w->step_x = -1;
		w->side_dist_x = (w->pos_x - w->map_x) * w->delta_dist_x;
	}
	else
	{
		w->step_x = 1;
		w->side_dist_x = (w->map_x + 1.0 - w->pos_x) * w->delta_dist_x;
	}
	if (w->ray_dir_y < 0)
	{
		w->step_y = -1;
		w->side_dist_y = (w->pos_y - w->map_y) * w->delta_dist_y;
	}
	else
	{
		w->step_y = 1;
		w->side_dist_y = (w->map_y + 1.0 - w->pos_y) * w->delta_dist_y;
	}
}

static	void	ft_hit(t_wolf *w)
{
	w->hit = 0;
	while (w->hit == 0)
	{
		if (w->side_dist_x < w->side_dist_y)
		{
			w->side_dist_x += w->delta_dist_x;
			w->map_x += w->step_x;
			w->side = 0;
		}
		else
		{
			w->side_dist_y += w->delta_dist_y;
			w->map_y += w->step_y;
			w->side = 1;
		}
		if (w->map.map[w->map_x][w->map_y] > 0)
			w->hit = 1;
	}
}

static void		ft_put_to_win(t_wolf *w)
{
	char	*c;
	double	frame_time;
	
	// mlx_put_image_to_window(w->mlx_ptr, w->win_ptr,
	// w->sky.img_ptr, 0, 0);
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr,
	w->mlx.img_ptr, 0, 0);

	

	mlx_string_put(w->mlx_ptr, w->win_ptr,
			10, 10, 0xffffff, "Show hints: Press Z ");
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr,
	w->text.menu, (WIDTH - (WIDTH / 2) - 130), (HEIGHT - 35));
	if (w->menu == 1)
	{
		menu(w);
		w->old_time = w->time;
		w->time = clock();
		frame_time = (w->time - w->old_time) / 1000000;
		c = ft_itoa(1 / frame_time);
		mlx_string_put(w->mlx_ptr, w->win_ptr,
						WIDTH - 50, 10, 0xffffff, c);
		free(c);
	}
}

// static void		draw_texture(t_wolf *wo, int x, int x_text)
// {
// 	int		color;
// 	int		pos;
// 	int		pos_text;

// 	pos = -1;
// 	while (++pos < HEIGHT)
// 	{
// 		pos_text = pos << 8;
// 		pos_text = ((pos_text * HEIGHT) / HEIGHT) >> 8;
// 		if (pos_text >= HEIGHT)
// 			pos_text = HEIGHT - 1;
// 		if (pos_text < 0)
// 			pos_text = 0;
// 		pos_text = WIDTH * pos_text + x_text;
// 		color = wo->text.t[7][pos_text * 3 + 2] << 16;
// 		color += wo->text.t[7][pos_text * 3 + 1] << 8;
// 		color += wo->text.t[7][pos_text * 3];
// 		if (x >= 0 && x < WIDTH && pos >= 0 && pos < HEIGHT)
// 			*(int*)(wo->mlx.img_data_addr + ((x + pos * WIDTH) * 4)) = color;
// 	}
// }


// static void		draw_skybox(t_wolf *wo, int x)
// {
// 	t_ray		look;
// 	float		sky_x;
// 	float		cam_x;

// 	cam_x = (2.0 * (float)x / (float)WIDTH - 1.0);
// 	look.dir.x = wo->camera.dir.x + wo->plane_x * cam_x;
// 	look.dir.y = wo->camera.dir.y + wo->plane_y * cam_x;
// 	cam_x = M_PI / 2 + atan((look.dir.y / look.dir.x));
// 	if (look.dir.x < 0.0)
// 		cam_x += M_PI;
// 	sky_x = (cam_x / (2.0 * M_PI)) * (float)WIDTH;
// 	draw_texture(wo, x, (int)sky_x);
// }

void			ft_raycasting(t_wolf *w)
{
	w->x = -1;
	while (++w->x < WIDTH)
	{
		ft_init_casting(w);
		ft_start(w);
		ft_hit(w);
		if (w->side == 0)
			w->perp_wall_dist = (w->map_x - w->pos_x + (1 - w->step_x) / 2)
			/ w->ray_dir_x;
		else
			w->perp_wall_dist = (w->map_y - w->pos_y + (1 - w->step_y) / 2)
			/ w->ray_dir_y;
		w->height_line = (int)(HEIGHT / w->perp_wall_dist);
		w->draw_start = -w->height_line / 2 + HEIGHT / 2 + w->h;
		(w->draw_start < 0) ? w->draw_start = 0 : 0;
		w->draw_end = w->height_line / 2 + HEIGHT / 2 + w->h;
		(w->draw_end >= HEIGHT) ? w->draw_end = HEIGHT - 1 : 0;
		draw_skybox(w, w->x);
		texturing_calc_wall(w);
		texturing_calc_floor(w);
	}
	ft_put_to_win(w);
}
