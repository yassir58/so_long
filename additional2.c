/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelatman <yelatman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 09:50:10 by yelatman          #+#    #+#             */
/*   Updated: 2021/12/28 14:28:31 by yelatman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	check_for_walls(char **map)
{
	int	first;
	int	last;
	int	i;

	first = 0;
	last = 0;
	i = 0;
	while (map[last])
		last++;
	while (map[first][i] && map[first][i] != '\n')
	{
		if (map[first][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	last--;
	while (map[last][i] && map[last][i] != '\n')
	{
		if (map[last][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_for_invalid_chr(char **map)
{
	int		i;
	int		j;
	char	*str_test ;

	i = 0;
	j = 0;
	str_test = "10PCE";
	while (map[i])
	{
		while (map[i][j] && map[i][j] != '\n')
		{
			if (ft_strchr(str_test, map[i][j]) == NULL)
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	check_for_valid_map(char **map)
{
	int	i;
	int	j;
	int	k;
	int	test;

	i = 0;
	j = 0;
	k = 0;
	test = 0;
	while (map[i])
	{
		k = l_strlen(map[i]);
		test = 0;
		if ((map[i][0] == '1' && map[i][k - 1] == '1'))
			test = 1;
		i++;
	}
	if (check_for_equal_walls(map) && check_for_duplicate(map))
	{
		if (test && check_for_invalid_chr(map) && check_for_walls(map))
			return (1);
	}
	return (0);
}

int	check_for_equal_walls(char **map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (map[i])
	{
		if (i > 0 && len != l_strlen(map[i]))
			return (0);
		len = l_strlen(map[i]);
		i++;
	}
	return (1);
}

int	check_for_duplicate(char **map)
{
	if (duplicate(map, 'P') || duplicate(map, 'E'))
		return (0);
	return (1);
}
