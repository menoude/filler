#include "filler.h"

int piece_update(t_data *data)
{
	char 	**info;
	char 	*input;
	int		i;

	get_next_line(0, &input);
	info = ft_strsplit(input, ' ');
	data->piece_height = ft_atoi(info[1]);
	data->piece_width = ft_atoi(info[2]);
	free(info);
	if (!(data->piece = ft_memalloc(sizeof(char *) * data->piece_height)))
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
