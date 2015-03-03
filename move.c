/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 23:19:49 by ide-vill          #+#    #+#             */
/*   Updated: 2015/03/03 23:20:15 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		move_up(t_all *all)
{
	all->off.y -= 5;
	all->img.re = 1;
}

void		move_down(t_all *all)
{
	all->off.y += 5;
	all->img.re = 1;
}

void		move_right(t_all *all)
{
	all->off.x += 5;
	all->img.re = 1;
}

void		move_left(t_all *all)
{
	all->off.x -= 5;
	all->img.re = 1;
}
