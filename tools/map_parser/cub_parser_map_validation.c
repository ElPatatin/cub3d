/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser_map_validation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:35:36 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/01 16:06:34 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_data.h"
#include "cub3d_parser.h"
#include "cub3d_map.h"
#include "cub3d_errors.h"

static t_bool	check_void_surroundings(char **grid,
					size_t width, size_t height);
static t_bool	is_surrounded_by_void_or_wall(char **grid, size_t x, size_t y);
static t_bool	check_map_characters(char **grid, size_t width, size_t height);

t_bool	validate_map(t_map *map)
{
	if (!check_void_surroundings(map->grid, map->width, map->height))
		return (FALSE);
	if (!check_map_characters(map->grid, map->width, map->height))
		return (FALSE);
	return (TRUE);
}

static t_bool	check_void_surroundings(char **grid,
	size_t width, size_t height)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (grid[y][x] != 'V')
			{
				++x;
				continue ;
			}
			if (!is_surrounded_by_void_or_wall(grid, x, y))
				return (FALSE);
			++x;
		}
		++y;
	}
	return (TRUE);
}

static t_bool	is_surrounded_by_void_or_wall(char **grid, size_t x, size_t y)
{
	const int	dx[] = {0, 0, 1, -1};
	const int	dy[] = {1, -1, 0, 0};
	size_t		idx;
	size_t		nx;
	size_t		ny;

	idx = 0;
	while (idx < 4)
	{
		nx = x + dx[idx];
		ny = y + dy[idx];
		if (nx < ft_strlen(*grid) && ny < ft_strcount(grid))
		{
			if (grid[ny][nx] != 'V' && grid[ny][nx] != '1')
				return (FALSE);
		}
		++idx;
	}
	return (TRUE);
}

static t_bool	check_map_characters(char **grid, size_t width, size_t height)
{
	size_t	x;
	size_t	y;
	int		player_count;
	char	valid_chars[8];

	built_valid_chars(valid_chars, &player_count);
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (!ft_strchr(valid_chars, grid[y][x]))
				return (FALSE);
			if (ft_strchr("NSEW", grid[y][x]))
				player_count++;
			if (player_count > 1)
				return (FALSE);
			x++;
		}
		y++;
	}
	return (TRUE);
}
