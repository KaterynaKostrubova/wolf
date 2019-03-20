/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkostrub <kkostrub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:39:06 by kkostrub          #+#    #+#             */
/*   Updated: 2018/11/20 13:16:25 by kkostrub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

static void		ft_texture_2(t_wolf *w, void *temp)
{
	int	win_x;
	int	win_y;

	win_x = WIDTH;
	win_y = HEIGHT;

	(!(temp = mlx_xpm_file_to_image(w->mlx_ptr, "texture/flag.xpm",
		&w->text.w, &w->text.h))) ? ft_error(6) : 0;
	(!(w->text.t[5] = (int*)mlx_get_data_addr(temp, &w->mlx.bpp, &w->mlx.sl,
		&w->mlx.end))) ? ft_error(4) : 0;
	(!(temp = mlx_xpm_file_to_image(w->mlx_ptr, "texture/grey_wall.xpm",
		&w->text.w, &w->text.h))) ? ft_error(6) : 0;
	(!(w->text.t[6] = (int*)mlx_get_data_addr(temp, &w->mlx.bpp, &w->mlx.sl,
		&w->mlx.end))) ? ft_error(4) : 0;
	(!(temp = mlx_xpm_file_to_image(w->mlx_ptr, "texture/grey_wall.xpm",
		&win_x, &win_y))) ? ft_error(6) : 0;
	(!(w->text.t[7] = (int*)mlx_get_data_addr(temp, &w->mlx.bpp, &w->mlx.sl,
		&w->mlx.end))) ? ft_error(4) : 0;
	// (!(w->sky.img_ptr = mlx_xpm_file_to_image(w->mlx_ptr, "texture/sky.xpm",
	// 	&win_x, &win_y))) ? ft_error(6) : 0;
	// (!(w->sky.img_data_addr = mlx_get_data_addr(w->sky.img_ptr, &w->mlx.bpp, &w->mlx.sl,
	// 	&w->mlx.end))) ? ft_error(4) : 0;
}

void			ft_texture(t_wolf *w)
{
	void *temp;

	(!(w->text.menu = mlx_xpm_file_to_image(w->mlx_ptr,
		"texture/info.xpm", &w->text.w, &w->text.h))) ? ft_error(6) : 0;
	(!(w->text.t[0] = (int*)mlx_get_data_addr(w->text.menu, &w->mlx.bpp,
		&w->mlx.sl, &w->mlx.end))) ? ft_error(4) : 0;
	(!(temp = mlx_xpm_file_to_image(w->mlx_ptr, "texture/wood.xpm",
		&w->text.w, &w->text.h))) ? ft_error(6) : 0;
	(!(w->text.t[1] = (int*)mlx_get_data_addr(temp, &w->mlx.bpp, &w->mlx.sl,
		&w->mlx.end))) ? ft_error(4) : 0;
	(!(temp = mlx_xpm_file_to_image(w->mlx_ptr, "texture/stone.xpm",
		&w->text.w, &w->text.h))) ? ft_error(6) : 0;
	(!(w->text.t[2] = (int*)mlx_get_data_addr(temp, &w->mlx.bpp, &w->mlx.sl,
		&w->mlx.end))) ? ft_error(4) : 0;
	(!(temp = mlx_xpm_file_to_image(w->mlx_ptr, "texture/redbrick.xpm",
		&w->text.w, &w->text.h))) ? ft_error(6) : 0;
	(!(w->text.t[3] = (int*)mlx_get_data_addr(temp, &w->mlx.bpp, &w->mlx.sl,
		&w->mlx.end))) ? ft_error(4) : 0;
	(!(temp = mlx_xpm_file_to_image(w->mlx_ptr, "texture/diffbrick.xpm",
		&w->text.w, &w->text.h))) ? ft_error(6) : 0;
	(!(w->text.t[4] = (int*)mlx_get_data_addr(temp, &w->mlx.bpp, &w->mlx.sl,
		&w->mlx.end))) ? ft_error(4) : 0;
	ft_texture_2(w, temp);
}

void			ft_error(int n)
{
	(n == 0) ? ft_putendl("open error: no such file") : 0;
	(n == 1) ? ft_putendl("memory allocate error") : 0;
	(n == 2) ? ft_putendl("mlx_init error") : 0;
	(n == 3) ? ft_putendl("mlx_new_image error") : 0;
	(n == 4) ? ft_putendl("mlx_get_data_addr error") : 0;
	(n == 5) ? ft_putendl("mlx_new_image error") : 0;
	(n == 6) ? ft_putendl("texture file error") : 0;
	(n == 7) ? ft_putendl("ft_strsplit error") : 0;
	(n == 8) ? ft_putendl("The map must contain borders.") : 0;
	(n == 9) ? ft_putendl("The map must contain empty space.") : 0;
	(n == 10) ?
	ft_putendl("The number of the square must contain only one digit.") : 0;
	(n == 11) ? ft_putendl("The map must contain only digits.") : 0;
	(n == 12) ? ft_putendl("Small map. Minimum size 3x3") : 0;
	(n == 13) ? ft_putendl("The map must contain the same length of line.") : 0;
	(n == 14) ? ft_putendl("The big map. Max size 100x100") : 0;
	(n > 7 && n < 14) ?
	ft_putendl("Example: 1 1 1\n         1 0 1\n         1 1 1") : 0;
	exit(0);
}

void			free_arr(t_wolf *v)
{
	int i;

	if (v->map.arr)
	{
		i = -1;
		while (v->map.arr[++i])
			ft_strdel(&v->map.arr[i]);
		free(v->map.arr);
		v->map.arr = NULL;
	}
}

int				is_zero(char *c)
{
	if (ft_strcmp(c, "0") == 0)
		return (1);
	return (0);
}
