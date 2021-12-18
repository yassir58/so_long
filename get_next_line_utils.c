/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelatman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:40:52 by yelatman          #+#    #+#             */
/*   Updated: 2021/12/16 18:35:44 by yelatman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	*ft_strndup(const char *str, int len)
{
	char	*new_str;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	new_str = (char *)malloc((len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	while (str[i] && i < len)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}



char	*extract_line(char **buffer, char **backup, char **line_return)
{
	char	*line;

	line = NULL;
	if (!(*backup))
		*backup = ft_strndup("", 0);
	*buffer = ft_strjoin(*backup, *buffer);
	line = try_get_line(*buffer);
	*line_return = line;
	*backup = get_rest_backup(*buffer);
	return (line);
}

