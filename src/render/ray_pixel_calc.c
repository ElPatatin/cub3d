/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_pixel_calc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:04:50 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/18 00:03:23 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"
#include "cub3d_basic_utils.h"
#include "cub3d_render_private.h"
#include "cub3d_texture.h"

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

	draw_start = -line_height / 2 + WINHEIGHT / 2 + PITCH;
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

	draw_end = line_height / 2 + WINHEIGHT / 2 + PITCH;
	if (draw_end >= WINHEIGHT)
		draw_end = WINHEIGHT - 1;
	return (draw_end);
}

void	calculate_texture(t_graphics *g, int x, int draw_start, int draw_end, int line_height)
{
	double		wallX;
	int			texX;
	uint32_t	color;
	int			textureIndex;
	double		step;
 	double		texPos;

	textureIndex = determine_wall_texture_index(g);
	if (g->ray.side == 0)
		wallX = g->player.pos_y + g->ray.distance * g->ray.dir_y;
	else
		wallX = g->player.pos_x + g->ray.distance * g->ray.dir_x;
	wallX -= floor((wallX));
	texX = (int)(wallX * (double)TEXWIDTH);
	if (g->ray.side == 0 && g->ray.dir_x > 0)
		texX = TEXWIDTH - texX - 1;
	if (g->ray.side == 1 && g->ray.dir_y < 0)
		texX = TEXWIDTH - texX - 1;
	step = 1.0 * TEXHEIGHT / line_height;
	texPos = (draw_start - WINHEIGHT / 2 + line_height / 2) * step;
	for (int y = draw_start; y < draw_end; y++)
	{
		int texY = (int)texPos & (TEXHEIGHT - 1);
		texPos += step;
		color = g->texture[textureIndex][TEXWIDTH * texY + texX];
		if (g->ray.side == 1 && textureIndex != 3)
			color = (color >> 1) & 8355711;
		g->buffer[y][x] = color;
	}
}

void	draw_buffer(t_graphics *g)
{
	int	x;
	int	y;

	y = -1;
	while (++y < WINHEIGHT)
	{
		x = -1;
		while (++x < WINWIDTH)
		{
			if (g->buffer[y][x] != 0)
				ft_mlx_put_pixel(g, x, y, g->buffer[y][x]);
		}
	}
}
