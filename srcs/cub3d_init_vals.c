/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init_vals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:16:15 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/06/11 13:13:19 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_data.h"
#include "cub3d_map.h"
#include "cub3d_parser.h"
#include "cub3d_hooks.h"
#include "cub3d_errors.h"

void	init_vals(t_mlx *vals, t_data *data)
{
	vals->ptr = mlx_init();
	if (!vals->ptr)
		terminate_error(ERR_WIN, SYS_WIN);
	vals->win = mlx_new_window(vals->ptr,
			WINWIDTH, WINHEIGHT, TITLE);
	data->img = mlx_new_image(vals->ptr, WINWIDTH, WINHEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bpp,
			&data->line_len, &data->endian);
	vals->data = data;
}

void	init_map(t_map *map, size_t map_len)
{
	map->map = NULL;
	map->length = map_len;
	map->no_path = NULL;
	map->so_path = NULL;
	map->we_path = NULL;
	map->ea_path = NULL;
	map->s_path = NULL;
	map->floor_colour = 0;
	map->ceiling_colour = 0;
	map->grid = NULL;
}
