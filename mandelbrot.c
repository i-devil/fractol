/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 11:53:05 by ide-vill          #+#    #+#             */
/*   Updated: 2015/03/03 23:19:44 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_draw_mandelbrot(t_all *all)
{
	t_pt2d		pt;
	int			i;
	float		c_i;
	float		c_r;
	float		z_i;
	float		z_r;
	float		a;
	float		b;
	float		tmp;

	pt.x = 0;
	a = -2.1;
	b = -1.2;
	while (pt.x < WIN_WIDTH)
	{
		pt.y = 0;
		while (pt.y < WIN_HEIGHT)
		{
			c_r = (pt.x / all->scale) + a;
			c_i = (pt.y / all->scale) + b;
			z_r = 0;
			z_i = 0;
			i = 0;
			while ((i < all->max_ite) &&
					((z_r * z_r) + (z_i * z_i) < all->limit))
			{
				tmp = z_r;
				z_r = (z_r * z_r) - (z_i * z_i) + c_r;
				z_i = (2 * tmp * z_i) + c_i;
				i++;
			}
			ft_choose_color(all, i);
			ft_put_pixel(&all->img, pt);
			pt.y++;
		}
		pt.x++;
	}
}
