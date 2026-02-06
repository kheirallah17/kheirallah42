#include "solong.h"

int destroys(t_game *data)
{
    int k;

    k = 0;
    while (k < data->lines)
    {
        free(data->map[k]);
        k++;
    }
    free(data->map);
    mlx_destroy_image(data->mlx, data->wall);
    mlx_destroy_image(data->mlx, data->road);
    mlx_destroy_image(data->mlx, data->check);
    mlx_destroy_image(data->mlx, data->pack);
    mlx_destroy_image(data->mlx, data->door);
    mlx_destroy_window(data->mlx, data->win);
    free(data->mlx);
    free(data);
    exit(0);
    return (0);
}