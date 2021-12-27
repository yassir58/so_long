/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelatman <yelatman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 09:23:39 by yelatman          #+#    #+#             */
/*   Updated: 2021/12/27 13:58:00 by yelatman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	**extract_map(char *file_name)
{
	int		i;
	char	*line;
	char	**map;
	int		fd;

	line = NULL;
	i = 0;
	map = (char **)malloc(10000 * sizeof(char *));
	if (!map)
		return (NULL);
	fd = open(file_name, O_RDONLY);
	line = get_next_line (fd);
	while (line)
	{
		map[i++] = line;
		line = get_next_line (fd);
	}
	map[i] = NULL;
	return (map);
}

void	process_map(char **map, int *ln, int *en)
{
	int	line_number;
	int	elem_number;

	line_number = 0;
	line_number = 0;
	if (map)
	{
		while (map[line_number])
			line_number++;
		*ln = line_number;
		*en = l_strlen(map[0]);
	}
}

void	draw_map(t_data *data)
{
	t_vars	vars;

	vars.x = 0;
	vars.y = 0;
	vars.j = 0;
	vars.i = 0;
	while (data->map_tab[vars.i])
	{
		while (data->map_tab[vars.i][vars.j])
		{
			display_image(data, vars);
			vars.x += ELM_WIDTH;
			vars.j++;
		}
		vars.y += ELM_WIDTH;
		vars.j = 0;
		vars.x = 0;
		vars.i++;
	}
}

void	get_element_position(char **map, int *i, int *j, char c)
{
	int	in;
	int	jn;

	in = 0;
	jn = 0;
	while (map[in])
	{
		while (map[in][jn])
		{
			if (map[in][jn] == c)
			{
				*i = in;
				*j = jn;
			}
			jn++;
		}
		jn = 0;
		in++;
	}
}

int	coin_count(char **map)
{
	int	i;
	int	j;
	int	coin_count;

	i = 0;
	j = 0;
	coin_count = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				coin_count++;
			j++;
		}
		j = 0;
		i++;
	}
	return (coin_count);
}
