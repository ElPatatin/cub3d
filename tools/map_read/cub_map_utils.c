/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:55:49 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/06/09 19:17:09 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_data.h"
#include "cub3d_map.h"
#include "cub3d_parser.h"
#include "cub3d_errors.h"

t_bool	while_isspace(char *str)
{
	ssize_t	idx;

	idx = -1;
	while (str[++idx])
	{
		if (!ft_isspace(str[idx]))
			return (TRUE);
	}
	return (FALSE);
}

t_bool	while_isdigit(char *str)
{
	ssize_t	idx;

	idx = -1;
	while (str[++idx])
	{
		if (!ft_isdigit(str[idx]))
			return (TRUE);
	}
	return (FALSE);
}

void	get_map_length(int fd, int *map_len)
{
	char	*line;

	*map_len = 0;
	while ((get_line(&line, fd)))
	{
		(*map_len)++;
		ft_delete(line);
	}
	ft_delete(line);
}

int	get_line(char **line, int fd)
{
	*line = get_next_line(fd);
	if (!*line)
		return ((intptr_t)ft_delete(*line));
	return (TRUE);
}

void	built_valid_chars(char *valid_chars, int *nullable)
{
	valid_chars[0] = WALL;
	valid_chars[1] = FREE;
	valid_chars[2] = P_NO;
	valid_chars[3] = P_SO;
	valid_chars[4] = P_WE;
	valid_chars[5] = P_EA;
	valid_chars[6] = CLOSE_DOOR;
	valid_chars[7] = OPEN_DOOR;
	valid_chars[8] = VOID;
	valid_chars[9] = '\0';
	if (nullable)
		*nullable = 0;
}
