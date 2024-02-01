/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 10:22:26 by ogonzale          #+#    #+#             */
/*   Updated: 2023/05/21 10:57:33 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_data.h"
#include "cub3d_errors.h"
#include "cub3d_ray.h"

void	calc_ray_pos_dir(t_game *game, int x)
/**
 * Calculate ray position and direction
*/
{
	float	camera_x;

	camera_x = 2 * x / (float)WINWIDTH - 1;
	game->ray.dir_x = game->player.dir_x + game->player.plane_x * camera_x;
	game->ray.dir_y = game->player.dir_y + game->player.plane_y * camera_x;
	game->ray.map_x = (int)game->player.x;
	game->ray.map_y = (int)game->player.y;
}

void	calc_ray_delta_dist(t_game *game)
/**
 * Calculate ray delta distance: length of ray from current position
 * to next x or y-side
 */
{
	if (game->ray.dir_x == 0)
		game->ray.delta_dist_x = 1E30;
	else
		game->ray.delta_dist_x = fabs(1 / game->ray.dir_x);
	if (game->ray.dir_y == 0)
		game->ray.delta_dist_y = 1E30;
	else
		game->ray.delta_dist_y = fabs(1 / game->ray.dir_y);
}

void	calc_ray_step_and_side_dist(t_game *game)
/**
 * Calculate ray step and side distance
*/
{
	if (game->ray.dir_x < 0)
	{
		game->ray.step_x = -1;
		game->ray.side_dist_x = (game->player.x - game->ray.map_x)
			* game->ray.delta_dist_x;
	}
	else
	{
		game->ray.step_x = 1;
		game->ray.side_dist_x = (game->ray.map_x + 1.0 - game->player.x)
			* game->ray.delta_dist_x;
	}
	if (game->ray.dir_y < 0)
	{
		game->ray.step_y = -1;
		game->ray.side_dist_y = (game->player.y - game->ray.map_y)
			* game->ray.delta_dist_y;
	}
	else
	{
		game->ray.step_y = 1;
		game->ray.side_dist_y = (game->ray.map_y + 1.0 - game->player.y)
			* game->ray.delta_dist_y;
	}
}
