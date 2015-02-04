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

int			loop_hook(t_all *all)
{
	if (all->re)
	{
		//ft_bzero(all->img.data, WIN_WIDTH * WIN_HEIGHT * 4);
		ft_draw_mandelbrot(all);
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
