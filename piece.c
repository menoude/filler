#include "filler.h"

// mieux lire la hauteur et largeur des pieces pour pouvoir faire rentrer les petites formes cachées dans des grandes pieces vides. Mais tout en sachant que la VM n'accepte que des coordonnées de piece et non pas de formes !
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
	reader_revise_piece_dimensions(data);
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
			else if (data->piece[i][j] == '*' && data->tab[y + i][x + j] == -1)
				superpos++;
			else if (data->piece[i][j] == '*' && data->tab[y + i][x + j] == 0)
				return (0);
		}
	}
	return (superpos == 1);
}

void piece_eval_distance(t_data *data, int y, int x, int size)
{
	int i;
	int j;
	int dist;

	dist = 0;
	i = -1;
	while (++i < data->piece_height)
	{
		j = -1;
		while (++j < data->piece_width)
		{
			if (data->piece[i][j] == '*' && data->tab[y + i][x + j] != -1)
			{
				dist += data->tab[y + i][x + j];
				size++;
			}
		}
	}
	fprintf(f, "piece has room at (%d, %d) where its distance is %d\n", y, x, dist);
	if (dist / size < data->candidate_dist)
	{
		data->candidate_y = y;
		data->candidate_x = x;
		data->candidate_dist = dist / size;
	}
}

void piece_put(t_data *data, int y, int x)
{
	piece_free(data);
	ft_printf("%d %d\n", y, x);
}
