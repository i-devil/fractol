/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 11:53:05 by ide-vill          #+#    #+#             */
/*   Updated: 2015/03/05 16:45:00 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_init_mandelbrot(t_pt2d *pt, t_frac *frac)
{
	pt->x = 0;
	frac->a = -2.1;
	frac->b = -1.2;
}

void		ft_mandelbrot_sub(t_all *all, t_frac *frac, t_pt2d *pt)
{
	frac->c_r = ((pt->x + all->off.x) / all->scale) + frac->a;
	frac->c_i = ((pt->y + all->off.y) / all->scale) + frac->b;
	frac->z_r = 0;
	frac->z_i = 0;
	frac->i = 0;
}

void		ft_draw_mandelbrot(t_all *all)
{
	t_pt2d	pt;
	t_frac	frac;

	ft_init_mandelbrot(&pt, &frac);
	while (pt.x++ < WIN_WIDTH)
	{
		pt.y = 0;
		while (pt.y++ < WIN_HEIGHT)
		{
			ft_mandelbrot_sub(all, &frac, &pt);
			while ((frac.i < all->max_ite) &&
					((frac.z_r * frac.z_r) +
						(frac.z_i * frac.z_i) < all->limit))
			{
				frac.tmp = frac.z_r;
				frac.z_r = (frac.z_r * frac.z_r) -
				(frac.z_i * frac.z_i) + frac.c_r;
				frac.z_i = (2 * frac.tmp * frac.z_i) + frac.c_i;
				frac.i++;
			}
			ft_choose_color(all, frac.i);
			ft_put_pixel(&all->img, pt);
		}
	}
}
