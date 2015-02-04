


#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <X11/Xlib.h>
# include <stdlib.h>
# include <math.h>
# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"

# define WIN_HEIGHT 2560
# define WIN_WIDTH 1440

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
	int				alt;
	int				posimgx;
	int				posimgy;
	float			adj;
	int				re;
}					t_img;

typedef struct		s_all
{
	t_env			e;
	t_img			img;
	t_pt2d		pos;
	float			scale;
	int 			limit;
	int 			max_ite;

}					t_all;

typedef unsigned char	t_byte;

typedef struct 		s_color
{
	t_byte r;
	t_byte g;
	t_byte b;
}									t_color;


void						ft_error(int argc, char *argv);
void						ft_init(t_all *all);

void						ft_put_pixel(t_img *img, t_pt2d p);

t_color		ft_rgb_to_color(unsigned char r, unsigned char g, unsigned char b);
int			ft_color_to_int(t_color color);
void		ft_put_color(double pos, t_all *all);



int							loop_hook(t_all *all);
int							expose_hook(t_all *all);



#endif
