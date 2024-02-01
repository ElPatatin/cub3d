/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser_textures_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:05:34 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/06/17 10:30:32 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_data.h"
#include "cub3d_map.h"
#include "cub3d_parser.h"
#include "cub3d_errors.h"

t_bool	check_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0 || fd > OPEN_MAX)
		return (FALSE);
	if (close(fd))
		return (FALSE);
	if (ft_strncmp(&path[ft_strlen(path) - 4], ".xpm", 4))
		return (FALSE);
	return (TRUE);
}

void	parse_texture(char **line, char **texture, char *type)
{
	char	*path;

	path = ft_strtrim(*line + ft_strlen(type), SPACES);
	if (!path)
		terminate_error(ERR_MEM, SYS_MEM);
	if (!check_file(path))
		terminate_error(ERR_BAD_TEX, SYS_BAD_TEX);
	*texture = ft_strdup(path);
	if (!*texture)
		terminate_error(ERR_MEM, SYS_MEM);
	free(path);
	ft_delete(*line);
	*line = ft_strdup("");
	if (!*line)
		terminate_error(ERR_MEM, SYS_MEM);
}

t_bool	validate_textures(t_map *map)
{
	if (!map->no_path || !map->so_path
		|| !map->we_path || !map->ea_path || !map->s_path)
		return (FALSE);
	return (TRUE);
}
