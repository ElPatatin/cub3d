/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:45:27 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/19 14:11:20 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"
#include "cub3d_hooks.h"
#include "cub3d_keys.h"

void	exit_game(t_graphics *graphics)
{
	mlx_destroy_window(graphics->mlx, graphics->win);
	// ft_memfree(graphics->info->map);
	// ft_delete(graphics->info->txr_no);
	// ft_delete(graphics->info->txr_so);
	// ft_delete(graphics->info->txr_we);
	// ft_delete(graphics->info->txr_ea);
	// ft_delete(graphics->info->txr_walls[0]);
	// ft_delete(graphics->info->txr_walls[1]);
	// ft_delete(graphics->info->txr_walls[2]);
	// ft_delete(graphics->info->txr_walls[3]);
	// ft_memfree((char **)graphics->tex.buffer);
	// ft_delete((char *)graphics->tex.img[0]);
	// ft_delete((char *)graphics->tex.img[1]);
	// ft_delete((char *)graphics->tex.img[2]);
	// ft_delete((char *)graphics->tex.img[3]);
	exit(EXIT_SUCCESS);
}
