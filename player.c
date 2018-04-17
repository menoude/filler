#include "filler.h"

void player_play(t_data *data)
{
	int i;
	int j;

	i = -1;
	while (++i < data->rows)
	{
		j = -1;
		while (++j < data->cols)
			if (piece_has_room(data, i, j))
			{
				piece_free(data);
				ft_printf("%d %d\n", i, j);
			}
	}
	return ;
}
