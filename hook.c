/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 11:52:34 by ide-vill          #+#    #+#             */
/*   Updated: 2015/03/05 17:20:53 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			loop_hook(t_all *all)
{
	if (all->re)
	{
		if (all->frac_nb == 1)
			ft_draw_mandelbrot(all);
		else if (all->frac_nb == 2)
			ft_draw_julia(all);
		else if (all->frac_nb == 3)
			ft_draw_douady(all);
		mlx_put_image_to_window(all->e.mlx, all->e.win, all->img.img, 0, 0);
		mlx_string_put(all->e.mlx, all->e.win, 10, 40, 0xFFFFFF,
			"Scroll Mouse = Zoom");
		mlx_string_put(all->e.mlx, all->e.win, 10, 60, 0xFFFFFF,
			"Arrows keys = Move");
		mlx_string_put(all->e.mlx, all->e.win, 10, 80, 0xFFFFFF,
			"Space Bar = Reset");
		mlx_string_put(all->e.mlx, all->e.win, 10, 100, 0xFFFFFF,
			"1 = Mandelbrot / 2 = Julia / 3 = Douady");
		mlx_string_put(all->e.mlx, all->e.win, 10, 120, 0xFFFFFF,
			"9/8 = Iterations +/- 50");
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
		all->re = 1;
	}
	if (button == 5)
	{
		all->scale /= ZOOM;
		all->off.x = all->off.x / ZOOM - ((WIN_WIDTH - (WIN_WIDTH / ZOOM)) / 2)
		/ ZOOM - (x - WIN_WIDTH / 2) * (1 - (1 / ZOOM)) + ZOOM;
		all->off.y = all->off.y / ZOOM - ((WIN_HEIGHT - (WIN_HEIGHT /
			ZOOM)) / 2) / ZOOM - (y - WIN_HEIGHT / 2) * (1 - (1 / ZOOM)) + ZOOM;
		all->re = 1;
	}
	return (0);
}

int			key_hook(int keycode, t_all *all)
{
	if (keycode == 65307)
		exit(0);
	if (keycode == 65362)
		all->off.y += 10;
	if (keycode == 65364)
		all->off.y -= 10;
	if (keycode == 65363)
		all->off.x -= 10;
	if (keycode == 65361)
		all->off.x += 10;
	if (keycode == 65457)
		all->frac_nb = 1;
	if (keycode == 65458)
		all->frac_nb = 2;
	if (keycode == 65459)
		all->frac_nb = 3;
	if (keycode == 65465)
		all->max_ite += 50;
	if (keycode == 65464)
		all->max_ite -= 50;
	if (keycode == 32)
		ft_init(all);
	all->re = 1;
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
	return (0);
}

int			expose_hook(t_all *all)
{
	mlx_put_image_to_window(all->e.mlx, all->e.win, all->img.img, 0, 0);
	mlx_string_put(all->e.mlx, all->e.win, 10, 40, 0xFFFFFF,
		"Scroll Mouse = Zoom");
	mlx_string_put(all->e.mlx, all->e.win, 10, 60, 0xFFFFFF,
		"Arrows keys = Move");
	mlx_string_put(all->e.mlx, all->e.win, 10, 80, 0xFFFFFF,
		"Space Bar = Reset");
	mlx_string_put(all->e.mlx, all->e.win, 10, 100, 0xFFFFFF,
		"1 = Mandelbrot / 2 = Julia / 3 = Douady");
	mlx_string_put(all->e.mlx, all->e.win, 10, 120, 0xFFFFFF,
		"9/8 = Iterations +/-50");
	return (0);
}
