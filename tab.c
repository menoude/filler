#include "filler.h"

int		tab_read(t_data *data, char c)
{
	if (c == 'O' || c == 'o')
	{
		if (data->symbol == 'O')
			return (-1);
		else
			return (0);
	}
	else if (c == 'X' || c == 'x')
	{
		if (data->symbol == 'X')
			return (-1);
		else
			return (0);
	}
	else
		return (data->max_distance);
}

int tab_init(t_data *data)
{
	int		i;


	if (!reader_tab_dimensions(data)
		|| !(data->tab = ft_memalloc(sizeof(int *) * data->rows)))
		return (0);
	ft_bzero((void *)data->tab, sizeof(int *) * data->rows);
	i = -1;
	while (++i < data->rows)
	{
		if (!(data->tab[i] = ft_memalloc(sizeof(int) * data->cols)))
		{
			tab_free(data);
			return (0);
		}
	}
	data->max_distance = data->rows + data->cols + 1;
	return (1);
}

void tab_free(t_data *data)
{
	int i;

	i = -1;
	while (++i < data->rows)
	{
		if (data->tab[i])
			free(data->tab[i]);
	}
	free(data->tab);
}

int tab_update(t_data *data)
{
	char	*input;
	int		i;
	int		j;

	if (!data->tab)
	{
		if (!tab_init(data))
			return (0);
	}
	else
		reader_skip_line();
	reader_skip_line();
	i = -1;
	while (++i < data->rows)
	{
		if (get_next_line(0, &input) <= 0)
			return (0);
		j = -1;
		while (++j < data->cols)
			data->tab[i][j] = tab_read(data, input[j + 4]);
		free(input);
	}
	return (1);
}
