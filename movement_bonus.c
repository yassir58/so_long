/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelatman <yelatman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 12:31:38 by yelatman          #+#    #+#             */
/*   Updated: 2021/12/29 22:06:12 by yelatman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	move_up(t_data *data)
{
	int	indx_x;
	int	indx_y;

	indx_x = data->map.player_p.row;
	indx_y = data->map.player_p.column;
	if (data->map_tab[indx_x - 1][indx_y] == '0')
	{
		data->map_tab[indx_x][indx_y] = '0';
		data->map_tab[indx_x - 1][indx_y] = 'P';
	}
	else if (data->map_tab[indx_x - 1][indx_y] == 'C')
		handle_element_up(data, indx_x, indx_y);
	else if (data->map_tab[indx_x - 1][indx_y] == 'I')
		player_dead(data, indx_x, indx_y);
	else if (data->map_tab[indx_x - 1][indx_y] == 'O')
		player_dead(data, indx_x, indx_y);
	get_element_position(data->map_tab, &indx_x, &indx_y, 'P');
	data->map.player_p.row = indx_x;
	data->map.player_p.column = indx_y;
}

void	move_down(t_data *data)
{
	int	indx_x;
	int	indx_y;

	indx_x = data->map.player_p.row;
	indx_y = data->map.player_p.column;
	if (data->map_tab[indx_x + 1][indx_y] == '0')
	{
		data->map_tab[indx_x][indx_y] = '0';
		data->map_tab[indx_x + 1][indx_y] = 'P';
	}
	else if (data->map_tab[indx_x + 1][indx_y] == 'C')
		handle_element_down(data, indx_x, indx_y);
	else if (data->map_tab[indx_x + 1][indx_y] == 'I')
		player_dead(data, indx_x, indx_y);
	else if (data->map_tab[indx_x + 1][indx_y] == 'O')
		player_dead(data, indx_x, indx_y);
	get_element_position(data->map_tab, &indx_x, &indx_y, 'P');
	data->map.player_p.row = indx_x;
	data->map.player_p.column = indx_y;
}

void	move_left(t_data *data)
{
	int	indx_x;
	int	indx_y;

	indx_x = data->map.player_p.row;
	indx_y = data->map.player_p.column;
	if (data->map_tab[indx_x][indx_y + 1] == '0')
	{
		data->map_tab[indx_x][indx_y] = '0';
		data->map_tab[indx_x][indx_y + 1] = 'P';
	}
	else if (data->map_tab[indx_x][indx_y + 1] == 'C')
		handle_element_left(data, indx_x, indx_y);
	else if (data->map_tab[indx_x][indx_y + 1] == 'I')
		player_dead(data, indx_x, indx_y);
	else if (data->map_tab[indx_x][indx_y + 1] == 'O')
		player_dead(data, indx_x, indx_y);
	get_element_position(data->map_tab, &indx_x, &indx_y, 'P');
	data->map.player_p.row = indx_x;
	data->map.player_p.column = indx_y;
}

void	move_right(t_data *data)
{
	int	indx_x;
	int	indx_y;

	indx_x = data->map.player_p.row;
	indx_y = data->map.player_p.column;
	if (data->map_tab[indx_x][indx_y - 1] == '0')
	{
		data->map_tab[indx_x][indx_y] = '0';
		data->map_tab[indx_x][indx_y - 1] = 'P';
	}
	else if (data->map_tab[indx_x][indx_y - 1] == 'C')
		handle_element_right(data, indx_x, indx_y);
	else if (data->map_tab[indx_x][indx_y - 1] == 'I')
		player_dead(data, indx_x, indx_y);
	else if (data->map_tab[indx_x][indx_y - 1] == 'O')
		player_dead(data, indx_x, indx_y);
	get_element_position(data->map_tab, &indx_x, &indx_y, 'P');
	data->map.player_p.row = indx_x;
	data->map.player_p.column = indx_y;
}

void	player_dead(t_data *data, int indx_x, int indx_y)
{
	int	i;

	data->map_tab[indx_x][indx_y] = '0';
	data->map.game_over = TRUE;
	data->map.player_dead = TRUE;
	i = 500000000;
	while (i)
		i--;
	handle_game_over(data);
}
