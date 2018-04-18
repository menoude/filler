#include "filler.h"

// a ENLEVER
void print_tab(t_data *data)
{
    int i;
    int j;

    i = -1;
    while (++i < data->rows)
        {
            j = -1;
            while (++j < data->cols)
                fprintf(f, "%d ", data->tab[i][j]);
            fprintf(f, "\n");
        }
}

int main(void)
{
    char *input;
	t_data data;

    f = fopen("vm_input.txt", "w+");
	get_next_line(0, &input);
	if (ft_strequ(input, "$$$ exec p1 : [players/meyami.filler]"))
		data.symbol = 'O';
	else
		data.symbol = 'X';
	free(input);
	// while (1)
	// {
		if (!tab_update(&data) || !piece_update(&data))
			return (0);
		if (!player_play(&data))
            return(0);
			// break ;
	// }
    fclose(f);
    return (0);
}
