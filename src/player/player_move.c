/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:52:00 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/15 16:15:15 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_player.h"

static void	move_forward(t_graphics *g);
static void	move_backward(t_graphics *g);
static void	move_left(t_graphics *g);
static void	move_right(t_graphics *g);

void	handle_player_movement(t_graphics *g)
{
	if (g->player.move_up)
		move_forward(g);
	if (g->player.move_down)
		move_backward(g);
	if (g->player.move_left)
		move_left(g);
	if (g->player.move_right)
		move_right(g);
}

static void	move_forward(t_graphics *g)
{
	if (g->info->map[(int)(g->player.pos_x + g->player.dir_x * MOVE_SPEED)]
		[(int)g->player.pos_y] != '1')
	{
		g->player.pos_x += g->player.dir_x * MOVE_SPEED;
	}
	if (g->info->map[(int)g->player.pos_x]
		[(int)(g->player.pos_y + g->player.dir_y * MOVE_SPEED)] != '1')
	{
		g->player.pos_y += g->player.dir_y * MOVE_SPEED;
	}
}

static void	move_backward(t_graphics *g)
{
	if (g->info->map[(int)(g->player.pos_x - g->player.dir_x * MOVE_SPEED)]
		[(int)g->player.pos_y] != '1')
	{
		g->player.pos_x -= g->player.dir_x * MOVE_SPEED;
	}
	if (g->info->map[(int)g->player.pos_x]
		[(int)(g->player.pos_y - g->player.dir_y * MOVE_SPEED)] != '1')
	{
		g->player.pos_y -= g->player.dir_y * MOVE_SPEED;
	}
}

static void	move_left(t_graphics *g)
{
	if (g->info->map[(int)(g->player.pos_x - g->player.dir_y * MOVE_SPEED)]
		[(int)g->player.pos_y] != '1')
	{
		g->player.pos_x -= g->player.dir_y * MOVE_SPEED;
	}
	if (g->info->map[(int)g->player.pos_x]
		[(int)(g->player.pos_y + g->player.dir_x * MOVE_SPEED)] != '1')
	{
		g->player.pos_y += g->player.dir_x * MOVE_SPEED;
	}
}

static void	move_right(t_graphics *g)
{
	if (g->info->map[(int)(g->player.pos_x + g->player.dir_y * MOVE_SPEED)]
		[(int)g->player.pos_y] != '1')
	{
		g->player.pos_x += g->player.dir_y * MOVE_SPEED;
	}
	if (g->info->map[(int)g->player.pos_x]
		[(int)(g->player.pos_y - g->player.dir_x * MOVE_SPEED)] != '1')
	{
		g->player.pos_y -= g->player.dir_x * MOVE_SPEED;
	}
}
