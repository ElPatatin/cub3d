/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:43:37 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/06/05 18:52:11 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_data.h"
#include "cub3d_hooks.h"
#include "cub3d_errors.h"

int	handle_keys_press(int keycode, t_game *game)
{
	if (keycode == W_KEY)
		game->player.move_up = 1;
	else if (keycode == S_KEY)
		game->player.move_down = 1;
	else if (keycode == A_KEY)
		game->player.move_left = 1;
	else if (keycode == D_KEY)
		game->player.move_right = 1;
	else if (keycode == LFT_KEY)
		game->player.rotate_left = 1;
	else if (keycode == RGT_KEY)
		game->player.rotate_right = 1;
	return (1);
}

int	handle_keys_release(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window((&game->mlx)->ptr, (&game->mlx)->win);
		exit(EXIT_SUCCESS);
	}
	if (keycode == W_KEY)
		game->player.move_up = 0;
	else if (keycode == S_KEY)
		game->player.move_down = 0;
	else if (keycode == A_KEY)
		game->player.move_left = 0;
	else if (keycode == D_KEY)
		game->player.move_right = 0;
	else if (keycode == LFT_KEY)
		game->player.rotate_left = 0;
	else if (keycode == RGT_KEY)
		game->player.rotate_right = 0;
	return (1);
}

int	key_print_hook(int keycode, t_mlx *vals)
{
	UNUSED(vals);
	if (keycode == ESC_KEY)
		return (1);
	return (0);
}
