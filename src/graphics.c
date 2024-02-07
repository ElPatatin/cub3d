/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:11:43 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/07 18:02:45 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"
#include "cub3d_graphics.h"
#include "cub3d_game.h"
#include "cub3d_hooks.h"
#include "cub3d_errors.h"


static void	init_graphics(t_graphics *graphics, t_info *info);

void	graphics(t_info *info)
{
	t_graphics	graphics;

	init_graphics(&graphics, info);
	mlx_put_image_to_window(graphics.mlx, graphics.win, graphics.img->img, 0, 0);
	mlx_loop_hook(graphics.mlx, game_loop, &graphics);
	hooks(&graphics);
	mlx_loop(graphics.mlx);
	
}

static void	init_graphics(t_graphics *graphics, t_info *info)
{
	graphics->mlx = mlx_init();
	if (!graphics->mlx)
		exit(EXIT_FAILURE); // TODO 
	graphics->win = mlx_new_window(graphics->mlx, WINWIDTH, WINHEIGHT, TITLE);
	if (!graphics->win)
		exit(EXIT_FAILURE); // TODO 
	graphics->img = (t_image *)malloc(sizeof(t_image));
	if (!graphics->img)
		exit(EXIT_FAILURE); // TODO
	graphics->img->img = mlx_new_image(graphics->mlx, WINWIDTH, WINHEIGHT);
	if (!graphics->img->img)
		exit(EXIT_FAILURE); // TODO 
	graphics->img->addr = mlx_get_data_addr(graphics->img->img, &graphics->img->bpp, &graphics->img->line_len, &graphics->img->endian);
	graphics->info = info;
	
}

