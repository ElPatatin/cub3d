/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_file_body.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:08:26 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/05 22:43:41 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_parser_private.h"
#include "cub3d_errors.h"

t_bool	check_metadata(const char *currnet_data)
{
	ssize_t	i;
	char	*metadata[MIN_HEADER + 1];

	i = -1;
	built_valid_metadata(metadata);
	while (metadata[++i])
	{
		if (currnet_data[0] == '\0' || currnet_data == NULL)
			continue ;
		if (!ft_strncmp(currnet_data, metadata[i], ft_strlen(metadata[i])))
			return (TRUE);
	}
	return (FALSE);
}

int	get_body_size(char **data, ssize_t i, size_t *size)
{
	ssize_t	j;
	t_bool	map_found;
	t_bool	map_complete;

	map_found = FALSE;
	map_complete = FALSE;
	while (--i >= 0)
	{
		j = -1;
		while (data[i][++j] == ' ')
			;
		if (data[i][j] == '1' || data[i][j] == '0')
		{
			if (!map_found && map_complete)
				return (TRUE);
			(*size)++;
			map_found = TRUE;
		}
		else if (map_found && !map_complete)
		{
			map_complete = TRUE;
			map_found = FALSE;
		}
	}
	return (FALSE);
}
