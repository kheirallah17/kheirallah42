#include "solong.h"

void	on_keypress1(int keysym, t_game *data)
{
	if (keysym == 119)
	{
		if (((data->map[data->i - 1][data->j] == '0') || (data->map[data->i
					- 1][data->j] == 'P') || (data->map[data->i
					- 1][data->j] == 'C')) && ((data->i - 1) < data->lines)
			&& ((data->i - 1) >= 0))
		{
			data->i = data->i - 1;
			mapgo(data);
			if (data->map[data->i][data->j] == 'C')
			{
				data->countc++;
				(data->map[data->i][data->j]) = '0';
			}
			data->count_moves++;
			ft_printf("your move:%d\n", data->count_moves);
		}
		else if ((data->map[data->i - 1][data->j] == 'E'))
			on1_helper(data);
	}
}

void	on_keypress3(int keysym, t_game *data)
{
	if (keysym == 115)
	{
		if (((data->map[data->i + 1][data->j] == '0') || (data->map[data->i
					+ 1][data->j] == 'P') || (data->map[data->i
					+ 1][data->j] == 'C')) && ((data->i + 1) < data->lines)
			&& ((data->i + 1) >= 0))
		{
			data->i = data->i + 1;
			mapgo(data);
			if (data->map[data->i][data->j] == 'C')
			{
				data->countc++;
				(data->map[data->i][data->j]) = '0';
			}
			data->count_moves++;
			ft_printf("your move:%d\n", data->count_moves);
		}
		else if (data->map[data->i + 1][data->j] == 'E')
			on3_helper(data);
	}
}

void	on_keypress4(int keysym, t_game *data)
{
	if (keysym == 97)
	{
		if (((data->map[data->i][data->j - 1] == '0')
			|| (data->map[data->i][data->j - 1] == 'P')
				|| (data->map[data->i][data->j - 1] == 'C')) && ((data->j
					- 1) < data->linesize) && ((data->j - 1) >= 0))
		{
			data->j = data->j - 1;
			mapgo(data);
			if (data->map[data->i][data->j] == 'C')
			{
				data->countc++;
				(data->map[data->i][data->j]) = '0';
			}
			data->count_moves++;
			ft_printf("your move:%d\n", data->count_moves);
            write(1, &data->count_moves, 3);
		}
		else if ((data->map[data->i][data->j - 1] == 'E'))
			on4_helper(data);
	}
}

void	on_keypress2(int keysym, t_game *data)
{
	if (keysym == 100)
	{
		if (((data->map[data->i][data->j + 1] == '0')
			|| (data->map[data->i][data->j + 1] == 'P')
				|| (data->map[data->i][data->j + 1] == 'C')) && ((data->j
					+ 1) < data->linesize) && ((data->j + 1) >= 0))
		{
			data->j = data->j + 1;
			mapgo(data);
			if (data->map[data->i][data->j] == 'C')
			{
				data->countc++;
				(data->map[data->i][data->j]) = '0';
			}
			data->count_moves++;
			ft_printf("your move:%d\n", data->count_moves);
		}
		else if (data->map[data->i][data->j + 1] == 'E')
			on2_helper(data);
	}
}

int	on_keypress(int keysym, t_game *data)
{
	if (keysym == 65307)
	{
		destroys(data);
	}
	else
	{
		on_keypress1(keysym, data);
		on_keypress2(keysym, data);
		on_keypress3(keysym, data);
		on_keypress4(keysym, data);
	}
	return (1);
}