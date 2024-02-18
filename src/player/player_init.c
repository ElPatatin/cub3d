/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:21:53 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/19 00:29:22 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_player.h"
#include "cub3d_parser.h"

static void	player_moves_init(t_graphics *graphics);
static void	player_dir_init(t_graphics *graphics, ssize_t i, ssize_t j);
static void	player_plane_init(t_graphics *graphics, ssize_t i, ssize_t j);

void	player_init(t_graphics *graphics)
{
	ssize_t	i;
	ssize_t	j;
	ssize_t	k;

	i = -1;
	player_moves_init(graphics);
	k = ft_strcount(graphics->info->map);
	while (++i < k)
	{
		j = -1;
		while (++j < (ssize_t)ft_strlen(graphics->info->map[i]))
		{
			if (ft_strchr("NEWS", graphics->info->map[i][j]))
			{
				graphics->player.pos_x = i + 0.5f;
				graphics->player.pos_y = j + 0.5f;
				player_dir_init(graphics, i, j);
				player_plane_init(graphics, i, j);
				return ;
			}
		}
	}
}

static void	player_moves_init(t_graphics *graphics)
{
	graphics->player.move_up = 0;
	graphics->player.move_down = 0;
	graphics->player.move_left = 0;
	graphics->player.move_right = 0;
	graphics->player.rotate_left = 0;
	graphics->player.rotate_right = 0;
	graphics->player.mouse_rotate = 0;
	graphics->player.rotate_speed = 0;
}

static void	player_dir_init(t_graphics *graphics, ssize_t i, ssize_t j)
{
	graphics->player.dir_x = 0;
	graphics->player.dir_y = 0;
	if (graphics->info->map[i][j] == P_SO)
		graphics->player.dir_x = 1;
	else if (graphics->info->map[i][j] == P_EA)
		graphics->player.dir_y = 1;
	else if (graphics->info->map[i][j] == P_WE)
		graphics->player.dir_y = -1;
	else if (graphics->info->map[i][j] == P_NO)
		graphics->player.dir_x = -1;
}

static void	player_plane_init(t_graphics *graphics, ssize_t i, ssize_t j)
{
	graphics->player.plane_x = 0;
	graphics->player.plane_y = 0;
	if (graphics->info->map[i][j] == P_SO)
		graphics->player.plane_y = -0.77f;
	else if (graphics->info->map[i][j] == P_EA)
		graphics->player.plane_x = 0.77f;
	else if (graphics->info->map[i][j] == P_WE)
		graphics->player.plane_x = -0.77f;
	else if (graphics->info->map[i][j] == P_NO)
		graphics->player.plane_y = 0.77f;
}
