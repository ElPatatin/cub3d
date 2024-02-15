/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:08:47 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/15 16:20:05 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_player.h"

static void	rotate_left(t_graphics *g, double rotate_speed);
static void	rotate_right(t_graphics *g, double rotate_speed);

void	handle_player_rotation(t_graphics *g)
{
	double	rotate_speed;

	// if (g->player.mouse_rotate)
	// 	rotate_speed = 2 * ROT_SPEED * g->player.normalized_rotate_speed;
	// else
	rotate_speed = ROT_SPEED;
	if (g->player.rotate_left)
		rotate_left(g, rotate_speed);
	if (g->player.rotate_right)
		rotate_right(g, rotate_speed);
}

static void	rotate_left(t_graphics *g, double rotate_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = g->player.dir_x;
	g->player.dir_x = g->player.dir_x * cos(rotate_speed)
		- g->player.dir_y * sin(rotate_speed);
	g->player.dir_y = old_dir_x * sin(rotate_speed)
		+ g->player.dir_y * cos(rotate_speed);
	old_plane_x = g->player.plane_x;
	g->player.plane_x = g->player.plane_x * cos(rotate_speed)
		- g->player.plane_y * sin(rotate_speed);
	g->player.plane_y = old_plane_x * sin(rotate_speed)
		+ g->player.plane_y * cos(rotate_speed);
}

static void	rotate_right(t_graphics *g, double rotate_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = g->player.dir_x;
	g->player.dir_x = g->player.dir_x * cos(-rotate_speed)
		- g->player.dir_y * sin(-rotate_speed);
	g->player.dir_y = old_dir_x * sin(-rotate_speed)
		+ g->player.dir_y * cos(-rotate_speed);
	old_plane_x = g->player.plane_x;
	g->player.plane_x = g->player.plane_x * cos(-rotate_speed)
		- g->player.plane_y * sin(-rotate_speed);
	g->player.plane_y = old_plane_x * sin(-rotate_speed)
		+ g->player.plane_y * cos(-rotate_speed);
}
