/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 11:31:35 by ogonzale          #+#    #+#             */
/*   Updated: 2024/02/01 16:18:10 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_data.h"
#include "cub3d_errors.h"
#include "cub3d_player.h"

static void	move_forward(t_game *game);
static void	move_backward(t_game *game);
static void	move_left(t_game *game);
static void	move_right(t_game *game);

void	handle_player_movement(t_game *game)
{
	if (game->player.move_up)
		move_forward(game);
	if (game->player.move_down)
		move_backward(game);
	if (game->player.move_left)
		move_left(game);
	if (game->player.move_right)
		move_right(game);
}

static void	move_forward(t_game *game)
{
	if (game->map.grid[(int)(game->player.x + game->player.dir_x * MOVE_SPEED)]
		[(int)game->player.y] != '1')
	{
		game->player.x += game->player.dir_x * MOVE_SPEED;
	}
	if (game->map.grid[(int)game->player.x]
		[(int)(game->player.y + game->player.dir_y * MOVE_SPEED)] != '1')
	{
		game->player.y += game->player.dir_y * MOVE_SPEED;
	}
}

static void	move_backward(t_game *game)
{
	if (game->map.grid[(int)(game->player.x - game->player.dir_x * MOVE_SPEED)]
		[(int)game->player.y] != '1')
	{
		game->player.x -= game->player.dir_x * MOVE_SPEED;
	}
	if (game->map.grid[(int)game->player.x]
		[(int)(game->player.y - game->player.dir_y * MOVE_SPEED)] != '1')
	{
		game->player.y -= game->player.dir_y * MOVE_SPEED;
	}
}

static void	move_left(t_game *game)
{
	if (game->map.grid[(int)(game->player.x - game->player.dir_y * MOVE_SPEED)]
		[(int)game->player.y] != '1')
	{
		game->player.x -= game->player.dir_y * MOVE_SPEED;
	}
	if (game->map.grid[(int)game->player.x]
		[(int)(game->player.y + game->player.dir_x * MOVE_SPEED)] != '1')
	{
		game->player.y += game->player.dir_x * MOVE_SPEED;
	}
}

static void	move_right(t_game *game)
{
	if (game->map.grid[(int)(game->player.x + game->player.dir_y * MOVE_SPEED)]
		[(int)game->player.y] != '1')
	{
		game->player.x += game->player.dir_y * MOVE_SPEED;
	}
	if (game->map.grid[(int)game->player.x]
		[(int)(game->player.y - game->player.dir_x * MOVE_SPEED)] != '1')
	{	
		game->player.y -= game->player.dir_x * MOVE_SPEED;
	}
}
