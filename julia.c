
#include "fractol.h"

void		ft_draw_julia(t_all *all)
{
	t_pt2d	pt;
	int		i;
	float	c_r;
	float	c_i;
	float	z_r;
	float	z_i;

	pt.x = 0;
	c_r = -0.7927;
	c_i = 0.1609;

	while (pt.x < WIN_WIDTH)
	{
		pt.y = 0;
		while (pt.y < WIN_HEIGHT)
		{
			i = 0;
			z_r = (pt.x * all->scale) + c_r;
			z_i = (pt.y * all->scale) + c_i;
			while ((i < all->max_ite) && ((z_r * z_r) + (z_i * z_i) < all->limit))
			{
				tmp = z_r;
				z_r = (z_r * z_r) - (z_i * z_i) + c_r;
				z_i = (2 * tmp * z_i) + c_i;
				i++;
			}
			if (i == all->max_ite)
				ft_put_pixel(&all->img, pt);
			pt.y++;
		}
		pt.x++;
	}

}
