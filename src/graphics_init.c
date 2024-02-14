/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:11:43 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/12 12:11:41 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"
#include "cub3d_graphics.h"
#include "cub3d_game.h"
#include "cub3d_render.h"
#include "cub3d_hooks.h"
#include "cub3d_errors.h"


static void	graphics_init(t_graphics *graphics, t_info *info);

void	graphics(t_info *info)
{
	t_graphics	graphics;

	graphics_init(&graphics, info);
	mlx_put_image_to_window(graphics.mlx,
		graphics.win, graphics.img->img, 0, 0);
	mlx_loop_hook(graphics.mlx, game_loop, &graphics);
	hooks(&graphics);
	mlx_loop(graphics.mlx);
}

static void	img_init(t_graphics *graphics)
{
	graphics->img = (t_image *)malloc(sizeof(t_image));
	if (!graphics->img)
		exit(EXIT_FAILURE); // TODO
	graphics->img->img = mlx_new_image(graphics->mlx, WINWIDTH, WINHEIGHT);
	if (!graphics->img->img)
		exit(EXIT_FAILURE); // TODO 
	graphics->img->addr = mlx_get_data_addr(graphics->img->img,
			&graphics->img->bpp, &graphics->img->line_len,
			&graphics->img->endian);
	graphics->mmap = (t_image *)malloc(sizeof(t_image));
	if (!graphics->mmap)
		exit(EXIT_FAILURE); // TODO
}

static void	graphics_init(t_graphics *graphics, t_info *info)
{
	graphics->mlx = mlx_init();
	if (!graphics->mlx)
		exit(EXIT_FAILURE); // TODO 
	graphics->win = mlx_new_window(graphics->mlx, WINWIDTH, WINHEIGHT, TITLE);
	if (!graphics->win)
		exit(EXIT_FAILURE); // TODO 
	img_init(graphics);
	graphics->info = info;
}

int	game_loop(t_graphics *graphics)
{
	mlx_destroy_image(graphics->mlx, graphics->img->img);
	graphics->img->img = mlx_new_image(graphics->mlx, WINWIDTH, WINHEIGHT);
	if (!graphics->img->img)
		exit(EXIT_FAILURE); // TODO 
	graphics->img->addr = mlx_get_data_addr(graphics->img->img,
			&graphics->img->bpp, &graphics->img->line_len,
			&graphics->img->endian);
	render_game(graphics);
	mlx_put_image_to_window(graphics->mlx, graphics->win,
		graphics->img->img, 0, 0);
	return (0);
}
