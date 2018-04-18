#include "filler.h"

void player_write_dist_right(t_data *data, int y, int x)
{
	int i;
	int j;
	int dist;

	i = y;
	while (i < data->rows)
	{
		j = i > y ? 0 : x + 1;
		while (j < data->cols)
		{
			if (data->tab[i][j] == 0)
			{
				dist = ft_abs_value(y - i) + ft_abs_value(x - j);
				if (dist < data->tab[y][x])
					data->tab[y][x] = dist;
			}
			j++;
		}
		i++;
	}
}

void player_write_dist_left(t_data *data, int y, int x)
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

void player_eval_map(t_data *data)
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
			if (data->tab[i][j] > 0)
				player_write_dist_left(data, i , j);
		}
	}
}

// essayer de poser partout, si la somme des distances est plus faible que celle d'avant, changer les positions candidates

int player_play(t_data *data)
{
	int i;
	int j;

	print_tab(data); // a ENLEVER
	player_eval_map(data);
	print_tab(data); // a ENLEVER
	print_piece(data);
	i = data->rows;
	while (--i >= 0)
	{
		j = data->cols;
		while (--j >= 0)
		{
			if (piece_has_room(data, i, j))
				piece_eval_distance(data, i, j, 0);
		}
	}
	fprintf(f, "piece will be put at (%d, %d)\n", data->candidate_y, data->candidate_x);
	if (data->candidate_dist == -1)
		return (0);
	else
	{
		piece_put(data, data->candidate_y, data->candidate_x);
		return (1);
	}
}
