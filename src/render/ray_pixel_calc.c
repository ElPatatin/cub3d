/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_pixel_calc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:04:50 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/18 15:45:09 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"
#include "cub3d_basic_utils.h"
#include "cub3d_render_private.h"
#include "cub3d_texture.h"

static void	build_buffer(t_graphics *g, int x);

void	set_line_limit(t_graphics *g)
{
	g->line.height = (int)(WINHEIGHT / g->ray.distance);
	g->line.start = (-g->line.height >> 1) + (WINHEIGHT >> 1) + PITCH;
	if (g->line.start < 0)
		g->line.start = 0;
	g->line.end = (g->line.height >> 1) + (WINHEIGHT >> 1) + PITCH;
	if (g->line.end >= WINHEIGHT)
		g->line.end = WINHEIGHT - 1;
}

void	calculate_texture(t_graphics *g, int x)
{
	if (g->ray.side == 0)
		g->tex.wall_x = g->player.pos_y + g->ray.distance * g->ray.dir_y;
	else
		g->tex.wall_x = g->player.pos_x + g->ray.distance * g->ray.dir_x;
	g->tex.wall_x -= floor((g->tex.wall_x));
	g->tex.tex_x = (int)(g->tex.wall_x * (double)TEXWIDTH);
	g->tex.step = 1.0 * TEXHEIGHT / g->line.height;
	g->tex.tex_pos = (g->line.start - (WINHEIGHT >> 1) \
		+ (g->line.height >> 1)) * g->tex.step;
	build_buffer(g, x);
}

static void	build_buffer(t_graphics *g, int x)
{
	int	y;
	int	px;

	y = g->line.start - 1;
	g->tex.tex_idx = determine_wall_texture_index(g);
	while (++y < g->line.end)
	{
		g->tex.tex_y = (int)g->tex.tex_pos & (TEXHEIGHT - 1);
		g->tex.tex_pos += g->tex.step;
		px = TEXWIDTH * g->tex.tex_y + g->tex.tex_x;
		g->tex.color = g->tex.texture[g->tex.tex_idx][px];
		g->tex.buffer[y][x] = g->tex.color;
	}
}

void	draw_buffer(t_graphics *g)
{
	int	x;
	int	y;

	y = -1;
	while (++y < WINHEIGHT)
	{
		x = -1;
		while (++x < WINWIDTH)
		{
			if (g->tex.buffer[y][x] != 0)
				ft_mlx_put_pixel(g, x, y, g->tex.buffer[y][x]);
		}
	}
}
