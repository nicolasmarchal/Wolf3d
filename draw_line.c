#include "./wolf.h"

int	draw_cas1(t_env *e, int x2, int y2)
{
  int	x;
  int	y;
  int	x1;
  int	y1;

  x1 = POSX / 10;
  y1 = POSY / 10;
  x = x1;
  while (x != x2)
    {
      y = y1 + ((y2 - y1) * (x - x1)) / (x2 - x1);
      mlx_put_img2(e, x, y, 0x00677E52);
      if (x1 < x2)
	x++;
      else
	x--;
    }
  return (0);
}

int	draw_cas2(t_env *e, int x2, int y2)
{
  int	y;
  int	x;
  int	x1;
  int	y1;

  x1 = POSX / 10;
  y1 = POSY / 10;
  y = y1;
  while (y != y2)
    {
      x = x1 + ((x2 - x1) *(y - y1)) / (y2 - y1);
      mlx_put_img2(e, x, y, 0x00677E52);
      if (y1 < y2)
	y++;
      else
	y--;
    }
  return (0);
}

int	draw_line(t_env *e, int x2, int y2)
{
  int	x;
  int	y;
  int	x1;
  int	y1;

  x1 = POSX / 10;
  y1 = POSY / 10;
  x = x2 - x1;
  y = y2 - y1;
  if (ABS(x) > ABS(y))
    draw_cas1(e, x2, y2);
  else
    draw_cas2(e, x2, y2);
  return (0);
}
