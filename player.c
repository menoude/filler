#include "filler.h"

static void player_find_adversary(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			if (data->tab[i][j] == 2)
			{
				data->adv_y = i;
				data->adv_x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

// void player_map(t_data *data)
// {
//
// }

// int player_try(t_data *data, int i, int j)
// {
// 
// }

int player_play(t_data *data)
{
	int i;
	int j;

	player_find_adversary(data);
	i = data->rows;
	while (--i >= 0)
	{
		j = data->cols;
		while (--j >= 0)
		{
			if (piece_has_room(data, i, j))
			{
				piece_free(data);
				ft_printf("%d %d\n", i, j);
				return (1);
			}
		}
	}
	return (0);
}
