/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_txt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:42:37 by alajara-          #+#    #+#             */
/*   Updated: 2024/02/15 15:57:16 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_parser_private.h"
#include "cub3d_errors.h"

static int	validate_texture(char *metadata, char **txr, char *txr_name, int *j);

int	prs_txt(char **metadata, t_info *info)
{
	int	i;
	int	j;
	int status;

	i = -1;
	j = 0;
	status = 0;
	while (metadata[++i])
	{
		if (ft_strncmp(metadata[i], "NO ", 3) == 0)
			status = validate_texture(metadata[i], &info->txr_no, "North", &j);
		else if (ft_strncmp(metadata[i], "SO ", 3) == 0)
			status = validate_texture(metadata[i], &info->txr_so, "South", &j);
		else if (ft_strncmp(metadata[i], "WE ", 3) == 0)
			status = validate_texture(metadata[i], &info->txr_we, "West", &j);
		else if (ft_strncmp(metadata[i], "EA ", 3) == 0)
			status = validate_texture(metadata[i], &info->txr_ea, "East", &j);
	}
	return (status);
}

static int	validate_texture(char *metadata, char **txr, char *txr_name, int *j)
{
	char	*cpy;
	int		fd;
	char	*errstr;

	cpy = ft_strtrim(&metadata[3], " ");
	if (!cpy)
		terminate_error(ERR_MEM, SYS_MEM);
	fd = open(cpy, O_RDONLY);
	if (fd < 0 || fd > OPEN_MAX)
	{
		ft_delete(cpy);
		*txr = NULL;
		errstr = ft_strjoin(txr_name, ERR_TEX);
		print_error(errstr, SYS_TEX);
		ft_delete(errstr);
		return (SYS_TEX);
	}
	if (close(fd) < 0)
		terminate_error(ERR_TEX_CLS, SYS_TEX_CLS);
	*txr = cpy;
	++*j;
	return (0);
}