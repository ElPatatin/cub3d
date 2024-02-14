/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:52:00 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/14 17:21:11 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_player.h"

static void	move_forward(t_graphics *graphics);
static void	move_backward(t_graphics *graphics);
static void	move_left(t_graphics *graphics);
static void	move_right(t_graphics *graphics);

void	handle_player_movement(t_graphics *graphics)
{
	if (graphics->player.move_up)
		move_forward(graphics);
	if (graphics->player.move_down)
		move_backward(graphics);
	if (graphics->player.move_left)
		move_left(graphics);
	if (graphics->player.move_right)
		move_right(graphics);
}

static void	move_forward(t_graphics *graphics)
{
	if (graphics->info->map[(int)(graphics->player.pos_x + graphics->player.dir_x * MOVE_SPEED)]
		[(int)graphics->player.pos_y] != '1')
	{
		graphics->player.pos_x += graphics->player.dir_x * MOVE_SPEED;
	}
	if (graphics->info->map[(int)graphics->player.pos_x]
		[(int)(graphics->player.pos_y + graphics->player.dir_y * MOVE_SPEED)] != '1')
	{
		graphics->player.pos_y += graphics->player.dir_y * MOVE_SPEED;
	}
}

static void	move_backward(t_graphics *graphics)
{
	if (graphics->info->map[(int)(graphics->player.pos_x - graphics->player.dir_x * MOVE_SPEED)]
		[(int)graphics->player.pos_y] != '1')
	{
		graphics->player.pos_x -= graphics->player.dir_x * MOVE_SPEED;
	}
	if (graphics->info->map[(int)graphics->player.pos_x]
		[(int)(graphics->player.pos_y - graphics->player.dir_y * MOVE_SPEED)] != '1')
	{
		graphics->player.pos_y -= graphics->player.dir_y * MOVE_SPEED;
	}
}

static void	move_left(t_graphics *graphics)
{
	if (graphics->info->map[(int)(graphics->player.pos_x - graphics->player.dir_y * MOVE_SPEED)]
		[(int)graphics->player.pos_y] != '1')
	{
		graphics->player.pos_x -= graphics->player.dir_y * MOVE_SPEED;
	}
	if (graphics->info->map[(int)graphics->player.pos_x]
		[(int)(graphics->player.pos_y + graphics->player.dir_x * MOVE_SPEED)] != '1')
	{
		graphics->player.pos_y += graphics->player.dir_x * MOVE_SPEED;
	}
}

static void	move_right(t_graphics *graphics)
{
	if (graphics->info->map[(int)(graphics->player.pos_x + graphics->player.dir_y * MOVE_SPEED)]
		[(int)graphics->player.pos_y] != '1')
	{
		graphics->player.pos_x += graphics->player.dir_y * MOVE_SPEED;
	}
	if (graphics->info->map[(int)graphics->player.pos_x]
		[(int)(graphics->player.pos_y - graphics->player.dir_x * MOVE_SPEED)] != '1')
	{	
		graphics->player.pos_y -= graphics->player.dir_x * MOVE_SPEED;
	}
}