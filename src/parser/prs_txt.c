/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_txt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:42:37 by alajara-          #+#    #+#             */
/*   Updated: 2024/02/19 15:57:46 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_parser_private.h"
#include "cub3d_errors.h"

static int	validate_texture(char *metadata, char **txr, int *j);

int	prs_txt(char **metadata, t_info *info)
{
	int	i;
	int	j;
	int	status;

	i = -1;
	j = 0;
	status = 0;
	while (metadata[++i])
	{
		if (ft_strncmp(metadata[i], "NO ", 3) == 0)
			status = validate_texture(metadata[i], &info->txr_no, &j);
		else if (ft_strncmp(metadata[i], "SO ", 3) == 0)
			status = validate_texture(metadata[i], &info->txr_so, &j);
		else if (ft_strncmp(metadata[i], "WE ", 3) == 0)
			status = validate_texture(metadata[i], &info->txr_we, &j);
		else if (ft_strncmp(metadata[i], "EA ", 3) == 0)
			status = validate_texture(metadata[i], &info->txr_ea, &j);
	}
	return (status);
}

static int	validate_texture(char *metadata, char **txr, int *j)
{
	char	*cpy;
	int		fd;

	cpy = ft_strtrim(&metadata[3], " ");
	if (!cpy)
		terminate_error(ERR_MEM, SYS_MEM);
	fd = open(cpy, O_RDONLY | O_DIRECTORY);
	if (fd >= 0)
		terminate_error(ERR_TEX_DIR, SYS_TEX_DIR);
	close(fd);
	fd = open(cpy, O_RDONLY);
	if (fd < 0 || fd > OPEN_MAX)
		terminate_error(ERR_BAD_TEX, SYS_BAD_TEX);
	if (close(fd) < 0)
		terminate_error(ERR_TEX_CLS, SYS_TEX_CLS);
	*txr = cpy;
	++*j;
	return (0);
}
