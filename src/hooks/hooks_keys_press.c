/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_keys_press.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:29:40 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/07 14:01:38 by cpeset-c         ###   ########.fr       */
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
	printf("keycode: %d\n", keycode);
	return (0);
}
