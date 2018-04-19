#include "filler.h"

// a ENLEVER
void print_piece(t_data *data)
{
	int i;
	int j;

	i = -1;
	while (++i < data->piece_height)
	{
		j = -1;
		while (++j < data->piece_width)
			fprintf(f, "%c", data->piece[i][j]);
		fprintf(f, "\n");
	}
	fprintf(f, "\n");
}
// pareil
void print_tab(t_data *data)
{
    int i;
    int j;
	int k;

	fprintf(f, "\t");
	k = -1;
	while (++k < data->cols)
		fprintf(f, "%2d ", k);
	fprintf(f, "\n\n");
    i = -1;
    while (++i < data->rows)
        {
			fprintf(f, "%2d\t", i);
            j = -1;
            while (++j < data->cols)
                fprintf(f, "%2d ", data->tab[i][j]);
            fprintf(f, "\n");
        }
    fprintf(f, "data->rows = %d, data->cols = %d\n", data->rows, data->cols);
}

int main(void)
{
    char		*input;
	t_data		data;

    f = fopen("vm_input.txt", "w+");
	get_next_line(0, &input);
	if (ft_strequ(input, "$$$ exec p1 : [players/meyami.filler]"))
		data.symbol = 'O';
	else if (ft_strequ(input, "$$$ exec p2 : [players/meyami.filler]"))
		data.symbol = 'X';
	else
	{
		free(input);
		return (0);
	}
	free(input);
	while (1)
	{
		if (!tab_update(&data) || !piece_update(&data))
			return (0);
		if (!player_play(&data))
			break ;
	}
	tab_free(&data);
	piece_free(&data);
    fclose(f);
    return (0);
}
