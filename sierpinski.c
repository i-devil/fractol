
#include "fractol.h"

void	draw_rect(int x, int y, int a, int b)
{

}

void	draw_tapis_sierpinski(t_all *all)
{
	t_pt2d	pt;
	pt.x = 0;
	pt.y = 0;
	a = 3;
	b = 3;

  if (all->ite_max >0)
    {
      /* on supprime le petit rectangle central */
      rectfill(bmp, (int) (x+a/3), (int) (y+b/3), (int) (x+2*a/3), (int)(y+2*b/3), 8);
      /* appels récursifs pour les huit rectangles restants */
      tapis_Sierpinski(pt.x, pt.y, a/3, b/3, all->ite_max - 1);
      tapis_Sierpinski(pt.x+a/3, pt.y, a/3, b/3, all->ite_max - 1);
      tapis_Sierpinski(pt.x+2*a/3, pt.y, a/3, b/3, all->ite_max - 1);
      tapis_Sierpinski(pt.x, pt.y+b/3, a/3, b/3, all->ite_max - 1);
      tapis_Sierpinski(pt.x+2*a/3, pt.y+b/3, a/3, b/3, all->ite_max - 1);
      tapis_Sierpinski(pt.x, pt.y+2*b/3, a/3, b/3, all->ite_max - 1);
      tapis_Sierpinski(pt.x+a/3, pt.y+2*b/3, a/3, b/3, all->ite_max - 1);
      tapis_Sierpinski(pt.x+2*a/3, pt.y+2*b/3, a/3, b/3, all->ite_max - 1);
    } else
      /* on dessine un rectangle plein */
      rectfill(bmp, (int) pt.x, (int) pt.y, (int) (pt.x+a), (int)(pt.y+b), 1);
}
