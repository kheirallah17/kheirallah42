#include "solong.h"

void	fillpos_player(t_game *data, char *mappath)
{
	t_playerpos	p;
	char		**map;

	map = maptoarray(mappath);
	p = findpos(map, mappath);
	data->j = p.x;
	data->i = p.y;
	freemen(map, mappath);
}

t_game	*begin(t_game	*data)
{
	int		h;
	int		w;

	data->wall = mlx_xpm_file_to_image(data->mlx, " textures/wall.xpm",
			&w, &h);
	data->door = mlx_xpm_file_to_image(data->mlx, " textures/door.xpm",
			&w, &h);
	data->road = mlx_xpm_file_to_image(data->mlx,
			" textures/road.xpm", &w, &h);
	data->check = mlx_xpm_file_to_image(data->mlx, " textures/collectible.xpm",
			&w, &h);
	data->pack = mlx_xpm_file_to_image(data->mlx, " textures/pack.xpm",
			&w, &h);
	return (data);
}

t_game	*create_game(char *mappath)
{
	t_game	*data;
	char	**map;
	int		width;
	int		height;

	width = getlinesize(mappath);
	height = countmaplines(mappath);
	data = (t_game *)malloc(sizeof(t_game));
	data->mlx = mlx_init();
	if (!data->mlx)
		return (NULL);
	data->win = mlx_new_window(data->mlx, width * 30, height * 30,
			"so_long");
	if (!data->win)
		return (NULL);
	data = begin(data);
	map = maptoarray(mappath);
	data->map = map;
	return (data);
}

int	mapgo(t_game *dat)
{
	int	i;
	int	j;

	j = -1;
	while (++j < dat->lines)
	{
		i = -1;
		while (++i < dat->linesize)
		{
			if (dat->map[j][i] == '1')
				mlx_put_image_to_window(dat->mlx, dat->win,
					dat->wall, i * 30, j * 30);
			else if (dat->map[j][i] == 'C')
				mlx_put_image_to_window(dat->mlx, dat->win,
					dat->check, i * 30, j * 30);
			else if (dat->map[j][i] == 'E')
				mlx_put_image_to_window(dat->mlx, dat->win,
					dat->door, i * 30, j * 30);
			else
				mlx_put_image_to_window(dat->mlx, dat->win,
					dat->road, i * 30, j * 30);
		}
	}
	return (mlx_put_image_to_window(dat->mlx, dat->win,
			dat->pack, dat->j * 30, dat->i * 30), 0);
}