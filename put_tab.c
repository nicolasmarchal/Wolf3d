#include "wolf.h"

char	**list_to_tab(t_list *list)
{
  char	**tab;
  int	i;

  i = -1;
  if ((tab = malloc(sizeof(char *) * (my_list_size(list) + 3))) == 0)
    return (0);
  while (list != NULL)
    {
      tab[++i] = list->data;
      list = list->next;
    }
  tab[++i] = 0;
  return (tab);
}

void	show_tab(char **tab)
{
  int	i;

  i = -1;
  while (tab[++i])
    {
      my_putstr(tab[i]);
      my_putchar('\n');
    }
}

void	free_tab(char **tab)
{
  int	i;

  i = -1;
  while (tab[++i])
    free(tab[i]);
}
