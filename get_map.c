#include "wolf.h"

t_list	*datainlist(void)
{
  char *s;
  t_list *list;

  list = NULL;
  while ((s = get_next_line(0)))
    {
      my_put_in_list(&list, my_strdup(s));
      free(s);
    }
  return (list);
}

int	still_tab(t_list *list, int **tab, int y)
{
  int	x;
  int	i;
  char	bool;

  x = -1;
  i = -1;
  if (list != NULL)
    {
      y = still_tab(list->next, tab, y);
      bool = '0';
      while (bool != '1' && list->data[++i])
	{
	  if (list->data[i] != ' ')
	    {
	      tab[y][++x] = my_getnbr(&list->data[i]);
	      while (list->data[++i] && list->data[i] != ' ');
	    }
	  if (!list->data[i])
	    bool = '1';
	}
      return (y + 1);
    }
  return (y);
}

int	**list_to_tab(t_list *list, int lenline, int nb_line)
{
  int	**tab;
  int	i;

  tab = malloc(sizeof(int *) * nb_line);
  i = -1;
  while (++i < nb_line)
    tab[i] = malloc(sizeof(int) * lenline);
  still_tab(list, tab, 0);
  return (tab);
}

int	main()
{
  t_map		map;
  t_list	*list;

  list = NULL;
  list = datainlist();
  map.lenline = len_line(list->data);
  map.nb_line = my_list_size(list);
  if ((check_line(list, map.lenline)) == -1)
    return (0);
  map.mapcor = list_to_tab(list, map.lenline, map.nb_line);
  free(list);
  do_fdf(&map);
  free (map.mapcor);
  return (0);
}
