/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkostrub <kkostrub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:27:30 by kkostrub          #+#    #+#             */
/*   Updated: 2018/11/20 13:16:29 by kkostrub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

static	void	add_presskey(int key, t_wolf *w)
{
	int fd;

	if (key == M)
	{
		if (w->music == 0 && (fd = open("sound/sound.mp3", O_RDONLY)) >= 0)
		{
			system("afplay sound/sound.mp3&");
			w->music = 1;
			close(fd);
		}
		else if (w->music == 1 && (fd = open("sound/sound.mp3", O_RDONLY)) >= 0)
		{
			system("killall afplay");
			w->music = 0;
			close(fd);
		}
	}
	else if (key == EXIT)
	{
		if (w->music == 1 && (fd = open("sound/sound.mp3", O_RDONLY)) >= 0)
			system("killall afplay");
		exit(1);
	}
}

int				presskey(int key, t_wolf *w)
{
	add_presskey(key, w);
	if (key == SPACE)
		w->speed = 0.1;
	else if (key == Z)
		w->menu = 1;
	else if (key == W || key == UP)
		w->up = 1;
	else if (key == S || key == DOWN)
		w->down = 1;
	else if (key == D || key == RIGHT)
		w->right = 1;
	else if (key == A || key == LEFT)
		w->left = 1;
	return (0);
}

int				key_zero(int key, t_wolf *w)
{
	if (key == UP || key == W)
		w->up = 0;
	else if (key == DOWN || key == S)
		w->down = 0;
	else if (key == D || key == RIGHT)
		w->right = 0;
	else if (key == A || key == LEFT)
		w->left = 0;
	else if (key == SPACE)
		w->speed = 0.05;
	else if (key == Z)
		w->menu = 0;
	return (0);
}

int				close_window(t_wolf *w)
{
	int fd;

	if (w->music == 1 && (fd = open("sound/sound.mp3", O_RDONLY)) >= 0)
		system("killall afplay");
	exit(1);
	return (0);
}

void			ex(int i)
{
	system("killall afplay");
	i += i;
	exit(1);
}
