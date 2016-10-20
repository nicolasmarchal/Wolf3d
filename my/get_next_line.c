/*
** main.c for get in /home/nicolasmarchal/rendu/getnextline/test1/CPE_2014_get_next_line
** 
** Made by nicolas marchal
** Login   <marcha_0@epitech.net>
** 
** Started on  Fri Nov 21 18:57:41 2014 nicolas marchal
** Last update Sun Dec 21 13:47:04 2014 nicolas marchal
*/

#include "my.h"
#include "get_next_line.h"

void	buf_init(char *str, int	taille)
{
  int	i;

  i = -1;
  while (++i < taille)
    str[i] = 0;
}

char	*my_realloc(char *str, int taille)
{
  char	*new_str;
  int	i;
  int	len;

  len = 0;
  while (str[len++]);
  i = -1;
  if ((new_str = malloc(sizeof(char) * (len + taille + 1))) == NULL)
    return (NULL);
  buf_init(new_str, (len + taille + 1));
  while (str[++i])
    new_str[i] = str[i];
  free(str);
  return (new_str);
}

int	still_tmp(char *tmp, char *buf, int i, int ret)
{
  int	j;

  j = -1;
  if (buf[i] == '\n' || ret < SIZE)
    {
      while (buf[i])
	tmp[++j] = buf[++i];
      return (1);
    }
  return (0);
}

char	*read_line(const int fd, char *str, char *tmp, int j)
{
  int	i;
  int	ret;
  char	buf[SIZE + 1];
  int	countread;

  countread = 0;
  buf_init(buf, SIZE + 1);
  while ((ret = read(fd, buf, SIZE)) > 0)
    {
      if ((str = my_realloc(str, ret)) == NULL)
	return (NULL);
      i = 0;
      while (buf[i] != '\n' && i < ret)
	str[j++] = buf[i++];
      if ((still_tmp(tmp, buf, i, ret)) == 1)
	return (str);
      buf_init(buf, SIZE + 1);
      countread = 1;
    }
  if (countread == 1 || j > 0)
    return (str);
  return (NULL);
}

char		*get_next_line(const int fd)
{
  static char	tmp[SIZE + 1];
  static int	i = 0;
  char		*str;
  int		j;

  j = 0;
  if ((str = malloc(sizeof(char) * SIZE + 1)) == NULL)
    return (NULL);
  buf_init(str, SIZE + 1);
  while (tmp[i] && tmp[i] != '\n')
    str[j++] = tmp[i++];
  if (tmp[i] != '\n')
    {
      i = 0;
      buf_init(tmp, SIZE + 1);
      if ((str = read_line(fd, str, tmp, j)) == NULL)
	return (NULL);
    }
  else
    i++;
  return (str);
}
