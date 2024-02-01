/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:29:20 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/06/04 20:14:43 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_data.h"
#include "cub3d_map.h"
#include "cub3d_parser.h"
#include "cub3d_errors.h"

/**
 * @brief Loads the north texture from the map.
 * 
 * @param map The map struct.
 * @return void
 */
void	load_north_texture(t_map *map)
{
	ssize_t	idx;

	idx = -1;
	while (map->map[++idx])
	{
		if (map->no_path)
			terminate_error(ERR_DUP_TEX, SYS_DUP_TEX);
		if (map->map[idx][0] == 'N' && map->map[idx][1] == 'O')
		{
			parse_texture(&map->map[idx], &map->no_path, "NO");
			return ;
		}
	}
}

/**
 * @brief Loads the south texture from the map.
 * 
 * @param map The map struct.
 * @return void
 */
void	load_south_texture(t_map *map)
{
	ssize_t	idx;

	idx = -1;
	while (map->map[++idx])
	{
		if (map->so_path)
			terminate_error(ERR_DUP_TEX, SYS_DUP_TEX);
		if (map->map[idx][0] == 'S' && map->map[idx][1] == 'O')
		{
			parse_texture(&map->map[idx], &map->so_path, "SO");
			return ;
		}
	}
}

void	load_west_texture(t_map *map)
{
	ssize_t	idx;

	idx = -1;
	while (map->map[++idx])
	{
		if (map->we_path)
			terminate_error(ERR_DUP_TEX, SYS_DUP_TEX);
		if (map->map[idx][0] == 'W' && map->map[idx][1] == 'E')
		{
			parse_texture(&map->map[idx], &map->we_path, "WE");
			return ;
		}
	}
}

/**
 * @brief Loads the east texture from the map.
 * 
 * @param map The map struct.
 * @return void
 */
void	load_east_texture(t_map *map)
{
	ssize_t	idx;

	idx = -1;
	while (map->map[++idx])
	{
		if (map->ea_path)
			terminate_error(ERR_DUP_TEX, SYS_DUP_TEX);
		if (map->map[idx][0] == 'E')
		{
			parse_texture(&map->map[idx], &map->ea_path, "E");
			return ;
		}
	}
}

/**
 * @brief Loads the sprites textures from the map.
 * 
 * @param map The map struct.
 * @return void
 */
void	load_sprite_texture(t_map *map)
{
	ssize_t	idx;

	idx = -1;
	while (map->map[++idx])
	{
		if (map->s_path)
			terminate_error(ERR_DUP_TEX, SYS_DUP_TEX);
		if (map->map[idx][0] == 'S')
		{
			parse_texture(&map->map[idx], &map->s_path, "S");
			return ;
		}
	}
}
