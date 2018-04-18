#include "filler.h"

void player_write_dist_right(t_data *data, int x, int y)
{
	int i;
	int j;
	int dist;

	i = y;
	while (i < data->rows)
	{
		j = i != y ? 0 : x;
		while (j < data->cols)
		{
			if (data->tab[i][j] == 0)
			{
				dist = ft_abs_value(y - i) + ft_abs_value(x - j);
				if (data->tab[y][x] == -1 || dist < data->tab[y][x])
					data->tab[y][x] = dist;
			}
			j++;
		}
		i++;
	}
}

void player_write_dist_left(t_data *data, int x, int y)
{
	int i;
	int j;
	int dist;

	i = y;
	while (i >= 0)
	{
		j = i != y ? data->cols : x;
		while (--j >= 0)
		{
			if (data->tab[i][j] == 0)
			{
				dist = ft_abs_value(y - i) + ft_abs_value(x - j);
				if (data->tab[y][x] == -1 || dist < data->tab[y][x])
					data->tab[y][x] = dist;
			}
		}
		i--;
	}
}

void player_heat_map(t_data *data)
{
	int i;
	int j;

	i = -1;
	while (++i < data->rows)
	{
		j = -1;
		while (++j < data->cols)
		{
			if (data->tab[i][j] > 0)
				player_write_dist_right(data, i, j);
		}
	}
	i = data->rows;
	while (--i >= 0)
	{
		j = data->cols;
		while (--j >= 0)
		{
			// if (data->tab[i][j] > 0)
			// 	player_write_dist_left(data, i , j);
		}
	}
}

int player_play(t_data *data)
{
	int i;
	int j;

	player_heat_map(data);
	print_tab(data); // a ENLEVER
	i = data->rows;
	while (--i >= 0)
	{
		j = data->cols;
		while (--j >= 0)
		{
			if (piece_has_room(data, i, j))
			{
				piece_put(data, i, j);
				return (1);
			}
		}
	}
	return (0);
}
