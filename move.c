#include "wolf.h"

int		move_ud(t_env *e, char which)
{
  double	tmp;
  double	tmp2;

  if (which == 'u')
    {
      tmp = POSX + (COS[ANGLE] * 10);
      tmp2 = POSY + (SIN[ANGLE] * 10);
    }
  else
    {
      tmp = POSX - (COS[ANGLE] * 10);
      tmp2 = POSY - (SIN[ANGLE] * 10);
    }
  if (e->map[(int)tmp2/100][(int)tmp/100] == '1')
    return (0);
  POSX = tmp;
  POSY = tmp2;
  sky_ground(e);
  mini_map(e);
  calc_coor(e);
  mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
  mlx_put_image_to_window(e->mlx, e->win, e->img2, 0, HEIGHT - HMAP);
  mlx_put_image_to_window(e->mlx, e->win, e->img3, WIDTH / 2, HEIGHT - 304);
  return (0);
}

int		move_rl(t_env *e, char which)
{
  double	tmp;
  double	tmp2;
  int		tmp3;

  tmp3 = ANGLE + 90;
  if (tmp3 > 360)
    tmp3 = tmp3 - 360;
  tmp = POSX - (COS[tmp3] * 10);
  tmp2 = POSY - (SIN[tmp3] * 10);
  if (which == 'r')
    {
      tmp = POSX + (COS[tmp3] * 10);
      tmp2 = POSY + (SIN[tmp3] * 10);
    }
  if (e->map[(int)tmp2/100][(int)tmp/100] == '1')
    return (0);
  POSX = tmp;
  POSY = tmp2;
  sky_ground(e);
  mini_map(e);
  calc_coor(e);
  mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
  mlx_put_image_to_window(e->mlx, e->win, e->img2, 0, HEIGHT - HMAP);
  mlx_put_image_to_window(e->mlx, e->win, e->img3, WIDTH / 2, HEIGHT - 302);
  return (0);
}

int	rotate_rl(t_env *e, char which)
{
  if (which == 'r')
    {
      if (ANGLE == 360)
	ANGLE = 0;
      ANGLE += 4;
    }
  else
    {
      if (ANGLE == 0)
	ANGLE = 360;
      ANGLE -= 4;
    }
  sky_ground(e);
  mini_map(e);
  calc_coor(e);
  mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
  mlx_put_image_to_window(e->mlx, e->win, e->img2, 0, HEIGHT - HMAP);
  mlx_put_image_to_window(e->mlx, e->win, e->img3, WIDTH / 2, HEIGHT - 303);
  return (0);
}
