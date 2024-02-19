/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:45:27 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/19 15:51:13 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"
#include "cub3d_hooks.h"
#include "cub3d_keys.h"

void	exit_game(t_graphics *graphics)
{
	mlx_destroy_window(graphics->mlx, graphics->win);
	exit(EXIT_SUCCESS);
}
