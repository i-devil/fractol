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

	k = 5;
	if (i % k == 0)
	{
		// c.r = 50;
		// c.g = 69;
		// c.b = 12;
		c.r = 00;
		c.g = 00;
		c.b = 00;
		all->img.color = ft_color_to_int(c);
	}
	else if (i % k == 1)
	{
		c.r = 63;
		c.g = 11;
		c.b = 27;
		all->img.color = ft_color_to_int(c);
	}
	else if (i % k == 2)
	{
		c.r = 122;
		c.g = 22;
		c.b = 49;
		all->img.color = ft_color_to_int(c);
	}
	else if (i % k == 3)
	{
		c.r = 207;
		c.g = 66;
		c.b = 60;
		all->img.color = ft_color_to_int(c);
	}
	else if (i % k == 4)
	{
		c.r = 252;
		c.g = 125;
		c.b = 73;
		all->img.color = ft_color_to_int(c);
	}
}

/*void		ft_choose_color(t_all *all, int i)
{
	t_color	c;
	int 	k;

	k = 4;
	if (i % k == 0)
	{
		c.r = 50;
		c.g = 69;
		c.b = 12;c.r = 50;
		c.g = 69;
		c.b = 12;
		all->img.color = ft_color_to_int(c);
	}
	else if (i % k == 1)
	{
		c.r = 113;
		c.g = 116;
		c.b = 0;
		all->img.color = ft_color_to_int(c);
	}
	else if (i % k == 2)
	{
		c.r = 220;
		c.g = 133;
		c.b = 5;
		all->img.color = ft_color_to_int(c);
	}
	else if (i % k == 3)
	{
		c.r = 236;
		c.g = 85;
		c.b = 25;
		all->img.color = ft_color_to_int(c);
	}
}*/
