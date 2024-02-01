/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 10:35:26 by ogonzale          #+#    #+#             */
/*   Updated: 2023/06/17 10:51:47 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_data.h"
#include "cub3d_errors.h"

void	draw_wall_and_background(t_game *game, int x)
{
	int	y;

	y = -1;
	game->wall.color = 0x387185;
	if (game->ray.side == 1)
		game->wall.color = (game->wall.color >> 1) & 8355711;
	while (++y < WINHEIGHT)
	{
		if (y < game->wall.draw_start)
			ft_mlx_put_pixels(game->mlx.data, x, y, game->map.ceiling_colour);
		else if (y >= game->wall.draw_start && y <= game->wall.draw_end)
			ft_mlx_put_pixels(game->mlx.data, x, y, game->wall.color);
		else
			ft_mlx_put_pixels(game->mlx.data, x, y, game->map.floor_colour);
	}
}
