/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:27:04 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/02 16:05:29 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d_parser_private.h"

static size_t	locate_map_start(char **raw_info);
static size_t	locate_map_end(char **raw_info);
static int		get_map_width(char **raw_info, size_t map_start,
					size_t map_end);

int	get_raw_map_data(char **raw_info, t_raw_map_data *raw_map_data)
{
	raw_map_data->map_start = locate_map_start(raw_info);
	if (raw_map_data->map_start == 0)
		return (TRUE);
	raw_map_data->map_end = locate_map_end(raw_info);
	if (raw_map_data->map_end == 0)
		return (TRUE);
	raw_map_data->width = get_map_width(raw_info, raw_map_data->map_start,
			raw_map_data->map_end);
	if (raw_map_data->width == 0)
		return (TRUE);
	raw_map_data->height = raw_map_data->map_end - raw_map_data->map_start;
	if (raw_map_data->map_end == 0)
		return (TRUE);
	return (FALSE);
}

int	allocate_map_grid(char **raw_info,
		t_raw_map_data raw_map_data, t_info *info)
{
	info->map = ft_calloc(sizeof(char *), raw_map_data.height + 1);
	if (!info->map)
		return (TRUE);
	return (FALSE);
}

static size_t	locate_map_start(char **raw_info)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (raw_info[++i])
	{
		j = 0;
		while (raw_info[i][j] == ' ' || raw_info[i][j] == '\t')
			++j;
		if (raw_info[i][j] == '\0' || raw_info[i][j] == '\n')
			continue ;
		if (ft_strchr(VALID_MAP_CHARS, raw_info[i][j]))
			return (i + 1);
	}
	return (0);
}

static size_t	locate_map_end(char **raw_info)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (raw_info[++i])
	{
		j = 0;
		while (raw_info[i][j] == ' ' || raw_info[i][j] == '\t')
			++j;
		if (raw_info[i][j] == '\0' || raw_info[i][j] == '\n')
			continue ;
		if (raw_info[i + 1] == NULL
			&& ft_strchr(VALID_MAP_CHARS, raw_info[i][j]))
			return (i + 1);
	}
	return (0);
}

static int	get_map_width(char **raw_info, size_t map_start, size_t map_end)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = map_start - 1;
	j = -1;
	k = 0;
	while (raw_info[++i] && i != map_end)
	{
		j = -1;
		while (!ft_strchr(EOL, raw_info[i][++j]))
			;
		if (j > k)
			k = j;
	}
	return (k);
}
