#include "solong.h"

void	check_lines(char *line, char *temp, int fd)
{
	free(line);
	free(temp);
	close(fd);
	write(1, "ERROR\n", 6);
	exit(1);
}

char *fillarray(char *mappath)
{
    char *line;
    char *c;
    int fd;
    char *arr;

    fd = open(mappath, O_RDONLY);
    if (fd == -1)
        return (NULL);
    line = get_next(fd);
    c = ft_strdup("");
    while (line)
	{
		if (ft_strncmp(line, "\n", ft_strlen(line)) != 0)
		{
			arr = ft_strjoin(c, line);
			free2(line, c);
			c = arr;
			line = get_next(fd);
		}
		else
			check_lines(line, c, fd);
	}
	close(fd);
	return (c);
}

char **maptoarray(char *mappath)
{
    char *arr;
    char **arraylines;

    arr = fillarray(mappath);
    arraylines = ft_split(arr, '\n');
    free(arr);
    return (arraylines);
}