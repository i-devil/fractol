/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 23:15:40 by ide-vill          #+#    #+#             */
/*   Updated: 2015/03/05 16:49:47 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_init_julia(t_pt2d *pt, t_frac *frac)
{
	pt->x = 0;
	frac->a = -1.4;
	frac->b = -1.2;
}

void		ft_draw_julia(t_all *all)
{
	t_pt2d	pt;
	t_frac	frac;

	ft_init_julia(&pt, &frac);
	while (pt.x++ < WIN_WIDTH)
	{
		pt.y = 0;
		while (pt.y++ < WIN_HEIGHT)
		{
			frac.i = 0;
			frac.z_r = ((pt.x + all->off.x) / all->scale) + frac.a;
			frac.z_i = ((pt.y + all->off.y) / all->scale) + frac.b;
			while ((frac.i < all->max_ite) && ((frac.z_r * frac.z_r) +
						(frac.z_i * frac.z_i) < all->limit))
			{
				frac.tmp = frac.z_r;
				frac.z_r = (frac.z_r * frac.z_r) - (frac.z_i * frac.z_i)
					+ all->c_r;
				frac.z_i = (2 * frac.tmp * frac.z_i) + all->c_i;
				frac.i++;
			}
			ft_choose_color(all, frac.i);
			ft_put_pixel(&all->img, pt);
		}
	}
}
