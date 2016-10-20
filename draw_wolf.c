#include "wolf.h"

int	sky_ground(t_env *e)
{
  int	i;
  int	color;

  i = 0;
  color = SKY;
  while (i < (1000 * 1000 * 4) / 2)
    {
      e->data[i] = color;
      e->data[i + 1] = color >> 8;
      e->data[i + 2] = color >> 16;
      i = i + 4;
    }
  color = FLOOR;
  while (i < (1000 * 1000 * 4))
    {
      e->data[i] = color;
      e->data[i + 1] = color >> 8;
      e->data[i + 2] = color >> 16;
      i = i + 4;
    }
  return (0);
}

void	draw_wall(double k, int x, t_env *e, int side)
{
  int	i;

  i = -1;
  e->tmp = e->calc.screen;
  while (++i <= HEIGHT / (2 * k))
    {
      if (e->tmp > 0 && e->tmp < 1000)
	{
	  (side == 1) ? mlx_put_img(e, x, e->tmp++, WEST) : 0;
	  (side == 2) ? mlx_put_img(e, x, e->tmp++, EAST) : 0;
	  (side == 3) ? mlx_put_img(e, x, e->tmp++, NORTH) : 0;
	  (side == 0) ? mlx_put_img(e, x, e->tmp++, SOUTH) : 0;
	}
    }
  e->tmp = e->calc.screen;
  while (--i >= 0)
    {
      if (e->tmp > 0 && e->tmp < 1000)
	{
	  (side == 1) ? mlx_put_img(e, x, e->tmp--, WEST) : 0;
	  (side == 2) ? mlx_put_img(e, x, e->tmp--, EAST) : 0;
	  (side == 3) ? mlx_put_img(e, x, e->tmp--, NORTH) : 0;
	  (side == 0) ? mlx_put_img(e, x, e->tmp--, SOUTH) : 0;
	}
    }
}

int		check_side(int	x, int y, double vx, double vy)
{
  static int	last = 0;

  if (x % 100 == 0 && y % 100 != 0)
    {
      if (vx > 0)
	{
	  last = 1;
	  return (1);
	}
      last = 2;
      return (2);
    }
  else if (x % 100 != 0 && y % 100 == 0)
    {
      if (vy > 0)
	{
	  last = 3;
	  return (3);
	}
      last = 0;
      return (0);
    }
  return (last);
}

int		find_wall(t_env *e, double vx, double vy, int x)
{
  double	k;
  double	x2;
  double	y2;
  int		hit;
  int		side;

  k = 0;
  hit = 0;
  while (hit != 1)
    {
      x2 = (k * vx) + (POSX);
      y2 = (k * vy) + (POSY);
      if (e->map[(int)(y2 / 100)][(int)(x2 / 100)] == '1')
	{
	  side = check_side((int)round(x2), (int)round(y2), vx, vy);
	  draw_wall(k, x, e, side);
	  hit = 1;
	}
      else
	k += 0.005;
    }
  draw_line(e, (int)x2/10, (int)y2/10);
  return (0);
}

int		calc_coor(t_env *e)
{
  double	x;
  double	y1;
  double	p;
  double	d;
  double	vx;
  double	vy;

  p = (WIDTH / 10);
  d = (WIDTH / 10) / 1.5;
  x = 0;
  while (x < WIDTH)
    {
      y1 = (p * ((WIDTH / 2) - x)) / WIDTH;
      vx = (d * COS[ANGLE]) - (y1 * -SIN[ANGLE]);
      vy = (d * SIN[ANGLE]) + (y1 * -COS[ANGLE]);
      find_wall(e, vx, vy, x);
      x++;
    }
  return (0);
}
