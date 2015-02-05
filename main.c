/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 11:52:49 by ide-vill          #+#    #+#             */
/*   Updated: 2015/02/04 11:52:54 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

void		ft_init(t_all *all)
{

	all->img.adj = 2.0;
	all->off.x = -100;
	all->off.y = -100;
	all->re = 1;
	all->limit = 4;
	all->scale = 300;
	all->max_ite = 100;
	all->fix = -1;

}

void		ft_choose(int ac, char **av, t_all *all)
{
	if (ac == 2)
	{
		if (ft_strcmp(av[1], "mandelbrot") == 0)
			all->frac_nb = 1;
		else if (ft_strcmp(av[1], "julia") == 0)
			all->frac_nb = 2;
		else if (ft_strcmp(av[1], "douady") == 0)
			all->frac_nb = 3;
		else
		{
			ft_putendl_fd("Error: \n Use julia, mandelbrot, or ??", 2);
			exit(0);
		}
	}
	else
	{
		ft_putendl_fd("Error: Too many or too few arguments\n Use julia, mandelbrot or ??", 2);
		exit(0);
	}
}

int			main(int argc, char **argv)
{
	t_all	*all;

	all = (t_all*)malloc(sizeof(t_all));
	ft_choose(argc, argv, all);
	all->e.mlx = mlx_init();
	all->e.win = mlx_new_window(all->e.mlx, WIN_WIDTH, WIN_HEIGHT, "Fract'ol");
	ft_init(all);
	all->img.img = mlx_new_image(all->e.mlx, WIN_WIDTH, WIN_HEIGHT);
	all->img.data = mlx_get_data_addr(all->img.img, &all->img.bpp,
	&all->img.size_line, &all->img.endian);
	mlx_hook(all->e.win, MotionNotify, PointerMotionMask, mouse_move, all);
	mlx_key_hook(all->e.win, key_hook, all);
	mlx_mouse_hook(all->e.win, mouse_hook, all);
	mlx_loop_hook(all->e.mlx, loop_hook, all);
	mlx_expose_hook(all->e.win, expose_hook, all);
	mlx_loop(all->e.mlx);
	return (0);
}
