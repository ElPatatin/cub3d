/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:11:43 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/19 17:47:05 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"
#include "cub3d_graphics.h"
#include "cub3d_game.h"
#include "cub3d_render.h"
#include "cub3d_hooks.h"
#include "cub3d_errors.h"
#include "cub3d_player.h"
#include "cub3d_texture.h"

static void	graphics_init(t_graphics *graphics, t_info *info);

/**
 * @brief Initialize the image
 * 
 * @param info (t_info *) - The info structure
 * 
 * @retval None
 * 
 * @note
 * This function initializes the image. It allocates memory for the image and
 * creates the image with the mlx_new_image function.
 */
void	graphics(t_info *info)
{
	t_graphics	graphics;

	graphics_init(&graphics, info);
	mlx_put_image_to_window(graphics.mlx,
		graphics.win, graphics.img->img, 0, 0);
	player_init(&graphics);
	graphics.tex.buffer = NULL;
	texture_init(&graphics);
	reset_buffer(&graphics);
	mlx_loop_hook(graphics.mlx, game_loop, &graphics);
	hooks(&graphics);
	mlx_loop(graphics.mlx);
}

static void	img_init(t_graphics *graphics)
{
	graphics->img = (t_image *)malloc(sizeof(t_image));
	if (!graphics->img)
		terminate_error(ERR_MEM, SYS_MEM);
	graphics->img->img = mlx_new_image(graphics->mlx, WINWIDTH, WINHEIGHT);
	if (!graphics->img->img)
		terminate_error(ERR_MEM, SYS_MEM);
	graphics->img->addr = mlx_get_data_addr(graphics->img->img,
			&graphics->img->bpp, &graphics->img->line_len,
			&graphics->img->endian);
}

static void	graphics_init(t_graphics *graphics, t_info *info)
{
	graphics->mlx = mlx_init();
	if (!graphics->mlx)
		terminate_error(ERR_MLX, SYS_MLX);
	graphics->win = mlx_new_window(graphics->mlx, WINWIDTH, WINHEIGHT, TITLE);
	if (!graphics->win)
		terminate_error(ERR_WIN, SYS_WIN);
	img_init(graphics);
	graphics->info = info;
}

/**
 * @brief The game loop
 * 
 * @param graphics (t_graphics *) - The graphics structure
 * 
 * @retval int - The return value
 * 
 * @note
 * This function is the game loop. It destroys the image, creates a new image,
 * handles the player movement, handles the player rotation, renders the game,
 * and puts the image to the window.
*/
int	game_loop(t_graphics *graphics)
{
	mlx_destroy_image(graphics->mlx, graphics->img->img);
	graphics->img->img = mlx_new_image(graphics->mlx, WINWIDTH, WINHEIGHT);
	if (!graphics->img->img)
		terminate_error(ERR_MLX, SYS_MLX);
	graphics->img->addr = mlx_get_data_addr(graphics->img->img,
			&graphics->img->bpp, &graphics->img->line_len,
			&graphics->img->endian);
	handle_player_movement(graphics);
	handle_player_rotation(graphics);
	render_game(graphics);
	mlx_put_image_to_window(graphics->mlx, graphics->win,
		graphics->img->img, 0, 0);
	return (0);
}
