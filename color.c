/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 11:51:51 by ide-vill          #+#    #+#             */
/*   Updated: 2015/02/04 11:51:56 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void		ft_choose_color(t_all *all, int i)
{
	t_color	c;
	int 	k;

	k = 4;
	if (i % k == 0)
	{
		c.r = 7;
		c.g = 127;
		c.b = 124;
		all->img.color = ft_color_to_int(c);
	}
	else if (i % k == 1)
	{
		c.r = 10;
		c.g = 127;
		c.b = 92;
		all->img.color = ft_color_to_int(c);
	}
	else if (i % k == 2)
	{
		c.r = 255;
		c.g = 197;
		c.b = 148;
		all->img.color = ft_color_to_int(c);
	}
	else if (i % k == 3)
	{
		c.r = 0;
		c.g = 215;
		c.b = 255;
		all->img.color = ft_color_to_int(c);
	}
}
