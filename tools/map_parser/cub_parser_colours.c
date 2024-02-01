/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser_colours.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:18:42 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/01/30 18:31:14 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_data.h"
#include "cub3d_map.h"
#include "cub3d_parser.h"
#include "cub3d_errors.h"

static void	erase_content(char **line);

/**
 * @brief Loads the floor color from the map.
 * 
 * @param map The map struct.
 * @return void
 */
void	load_floor_colour(t_map *map)
{
	ssize_t	idx;
	t_bool	dup_colour;

	idx = -1;
	dup_colour = FALSE;
	while (map->map[++idx])
	{
		if (dup_colour)
			terminate_error(ERR_DUP_CLR, SYS_DUP_CLR);
		if (map->map[idx][0] == 'F')
		{
			parse_colour(map->map[idx], &map->floor_colour, 'F');
			erase_content(&map->map[idx]);
			dup_colour = TRUE;
			return ;
		}
	}
}

/**
 * @brief Loads the ceiling color from the map.
 * 
 * @param map The map struct.
 * @return void
 */
void	load_cealing_colour(t_map *map)
{
	ssize_t	idx;
	t_bool	dup_colour;

	idx = -1;
	dup_colour = FALSE;
	while (map->map[++idx])
	{
		if (dup_colour)
			terminate_error(ERR_DUP_CLR, SYS_DUP_CLR);
		if (map->map[idx][0] == 'C')
		{
			parse_colour(map->map[idx], &map->ceiling_colour, 'C');
			erase_content(&map->map[idx]);
			dup_colour = TRUE;
			return ;
		}
	}
}

/**
 * @brief Parses the color from the map.
 * 
 * @param line The line from the map.
 * @param color The color struct.
 * @param letter The letter of the color.
 * @return void
 */
void	parse_colour(char *line, int *colour, char letter)
{
	int	r;
	int	g;
	int	b;

	++line;
	while (*line && ft_isspace(*line))
		++line;
	check_valid_number(&r, line);
	while (*line && ft_isdigit(*line))
		++line;
	++line;
	check_valid_number(&g, line);
	while (*line && ft_isdigit(*line))
		++line;
	++line;
	check_valid_number(&b, line);
	if (letter == *FLOOR)
		(*colour) = (r << 16) | (g << 8) | b;
	else if (letter == *CEALING)
		(*colour) = (r << 16) | (g << 8) | b;
}

/**
 * @brief Deletes the content of the line.
 * 
 * @param line The line from the map.
 * @return void
 */
static void	erase_content(char **line)
{
	ft_delete(*line);
	*line = ft_strdup("");
	if (!*line)
		terminate_error(ERR_MEM, SYS_MEM);
}

t_bool	validate_colours(t_map *map)
{
	if (map->floor_colour == -1)
		return (FALSE);
	if (map->ceiling_colour == -1)
		return (FALSE);
	return (TRUE);
}
