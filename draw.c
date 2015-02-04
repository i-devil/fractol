#include "fractol.h"

void		ft_put_pixel(t_img *img, t_pt2d p)
{
	if ((p.x >= 0 && p.x <= WIN_WIDTH) && (p.y >= 0 && p.y <= WIN_HEIGHT))
		ft_memcpy(&img->data[p.x * 4 + p.y * img->size_line],
			&img->color, (size_t)(sizeof(int)));
}
