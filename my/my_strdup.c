#include "my.h"

char	*my_strdup(char *str)
{
  int	i;
  char	*res;

  i = -1;
  if ((res = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (str[++i])
    res[i] = str[i];
  res[i] = 0;
  return (res);
}
