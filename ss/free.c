#include "solong.h"

void freemen(char **map, char *mappath)
{
    int i;

    i = 0;
    (void)mappath;
    while (map[i] != NULL)
    {
        free(map[i]);
        i++;
    }
    free(map);
}

void free2(char *str2, char *str1)
{
    free(str2);
    free(str1);
}

void free_close(char *str, int fd)
{
    free(str);
    close(fd);
}