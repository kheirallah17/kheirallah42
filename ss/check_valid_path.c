#include "solong.h"

int	check_valid_char_exit(char **map, int i, int j)
{
	if (map[j][i] == 'P' || map[j][i] == '0' || map[j][i] == 'C'
		|| map[j][i] == 'E')
		return (1);
	return (0);
}

void	check_valid_path_to_exit(char **tab, t_playerpos size,
			t_playerpos cur, t_countcheck *p)
{
	if (!check_valid_char_exit(tab, cur.x, cur.y))
		return ;
	if (tab[cur.y][cur.x] == 'E')
		p->n_counte++;
	tab[cur.y][cur.x] = 'F';
	check_valid_path_to_exit(tab, size, (t_playerpos){cur.x - 1, cur.y}, p);
	check_valid_path_to_exit(tab, size, (t_playerpos){cur.x + 1, cur.y}, p);
	check_valid_path_to_exit(tab, size, (t_playerpos){cur.x, cur.y - 1}, p);
	check_valid_path_to_exit(tab, size, (t_playerpos){cur.x, cur.y + 1}, p);
}

int	check_valid_char_coin(char **map, int i, int j)
{
	if (map[j][i] == 'P' || map[j][i] == '0' || map[j][i] == 'C')
		return (1);
	return (0);
}

void	check_valid_path_to_coin(char **tab, t_playerpos size,
			t_playerpos cur, t_countcheck *p)
{
	if (!check_valid_char_coin(tab, cur.x, cur.y))
		return ;
	if (tab[cur.y][cur.x] == 'C')
		p->n_countc++;
	tab[cur.y][cur.x] = 'F';
	check_valid_path_to_coin(tab, size, (t_playerpos){cur.x - 1, cur.y}, p);
	check_valid_path_to_coin(tab, size, (t_playerpos){cur.x + 1, cur.y}, p);
	check_valid_path_to_coin(tab, size, (t_playerpos){cur.x, cur.y - 1}, p);
	check_valid_path_to_coin(tab, size, (t_playerpos){cur.x, cur.y + 1}, p);
}

int check_pande(char **map, char *mappath)
{
	int counte;
	int countp;
	int i;
	int j;

	counte = 0;
	countp = 0;
	i = 0;
	j = 0;
	while (i < countmaplines(mappath))
	{
		j = 0;
		while (j < getlinesize(mappath))
		{
			if (map[i][j] == 'E')
				counte++;
			if (map[i][j] == 'P')
				countp++;
			j++;
		}
		i++;
	}
	if (counte > 1 || countp > 1 || counte == 0 || countp == 0)
		return (0);
	return (1);
}