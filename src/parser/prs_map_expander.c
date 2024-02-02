/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_map_expander.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:43:21 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/02 20:40:26 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d_struct.h"
#include "cub3d_parser.h"
#include "cub3d_parser_private.h"

static void	copy_raw_to_map(char **raw_info,
				t_raw_map_data raw_map_data, t_info *info);
static void	replace_spaces_with_void(t_info *info, size_t width, size_t height);

int	map_expander(char **raw_info, t_raw_map_data raw_map_data, t_info *info)
{
	copy_raw_to_map(raw_info, raw_map_data, info);
	replace_spaces_with_void(info, raw_map_data.width, raw_map_data.height);
	return (0);
}

static void	copy_raw_to_map(char **raw_info,
	t_raw_map_data raw_map_data, t_info *info)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < raw_map_data.width)
	{
		info->map[0][i] = ' ';
		info->map[raw_map_data.height - 1][i] = ' ';
	}
	i = -1;
	while (++i < raw_map_data.height
		&& raw_info[raw_map_data.map_start + i] != NULL)
	{
		j = -1;
		info->map[i + 1][0] = ' ';
		while (raw_info[raw_map_data.map_start + i][++j])
			info->map[i + 1][j + 1] = raw_info[raw_map_data.map_start + i][j];
		while (++j < raw_map_data.width)
			info->map[i + 1][j] = ' ';
	}
}

static void	replace_spaces_with_void(t_info *info, size_t width, size_t height)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
		{
			if (info->map[i][j] == ' ')
				info->map[i][j] = VOID;
		}
	}
}
