/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 11:52:34 by ide-vill          #+#    #+#             */
/*   Updated: 2015/02/04 11:52:39 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
int			loop_hook(t_all *all)
{
	if (all->re)
	{
		//ft_bzero(all->img.data, WIN_WIDTH * WIN_HEIGHT * 4);
		if (all->frac_nb == 1)
			ft_draw_mandelbrot(all);
		else if (all->frac_nb == 2)
			ft_draw_julia(all);
		else if (all->frac_nb == 3)
			ft_draw_douady(all);
		mlx_put_image_to_window(all->e.mlx, all->e.win, all->img.img, 0, 0);
		mlx_string_put(all->e.mlx, all->e.win, 10, 40, 0xFFFFFF,
			"Mouse click or 8/5 = Zoom");
		mlx_string_put(all->e.mlx, all->e.win, 10, 60, 0xFFFFFF,
			"Arrows keys = Move");
		mlx_string_put(all->e.mlx, all->e.win, 10, 80, 0xFFFFFF,
			"space bar = reset");
		mlx_string_put(all->e.mlx, all->e.win, 10, 100, 0xFFFFFF,
			"9/6 = rotation");
		mlx_string_put(all->e.mlx, all->e.win, 10, 120, 0xFFFFFF,
			"+/- = altitude");
		all->re = 0;
	}
	return (0);
}

int			mouse_hook(int button, int x, int y, t_all *all)
{
	if (button == 1)
		all->fix = -all->fix;
	if (button == 4)
	{
		all->scale *= ZOOM;
		all->off.x = (all->off.x + ((WIN_WIDTH - (WIN_WIDTH / ZOOM)) / 2) +
		(x - WIN_WIDTH / 2) * (1 - (1 / ZOOM))) * ZOOM;
		all->off.y = (all->off.y + ((WIN_HEIGHT - (WIN_HEIGHT / ZOOM)) / 2) +
		(y - WIN_HEIGHT / 2) * (1 - (1 / ZOOM))) * ZOOM;
	}
	if (button == 5)
	{
		all->scale /= ZOOM;
		all->off.x = (all->off.x - ((WIN_WIDTH - (WIN_WIDTH / ZOOM)) / 2) +
		(x - WIN_WIDTH / 2) / (1 - (1 / ZOOM))) / ZOOM;
		all->off.y = (all->off.y - ((WIN_HEIGHT - (WIN_HEIGHT / ZOOM)) / 2) +
		(y - WIN_HEIGHT / 2) / (1 - (1 / ZOOM))) / ZOOM;
	}
	all->re = 1;
	return(0);
}

int			key_hook(int keycode, t_all *all)
{
	(void)all;
	if (keycode == 65307)
	{
		//mlx_destroy_image(all->e.mlx, all->img.img);
		exit(0);
	}
	if (keycode == 65464)
	{
		all->scale *= ZOOM;
		all->off.x -= WIN_WIDTH / 2.0;
		all->off.y -= WIN_HEIGHT/2.0;
		all->re = 1;
	}
	if (keycode == 65461)
	{
		all->scale /= ZOOM;
		all->off.x += WIN_WIDTH/2.0;
		all->off.y += WIN_HEIGHT/2.0;
		all->re = 1;
	}
	return (0);
}

int			mouse_move(int x, int y, t_all *all)
{
	if (all->fix < 0)
	{
		all->c_r = (float)((x - WIN_WIDTH / 2) / all->scale);
		all->c_i = (float)((y - WIN_HEIGHT / 2) / all->scale);
		all->re = 1;
	}
	return(0);
}

int			expose_hook(t_all *all)
{
	mlx_put_image_to_window(all->e.mlx, all->e.win, all->img.img, 0, 0);
	mlx_string_put(all->e.mlx, all->e.win, 10, 40, 0xFFFFFF,
		"Mouse click or 8/5 = Zoom");
	mlx_string_put(all->e.mlx, all->e.win, 10, 60, 0xFFFFFF,
		"Arrows keys = Move");
	mlx_string_put(all->e.mlx, all->e.win, 10, 80, 0xFFFFFF,
		"space bar = reset");
	mlx_string_put(all->e.mlx, all->e.win, 10, 100, 0xFFFFFF,
		"9/6 = rotation");
	mlx_string_put(all->e.mlx, all->e.win, 10, 120, 0xFFFFFF,
		"+/- = altitude");
	return (0);
}
