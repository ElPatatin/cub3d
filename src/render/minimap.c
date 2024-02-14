/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:47:47 by alajara-          #+#    #+#             */
/*   Updated: 2024/02/14 19:11:48 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"
#include "cub3d_render_private.h"

static void put_wall_mmap(t_graphics *g, int y, int x)
{
	int y_end;
	int x_end;

	y_end = (y + 1) * MMAP_SQR_SIZE;
	x_end = (x + 1) * MMAP_SQR_SIZE;
	y *= MMAP_SQR_SIZE;
	while (y < y_end)
	{
		while (x < x_end)
		{
			ft_mlx_put_pixel(g, x, y, 0xFFFFFFFF);
			++x;
		}
		x -= MMAP_SQR_SIZE;
		++y;		
	}
}

// Converts (char **)map to (t_img)mmap, representing the 1 as squares.
// Squares will have MMAP_SQR_SIZE pixels as side.
void generate_mmap(t_graphics *g)
{
	int	mapw;
	int	maph;
	int	y;
	int	x;

	g->mmap->img = mlx_new_image(g->mlx, mapw * MMAP_SQR_SIZE, \
		maph * MMAP_SQR_SIZE);
	if (!g->mmap->img)
		exit(EXIT_FAILURE); // TODO 
	g->mmap->addr = mlx_get_data_addr(g->mmap->img,
			&g->mmap->bpp, &g->mmap->line_len,
			&g->mmap->endian);
	mapw = ft_strlen(g->info->map[0]);
	maph = ft_strcount(g->info->map);
	y = -1;
	while (++y < maph)
	{
		x = -1;
		while (++x < mapw)
			if (g->info->map[y][x] == '1')
				put_wall_mmap(g, y, x);
	}
}

// 
// void	render_mmap(t_img *mmap)
// {

// }