#ifndef MY_H_
# define MY_H_

#include <unistd.h>
#include <stdlib.h>

int	my_strlen(char *str);
void	my_putstr(char *str);
void	my_putchar(char c);
char	*my_strdup(char *str);
char	*get_next_line(int fd);

#endif /* !MY_H_ */
