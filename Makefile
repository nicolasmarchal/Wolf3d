CC		= gcc

MINILIBX	= -L./minilibx/ -lmlx_$(HOSTTYPE) -L/usr/lib64/X11 -lXext -lX11

MATHLIB		= -lm

MYLIB		= -L./my -lmy

NAME		= wolf3d

OBJ		= $(SRC:.c=.o)

RM		= rm -f

CFLAGS		= -Wall -Werror -Wextra -g3 -Iinclude -Iminilibx -Imy

PATHSRC		= ./srcs/

SRC		= $(PATHSRC)main.c	\
		$(PATHSRC)put_list.c	\
		$(PATHSRC)do_wolf.c	\
		$(PATHSRC)put_img.c	\
		$(PATHSRC)draw_line.c	\
		$(PATHSRC)do_minimap.c	\
		$(PATHSRC)move.c	\
		$(PATHSRC)put_tab.c	\
		$(PATHSRC)draw_wolf.c	\
		$(PATHSRC)check_map.c

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
