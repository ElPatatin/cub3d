/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:08:17 by cmakpeset-c          #+#    #+#             */
/*   Updated: 2024/02/14 15:31:36 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"
#include "cub3d_basic_utils.h"
#include "cub3d_render_private.h"

void	put_wall_layer(t_graphics *graphics)
{
	ssize_t		x;

	x = -1;
	while (++x < WINWIDTH)
	{
		//calculate ray position and direction
		float	cameraX = 2 * x / (float)WINWIDTH - 1;
		
		graphics->ray.dir_x = graphics->player.dir_x + graphics->player.plane_x * cameraX;
		graphics->ray.dir_y = graphics->player.dir_y + graphics->player.plane_y * cameraX;

	    //which box of the map we're in
		graphics->ray.map_x = (int)graphics->player.pos_x;
		graphics->ray.map_y = (int)graphics->player.pos_y;

		//length of ray from one x or y-side to next x or y-side
		if (graphics->ray.dir_y == 0)
			graphics->ray.delta_dist_x = 1E30;
		else
			graphics->ray.delta_dist_x = fabs(1 / graphics->ray.dir_x);
		if (graphics->ray.dir_x == 0)
			graphics->ray.delta_dist_y = 1E30;
		else
			graphics->ray.delta_dist_y = fabs(1 / graphics->ray.dir_y);

		//calculate step and initial sideDist
		if (graphics->ray.dir_x < 0)
		{
			graphics->ray.step_x = -1;
			graphics->ray.side_dist_x = (graphics->player.pos_x - graphics->ray.map_x) * graphics->ray.delta_dist_x;
		}
		else
		{
			graphics->ray.step_x = 1;
			graphics->ray.side_dist_x = (graphics->ray.map_x + 1.0 - graphics->player.pos_x) * graphics->ray.delta_dist_x;
		}
		if (graphics->ray.dir_y < 0)
		{
			graphics->ray.step_y = -1;
			graphics->ray.side_dist_y = (graphics->player.pos_y - graphics->ray.map_y) * graphics->ray.delta_dist_y;
		}
		else
		{
			graphics->ray.step_y = 1;
			graphics->ray.side_dist_y = (graphics->ray.map_y + 1.0 - graphics->player.pos_y) * graphics->ray.delta_dist_y;
		}

		//perform DDA
		graphics->ray.hit = FALSE;
		while (graphics->ray.hit == FALSE)
		{
			// jump to next map square, OR in x-direction, OR in y-direction
			if (graphics->ray.side_dist_x < graphics->ray.side_dist_y)
			{
				graphics->ray.side_dist_x += graphics->ray.delta_dist_x;
				graphics->ray.map_x += graphics->ray.step_x;
				graphics->ray.side = 0;
			}
			else
			{
				graphics->ray.side_dist_y += graphics->ray.delta_dist_y;
				graphics->ray.map_y += graphics->ray.step_y;
				graphics->ray.side = 1;
			}

			//Check if ray has graphics->ray.hit a wall
			if (graphics->info->map[graphics->ray.map_x][graphics->ray.map_y] == '1')
				graphics->ray.hit = TRUE;
		}

		// Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
		if (graphics->ray.side == 0)
			graphics->ray.distance = (graphics->ray.side_dist_x - graphics->ray.delta_dist_x);
		else
			graphics->ray.distance = (graphics->ray.side_dist_y - graphics->ray.delta_dist_y);

		// Calculate height of line to draw on screen
		int lineHeight = (int)(WINHEIGHT / graphics->ray.distance);

		// Calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + WINHEIGHT / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + WINHEIGHT / 2;
		if(drawEnd >= WINHEIGHT)
			drawEnd = WINHEIGHT - 1;

		int	y;

		y = -1;
		int color = 0x387185;
		if (graphics->ray.side == 1)
			color = (color >> 1) & 8355711;
		while (++y < WINHEIGHT)
			if (y >= drawStart && y <= drawEnd)
				ft_mlx_put_pixel(graphics, x, y, color);
	}
}
	