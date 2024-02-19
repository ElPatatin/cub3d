/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:19:43 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/12 12:09:20 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"
#include "cub3d_basic_utils.h"

void	ft_mlx_put_pixel(t_graphics *graphics, int x, int y, int color)
{
	char	*dst;

	dst = graphics->img->addr + (y * graphics->img->line_len + x * \
		(graphics->img->bpp / 8));
	*(t_unt *)dst = color;
}
