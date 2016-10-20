NAME	= libmy.a

OBJ	= $(SRC:.c=.o)

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror -O3

SRC	= my_putchar.c	\
	my_putstr.c	\
	my_strdup.c	\
	my_strlen.c	\
	get_next_line.c

LINK	= ar rc

all:	$(NAME)

$(NAME): $(OBJ)
	$(LINK) $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
