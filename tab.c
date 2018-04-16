#include "filler.h"

int		tab_read(t_data *data, char c)
{
	if (c == '.')
	return (0);
	else if (c == 'O' || c == 'o')
	{
		if (data->symbol == 'O')
		return (1);
		else
		return (2);
	}
	else if (c == 'X' || c == 'x')
	{
		if (data->symbol == 'X')
		return (1);
		else
		return (2);
	}
	else
		return (-1);
}

int tab_init(t_data *data)
{
	char	*input;
	char	**info;
	int		i;

	get_next_line(0, &input);

	info = ft_strsplit(input, ' ');
	free(input);
	free(info[0]);
	data->rows = ft_atoi(info[1]);
	free(info[1]);
	data->cols = ft_atoi(info[2]);
	free(info[2]);
	free(info);
	if (!(data->tab = ft_memalloc(sizeof(int *) * data->rows)))
		return (0);
	ft_bzero((void *)data->tab, sizeof(int *) * data->rows);
	i = -1;
	while (++i < data->rows)
	{
		if (!(data->tab[i] = ft_memalloc(sizeof(int) * data->cols)))
			tab_free(data);
	}
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

void tab_update(t_data *data)
{
	char	*input;
	int		i;
	int		j;

	get_next_line(0, &input);
	free(input);
	i = -1;
	while (++i < data->rows)
	{
		get_next_line(0, &input);
		j = -1;
		while (++j < data->cols)
			data->tab[i][j] = tab_read(data, input[j + 4]);
		free(input);
	}
}
