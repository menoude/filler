#include "filler.h"

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
	while (1)
	{
		if (!tab_update(&data) || !piece_update(&data))
			return (0);
		player_play(&data);
	}
	for (int i = 0; i < data.rows; i++)
	{
		for (int j = 0; j < data.cols; j++)
			fprintf(f, "%d ", data.tab[i][j]);
		fprintf(f, "\n");
	}
	fprintf(f, "piece heigth = %d and width = %d\n", data.piece_height, data.piece_width);
	for (int i = 0; i < data.piece_height; i++)
		fprintf(f, "%s\n", data.piece[i]);
    fclose(f);
    return (0);
}
