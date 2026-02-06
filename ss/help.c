#include "solong.h"
void	on1_helper(t_game *data)
{
	if (data->countc == data->countoc)
	{
		data->i = data->i - 1;
		destroys(data);
	}
}

void	on3_helper(t_game *data)
{
	if (data->countc == data->countoc)
	{
		data->i = data->i + 1;
		destroys(data);
	}
}

void	on4_helper(t_game *data)
{
	if (data->countc == data->countoc)
	{
		data->j = data->j - 1;
		destroys(data);
	}
}

void	on2_helper(t_game *data)
{
	if (data->countc == data->countoc)
	{
		data->j = data->j + 1;
		destroys(data);
	}
}