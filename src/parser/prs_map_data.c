/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:27:04 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/12 11:19:25 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d_parser_private.h"

// ===============================PROTOTYPES===================================
static size_t	locate_map_start(char **raw_info);
static size_t	locate_map_end(char **raw_info);
static int		get_map_width(char **raw_info, ssize_t map_start,
					ssize_t map_end);
// ============================================================================

int	get_raw_map_data(char **raw_info, t_raw_map_data *raw_map_data)
{
	raw_map_data->map_start = locate_map_start(raw_info);
	if (raw_map_data->map_start == -1)
		return (TRUE);
	raw_map_data->map_end = locate_map_end(raw_info);
	if (raw_map_data->map_end == -1)
		return (TRUE);
	raw_map_data->width = get_map_width(raw_info, raw_map_data->map_start,
			raw_map_data->map_end);
	if (raw_map_data->width == -1)  
		return (TRUE);
	raw_map_data->width += 2;
	raw_map_data->height
		= (raw_map_data->map_end - raw_map_data->map_start) + 3;
	return (FALSE);
}

int	allocate_map_grid(t_raw_map_data raw_map_data, t_info *info)
{
	ssize_t	i;

	info->map = (char **)ft_calloc(sizeof(char *), raw_map_data.height + 1);
	if (!info->map)
		return (TRUE);
	i = -1;
	while (++i < raw_map_data.height)
	{
		info->map[i] = (char *)ft_calloc(raw_map_data.width + 1, sizeof(char));
		if (!info->map[i])
		{
			ft_memfree(info->map);
			return (TRUE);
		}
	}
	info->map[i] = NULL;
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
		while (raw_info[i][j] == ' ')
			++j;
		if (raw_info[i][j] == '\0')
			continue ;
		else if (raw_info[i][j] == '1' || raw_info[i][j] == '0')
			return (i);
	}
	return (-1);
}

static size_t	locate_map_end(char **raw_info)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (raw_info[++i])
	{
		j = 0;
		while (raw_info[i][j] == ' ')
			++j;
		if (raw_info[i][j] == '\0')
			continue ;
		else if (raw_info[i + 1] == NULL && (raw_info[i][j] == '1'
			|| raw_info[i][j] == '0'))
			return (i);
	}
	return (-1);
}

static int	get_map_width(char **raw_info, ssize_t map_start, ssize_t map_end)
{
	ssize_t	i;
	ssize_t	j;
	ssize_t	k;

	i = map_start - 1;
	j = -1;
	k = -1;
	while (raw_info[++i] && i != map_end)
	{
		j = -1;
		while (raw_info[i][++j])
			;
		if (j > k)
			k = j;
	}
	return (k);
}
