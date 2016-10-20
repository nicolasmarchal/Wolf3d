#include "wolf.h"

char		**get_map(int fd)
{
  char		*s;
  t_list	*list;
  char		**map;

  list = NULL;
  while ((s = get_next_line(fd)) != 0)
    {
      list = put_in_list(list, my_strdup(s));
      free(s);
    }
  map = list_to_tab(list);
  free_list(list);
  return (map);
}

int	init_param(t_env *e)
{
  int	x;
  int	y;

  ANGLE = 0;
  x = 335;
  y = 302;
  e->calc.screen = HEIGHT / 2;
  if ((e->mlx = mlx_init()) == 0)
    return (1);
  if ((e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "Wolf3d")) == 0)
    return (1);
  if ((e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT)) == 0)
    return (1);
  if ((e->img2 = mlx_new_image(e->mlx, WMAP, HMAP)) == 0)
    return (1);
  if ((e->data = mlx_get_data_addr(e->img, &e->bpp,
				   &e->sizeline, &e->endian)) ==  0)
    return (1);
  if ((e->data2 = mlx_get_data_addr(e->img2, &e->bpp2,
				    &e->sizeline2, &e->endian2)) == 0)
    return (1);
  if ((e->img3 = mlx_xpm_file_to_image(e->mlx, "./ressources/a1.xpm", &x, &y)) == 0)
    return (1);
  return (0);
}

int		main(int ac, char **av)
{
  int		fd;
  t_env		e;

  if (ac < 2)
    {
      my_putstr("usage: ./wolf3d map\n");
      return (0);
    }
  if ((fd = open(av[1], O_RDONLY)) == -1)
    {
      my_putstr("bad file\n");
      return (1);
    }
  e.map = get_map(fd);
  close(fd);
  if ((check_error(&e)) == 1)
    return (1);
  fill_angle(&e);
  do_wolf(&e);
  free_tab(e.map);
  free(e.calc.cosi);
  free(e.calc.sinu);
  return (0);
}
