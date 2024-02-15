/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_pixel_calc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:04:50 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/15 17:45:01 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"
#include "cub3d_basic_utils.h"

/**
 * @brief This function calculates the lowest pixel to fill
 * 
 * @param line_height (int) - The height of the line
 * 
 * @retval int - The lowest pixel to fill
 * 
 * @note
 * This function calculates the lowest pixel to fill. It calculates the pixel
 * where the wall starts to be drawn on the screen.
*/
int	calculate_lowest_pixel_to_fill(int line_height)
{
	int	draw_start;

	draw_start = -line_height / 2 + WINHEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	return (draw_start);
}

/**
 * @brief This function calculates the highest pixel to fill
 * 
 * @param line_height (int) - The height of the line
 * 
 * @retval int - The highest pixel to fill
 * 
 * @note
 * This function calculates the highest pixel to fill. It calculates the pixel
 * where the wall ends to be drawn on the screen.
*/
int	calculate_highest_pixel_to_fill(int line_height)
{
	int	draw_end;

	draw_end = line_height / 2 + WINHEIGHT / 2;
	if (draw_end >= WINHEIGHT)
		draw_end = WINHEIGHT - 1;
	return (draw_end);
}

/**
 * @brief This function draws the line on the screen
 * 
 * @param g (t_graphics *) - The graphics structure
 * @param x (int) - The x position of the line
 * @param draw_start (int) - The lowest pixel to fill
 * @param draw_end (int) - The highest pixel to fill
 * 
 * @retval None
 * 
 * @note
 * This function draws the line on the screen. It fills the pixels between
 * draw_start and draw_end with the color of the wall.
*/
void	draw_line(t_graphics *g, int x, int draw_start, int draw_end)
{
	int	y;
	int	color;

	y = -1;
	color = 0x387185;
	if (g->ray.side == 1)
		color = (color >> 1) & 8355711;
	while (++y < WINHEIGHT)
		if (y >= draw_start && y <= draw_end)
			ft_mlx_put_pixel(g, x, y, color);
}
