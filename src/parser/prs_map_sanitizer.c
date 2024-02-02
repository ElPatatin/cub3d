/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_map_sanitizer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:35:59 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/02 21:14:51 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d_struct.h"
#include "cub3d_parser.h"
#include "cub3d_parser_private.h"

static void	built_valid_chars(char *valid_chars, int *nullable);

t_bool	map_sanitizer(t_info *info, size_t width, size_t height)
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
			if (!ft_strchr(valid_chars, info->map[y][x]))
				return (TRUE);
			if (ft_strchr("NSEW", info->map[y][x]))
				player_count++;
			if (player_count > 1)
				return (TRUE);
			x++;
		}
		y++;
	}
	return (FALSE);
}

static void	built_valid_chars(char *valid_chars, int *nullable)
{
	valid_chars[0] = WALL;
	valid_chars[1] = MPTY;
	valid_chars[2] = P_NO;
	valid_chars[3] = P_SO;
	valid_chars[4] = P_WE;
	valid_chars[5] = P_EA;
	valid_chars[6] = VOID;
	valid_chars[7] = '\0';
	if (nullable)
		*nullable = 0;
}
