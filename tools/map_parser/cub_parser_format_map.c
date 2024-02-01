/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser_format_map.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:31:07 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/06/09 18:55:09 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_map.h"
#include "cub3d_data.h"
#include "cub3d_parser.h"
#include "cub3d_errors.h"

static int	contains_numbers(const char *str);
static void	set_numbers(t_map *map, size_t *head_idx,
				size_t *tail_idx, size_t *new_height);

void	format_map(t_map *map)
{
	ssize_t	idx;
	size_t	head_idx;
	size_t	tail_idx;
	size_t	new_height;
	char	**new_grid;

	map->height = ft_strcount(map->grid);
	set_numbers(map, &head_idx, &tail_idx, &new_height);
	new_grid = (char **)ft_calloc((new_height + 1), sizeof(char *));
	if (!new_grid)
		terminate_error(ERR_MEM, SYS_MEM);
	idx = -1;
	while (++idx < (ssize_t)new_height)
	{
		new_grid[idx] = ft_strdup(map->grid[head_idx + idx]);
		if (!new_grid[idx])
			terminate_error(ERR_MEM, SYS_MEM);
	}
	map->height = new_height;
	map->width = ft_strlen(new_grid[0]);
	ft_memfree(map->grid);
	map->grid = new_grid;
}

static void	set_numbers(t_map *map, size_t *head_idx,
	size_t *tail_idx, size_t *new_height)
{
	*head_idx = 0;
	while (*head_idx < map->height
		&& !contains_numbers(map->grid[*head_idx + 1]))
		++(*head_idx);
	*tail_idx = map->height - 1;
	while (*tail_idx > *head_idx
		&& !contains_numbers(map->grid[*tail_idx - 1]))
		--(*tail_idx);
	*new_height = *tail_idx - *head_idx + 1;
}

static int	contains_numbers(const char *str)
{
	while (*str)
	{
		if (ft_isdigit(*str))
			return (TRUE);
		str++;
	}
	return (FALSE);
}
