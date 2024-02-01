/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser_map_expander.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:30:21 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/06/11 17:49:20 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_data.h"
#include "cub3d_map.h"
#include "cub3d_parser.h"
#include "cub3d_errors.h"

static void	adjust_line_lengths(t_map *map, size_t width);
static void	add_padding(t_map *map, size_t width, size_t height);
static void	aux_add_padding(char **new_grid, size_t new_width, size_t idx);

void	map_expander_handler(t_map *map, size_t width)
{
	adjust_line_lengths(map, width);
	add_padding(map, width, ft_strcount(map->grid));
}

static void	adjust_line_lengths(t_map *map, size_t width)
{
	ssize_t	idx;
	size_t	len;
	size_t	count;

	idx = -1;
	while (++idx < (ssize_t)map->length)
	{
		len = ft_strlen(map->grid[idx]);
		map->grid[idx] = (char *)ft_realloc(map->grid[idx],
				(width + 1), sizeof(char));
		if (!map->grid[idx])
			terminate_error(ERR_MEM, SYS_MEM);
		count = len;
		while (count < width)
		{
			map->grid[idx][count] = VOID;
			count++;
		}
	}
}

static void	add_padding(t_map *map, size_t width, size_t height)
{
	size_t	new_width;
	size_t	new_height;
	char	**new_grid;
	size_t	idx;

	new_width = width + 2;
	new_height = height + 2;
	new_grid = (char **)ft_calloc(new_height + 1, sizeof(char *));
	if (!new_grid)
		terminate_error(ERR_MEM, SYS_MEM);
	aux_add_padding(new_grid, new_width, 0);
	idx = 0;
	while (++idx < height)
	{
		new_grid[idx] = (char *)ft_calloc(new_width + 1, sizeof(char));
		if (!new_grid[idx])
			terminate_error(ERR_MEM, SYS_MEM);
		ft_memset(new_grid[idx], VOID, 1);
		ft_memcpy(new_grid[idx] + 1, map->grid[idx], width);
		ft_memset(&new_grid[idx][new_width - 1], VOID, 1);
	}
	aux_add_padding(new_grid, new_width, idx);
	ft_memfree(map->grid);
	map->grid = new_grid;
}

static void	aux_add_padding(char **new_grid, size_t new_width, size_t idx)
{
	new_grid[idx] = (char *)ft_calloc(new_width + 1, sizeof(char));
	if (!new_grid[idx])
		terminate_error(ERR_MEM, SYS_MEM);
	ft_memset(new_grid[idx], VOID, new_width);
}
