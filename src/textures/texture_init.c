/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:43:31 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/18 00:04:35 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"
#include "cub3d_texture.h"

void	texture_init(t_graphics *graphics)
{
	int	x;
	int	y;

	x = -1;
	graphics->texture[0] = (uint32_t *)malloc(sizeof(uint32_t) * TEXWIDTH * TEXHEIGHT);
	graphics->texture[1] = (uint32_t *)malloc(sizeof(uint32_t) * TEXWIDTH * TEXHEIGHT);
	graphics->texture[2] = (uint32_t *)malloc(sizeof(uint32_t) * TEXWIDTH * TEXHEIGHT);
	graphics->texture[3] = (uint32_t *)malloc(sizeof(uint32_t) * TEXWIDTH * TEXHEIGHT);
	while (++x < TEXWIDTH)
	{
		y = -1;
		while (++y < TEXHEIGHT)
		{
			graphics->texture[0][TEXWIDTH * y + x] = 0x00FF0000;
			graphics->texture[1][TEXWIDTH * y + x] = 0x0000FF00;
			graphics->texture[2][TEXWIDTH * y + x] = 0x000000FF;
			if ((x < TEXWIDTH / 2 && y < TEXHEIGHT / 2) || (x >= TEXWIDTH / 2 && y >= TEXHEIGHT / 2))
			{
				// black
				graphics->texture[3][TEXWIDTH * y + x] = 0xFF000000;
			}
			else
			{
				graphics->texture[3][TEXWIDTH * y + x] = 0xFFf800f8;
			}
		}
	}
	reset_buffer(graphics);
}

void	reset_buffer(t_graphics *g)
{
	int	i;

	if (g->buffer)
	{
		i = -1;
		while (++i < WINHEIGHT)
			ft_bzero(g->buffer[i], WINWIDTH * sizeof(uint32_t));
		return ;
	}
	g->buffer = ft_calloc(WINHEIGHT + 1, sizeof(uint32_t *));
	if (!g->buffer)
		exit(1);
	i = -1;
	while (++i < WINHEIGHT)
	{
		g->buffer[i] = ft_calloc(WINWIDTH + 1, sizeof(uint32_t));
		if (!g->buffer[i])
			exit(1);
	}
}
