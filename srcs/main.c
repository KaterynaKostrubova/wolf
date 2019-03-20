/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkostrub <kkostrub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 15:29:44 by kkostrub          #+#    #+#             */
/*   Updated: 2018/11/20 13:16:23 by kkostrub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

static	void	ft_usage(void)
{
	ft_putendl("usage: ./wolf3d [map]");
	exit(0);
}

static	int		find_first_position(t_wolf *w)
{
	int x;
	int y;

	x = w->map.rows - 2;
	while (x >= 1)
	{
		y = w->map.cols - 2;
		while (y >= 1)
		{
			if (w->map.map[x][y] == 0)
			{
				w->pos_x = x + 0.5;
				w->pos_y = y + 0.5;
				return (1);
			}
			y--;
		}
		x--;
	}
	return (0);
}

static	void	init_value(t_wolf *w)
{
	int	win_x;
	int	win_y;

	win_x = 2048;
	win_y = 1024;
	if (!find_first_position(w))
		ft_error(8);
	w->h = 0;
	w->dir_x = -1;
	w->dir_y = 0;
	w->plane_x = 0;
	w->plane_y = 0.66;
	w->text.w = 64;
	w->text.h = 64;
	w->mlx.bpp = 5;
	w->mlx.sl = 1;
	w->mlx.end = 1;
	w->text.side_text = 0;
	w->music = 0;
	w->time = 0;
	w->old_time = 0;
	w->collision = 0.4;
	w->speed = 0.05;
	w->menu = 0;
	// (!(w->sky.img_ptr = mlx_xpm_file_to_image(w->mlx_ptr, "texture/skybox.xpm",
	// 	&win_x, &win_y))) ? ft_error(6) : 0;
	// (!(w->sky.img_data_addr = mlx_get_data_addr(w->sky.img_ptr, &w->mlx.bpp, &w->mlx.sl,
	// 	&w->mlx.end))) ? ft_error(4) : 0;
	ft_texture(w);
}

static	void	ft_mlx_init(t_wolf *w)
{
	if (!(w->mlx_ptr = mlx_init()))
		ft_error(2);
	if (!(w->win_ptr = mlx_new_window(w->mlx_ptr, WIDTH,
			HEIGHT, "wolf3d")))
		ft_error(3);
	init_value(w);
	if (!(w->mlx.img_ptr = mlx_new_image(w->mlx_ptr, WIDTH, HEIGHT)))
		ft_error(5);
	if (!(w->mlx.img_data_addr = mlx_get_data_addr(w->mlx.img_ptr,
			&w->mlx.bpp, &w->mlx.sl, &w->mlx.end)))
		ft_error(4);
	
}

int				main(int argc, char **argv)
{
	t_wolf	*w;

	if (argc != 2)
		ft_usage();
	if (!(w = (t_wolf *)malloc(sizeof(t_wolf))))
		ft_error(1);
	ft_parser(argv[1], w);
	ft_mlx_init(w);
	ft_raycasting(w);
	mlx_hook(w->win_ptr, 17, 0, close_window, w);
	mlx_hook(w->win_ptr, 2, 0, presskey, w);
	mlx_hook(w->win_ptr, 3, 0, key_zero, w);
	mlx_hook(w->win_ptr, 6, 0, mouse, w);
	mlx_mouse_hook(w->win_ptr, click, w);
	signal(SIGINT, ex);
	mlx_loop_hook(w->mlx_ptr, action, w);
	mlx_loop(w->mlx_ptr);
	return (0);
}
