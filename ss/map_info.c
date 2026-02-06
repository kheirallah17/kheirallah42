#include "solong.h"

int countmaplines(char *mappath)
{
    char c;
    int countlines;
    int fd;

    countlines = 0;
    fd = open(mappath, O_RDONLY);
    if (fd == -1)
        return (-1);
    while (read(fd, &c, 1) > 0)
        if (c == '\n')
            countlines++;
    close(fd);
    return (countlines);
}

int getlinesize(char *mappath)
{
    int fd;
    char c;
    int count;

    count = 0;
    fd = open(mappath, O_RDONLY);
    if (fd == -1)
        return (-1);
    while (read(fd, &c, 1) > 0 && c != '\n')
        count++;
    close(fd);
    return (count);
}

t_playerpos findpos(char **map, char *mappath)
{
    t_playerpos player;
    int         i;
    int         j;

    i = 0;
    j = 0;
    while (i < countmaplines(mappath))
    {
        j = 0;
        while (j < getlinesize(mappath))
        {
            if (map[i][j] == 'P')
            {
                player.x = i;
                player.y = j;
            }
            j++;
        }
        i++;
    }
    return (player);
}