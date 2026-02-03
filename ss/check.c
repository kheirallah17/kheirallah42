#include "solong.h"

int check_all_lines(char **map, char *mappath)
{
    int i;
    int j;
    int count;
    int temp;

    i = 0;
    j = 0;
    count = 0;
    temp = getlinesize(mappath);
    while (map[i] != NULL)
    {
        count = 0;
        j = 0;
        while (map[i][j] != '\0' && map[i][j] != '\n')
        {
            count++;
            j++;
        }
        if(temp != count)
            return (0);
        i++;
        temp = count;
    }
    return (1);
}

int check_map(char **map, char *mappath)
{
    int line_size;
    int count_lines;
    int i;
    int j;

    line_size = getlinesize(mappath);
    count_lines = countmaplines(mappath);
    i = 0;
    j = 0;
    count_lines--;
    line_size--;
    while (i < count_lines)
    {
        j = 0;
        while (j < line_size)
        {
            if(map[0][j] != '1' || map[count_lines][j] != '1'
            || map[i][0] != '1' || map[i][line_size] != '1')
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int count_c(char **map, char *mappath)
{
    int count ;
    int k;
    int m;

    count = 0;
    k = 0;
    m = 0;
    while (k < countmaplines(mappath))
    {
        m = 0;
        while (m < getlinesize(mappath))
        {
            if (map[k][m] == 'C')
                count++;
            m++;
        }
        k++;
    }
    return (count);
}

int check_valid_chars(char **map, char *mappath)
{
    int k;
    int m;

    k = 0;
    m = 0;
    while (map[k] != NULL)
    {
        m = 0;
        while (m < getlinesize(mappath))
        {
            if (map[k][m] != '0' && map[k][m] != '1' && map[k][m] != 'C'
            && map[k][m] != 'E' && map[k][m] != 'P' && map[k][m] != '\n')
                return (0);
            m++;
        }
        k++;
    }
    return (1);
}

int checkc(char **map, char *mappath)
{
    int k;
    int m;

    k = 0;
    m = 0;
    while (k < countmaplines(mappath))
    {
        m = 0;
        while (m < getlinesize(mappath))
        {
            if (map[k][m] == 'C')
                return (1);
            m++;
        }
        k++;
    }
    return (0);
}