/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkostrub <kkostrub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 12:50:44 by kkostrub          #+#    #+#             */
/*   Updated: 2018/11/07 16:46:39 by kkostrub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "mlx.h"
# include "math.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <signal.h>
# include <time.h>

# define WIDTH 2048
# define HEIGHT 1024
# define TEX_W 64
# define TEX_H 64

# define EXIT 53
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126

# define SPACE 49
# define A 0
# define S 1
# define D 2
# define W 13
# define M 46
# define Z 6

# define LEFT_MOUSE 1
# define RIGHT_MOUSE 2

typedef struct		s_mlx
{
	int				bpp;
	int				sl;
	int				end;
	char			*img_data_addr;
	void			*img_ptr;
}					t_mlx;

typedef struct		s_map
{
	int				fd;
	char			*line;
	int				len_line;
	int				first_line;
	int				cols;
	int				rows;
	int				**map;
	char			**arr;
}					t_map;

typedef struct		s_text
{
	int				*t[20];
	int				w;
	int				h;
	void			*menu;
	int				side_text;
}					t_text;

typedef struct	s_vec2
{
	float		x;
	float		y;
}				t_vec2;

typedef struct	s_camera
{
	t_vec2		pos;
	t_vec2		dir;
	t_vec2		plane;
}				t_camera;				



typedef struct	s_ray
{
	t_vec2		pos;
	t_vec2		dir;
}				t_ray;

typedef struct		s_wolf
{
	void			*mlx_ptr;
	void			*win_ptr;

	t_mlx			mlx;
	t_map			map;
	t_text			text;
	t_mlx			sky;
	t_camera		camera;

	int				x;
	int				up;
	int				down;
	int				left;
	int				right;
	double			pos_x;
	double			pos_y;
	double			x_ray_pos;
	double			y_ray_pos;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			cam;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				draw_start;
	int				draw_end;
	double			move_speed;
	double			rot_speed;
	double			old_dir_x;
	double			old_plane_x;
	int				height_line;
	int				color;
	int				x1;
	int				y1;
	int				text_x;
	int				text_y;
	int				num;
	double			wall_x;
	double			floor_x_wall;
	double			floor_y_wall;
	double			dist_wall;
	double			dist_player;
	double			current_dist;
	int				floor_x;
	int				floor_y;
	double			weight;
	double			current_floor_x;
	double			current_floor_y;
	int				music;
	double			time;
	double			old_time;
	int				h;
	double			collision;
	double			speed;
	int				menu;
}					t_wolf;

int					click(int key);
int					mouse(int x, int y, t_wolf *w);
int					close_window(t_wolf *w);
void				ex(int i);
void				ft_raycasting(t_wolf	*w);
int					action(t_wolf *w);
void				draw_wall(t_wolf	*w);
int					is_zero(char *c);
void				ft_parser(char *str, t_wolf *valid);
void				ft_error(int n);
void				ft_texture(t_wolf *w);
void				texturing_calc_wall(t_wolf	*w);
void				texturing_calc_floor(t_wolf	*w);
int					presskey(int key, t_wolf *w);
int					key_zero(int key, t_wolf *w);
void				free_arr(t_wolf *v);
int					is_zero(char *c);
void				menu(t_wolf *w);
#endif
