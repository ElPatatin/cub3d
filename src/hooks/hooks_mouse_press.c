/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_mouse_press.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:44:06 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/19 00:41:51 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"
#include "cub3d_hooks.h"
#include "cub3d_keys.h"

int	exit_on_click(t_graphics *graphics)
{
	exit_game(graphics);
	return (0);
}

int	mouse_press_handler(int keycode, int x, int y, t_graphics *g)
{
	int		delta_x;

	UNUSED(y);
	if (keycode == 1)
		g->player.mouse_rotate = 1;
	delta_x = x - (WINWIDTH >> 1);
	g->player.rotate_speed = (float)ft_absval(delta_x) / (WINWIDTH >> 1);
	g->player.rotate_left = 0;
	g->player.rotate_right = 0;
	if (delta_x > 0)
		g->player.rotate_right = 1;
	else if (delta_x < 0)
		g->player.rotate_left = 1;
	return (0);
}

int	camera_press_handler(int x, int y, t_graphics *g)
{
	int		delta_x;

	UNUSED(y);
	if (g->player.mouse_rotate == 0)
		return (0);
	delta_x = x - (WINWIDTH >> 1);
	g->player.rotate_speed = (float)ft_absval(delta_x) / (WINWIDTH >> 1);
	g->player.rotate_left = 0;
	g->player.rotate_right = 0;
	if (delta_x > 0)
		g->player.rotate_right = 1;
	else if (delta_x < 0)
		g->player.rotate_left = 1;
	return (0);
}
