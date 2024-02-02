/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_map_utls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:27:04 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/02 13:15:18 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d_parser_private.h"

static size_t  locate_map_start(char **raw_info);

void    get_raw_map_data(char **raw_info, t_raw_map_data *raw_map_data)
{
    raw_map_data->map_start = locate_map_start(raw_info);
    if 
}

static size_t  locate_map_start(char **raw_info)
{
    size_t  i;

    i = 0;
    while(raw_info[i])
    {
        size_t j;

        j = 0;
        while (raw_info[i][j] == ' ' || raw_info[i][j] == '\t')
            ++j;
        if (raw_info[i][j] == '\0' || raw_info[i][j] == '\n')
            continue ;
        while (raw_info[i][j] != '\0' || raw_info[i][j] == '\n')
        {
            while (ft_strchr(VALID_MAP_CHARS, raw_info[i][j++]))
                printf("%c", raw_info[i][j]);
        }
    }
    return i;
}