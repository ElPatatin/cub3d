/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:41:07 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/19 13:47:30 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"
#include "cub3d_texture.h"

int	determine_wall_texture_index(t_graphics *g)
{
	if (g->ray.side == 0)
	{
		if (g->ray.dir_x > 0)
			return (1);
		else
			return (0);
	}
	else
	{
		if (g->ray.dir_y > 0)
			return (2);
		else
			return (3);
	}
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
