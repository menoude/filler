/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:44:11 by meyami            #+#    #+#             */
/*   Updated: 2018/04/20 16:44:14 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	char	*input;
	t_data	data;

	get_next_line(0, &input);
	if (ft_strnequ(input, "$$$ exec p1 : [players/meyami.filler]", 15))
		data.symbol = 'O';
	else if (ft_strnequ(input, "$$$ exec p2 : [players/meyami.filler]", 15))
		data.symbol = 'X';
	else
	{
		free(input);
		return (0);
	}
	free(input);
	data.tab = 0;
	while (1)
	{
		if (!tab_update(&data) || !piece_update(&data))
			return (0);
		if (!player_play(&data))
			break ;
	}
	tab_free(&data);
	piece_free(&data);
	return (0);
}
