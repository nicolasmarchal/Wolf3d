#include "wolf.h"

t_list		*put_in_list(t_list *list, char *str)
{
  t_list	*new_elem;
  t_list	*tmp;

  tmp = list;
  if ((new_elem = malloc(sizeof(*new_elem))) == NULL)
    return (NULL);
  new_elem->data = str;
  new_elem->next = NULL;
  if (list == NULL)
    return (new_elem);
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new_elem;
  return (list);
}

void	my_show_list(t_list *list)
{
  if (list != NULL)
    {
      my_putstr(list->data);
      my_putchar('\n');
      my_show_list(list->next);
    }
}

int	my_list_size(t_list *list)
{
  int	nb_line;

  nb_line = 0;
  while (list != NULL)
    {
      list = list->next;
      nb_line = nb_line + 1;
    }
  return (nb_line);
}

void	free_list(t_list *list)
{
  if (list != NULL)
    {
      free(list->next);
      free(list);
    }
}
