/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:44:39 by meyami            #+#    #+#             */
/*   Updated: 2018/04/20 16:44:42 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_piece(t_data *data)
{
	int i;
	int j;

	i = -1;
	while (++i < data->piece_height)
	{
		j = -1;
		while (++j < data->piece_width)
			fprintf(f, "%c",
					data->piece[data->y_offset + i][data->x_offset + j]);
		fprintf(f, "\n");
	}
	fprintf(f, "\n");
}

void	print_tab(t_data *data)
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
}
