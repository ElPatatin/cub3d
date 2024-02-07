/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:23:08 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/07 17:30:47 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"
#include "cub3d_hooks.h"

void	hooks(t_graphics *graphics)
{
	mlx_hook(graphics->win, 2, 1L << 0, hooks_keys_press, graphics);
	mlx_hook(graphics->win, 3, 1L << 1, hooks_keys_release, graphics);
	mlx_hook(graphics->win, 17, 0, exit_on_click, graphics);
}
