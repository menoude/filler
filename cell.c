#include "filler.h"

void cell_fill(t_data *data, int y, int x)
{
	piece_free(data);
	ft_printf("%d %d\n", y, x);


	// fprintf(f, "%d %d\n", y, x);
}

int cell_authorized(t_data *data, int y, int x)
{
	int i;
	int j;
	int superpos;

	if (data->rows - y < data->piece_height
		|| data->cols - x < data->piece_width)
		return (0);
	superpos = 0;
	i = -1;
	while (++i < data->piece_height)
	{
	 	j = -1;
	 	while (++j < data->piece_width)
		{
			if (superpos > 1)
				return (0);
			else if (data->piece[data->y_offset + i][data->x_offset + j] == '*'
					&& data->tab[y + i][x + j] == -1)
				superpos++;
			else if (data->piece[data->y_offset + i][data->x_offset + j] == '*'
			 		&& data->tab[y + i][x + j] == 0)
				return (0);
		}
	}
	return (superpos == 1);
}


void cell_eval_distance(t_data *data, int y, int x, int size)
{
	int i;
	int j;
	int dist;

	dist = 0;
	i = -1;
	while (++i < data->piece_height)
	{
		j = -1;
		while (++j < data->piece_width)
		{
			if (data->piece[data->y_offset + i][data->x_offset + j] == '*'
				&& data->tab[y + i][x + j] != -1)
			{
				dist += data->tab[y + i][x + j];
				size++;
			}
		}
	}
	if (dist / size < data->candidate_dist)
	{
		data->candidate_y = y - data->y_offset;
		data->candidate_x = x - data->x_offset;
		data->candidate_dist = dist / size;
	}
}
