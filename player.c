/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:45:01 by meyami            #+#    #+#             */
/*   Updated: 2018/04/20 16:45:03 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	player_write_dist_right(t_data *data, int y, int x)
{
	int i;
	int j;
	int dist;

	i = y;
	while (i < data->rows)
	{
		j = i > y ? 0 : x + 1;
		while (j < data->cols)
		{
			if (data->tab[i][j] == 0)
			{
				dist = ft_abs_value(y - i) + ft_abs_value(x - j);
				if (dist < data->tab[y][x])
					data->tab[y][x] = dist;
			}
			j++;
		}
		i++;
	}
}

void	player_write_dist_left(t_data *data, int y, int x)
{
	int i;
	int j;
	int dist;

	i = y;
	while (i >= 0)
	{
		j = i != y ? data->cols : x;
		while (--j >= 0)
		{
			if (data->tab[i][j] == 0)
			{
				dist = ft_abs_value(y - i) + ft_abs_value(x - j);
				if (data->tab[y][x] == -1 || dist < data->tab[y][x])
					data->tab[y][x] = dist;
			}
		}
		i--;
	}
}

void	player_eval_map(t_data *data)
{
	int i;
	int j;

	i = -1;
	while (++i < data->rows)
	{
		j = -1;
		while (++j < data->cols)
		{
			if (data->tab[i][j] > 0)
			{
				player_write_dist_right(data, i, j);
				player_write_dist_left(data, i, j);
			}
		}
	}
}

int		player_play(t_data *data)
{
	int i;
	int j;

	player_eval_map(data);
	i = -1;
	while (++i < data->rows - data->piece_height)
	{
		j = -1;
		while (++j < data->cols - data->piece_width)
		{
			if (cell_authorized(data, i, j))
				cell_eval_distance(data, i, j, 0);
		}
	}
	if (data->candidate_dist == -1)
		return (0);
	cell_fill(data, data->candidate_y, data->candidate_x);
	return (1);
}
