/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:41:07 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/18 20:15:31 by cpeset-c         ###   ########.fr       */
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
