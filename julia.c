
#include "fractol.h"

void		ft_draw_julia(t_all *all)
{
	t_pt2d	pt;
	t_frac 	frac;
	int		i;
	float	tmp;

	pt.x = 0;
	frac.a = -1.4;
	frac.b = -1.2;
	while (pt.x < WIN_WIDTH)
	{
		pt.y = 0;
		while (pt.y < WIN_HEIGHT)
		{
			i = 0;
			frac.z_r = ((pt.x + all->off.x) / all->scale) + frac.a;
			frac.z_i = ((pt.y + all->off.y) / all->scale) + frac.b;
			while ((i < all->max_ite) && ((frac.z_r * frac.z_r) + (frac.z_i * frac.z_i) < all->limit))
			{
				tmp = frac.z_r;
				frac.z_r = (frac.z_r * frac.z_r) - (frac.z_i * frac.z_i) + all->c_r;
				frac.z_i = (2 * tmp * frac.z_i) + all->c_i;
				i++;
			}
			ft_choose_color(all, i);
			ft_put_pixel(&all->img, pt);
			pt.y++;
		}
		pt.x++;
	}
}



/*void		ft_draw_julia3(t_all *all)
{
	t_pt2d	pt;
	int		i;
	float	c_r;
	float	c_i;
	float	z_r;
	float	z_i;
	float		tmp;
	float		a;
	float		b;

	pt.x = 0;
	a = -1.4;
	b = -1.2;
	c_r = 0.32;
	c_i = 0.043;

	while (pt.x < WIN_WIDTH)
	{
		pt.y = 0;
		while (pt.y < WIN_HEIGHT)
		{
			i = 0;
			z_r = (pt.x / all->scale) + a;
			z_i = (pt.y / all->scale) + b;
			while ((i < all->max_ite) && ((z_r * z_r) + (z_i * z_i) < all->limit))
			{
				tmp = z_r;
				z_r = (z_r * z_r) - (z_i * z_i) + c_r;
				z_i = (2 * tmp * z_i) + c_i;
				i++;
			}
			//if (i == all->max_ite)
			//{
				ft_choose_color(all, i);
				ft_put_pixel(&all->img, pt);
			//}
			pt.y++;
		}
		pt.x++;
	}
}

void		ft_draw_julia4(t_all *all)
{
	t_pt2d	pt;
	int		i;
	float	c_r;
	float	c_i;
	float	z_r;
	float	z_i;
	float		tmp;
	float		a;
	float		b;

	pt.x = 0;
	a = -1.4;
	b = -1.2;
	c_r = -0.3380;
	c_i = -0.6230;

	while (pt.x < WIN_WIDTH)
	{
		pt.y = 0;
		while (pt.y < WIN_HEIGHT)
		{
			i = 0;
			z_r = (pt.x / all->scale) + a;
			z_i = (pt.y / all->scale) + b;
			while ((i < all->max_ite) && ((z_r * z_r) + (z_i * z_i) < all->limit))
			{
				tmp = z_r;
				z_r = (z_r * z_r) - (z_i * z_i) + c_r;
				z_i = (2 * tmp * z_i) + c_i;
				i++;
			}
			//if (i == all->max_ite)
			//{
				ft_choose_color(all, i);
				ft_put_pixel(&all->img, pt);
			//}
			pt.y++;
		}
		pt.x++;
	}
}*/
