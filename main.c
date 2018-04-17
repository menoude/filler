#include "filler.h"

int main(void)
{
    char *input;
	t_data data;

    // f = fopen("vm_input.txt", "w+");
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
		if (!player_play(&data))
			break ;
	}
    // fclose(f);
    return (0);
}
