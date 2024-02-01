/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:18:00 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/06/10 13:48:57 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_data.h"
#include "cub3d_errors.h"

void	new_window(t_mlx *vals, t_data *data)
{
	mlx_put_image_to_window(vals->ptr, vals->win, data->img, 0, 0);
}

void	ft_mlx_put_pixels(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(t_unt *)dst = color;
}

t_bool	ft_ismap(int c)
{
	if (c == '1' || ft_isspace(c))
		return (TRUE);
	return (FALSE);
}
