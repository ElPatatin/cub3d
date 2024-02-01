/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:16:09 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/06/17 11:58:20 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_data.h"
#include "cub3d_errors.h"
#include "cub3d_parser.h"

static void	init_player_move_rotate(t_game *game);
static void	init_player_dir(t_game *game, int i, int j);
static void	init_player_plane(t_game *game, int i, int j);

void	init_player(t_game *game)
{
	size_t	i;
	size_t	j;

	i = -1;
	init_player_move_rotate(game);
	while (++i < game->map.height)
	{
		j = -1;
		while (++j < game->map.width)
		{
			if (ft_strchr("NEWS", game->map.grid[i][j]))
			{
				game->player.x = i;
				game->player.y = j;
				init_player_dir(game, i, j);
				init_player_plane(game, i, j);
				return ;
			}
		}
	}
}

static void	init_player_move_rotate(t_game *game)
{
	game->player.move_up = 0;
	game->player.move_down = 0;
	game->player.move_left = 0;
	game->player.move_right = 0;
	game->player.rotate_left = 0;
	game->player.rotate_right = 0;
	game->player.mouse_rotate = 0;
	game->player.normalized_rotate_speed = 0;
}

static void	init_player_dir(t_game *game, int i, int j)
{
	if (game->map.grid[i][j] == P_NO)
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
	}
	else if (game->map.grid[i][j] == P_EA)
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
	}
	else if (game->map.grid[i][j] == P_WE)
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
	}
	else if (game->map.grid[i][j] == P_SO)
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
	}
}

static void	init_player_plane(t_game *game, int i, int j)
{
	if (game->map.grid[i][j] == P_NO)
	{
		game->player.plane_x = 0;
		game->player.plane_y = 0.66;
	}
	else if (game->map.grid[i][j] == P_EA)
	{
		game->player.plane_x = 0.66;
		game->player.plane_y = 0;
	}
	else if (game->map.grid[i][j] == P_WE)
	{
		game->player.plane_x = -0.66;
		game->player.plane_y = 0;
	}
	else if (game->map.grid[i][j] == P_SO)
	{
		game->player.plane_x = 0;
		game->player.plane_y = -0.66;
	}
}
