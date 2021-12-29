/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_game_over.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelatman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:00:17 by yelatman          #+#    #+#             */
/*   Updated: 2021/12/29 22:01:50 by yelatman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	handle_game_over(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	mlx_string_put(data->mlx, data->win, (data->map.w_width / 2),
		(data->map.w_height / 2),
		0xFFFF0000, "game over");
}
