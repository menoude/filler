/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:44:52 by meyami            #+#    #+#             */
/*   Updated: 2018/04/20 16:44:53 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	trim_bottom(t_data *data)
{
	int i;
	int j;

	i = data->piece_height;
	while (--i >= 0)
	{
		j = -1;
		while (++j < data->piece_width)
		{
			if (data->piece[i][j] == '*')
			{
				data->piece_height = i + 1;
				return ;
			}
		}
	}
}

void	trim_right(t_data *data)
{
	int i;
	int j;

	j = data->piece_width;
	while (--j >= 0)
	{
		i = data->y_offset - 1;
		while (++i < data->piece_height)
		{
			if (data->piece[i][j] == '*')
			{
				data->piece_width = j + 1;
				return ;
			}
		}
	}
}

void	trim_top(t_data *data)
{
	int i;
	int j;

	i = -1;
	while (++i < data->piece_height)
	{
		j = -1;
		while (++j < data->piece_width)
		{
			if (data->piece[i][j] == '*')
			{
				data->y_offset = i;
				data->piece_height -= i;
				return ;
			}
		}
	}
}

void	trim_left(t_data *data)
{
	int i;
	int j;

	j = -1;
	while (++j < data->piece_width)
	{
		i = -1;
		while (++i < data->piece_height)
		{
			if (data->piece[data->y_offset + i][j] == '*')
			{
				data->x_offset = j;
				data->piece_width -= j;
				return ;
			}
		}
	}
}

void	trim_piece(t_data *data)
{
	trim_bottom(data);
	trim_right(data);
	trim_top(data);
	trim_left(data);
}
