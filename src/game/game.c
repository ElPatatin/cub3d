/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:25:04 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/07 18:01:27 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"
#include "cub3d_game.h"

int	game_loop(t_graphics *graphics)
{
    mlx_destroy_image(graphics->mlx, graphics->img->img);
    graphics->img->img = mlx_new_image(graphics->mlx, WINWIDTH, WINHEIGHT);
    if (!graphics->img->img)
        exit(EXIT_FAILURE); // TODO 
    graphics->img->addr = mlx_get_data_addr(graphics->img->img,
        &graphics->img->bpp, &graphics->img->line_len, &graphics->img->endian);
    // render_game(graphics);
    mlx_put_image_to_window(graphics->mlx, graphics->win, graphics->img->img, 0, 0);
    return (0);
}