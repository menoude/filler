#include "filler.h"

int piece_update(t_data *data)
{
	char 	*input;
	int		i;


	if (!reader_piece_dimensions(data)
		|| !(data->piece = ft_memalloc(sizeof(char *) * (data->piece_height + 1))))
		return (0);
	data->piece[data->piece_height] = 0;
	i = -1;
	while (++i < data->piece_height)
	{
		get_next_line(0, &input);
		data->piece[i] = ft_strdup(input);
		free(input);
	}

	// print_piece(data);

	trim_piece(data);

	// print_piece(data);
	data->candidate_y = -1;
	data->candidate_x = -1;
	data->candidate_dist = data->max_distance;
	return (1);
}

void piece_free(t_data *data)
{
	int i;

	i = -1;
	while (data->piece[++i])
		free(data->piece[i]);
	free(data->piece);
}
