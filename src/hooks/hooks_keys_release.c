/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_keys_release.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:29:52 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/15 22:39:21 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"
#include "cub3d_hooks.h"
#include "cub3d_keys.h"

int	hooks_keys_release(int keycode, t_graphics *graphics)
{
	if (keycode == W_KEY)
		graphics->player.move_up = 0;
	if (keycode == S_KEY)
		graphics->player.move_down = 0;
	if (keycode == A_KEY)
		graphics->player.move_left = 0;
	if (keycode == D_KEY)
		graphics->player.move_right = 0;
	if (keycode == LFT_KEY)
		graphics->player.rotate_left = 0;
	if (keycode == RGT_KEY)
	{
		graphics->player.rotate_right = 0;
	}
	return (0);
}
