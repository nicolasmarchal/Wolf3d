#include "wolf.h"

int	mlx_put_img(t_env *e, int x, int y, int color)
{
  int	pos;

  pos = (((e->bpp) / 8) * x) + (e->sizeline * y);
  e->data[pos] = color;
  e->data[pos + 1] = color >> 8;
  e->data[pos + 2] = color >> 16;
  return (0);
}

int	mlx_put_img2(t_env *e, int x, int y, int color)
{
  int	pos;

  pos = (((e->bpp2) / 8) * x) + (e->sizeline2 * y);
  e->data2[pos] = color;
  e->data2[pos + 1] = color >> 8;
  e->data2[pos + 2] = color >> 16;
  return (0);
}
