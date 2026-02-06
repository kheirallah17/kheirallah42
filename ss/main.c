#include "solong.h"

void main_helper(char *mappath)
{
    t_game	*data;
	int		i;
	int		y;

    data = create_game(mappath);
	if (!data)
	{
		write(2, "Error\nFailed to create window\n", 31);
		return ;
	}
	fillpos_player(data, mappath);
	data->countc = 0;
	data->count_moves = 0;	
	data->countoc = count_c(data->map, mappath);
	i = countmaplines(mappath);
	y = getlinesize(mappath);
	data->lines = i;
	data->linesize = y;
	mlx_hook(data->win, KeyPress, KeyPressMask, &on_keypress, data);
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask,
		&on_destroy, data);
	mapgo(data);
	mlx_loop(data->mlx);
}

void first_error_check(char *str)
{
    int		fd;
    char	buf;
    int		ret;

    fd = open(str, O_RDONLY);
    if (fd < 0)
    {
        write(2, "Error\n", 6);
        exit(1);
    }
    ret = 0;
	while ((read(fd, &buf, 1)) > 0)
		ret++;
	if (ret == 0)
	{
		close(fd);
		write(1, "Error\n", 6);
		exit(1);
	}
    close(fd);
}

void check_file(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (i > 0 && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		i--;
	i--;
	if (i < 2 || str[i] != 'r' || str[i - 1] != 'e' || str[i - 2] != 'b'
		|| str[i - 3] != '.')
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}

int main (int argc, char **argv) {
    int error;

    if (argc != 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
    check_file(argv[1]);
    first_error_check(argv[1]);
    error = check_all(argv[1]);
    if (error == 0)
		return (1);
    main_helper(argv[1]);
	return (0);
}