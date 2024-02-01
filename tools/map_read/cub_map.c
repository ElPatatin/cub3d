/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:19:07 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/06/09 16:52:35 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_data.h"
#include "cub3d_map.h"
#include "cub3d_parser.h"
#include "cub3d_errors.h"

static int	check_map_extension(char *cw_map);

void	map_handler(char *cw_map, t_map *map)
{
	int	fd;
	int	map_len;

	if (check_map_extension(cw_map))
		terminate_error(ERR_EXT_MAP, SYS_EXT_MAP);
	fd = open(cw_map, O_RDONLY);
	if (fd < 0 || fd > OPEN_MAX)
		terminate_error(ERR_OPEN_MAP, SYS_OPEN_MAP);
	get_map_length(fd, &map_len);
	if (close(fd))
		terminate_error(ERR_CLOSE_MAP, SYS_CLOSE_MAP);
	fd = open(cw_map, O_RDONLY);
	if (fd < 0 || fd > OPEN_MAX)
		terminate_error(ERR_OPEN_MAP, SYS_OPEN_MAP);
	get_map(fd, map_len, map);
	if (close(fd))
		terminate_error(ERR_CLOSE_MAP, SYS_CLOSE_MAP);
}

static int	check_map_extension(char *cw_map)
{
	size_t	len;
	char	*str;

	len = ft_strlen(cw_map);
	str = ft_strrchr(cw_map, '/');
	if (!str)
		str = cw_map;
	if (len <= 4 || ft_strlen(&str[1]) <= 4)
		return (TRUE);
	if (ft_strncmp(MAP_EXT, &cw_map[len - 4], ft_strlen(MAP_EXT)))
		return (TRUE);
	return (FALSE);
}

void	read_map(int fd, t_map *map)
{
	char	*line;
	size_t	idx;

	map->map = (char **)ft_calloc(map->length + 1, sizeof(char *));
	if (!map->map)
		terminate_error(ERR_MEM, SYS_MEM);
	idx = 0;
	while (get_line(&line, fd))
	{
		map->map[idx] = ft_strdup(line);
		idx++;
		ft_delete(line);
	}
}
