#include "wolf.h"

int	clear_img(t_env *e)
{
  int	i;

  i = 0;
  while (i < 1000 * 1000 * 4)
    {
      e->data[i] = 0;
      i = i + 1;
    }
  mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
  return (0);
}

int	gere_key(int keycode, t_env *e)
{
  if (keycode == ECHAP)
    {
      mlx_destroy_window(e->mlx, e->win);
      exit(1);
    }
  if (keycode == Z)
    move_ud(e, 'u');
  if (keycode == S)
    move_ud(e, 'd');
  if (keycode == Q)
    move_rl(e, 'l');
  if (keycode == D)
    move_rl(e, 'r');
  if (keycode == RIGHT)
    rotate_rl(e, 'r');
  if (keycode == LEFT)
    rotate_rl(e, 'l');
  return (0);
}

int	fill_angle(t_env *e)
{
  int	i;

  if ((COS = malloc(sizeof(double) * 370)) == NULL)
    return (0);
  if ((SIN = malloc(sizeof(double) * 370)) == NULL)
    return (0);
  i = -1;
  while (++i <= 360)
    COS[i] = cos((i * M_PI) / 180);
  while (--i >= 0)
    SIN[i] = sin((i * M_PI) / 180);
  return (0);
}

int	gere_expose(t_env *e)
{
  mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
  mlx_put_image_to_window(e->mlx, e->win, e->img2, 0, HEIGHT - HMAP);
  mlx_put_image_to_window(e->mlx, e->win, e->img3, WIDTH / 2, HEIGHT - 302);
  return (0);
}

int	do_wolf(t_env *e)
{
  mini_map(e);
  sky_ground(e);
  calc_coor(e);
  if ((mlx_hook(e->win, KeyPress, KeyRelease, gere_key, e)) == 0)
    return (0);
  if ((mlx_expose_hook(e->win, gere_expose, e)) == 0)
    return (0);
  if ((mlx_loop(e->mlx)) == 0)
    return (0);
  return (0);
}
