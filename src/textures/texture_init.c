/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:43:31 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/18 15:12:40 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"
#include "cub3d_texture.h"

void	texture_init(t_graphics *g)
{
	int	x;
	int	y;

	x = -1;
	g->tex.texture[0] = (uint32_t *)ft_calloc(sizeof(uint32_t), TEXWIDTH * TEXHEIGHT);
	g->tex.texture[1] = (uint32_t *)ft_calloc(sizeof(uint32_t), TEXWIDTH * TEXHEIGHT);
	g->tex.texture[2] = (uint32_t *)ft_calloc(sizeof(uint32_t), TEXWIDTH * TEXHEIGHT);
	g->tex.texture[3] = (uint32_t *)ft_calloc(sizeof(uint32_t), TEXWIDTH * TEXHEIGHT);
	while (++x < TEXWIDTH)
	{
		y = -1;
		while (++y < TEXHEIGHT)
		{
			g->tex.texture[0][TEXWIDTH * y + x] = 0x00FF0000;
			g->tex.texture[1][TEXWIDTH * y + x] = 0x0000FF00;
			g->tex.texture[2][TEXWIDTH * y + x] = 0x000000FF;
			if ((x < TEXWIDTH / 2 && y < TEXHEIGHT / 2)
				|| (x >= TEXWIDTH / 2 && y >= TEXHEIGHT / 2))
				g->tex.texture[3][TEXWIDTH * y + x] = 0x01FFFFFF;
			else
				g->tex.texture[3][TEXWIDTH * y + x] = 0x00f800f8;
		}
	}
	reset_buffer(g);
}

void	reset_buffer(t_graphics *g)
{
	int	i;

	if (g->tex.buffer)
	{
		i = -1;
		while (++i < WINHEIGHT)
			ft_bzero(g->tex.buffer[i], WINWIDTH * sizeof(uint32_t));
		return ;
	}
	g->tex.buffer = ft_calloc(WINHEIGHT + 1, sizeof(uint32_t *));
	if (!g->tex.buffer)
		exit(1);
	i = -1;
	while (++i < WINHEIGHT)
	{
		g->tex.buffer[i] = ft_calloc(WINWIDTH + 1, sizeof(uint32_t));
		if (!g->tex.buffer[i])
			exit(1);
	}
}
