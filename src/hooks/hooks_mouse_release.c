/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_mouse_release.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 00:23:07 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/19 15:01:36 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"
#include "cub3d_hooks.h"

int	mouse_release_handler(int keycode, int x, int y, t_graphics *g)
{
	(void)x;
	(void)y;
	if (keycode == 1)
		g->player.mouse_rotate = 0;
	g->player.rotate_right = 0;
	g->player.rotate_left = 0;
	return (0);
}
