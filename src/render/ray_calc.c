/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:03:24 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/18 16:18:53 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"
#include "cub3d_basic_utils.h"

/**
 * @brief This function calculates the position of the ray
 * 
 * @param g (t_graphics *) - The graphics structure
 * @param x (int) - The x position of the ray
 * 
 * @retval None
 * 
 * @note
 * This functions the ray position. The ray starts at the player position.
 * Camera_x is the x-coordinate on the camera plane that the current
 * x-coordinate of the screen represents, done this way so that the right
 * side of the screen will get coordinate 1, the center of the screen gets
 * coordinate 0, and the left side of the screen gets coordinate -1.
 * Out of this, the direction of the ray can be calculated as was
 * explained earlier: as the sum of the direction vector, and a part of the
 * plane vector.
 * This has to be done both for the x and y coordinate of the vector
 * (since adding two vectors is adding their x-coordinates,
 * and adding their y-coordinates).
 * 
 * the players plain is the 2D raycaster version of the camera plane.
*/
void	calculate_ray_position(t_graphics *g, int x)
{
	float	camera_x;

	camera_x = (x << 1) / (float)WINWIDTH - 1;
	g->ray.dir_x = g->player.dir_x + g->player.plane_x * camera_x;
	g->ray.dir_y = g->player.dir_y + g->player.plane_y * camera_x;
}

/**
 * @brief This function calculates the map position
 * 
 * @param g (t_graphics *) - The graphics structure
 * 
 * @retval None
 * 
 * @note
 * This function calculates the map position. The map represent the current
 * square of the map the ray is in.
*/
void	calculate_map_position(t_graphics *g)
{
	g->ray.map_x = (int)g->player.pos_x;
	g->ray.map_y = (int)g->player.pos_y;
}

/**
 * @brief This function calculates the length of the ray
 * 
 * @param g (t_graphics *) - The graphics structure
 * 
 * @retval None
 * 
 * @note
 * delta_dist_x and delta_dist_y are the distance the ray has to travel go
 * from 1 x-side to the next x-side, or from 1 y-side to the next y-side.
 * 
 * This function calculates the length of the ray. The length of the ray is
 * calculated using the Pythagorean theorem:
 * 	deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX))
 * 	deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY))
 * But this can be optimized to:
 *  deltaDistX = abs(|rayDir| / rayDirX)
 * 	deltaDistY = abs(|rayDir| / rayDirY)
 * 
 * Where |rayDir| is the length of the vector rayDirX, rayDirY (that is 
 * sqrt(rayDirX * rayDirX + rayDirY * rayDirY)): you can indeed verify that 
 * e.g. sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX)) equals 
 * abs(sqrt(rayDirX * rayDirX + rayDirY * rayDirY) / rayDirX). 
 * However, we can use 1 instead of |rayDir|, because only the *ratio* between
 * deltaDistX and deltaDistY matters for the DDA code that follows later below,
 * so we get: 
 * 	deltaDistX = abs(1 / rayDirX)
 * 	deltaDistY = abs(1 / rayDirY)
 * 
 * If rayDirX or rayDirY are 0, the division through zero is avoided by
 * setting it to a very high value 1e30.
*/
void	calculate_length_of_ray(t_graphics *g)
{
	if (g->ray.dir_y == 0)
		g->ray.delta_dist_x = 1E30;
	else
		g->ray.delta_dist_x = fabs(1 / g->ray.dir_x);
	if (g->ray.dir_x == 0)
		g->ray.delta_dist_y = 1E30;
	else
		g->ray.delta_dist_y = fabs(1 / g->ray.dir_y);
}

/**
 * @brief This function calculates the step and initial side distance
 * 
 * @param g (t_graphics *) - The graphics structure
 * 
 * @retval None
 * 
 * @note
 * side_dist_x and side_dist_y are the distance the ray has to travel to travel
 * from its starting position to the first x-side and the first y-side.
 * 
 * Now, before the actual DDA can start, first stepX, stepY, and the initial
 * sideDistX and sideDistY still have to be calculated.
 * 
 * This function calculates the step and initial side distance.
 * 
 * If the ray direction has a negative x-component, stepX is -1, if the ray
 * direciton has a positive x-component it's +1. If the x-component is 0,
 * it doesn't matter what value stepX has since it'll then be unused.
 * The same goes for the y-component.
 * 
 * If the ray direction has a negative x-component, sideDistX is the distance
 * from the ray starting position to the first side to the left,
 * if the ray direciton has a positive x-component the first side to the right
 * is used instead.
 * The same goes for the y-component, but now with the first side above or
 * below the position.
*/
void	calculate_step_and_initial_side_dist(t_graphics *g)
{
	if (g->ray.dir_x < 0)
	{
		g->ray.step_x = -1;
		g->ray.side_dist_x = (g->player.pos_x - g->ray.map_x) \
			* g->ray.delta_dist_x;
	}
	else
	{
		g->ray.step_x = 1;
		g->ray.side_dist_x = (g->ray.map_x + 1.0 - g->player.pos_x) \
			* g->ray.delta_dist_x;
	}
	if (g->ray.dir_y < 0)
	{
		g->ray.step_y = -1;
		g->ray.side_dist_y = (g->player.pos_y - g->ray.map_y) \
			* g->ray.delta_dist_y;
	}
	else
	{
		g->ray.step_y = 1;
		g->ray.side_dist_y = (g->ray.map_y + 1.0 - g->player.pos_y) \
			* g->ray.delta_dist_y;
	}
}

/**
 * @brief This function calculates the distance projected on camera direction
 * 
 * @param g (t_graphics *) - The graphics structure
 * 
 * @retval None
 * 
 * @note
 * After the DDA has been performed, we nned to calculate the distance of the
 * ray to the wall, so that we can calculate the height of the line that has
 * to be drawn on the screen.
*/
void	calculate_distance_projected(t_graphics *g)
{
	if (g->ray.side == 0)
		g->ray.distance = (g->ray.map_x - g->player.pos_x \
			+ (1 - g->ray.step_x) / 2) / g->ray.dir_x;
	else
		g->ray.distance = (g->ray.map_y - g->player.pos_y \
			+ (1 - g->ray.step_y) / 2) / g->ray.dir_y;
}
