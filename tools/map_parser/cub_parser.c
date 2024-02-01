/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:19:05 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/06/09 18:03:35 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_data.h"
#include "cub3d_map.h"
#include "cub3d_parser.h"
#include "cub3d_errors.h"

static void	load_textures(t_map *map);
static void	load_colours(t_map *map);
static void	load_map(t_map *map);

void	get_map(int fd, size_t map_len, t_map *map)
{
	init_map(map, map_len);
	read_map(fd, map);
	load_textures(map);
	if (!validate_textures(map))
		terminate_error(ERR_TEX, SYS_TEX);
	load_colours(map);
	if (!validate_colours(map))
		terminate_error(ERR_CLR, SYS_CLR);
	load_map(map);
	if (!validate_map(map))
		terminate_error(ERR_BAD_MAP, SYS_BAD_MAP);
	ft_memfree(map->map);
}

static void	load_textures(t_map *map)
{
	load_north_texture(map);
	load_south_texture(map);
	load_west_texture(map);
	load_east_texture(map);
	load_sprite_texture(map);
}

static void	load_colours(t_map *map)
{
	load_floor_colour(map);
	load_cealing_colour(map);
}

void	load_map(t_map *map)
{
	size_t	width;

	width = get_max_length(map);
	allocate_grid(map, width);
	replace_spaces_with_void(map);
	map_expander_handler(map, width);
	format_map(map);
}
