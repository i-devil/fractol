
#include "fractol.h"

void			ft_draw_mandelbrot(){
	float		cx = 0;
	float		cy = 0;
	int			limit = 4;
	int			i;
	float		scale = 0.02;
	float		a1;
	float		b1;
	float		a2;
	float		b2;
	int			x;
	int			y;
	float		ax;
	float		ay;
	t_pt2d	pos;

	pos = (t_pt2d *)(malloc(sizeof(t_pt2d)));
	pos->x = 0;



	while (x <= WIN_WIDTH)
	{
		pos->y = 0;
		while (y <= WIN_HEIGHT)
		{
			ax = cx + (x * scale);
			ay = cy + (y * scale);
			a1 = ax;
			b1 = ay;
			i = 0;
			while ((i < all->max_ite) && ((a1 * a1) + (b1 * b1) < limit))
			{
				i++;
				a2 = (a1 * a1) - (b1 * b1) + ax;
				b2 = (2 * a1 * b1) + ay;
				a1 = a2;
				b1 = b2;
			}
			color
		}
	}


}




/*void		frac_mandelbrot(t_all *all)
{
	t_pos	*pt;
	float	x1;
	float	y1;
	float	c_r;
	float	c_i;
	float	z_r;
	float	z_i;
	float	tmp;
	int		i;


	pt = (t_pos *)malloc(sizeof(t_pos));
	pt->x = 0;
	x1 = -2.1;
	y1 = -1.2;
	while (pt->x < WIN_SZ_X)
	{
		pt->y = 0;
		while (pt->y < WIN_SZ_Y)
		{
			c_r = (float)((pt->x + all->off.x) / all->zoom) + x1;
			c_i = (float)((pt->y + all->off.y) / all->zoom) + y1;
			z_r = 0;
			z_i = 0;
			i = 0;
			while((z_r * z_r + z_i * z_i) < 4 && i < all->ite_max)
			{
				tmp = z_r;
				z_r = (z_r * z_r) - (z_i * z_i) + c_r;
				z_i = (2 * tmp * z_i) + c_i;
				i++;
			}
			rainbow_color((double)i / (double)all->ite_max, all);
			ft_put_pxl(all, pt);
			pt->y++;
		}
		pt->x++;
	}
	free(pt);
}*/
