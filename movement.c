/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelatman <yelatman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 12:31:38 by yelatman          #+#    #+#             */
/*   Updated: 2021/12/26 19:34:34 by yelatman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int move_up(t_data *data)
{
    int indx_x = data->map.player_p.row;
    int indx_y = data->map.player_p.column;
    if (data->map_tab[indx_x - 1][indx_y] == '0')
    {
        data->map_tab[indx_x][indx_y] = '0';
        data->map_tab[indx_x - 1][indx_y] = 'P';
    }
    else if  (data->map_tab[indx_x - 1][indx_y ] == 'C')
    {
        data->map.coin_count--;
        data->map_tab[indx_x][indx_y] = '0';
        data->map_tab[indx_x - 1][indx_y ] = 'P';
        if (data->map.coin_count == 0)
        {
            end_game(data);
            return (TRUE);
        }
    }
    else if (data->map_tab[indx_x - 1][indx_y] == 'I')
    {
        data->map_tab[indx_x][indx_y] = '0';
        printf ("player is dead !\n");
        return (TRUE);
    }
    get_element_position(data->map_tab, &indx_x, &indx_y, 'P');
    data->map.player_p.row = indx_x;
    data->map.player_p.column = indx_y;
    return (FALSE);
}

int move_down(t_data *data)
{
    int indx_x = data->map.player_p.row;
    int indx_y = data->map.player_p.column;
    if (data->map_tab[indx_x + 1][indx_y] == '0')
    {
        data->map_tab[indx_x][indx_y] = '0';
        data->map_tab[indx_x + 1][indx_y] = 'P';
    }
    else if  (data->map_tab[indx_x + 1][indx_y] == 'C')
    {
        data->map.coin_count--;
        data->map_tab[indx_x][indx_y] = '0';
        data->map_tab[indx_x +1][indx_y] = 'P';
        if (data->map.coin_count == 0)
        {
            end_game(data);
            return (TRUE);
        }
    }
    else if (data->map_tab[indx_x + 1][indx_y] == 'I')
    {
        data->map_tab[indx_x][indx_y] = '0';
        printf ("player_p is dead !\n");
        return (TRUE);
    }
    get_element_position(data->map_tab, &indx_x, &indx_y, 'P');
    data->map.player_p.row = indx_x;
    data->map.player_p.column = indx_y;
    return (FALSE);
}

int move_left(t_data *data)
{
    int indx_x = data->map.player_p.row;
    int indx_y = data->map.player_p.column;
    if (data->map_tab[indx_x ][indx_y + 1] == '0')
    {
            data->map_tab[indx_x][indx_y] = '0';
            data->map_tab[indx_x ][indx_y + 1] = 'P';
    }
    else if  (data->map_tab[indx_x ][indx_y  + 1] == 'C')
    {
        data->map.coin_count--;
        data->map_tab[indx_x][indx_y] = '0';
        data->map_tab[indx_x ][indx_y + 1] = 'P';
        if (data->map.coin_count == 0)
        {
            end_game(data);
            return (TRUE);
        }
    }
    else if (data->map_tab[indx_x ][indx_y  + 1] == 'I')
    {
        data->map_tab[indx_x][indx_y] = '0';
        printf ("player is dead !\n");
        return (TRUE);
    }
    get_element_position(data->map_tab, &indx_x, &indx_y, 'P');
    data->map.player_p.row = indx_x;
    data->map.player_p.column = indx_y;
    return (FALSE);
}

int move_right(t_data *data)
{
    int indx_x = data->map.player_p.row;
    int indx_y = data->map.player_p.column;
    if (data->map_tab[indx_x ][indx_y - 1] == '0')
    {
        data->map_tab[indx_x][indx_y] = '0';
        data->map_tab[indx_x ][indx_y - 1] = 'P';
    }
    else if  (data->map_tab[indx_x ][indx_y - 1] == 'C')
    {
        data->map.coin_count--;
        data->map_tab[indx_x][indx_y] = '0';
        data->map_tab[indx_x ][indx_y - 1] = 'P';
        if (data->map.coin_count == 0)
        {
            end_game(data);
            return (TRUE);
        }
    }
    else if (data->map_tab[indx_x ][indx_y  - 1] == 'I')
    {
        data->map_tab[indx_x][indx_y] = '0';
        printf ("player is dead !\n");
        return (TRUE);
    }
    get_element_position(data->map_tab, &indx_x, &indx_y, 'P');
    data->map.player_p.row = indx_x;
    data->map.player_p.column = indx_y;
    return (FALSE);
}