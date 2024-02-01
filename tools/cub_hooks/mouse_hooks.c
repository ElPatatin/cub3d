/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:43:51 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/06/17 12:00:14 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_data.h"
#include "cub3d_hooks.h"
#include "cub3d_errors.h"

int	mouse_close_onclick(t_mlx *vals)
{
	mlx_destroy_window(vals->ptr, vals->win);
	exit(EXIT_SUCCESS);
}

int	mouse_press_handler(int keycode, int x, int y, t_game *game)
{
	int		delta_x;

	UNUSED(y);
	if (keycode == 1)
		game->player.mouse_rotate = 1;
	delta_x = x - (WINWIDTH / 2);
	game->player.normalized_rotate_speed
		= (double)ft_absval(delta_x) / (WINWIDTH / 2);
	if (delta_x > 0)
	{
		game->player.rotate_left = 0;
		game->player.rotate_right = 1;
	}
	else if (delta_x < 0)
	{
		game->player.rotate_right = 0;
		game->player.rotate_left = 1;
	}
	else
	{
		game->player.rotate_right = 0;
		game->player.rotate_left = 0;
	}
	return (0);
}

int	mouse_release_handler(int keycode, int x, int y, t_game *game)
{
	UNUSED(x);
	UNUSED(y);
	if (keycode == 1)
		game->player.mouse_rotate = 0;
	game->player.rotate_right = 0;
	game->player.rotate_left = 0;
	return (0);
}

int	mouse_camera_handler(int x, int y, t_game *game)
{
	int			delta_x;

	UNUSED(y);
	if (game->player.mouse_rotate == 0)
		return (0);
	delta_x = x - (WINWIDTH / 2);
	game->player.normalized_rotate_speed
		= (double)ft_absval(delta_x) / (WINWIDTH / 2);
	if (delta_x > 0)
	{
		game->player.rotate_left = 0;
		game->player.rotate_right = 1;
	}
	else if (delta_x < 0)
	{
		game->player.rotate_right = 0;
		game->player.rotate_left = 1;
	}
	else
	{
		game->player.rotate_right = 0;
		game->player.rotate_left = 0;
	}
	return (0);
}
