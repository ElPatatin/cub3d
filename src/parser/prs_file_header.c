/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_file_header.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:07:56 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/05 13:16:30 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_basic_utils.h"
#include "cub3d_parser.h"
#include "cub3d_parser_private.h"
#include "cub3d_errors.h"

int get_metadata(char *current_data, char **metadata, t_file_data *file_data)
{	
	ssize_t	j;

	if (end_of_metadata(current_data))
		return (FALSE);
    j = -1;
    while (metadata[++j] && current_data != NULL)
	{
			if (current_data[0] == '\0' || current_data == NULL)
				continue;
            if (!ft_strncmp(current_data, metadata[j], ft_strlen(metadata[j])))
            {
                file_data->metadate[j] = ft_strdup(current_data);
                if (!file_data->metadate[j])
                    return (TRUE);
				return (FALSE);
            }
	}
	return (FALSE);
}

int	duplicated_metadata(char **data, char **metadata)
{
	ssize_t	i;
	ssize_t	j;
	t_bool	found;

	i = -1;
	while (metadata[++i])
	{
		found = FALSE;
		j = -1;
		while (data[++j])
		{
			if (data[j][0] == '\0' || data[j] == NULL)
				continue;
			if (!ft_strncmp(data[j], metadata[i], ft_strlen(metadata[i])))
			{
				if (found)
					return (TRUE);
				found = TRUE;
			}
		}
	}
	return (FALSE);
}

int   get_metadata_size(char **data, char **metadata)
{
    ssize_t  i;
    ssize_t  j;
    size_t  metadata_size;

    i = -1;
    metadata_size = 0;
    while (data[++i])
    {
		if (end_of_metadata(data[i]))
			break ;
        j = -1;
        while (metadata[++j])
		{
			if (data[i][0] == '\0' || data[i] == NULL)
				continue;
            if (!ft_strncmp(data[i], metadata[j], ft_strlen(metadata[j])))
                metadata_size++;
		}
    }
    if (metadata_size < MIN_HEADER)
        return (-1);
    return (metadata_size);
}

int	end_of_metadata(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '1' || line[i] == '0')
		return (TRUE);
	return (FALSE);
}

void built_valid_metadata(char **valid_metadata)
{
    valid_metadata[0] = NORTH;
    valid_metadata[1] = SOUTH;
    valid_metadata[2] = WEST;
    valid_metadata[3] = EAST;
    valid_metadata[4] = FLOOR;
    valid_metadata[5] = CEALING;
    valid_metadata[6] = NULL;
}
