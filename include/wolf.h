#ifndef WOLF_H_
# define WOLF_H_

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include "/usr/include/X11/X.h"
#include "mlx.h"
#include "my.h"

#define WIDTH 1000
#define HEIGHT 1000
#define WMAP 100
#define HMAP 100
#define ECHAP 65307
#define RIGHT 65363
#define LEFT  65361
#define UP 65362
#define DOWN 65364
#define Q 113
#define D 100
#define Z 122
#define S 115
#define SPACE 32
#define WEST 0x002E1C0B
#define EAST 0x0063100F
#define NORTH 0x00F9A41E
#define SOUTH 0x00D2732F
#define SKY 0x00F6E8B1
#define FLOOR 0x0089725B
#define COS e->calc.cosi
#define SIN e->calc.sinu
#define POSX e->calc.posx
#define POSY e->calc.posy
#define ANGLE e->calc.angle
#define ABS(x) ((x < 0) ? -(x) : (x))

typedef struct s_list
{
  char	*data;
  struct s_list *next;
} t_list;

typedef struct	s_calc
{
  double	*cosi;
  double	*sinu;
  int		posx;
  int		posy;
  int		screen;
  int		angle;
} t_calc;

typedef struct s_env
{
  void		*mlx;
  void		*win;
  void		*img;
  void		*img2;
  void		*img3;
  char		*data;
  char		*data2;
  int		bpp;
  int		bpp2;
  int		sizeline;
  int		sizeline2;
  int		endian;
  int		endian2;
  int		tmp;
  char		**map;
  t_calc	calc;
}		t_env;

char	**list_to_tab(t_list *);
void	free_list(t_list *);
char	**get_map(int);
void	show_tab(char **);
void	free_tab(char **);
int	init_param(t_env *);
int	clear_img(t_env *);
int	sky_ground(t_env *);
int	gere_key(int,t_env *);
void	draw_wall(double, int, t_env *, int);
int	check_side(int, int, double, double);
int	find_wall(t_env *, double ,double, int);
int	calc_coor(t_env *);
int	fill_angle(t_env *);
int	gere_expose(t_env *);
int	do_wolf(t_env *);
t_list	*put_in_list(t_list *, char *);
void	my_show_list(t_list *);
int	my_list_size(t_list *);
int	draw_line(t_env *, int, int);
int	draw_cas2(t_env *, int, int);
int	draw_cas1(t_env *, int , int);
int	move_ud(t_env *, char);
int	move_rl(t_env *, char);
int	map_size(char **, char);
int	draw_map(t_env *, int, int, int);
int	mini_map(t_env *);
int	mlx_put_img(t_env *, int, int, int);
int	mlx_put_img2(t_env *, int, int, int);
int	rotate_rl(t_env *, char);
int	check_map(char **);
int	init_pos(t_env *);
int	check_error(t_env *);

#endif /* !WOLF_H_ */
