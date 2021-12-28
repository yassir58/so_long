/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelatman <yelatman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 14:28:42 by yelatman          #+#    #+#             */
/*   Updated: 2021/12/28 14:56:24 by yelatman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	duplicate(char **map, char c)
{
	int	i ;
	int	j ;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[i])
	{
		while (map[i][j] && map[i][j] != '\n')
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	if (count > 1)
		return (1);
	return (0);
}

int	check_for_valid_file(char *str)
{
	int		len;
	int		i;
	char	*ext;
	int		ext_len;

	i = 0;
	len = 0;
	ext = ".ber";
	ext_len = 4;
	len = ft_strlen(str) - 1;
	while (ext_len--)
	{
		if (str[len - i++] != ext[ext_len])
			return (0);
	}
	return (1);
}

int	check_for_existing_elm(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'P' || map[i][j] == 'E')
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	if (count == 2)
		return (1);
	return (0);
}

int	validate_map(char **map, char *str)
{
	if (check_for_valid_file(str) && check_for_valid_map(map))
	{
		if (check_for_existing_elm(map))
			return (1);
	}
	return (0);
}
