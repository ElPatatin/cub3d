/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_dda.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:03:33 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/15 17:42:26 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"
#include "cub3d_basic_utils.h"

/**
 * @brief This function performs the DDA algorithm
 * 
 * @param g (t_graphics *) - The graphics structure
 * 
 * @retval None
 * 
 * @note
 * DDA (Digital Differential Analysis) is a simple algorithm to calculate
 * the distance of the ray to the wall.
 * 
 * This function performs the DDA algorithm. It is a loop that increments the
 * ray with 1 square every time, until a wall is hit. Each time, either it
 * jumps a square in the x-direction (with stepX) or a square in the
 * y-direction (with stepY), it always jumps 1 square at once.
 * If the ray's direction would be the x-direction, the loop will only have to
 * jump a square in the x-direction everytime, because the ray will never
 * change its y-direction. If the ray is a bit sloped to the y-direction,
 * then every so many jumps in the x-direction, the ray will have to jump one
 * square in the y-direction. If the ray is exactly the y-direction, it never
 * has to jump in the x-direction, etc...
 * 
 * When the ray has hit a wall, the loop ends, and then we'll know whether
 * an x-side or y-side of a wall was hit in the variable "side",
 * and what wall was hit with mapX and mapY. We won't know exactly
 * where the wall was hit however, but that's not needed in this case because
 * we won't use textured walls for now.
*/
void	perfome_dda(t_graphics *g)
{
	g->ray.hit = FALSE;
	while (g->ray.hit == FALSE)
	{
		if (g->ray.side_dist_x < g->ray.side_dist_y)
		{
			g->ray.side_dist_x += g->ray.delta_dist_x;
			g->ray.map_x += g->ray.step_x;
			g->ray.side = 0;
		}
		else
		{
			g->ray.side_dist_y += g->ray.delta_dist_y;
			g->ray.map_y += g->ray.step_y;
			g->ray.side = 1;
		}
		if (g->info->map[g->ray.map_x][g->ray.map_y] == '1')
			g->ray.hit = TRUE;
	}
}
