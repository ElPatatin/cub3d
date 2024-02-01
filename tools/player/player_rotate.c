/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 11:32:34 by ogonzale          #+#    #+#             */
/*   Updated: 2023/06/17 11:52:33 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_data.h"
#include "cub3d_errors.h"
#include "cub3d_player.h"

static void	rotate_left(t_game *game, double rotate_speed);
static void	rotate_right(t_game *game, double rotate_speed);

void	handle_player_rotation(t_game *game)
{
	double	rotate_speed;

	if (game->player.mouse_rotate)
		rotate_speed = 2 * ROT_SPEED * game->player.normalized_rotate_speed;
	else
		rotate_speed = ROT_SPEED;
	if (game->player.rotate_left)
		rotate_left(game, rotate_speed);
	if (game->player.rotate_right)
		rotate_right(game, rotate_speed);
}

static void	rotate_left(t_game *game, double rotate_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(rotate_speed)
		- game->player.dir_y * sin(rotate_speed);
	game->player.dir_y = old_dir_x * sin(rotate_speed)
		+ game->player.dir_y * cos(rotate_speed);
	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(rotate_speed)
		- game->player.plane_y * sin(rotate_speed);
	game->player.plane_y = old_plane_x * sin(rotate_speed)
		+ game->player.plane_y * cos(rotate_speed);
}

static void	rotate_right(t_game *game, double rotate_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(-rotate_speed)
		- game->player.dir_y * sin(-rotate_speed);
	game->player.dir_y = old_dir_x * sin(-rotate_speed)
		+ game->player.dir_y * cos(-rotate_speed);
	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(-rotate_speed)
		- game->player.plane_y * sin(-rotate_speed);
	game->player.plane_y = old_plane_x * sin(-rotate_speed)
		+ game->player.plane_y * cos(-rotate_speed);
}
