/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_keys_press.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:29:40 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/14 17:19:29 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"
#include "cub3d_hooks.h"
#include "cub3d_keys.h"

int	hooks_keys_press(int keycode, t_graphics *graphics)
{
	if (keycode == ESC_KEY)
		exit_game(graphics);
	if (keycode == W_KEY)
		graphics->player.move_up = 1;
	if (keycode == S_KEY)
		graphics->player.move_down = 1;
	if (keycode == A_KEY)
		graphics->player.move_left = 1;
	if (keycode == D_KEY)
		graphics->player.move_right = 1;
	if (keycode == LFT_KEY)
		graphics->player.rotate_left = 1;
	if (keycode == RGT_KEY)
		graphics->player.rotate_right = 1;

	// printf("keycode: %d\n", keycode);
	return (0);
}
