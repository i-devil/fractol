#include "fractol.h"

t_color		ft_rgb_to_color(unsigned char r, unsigned char g, unsigned char b)
{
	t_color		color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

int			ft_color_to_int(t_color color)
{
	int		c;
	c = color.r;
	c = c << 8;
	c += color.g;
	c = c << 8;
	c += color.b;
	return (c);
}

void		ft_put_color(double pos, t_all *all)
{
}
