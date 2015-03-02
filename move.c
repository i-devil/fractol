
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