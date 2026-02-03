#include "solong.h"

int errorcheck(char **map, char *mappath)
{
	if(!check_map(map, mappath))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	else if (!check_pande(map, mappath))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if(!checkc(map, mappath))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

int error(char **map, char *mappath)
{
	if (!check_valid_chars(map, mappath))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	else if (!check_all_lines(map, mappath))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);

}

int	check_all(char *mappath)
{
	char	**map;
	int		result;

	map = array2d(mappath);
	if (!map)
		return (0);
	if (error(map, mappath) == 0)
		result = 0;
	else if (errorcheck(map, mappath) == 0)
		result = 0;
	else if (errorcheck(map, mappath) == 0)
		result = 0;
	else
		result = 1;
	freemem(map, mappath);
	return (result);
}

void error_check_help(char **map1, char **map2, char *mappath)
{
	write(2, "Error\nMap is not rectangular\n", 28);
	freemen(map1, mappath);
	freemen(map2, mappath);
	exit(1);
}

int error_chck(char **map, char *mappath)
{
	t_playerpos			start;
	t_countcheck		c;
	int					j;
	char				**map1;

	map1 = array2d(mappath);
	if (!map1)
		return (0);
	j = count_c(map, mappath);
	c.n_counte = 0;
	c.n_countc = 0;
	start = find_playerpos(map, mappath);
	check_valid_path_to_coin(map, (t_playerpos){getlinesize(mappath),
		countlines(mappath)}, start, &c);
	check_valid_path_to_exit(map1, (t_playerpos){getlinesize(mappath),
		countlines(mappath)}, start, &c);
	if (j != c.n_countc)
		error_check_help(map1, map, mappath);
	else if (c.n_counte != 1)
		error_check_help(map1, map, mappath);
	freemem(map1, mappath);
	return (1);
}