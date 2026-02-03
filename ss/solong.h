#ifndef SOLONG_H
# define SOLONG_H
# include "minilibx-linux/mlx.h"
# include <X11/Xlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct n_playerpos
{
	int		x;
	int		y;
}			t_playerpos;

typedef struct n_countcheck
{
	int		n_counte;
	int		n_countc;
}			t_countcheck;

typedef struct n_mapname
{
	char	*name;
}			t_mapname;

typedef struct t_game
{
	void	*mlx;
	void	*win;
	void	*wall;
	void	*road;
	void	*check;
	void	*pack;
	void	*door;
	char	**map;
	int		lines;
	int		linesize;
	int		j;
	int		i;
	int		countc;
	int		countoc;
	int		count_moves;
}			t_game;

int	check_all(char *mappath);
int check_all_lines(char **map, char *mappath);
int check_map(char **map, char *mappath);
void	check_valid_path_to_coin(char **tab, t_playerpos size,
			t_playerpos cur, t_countcheck *p);
void	check_valid_path_to_exit(char **tab, t_playerpos size,
			t_playerpos cur, t_countcheck *p);
int check_pande(char **map, char *mappath);
int count_c(char **map, char *mappath);
int check_valid_chars(char **map, char *mappath);
int checkc(char **map, char *mappath);
void freemen(char **map, char *mappath);
void free2(char *str2, char *str1);
void free_close(char *str, int fd);
# endif