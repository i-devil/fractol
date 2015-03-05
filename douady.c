/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   douady.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 23:21:19 by ide-vill          #+#    #+#             */
/*   Updated: 2015/03/05 16:43:39 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_init_douady(t_pt2d *pt, t_frac *frac)
{
	pt->x = 0;
	frac->a = -1.4;
	frac->b = -1.2;
	frac->c_r = -0.123;
	frac->c_i = 0.745;
}

void		ft_douady_sub(t_all *all, t_frac *frac, t_pt2d *pt)
{
	frac->z_r = ((pt->x + all->off.x) / all->scale) + frac->a;
	frac->z_i = ((pt->y + all->off.y) / all->scale) + frac->b;
}

void		ft_draw_douady(t_all *all)
{
	t_pt2d	pt;
	t_frac	frac;

	ft_init_douady(&pt, &frac);
	while (pt.x++ < WIN_WIDTH)
	{
		pt.y = 0;
		while (pt.y++ < WIN_HEIGHT)
		{
			frac.i = 0;
			ft_douady_sub(all, &frac, &pt);
			while ((frac.i < all->max_ite) && ((frac.z_r * frac.z_r) +
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
