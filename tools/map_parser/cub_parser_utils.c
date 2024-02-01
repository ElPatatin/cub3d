/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:31:03 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/06/09 18:54:51 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_data.h"
#include "cub3d_map.h"
#include "cub3d_parser.h"
#include "cub3d_errors.h"

t_bool	check_valid_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0 || fd > OPEN_MAX)
		return (TRUE);
	return (FALSE);
}

void	check_valid_number(int *nbr, char *line)
{
	size_t	len;
	char	*val;

	len = 0;
	while (ft_isdigit(line[len]))
		len++;
	*nbr = ft_atoi(line);
	val = ft_itoa(*nbr);
	if (!val)
		terminate_error(ERR_MEM, SYS_MEM);
	if (ft_strncmp(val, line, len))
	{
		ft_delete(val);
		terminate_error(ERR_BAD_CLR, SYS_BAD_CLR);
	}
	ft_delete(val);
	if (*nbr > 255 || *nbr < 0)
		terminate_error(ERR_BAD_CLR, SYS_BAD_CLR);
}

char	**ft_grid_realloc(char **grid, ssize_t count, ssize_t size)
{
	char	**new_grid;
	ssize_t	idx;

	idx = -1;
	new_grid = (char **)ft_calloc(count, size);
	if (!new_grid)
		terminate_error(ERR_MEM, SYS_MEM);
	while (++idx < count - 1)
	{
		new_grid[idx] = ft_strdup(grid[idx]);
		if (!new_grid[idx])
			terminate_error(ERR_MEM, SYS_MEM);
	}
	return (new_grid);
}

void	ft_gridcpy(char **grid, char **cpygrid, char *first)
{
	ssize_t	idx;

	idx = -1;
	grid[0] = ft_strdup(first);
	while (cpygrid[++idx])
	{
		grid[idx + 1] = ft_strdup(cpygrid[idx]);
		if (!grid[idx + 1])
			terminate_error(ERR_MEM, SYS_MEM);
	}
}

t_bool	ft_gridcheck(char *line)
{
	ssize_t	idx;

	idx = -1;
	while (line[++idx])
	{
		if (!(line[idx] == '1' || line[idx] == '0'
				|| line[idx] == 'S' || line[idx] == 'N' || line[idx] == 'W'
				|| line[idx] == 'E' || line[idx] == 'D' || line[idx] == 'C'
				|| ft_isspace(line[idx])))
			return (TRUE);
	}
	return (FALSE);
}
