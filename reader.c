#include "filler.h"

void reader_skip_line(void)
{
	char	*input;
	int		read;

	read = get_next_line(0, &input);
	if (read)
		free(input);
}

int reader_tab_dimensions(t_data *data)
{
	char *input;
	char **info;
	int read;

	read = get_next_line(0, &input);
	if (read < 1)
		return (0);
	info = ft_strsplit(input, ' ');
	data->rows = ft_atoi(info[1]);
	data->cols = ft_atoi(info[2]);
	reader_free_info(input, info, read);
	return (1);
}

int reader_piece_dimensions(t_data *data)
{
	char *input;
	char **info;
	int read;

	read = get_next_line(0, &input);
	if (read < 1)
		return (0);
	info = ft_strsplit(input, ' ');
	data->piece_height = ft_atoi(info[1]);
	data->piece_width = ft_atoi(info[2]);
	reader_free_info(input, info, read);
	return (1);
}

void reader_free_info(char *input, char **info, int read)
{
	if (read)
		free(input);
	free(info[2]);
	free(info[1]);
	free(info[0]);
	free(info);
}
