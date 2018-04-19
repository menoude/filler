#include "filler.h"

void trim_height_top(t_data *data)
{
	int j;

	while (++data->y_offset < data->piece_height)
	{
		j = -1;
		while (++j < data->piece_width)
		{
			if (data->piece[data->y_offset][j] == '*')
				return ;
		}
	}
}

void trim_height_bottom(t_data *data)
{
	int i;
	int j;

	i = data->piece_height;
	while (--i >= 0)
	{
		j = -1;
		while (++j < data->piece_width)
		{
			if (data->piece[i][j] == '*')
			{
				data->piece_height = i + 1;
				return ;
			}
		}
	}
}

void trim_width_left(t_data *data)
{
	int i;

	while (++data->x_offset < data->piece_width)
	{
		i = data->y_offset - 1;
		while (++i < data->piece_height)
		{
			if (data->piece[i][data->x_offset] == '*')
				return ;
		}
	}
}

void trim_width_right(t_data *data)
{
	int i;
	int j;

	j = data->piece_width;
	while (--j >= 0)
	{
		i = data->piece_height;
		while (--i >= data->y_offset)
		if (data->piece[i][j] == '*')
		{
			data->piece_width = j + 1;
			return ;
		}
	}
}

void trim_piece(t_data *data)
{
	trim_height_bottom(data);
	trim_width_right(data);
	trim_height_top(data);
	trim_width_left(data);
}
