/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_map_validator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:37:05 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/18 18:30:38 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d_struct.h"
#include "cub3d_parser_private.h"

// ===============================PROTOTYPES===================================
static t_bool	is_surrounded_by_void_or_wall(t_info *info,
					size_t x, size_t y);
// ============================================================================

t_bool	map_validator(t_info *info, size_t width, size_t height)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (info->map[y][x] != 'V')
			{
				++x;
				continue ;
			}
			if (is_surrounded_by_void_or_wall(info, x, y))
				return (TRUE);
			++x;
		}
		++y;
	}
	return (FALSE);
}

static t_bool	is_surrounded_by_void_or_wall(t_info *info, size_t x, size_t y)
{
	const int	dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
	const int	dy[] = {1, -1, 0, 0, 1, -1, -1, 1};
	size_t		idx;
	size_t		nx;
	size_t		ny;

	idx = 0;
	while (idx < 8)
	{
		nx = x + dx[idx];
		ny = y + dy[idx];
		if (nx < ft_strlen(*info->map) && ny < ft_strcount(info->map))
		{
			if (info->map[ny][nx] != 'V' && info->map[ny][nx] != '1')
				return (TRUE);
		}
		++idx;
	}
	return (FALSE);
}

void	flip_map(t_info *info, size_t height)
{
	size_t	y;

	y = -1;
	while (++y < (height >> 1))
	{
		ft_swap((int *)&info->map[y], (int *)&info->map[height - y - 1]);
	}
	y = -1;
	while (++y < height)
	{
		printf("%s\n", info->map[y]);
	}
}
