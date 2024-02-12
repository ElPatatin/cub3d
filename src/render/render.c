/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:54:01 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/12 12:36:33 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_basic_utils.h"
#include "cub3d_render_private.h"

void	render_game(t_graphics *graphics)
{
	put_background_layer(graphics);
	

}

static void	put_background_layer(t_graphics *graphics)
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
