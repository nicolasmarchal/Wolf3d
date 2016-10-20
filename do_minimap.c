#include "wolf.h"

int	map_size(char **map, char c)
{
  int	i;

  i = -1;
  if (c == 'h')
    while (map[++i]);
  else
    while (map[0][++i]);
  return (i);
}

int	draw_map(t_env *e, int map_x, int map_y, int color)
{
  int	y;
  int	x;
  int	tmp;

  y = -1;
  map_y = map_y * (WMAP / map_size(e->map, 'h'));
  tmp = map_x;
  while (++y < HMAP / map_size(e->map, 'h'))
    {
      x = -1;
      tmp = map_x * (WMAP / map_size(e->map, 'w'));
      while (++x < WMAP / map_size(e->map, 'w'))
	{
	  mlx_put_img2(e, tmp, map_y, color);
	  tmp++;
	}
      map_y++;
    }
  return (0);
}

int	mini_map(t_env *e)
{
  int	i;
  int	j;

  i = -1;
  while (e->map[++i])
    {
      j = -1;
      while (e->map[i][++j])
	{
	  if (e->map[i][j] == '1')
	    draw_map(e, j, i, 0x00A7A37E);
	  else
	    draw_map(e, j, i , 0x00F6E8B1);
	}
    }
  return (0);
}
