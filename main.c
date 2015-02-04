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

/*void ft_error(int argc, char *argv)
{
	if (argc != 2 || (argv != 'julia' || argv != 'mandelbrot' || argv != 'cosinus' || argv != 'modulo')
	{
		ft_putendl_fd("Error: \n Use julia, mandelbrot, cosinus or modulo.", 2);
		exit(0);
	}
}*/

void		ft_init(t_all *all)
{
	t_color	c;

	c.r = 255;
	c.g = 0;
	c.b = 0;
	all->img.adj = 2.0;
	all->img.posimgx = WIN_WIDTH / 8;
	all->img.posimgy = WIN_HEIGHT / 2;
	all->re = 1;
	all->limit = 4;
	all->scale = 20;
	all->max_ite = 100;
	all->img.color = ft_color_to_int(c);
}

int			main(int argc, char **argv)
{
	t_all	all;

	(void)argc;
	(void)argv;
	//ft_error(argc, argv[1]);
	all.e.mlx = mlx_init();
	all.e.win = mlx_new_window(all.e.mlx, WIN_WIDTH, WIN_HEIGHT, "Fract'ol");
	ft_init(&all);
	all.img.img = mlx_new_image(all.e.mlx, WIN_WIDTH, WIN_HEIGHT);
	all.img.data = mlx_get_data_addr(all.img.img, &all.img.bpp,
	&all.img.size_line, &all.img.endian);
	//mlx_key_hook(all.e.win, key_hook, &all);
	//mlx_mouse_hook(all.e.win, mouse_hook, &all);
	mlx_loop_hook(all.e.mlx, loop_hook, &all);
	mlx_expose_hook(all.e.win, expose_hook, &all);
	mlx_loop(all.e.mlx);
	return (0);
}
