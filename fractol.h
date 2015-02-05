/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 11:52:21 by ide-vill          #+#    #+#             */
/*   Updated: 2015/02/04 11:57:28 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"
# include <X11/Xlib.h>

# define WIN_HEIGHT 1024
# define WIN_WIDTH 1024

typedef struct		s_env
{
	void			*mlx;
	void			*win;
}					t_env;

typedef struct		s_pt2d
{
	int				x;
	int				y;
}					t_pt2d;

typedef struct		s_img
{
	int				bpp;
	int				size_line;
	void			*img;
	int				endian;
	char			*data;

	int				lx;
	int				ly;
	int				type;
	int				format;
	int				color;

	int				posimgx;
	int				posimgy;

	float			adj;
	int				re;
}					t_img;

typedef struct		s_frac
{
	float 			z_r;
	float 			z_i;
	float 			c_r;
	float 			c_i;
	float 			a;
	float 			b;
}					t_frac;

typedef struct		s_off
{
	int 			x;
	int 			y;
}					t_off;

typedef struct		s_all
{
	t_env			e;
	t_img			img;
	t_pt2d			*pt;
	t_frac 			frac;
	float			scale;
	int 			limit;
	int 			max_ite;
	int				re;
	int 			frac_nb;
	float 			c_r;
	float 			c_i;
	t_off			off;
	int 			fix;
}					t_all;

typedef unsigned char	t_byte;

typedef struct 		s_color
{
	t_byte r;
	t_byte g;
	t_byte b;
}					t_color;

void				ft_init(t_all *all);
void				ft_choose(int ac, char **av, t_all *all);

void				ft_put_pixel(t_img *img, t_pt2d p);

t_color				ft_rgb_to_color(unsigned char r, unsigned char g, unsigned char b);
int					ft_color_to_int(t_color color);
void		ft_choose_color(t_all *all, int i);

void				ft_draw_mandelbrot(t_all *all);
void				ft_draw_julia(t_all *all);
void				ft_draw_douady(t_all *all);

int					loop_hook(t_all *all);
int					expose_hook(t_all *all);
int					key_hook(int keycode, t_all *all);
int			mouse_move(int x, int y, t_all *all);
int			mouse_hook(int button, int x, int y, t_all *all);


#endif
