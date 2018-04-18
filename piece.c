#include "filler.h"

int piece_update(t_data *data)
{
	char 	*input;
	int		i;


	if (!reader_piece_dimensions(data)
		|| !(data->piece = ft_memalloc(sizeof(char *) * data->piece_height)))
		return (0);
	i = -1;
	while (++i < data->piece_height)
	{
		get_next_line(0, &input);
		data->piece[i] = ft_strdup(input);
		free(input);
	}
	return (1);
}

void piece_free(t_data *data)
{
	while (data->piece_height)
	{
		free(data->piece[data->piece_height - 1]);
		data->piece_height--;
	}
	free(data->piece);
}

int piece_has_room(t_data *data, int y, int x)
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
			else if (data->piece[i][j] == '*' && data->tab[y + i][x + j] == 1)
				superpos++;
			else if (data->piece[i][j] == '*' && data->tab[y + i][x + j] == 2)
				return (0);
		}
	}
	return (superpos == 1);
}

void piece_put(t_data *data, int y, int x)
{
	piece_free(data);
	ft_printf("%d %d\n", y, x);
}
