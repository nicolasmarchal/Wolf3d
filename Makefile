
CC		= gcc

MINILIBX	= -L./minilibx/ -lmlx_$(HOSTTYPE) -L/usr/lib64/X11 -lXext -lX11

MATHLIB		= -lm

MYLIB		= -L./my -lmy

NAME		= wolf3d

OBJ		= $(SRC:.c=.o)

RM		= rm -f

CFLAGS		= -Wall -Werror -Wextra -g3 -Iinclude -Iminilibx -Imy

SRC		= main.c	\
		put_list.c	\
		do_wolf.c	\
		put_img.c	\
		draw_line.c	\
		do_minimap.c	\
		move.c		\
		put_tab.c	\
		draw_wolf.c	\
		check_map.c

all: $(NAME)

$(NAME): $(OBJ) lib
	 $(CC) $(OBJ) -o $(NAME) $(MINILIBX) $(MATHLIB) $(MYLIB)

clean:
	make clean -C ./minilibx/
	make clean -C ./my
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

lib:
	make -C ./minilibx/
	make -C ./my

.PHONY:	all clean fclean re lib
