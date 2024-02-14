/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:08:47 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/14 17:21:18 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_player.h"


static void	rotate_left(t_graphics *graphics, double rotate_speed);
static void	rotate_right(t_graphics *graphics, double rotate_speed);

void	handle_player_rotation(t_graphics *graphics)
{
	double	rotate_speed;

	// if (graphics->player.mouse_rotate)
	// 	rotate_speed = 2 * ROT_SPEED * graphics->player.normalized_rotate_speed;
	// else
	rotate_speed = ROT_SPEED;
	if (graphics->player.rotate_left)
		rotate_left(graphics, rotate_speed);
	if (graphics->player.rotate_right)
		rotate_right(graphics, rotate_speed);
}

static void	rotate_left(t_graphics *graphics, double rotate_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = graphics->player.dir_x;
	graphics->player.dir_x = graphics->player.dir_x * cos(rotate_speed)
		- graphics->player.dir_y * sin(rotate_speed);
	graphics->player.dir_y = old_dir_x * sin(rotate_speed)
		+ graphics->player.dir_y * cos(rotate_speed);
	old_plane_x = graphics->player.plane_x;
	graphics->player.plane_x = graphics->player.plane_x * cos(rotate_speed)
		- graphics->player.plane_y * sin(rotate_speed);
	graphics->player.plane_y = old_plane_x * sin(rotate_speed)
		+ graphics->player.plane_y * cos(rotate_speed);
}

static void	rotate_right(t_graphics *graphics, double rotate_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = graphics->player.dir_x;
	graphics->player.dir_x = graphics->player.dir_x * cos(-rotate_speed)
		- graphics->player.dir_y * sin(-rotate_speed);
	graphics->player.dir_y = old_dir_x * sin(-rotate_speed)
		+ graphics->player.dir_y * cos(-rotate_speed);
	old_plane_x = graphics->player.plane_x;
	graphics->player.plane_x = graphics->player.plane_x * cos(-rotate_speed)
		- graphics->player.plane_y * sin(-rotate_speed);
	graphics->player.plane_y = old_plane_x * sin(-rotate_speed)
		+ graphics->player.plane_y * cos(-rotate_speed);
}
