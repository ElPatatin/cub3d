/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:28:37 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/01 18:32:11 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_errors.h"

static int	check_map_extension(char *map_name);
static char	*read_map_file(int fd, char *buffer);
static void	*clean_buffer(void **dlt);

char	**reader(char *map_name)
{
	int		fd;
	char	**map_data;
	char	*buffer;

	if (check_map_extension(map_name))
		terminate_error(ERR_EXT_MAP, SYS_EXT_MAP);
	fd = open(map_name, O_RDONLY);
	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		terminate_error(ERR_OPEN_MAP, SYS_OPEN_MAP);
	buffer = ft_strdup("");
	if (!buffer)
		terminate_error(ERR_MEM, SYS_MEM);
	buffer = read_map_file(fd, buffer);
	if (!buffer)
		terminate_error(ERR_READ_MAP, SYS_READ_MAP);
	if (close(fd))
		terminate_error(ERR_CLOSE_MAP, SYS_CLOSE_MAP);
	map_data = ft_split(buffer, '\n');
	if (!map_data)
		terminate_error(ERR_MEM, SYS_MEM);
	return (map_data);
}

static int	check_map_extension(char *map_name)
{
	size_t	len;
	char	*str;

	len = ft_strlen(map_name);
	str = ft_strrchr(map_name, '/');
	if (!str)
		str = map_name;
	if (len <= 4 || ft_strlen(&str[1]) <= 4)
		return (TRUE);
	if (ft_strncmp(MAP_EXT, &map_name[len - 4], ft_strlen(MAP_EXT)))
		return (TRUE);
	return (FALSE);
}

static char	*read_map_file(int fd, char *buffer)
{
	char	*line;
	int		bytes;

	line = ft_calloc((BUFFER_SIZE + 2), sizeof(char));
	if (!line)
		terminate_error(ERR_MEM, SYS_MEM);
	bytes = 1;
	while (bytes && !ft_strchr(buffer, '\n'))
	{
		bytes = read(fd, line, BUFFER_SIZE);
		if (bytes == -1)
		{
			clean_buffer((void **)&line);
			return (clean_buffer((void **)&buffer));
		}
		line[bytes] = '\0';
		buffer = ft_memjoin(buffer, line);
		if (!buffer)
			return (clean_buffer((void **)&line));
	}
	clean_buffer((void **)&line);
	if (buffer)
		return (buffer);
	return (NULL);
}

static void	*clean_buffer(void **dlt)
{
	free(*dlt);
	*dlt = NULL;
	return (NULL);
}
