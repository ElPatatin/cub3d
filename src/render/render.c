/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:54:01 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/15 17:16:22 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_basic_utils.h"
#include "cub3d_render_private.h"

void	render_game(t_graphics *graphics)
{
	put_background_layer(graphics);
	put_wall_layer(graphics);
	// put_front_layer(graphics);
}

void	put_background_layer(t_graphics *graphics)
{
	int	l;
	int	x;
	int	y;

	y = -1;
	l = WINHEIGHT >> 1;
	while (++y < WINHEIGHT)
	{
		x = -1;
		while (++x < WINWIDTH)
		{
			if (y < l)
				ft_mlx_put_pixel(graphics, x, y, graphics->info->c.argb);
			else
				ft_mlx_put_pixel(graphics, x, y, graphics->info->f.argb);
		}
	}
}

/**
 * @brief This function does the raycasting loop for each column of the screen
 * 
 * @param graphics (t_graphics *) - The graphics structure
 * 
 * @retval None
 * 
 * @note
 * This function is the main function for the raycasting. It loops through each
 * column of the screen and calculates the position of the ray, the map position,
 * the length of the ray, the step and initial side distance, performs the DDA
 * algorithm, calculates the distance projected on camera direction, and draws
 * the line on the screen.
 * 
 * @link https://lodev.org/cgtutor/raycasting.html
*/
void	put_wall_layer(t_graphics *graphics)
{
	ssize_t		x;
	int			line_height;
	int			draw_start;
	int			draw_end;

	x = -1;
	while (++x < WINWIDTH)
	{
		calculate_ray_position(graphics, x);
		calculate_map_position(graphics);
		calculate_length_of_ray(graphics);
		calculate_step_and_initial_side_dist(graphics);
		perfome_dda(graphics);
		calculate_distance_projected(graphics);
		line_height = (int)(WINHEIGHT / graphics->ray.distance);
		draw_start = calculate_lowest_pixel_to_fill(line_height);
		draw_end = calculate_highest_pixel_to_fill(line_height);
		draw_line(graphics, x, draw_start, draw_end);
	}
}
