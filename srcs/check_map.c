#include "wolf.h"

int	check_len(char **map)
{
  int	i;
  int	len;
  int	j;

  i = -1;
  len = -1;
  while (map[0][++len]);
  if (len != 10)
    return (1);
  while (map[++i])
    {
      j = -1;
      while (map[i][++j]);
      if (j != len)
	return (1);
    }
  return (0);
}

int	check_map(char **map)
{
  int	i;
  int	j;

  i = -1;
  if ((check_len(map)) == 1)
    return (1);
  while (map[0][++i])
    {
      if (map[0][i] != '1')
	return (1);
    }
  i = -1;
  while (map[++i])
    {
      if (map[i][0] != '1' || map[i][my_strlen(map[i]) - 1] != '1')
	return (1);
    }
  j = -1;
  while (map[i - 1][++j])
    {
      if (map[i - 1][j] != '1')
	return (1);
    }
  return (0);
}

int	init_pos(t_env *e)
{
  int	i;
  int	j;

  i = -1;
  while (e->map[++i])
    {
      j = -1;
      while (e->map[i][++j])
	{
	  if (e->map[i][j] != '1')
	    {
	      POSX = (j * 100) + 50;
	      POSY = (i * 100) + 50;
	      return (0);
	    }
	}
    }
  return (1);
}

int	check_error(t_env *e)
{
  if ((check_map(e->map)) == 1 || (init_pos(e)) == 1)
    {
      my_putstr("bad map !\n");
      return (1);
    }
  if ((init_param(e)) == 1)
    {
      my_putstr("don't try to do something stupid :)\n");
      return (1);
    }
  return (0);
}
