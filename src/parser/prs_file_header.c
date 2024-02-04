/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_file_header.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:07:56 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/05 00:57:37 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_basic_utils.h"
#include "cub3d_parser.h"
#include "cub3d_parser_private.h"
#include "cub3d_errors.h"

static size_t   get_metadata_size(char **data, char **metadata);
static void built_valid_metadata(char **valid_metadata);

void    prs_file_header(char **data, t_file_data *file_data)
{
    size_t  i;
    size_t  j;
    char    *metadata[MIN_HEADER + 1];

    built_valid_metadata(metadata);
    file_data->metadate = (char **)ft_calloc(get_metadata_size(data, metadata) + 1, sizeof(char *));
    if (!file_data->metadate)
        terminate_error(ERR_MEM, SYS_MEM);
    i = -1;
    while (data[++i])
    {
        if (ft_strlen(data[i]) < 3)
            continue ;
        if (data[i][0] == '1' || data[i][0] == '0')
            break ;
        j = -1;
        while (metadata[++j] && data[i] != NULL)
            if (data[i][2] != '\0' && !ft_strncmp(data[i], metadata[j], ft_strlen(metadata[j])))
            {
                file_data->metadate[j] = ft_strdup(data[i]);
                if (!file_data->metadate[j])
                    terminate_error(ERR_MEM, SYS_MEM);
            }
    }
}

static size_t   get_metadata_size(char **data, char **metadata)
{
    size_t  i;
    size_t  j;
    size_t  metadata_size;

    i = -1;
    metadata_size = 0;
    while (data[++i])
    {
        if (ft_strlen(data[i]) < 3)
            continue ;
        if (data[i][0] == '1' || data[i][0] == '0')
            break ;
        j = -1;
        while (metadata[++j])
            if (!ft_strncmp(data[i], metadata[j], ft_strlen(metadata[j])) && data[i][2])
                metadata_size++;
    }
    if (metadata_size < MIN_HEADER)
    {
        ft_memfree(data);
        terminate_error(ERR_HDR_MIS, SYS_HDR_MIS);
    }
    return (metadata_size);
}

static void built_valid_metadata(char **valid_metadata)
{
    valid_metadata[0] = NORTH;
    valid_metadata[1] = SOUTH;
    valid_metadata[2] = WEST;
    valid_metadata[3] = EAST;
    valid_metadata[4] = FLOOR;
    valid_metadata[5] = CEALING;
    valid_metadata[6] = NULL;
}
