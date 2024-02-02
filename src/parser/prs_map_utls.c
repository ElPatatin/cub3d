/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_map_utls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:27:04 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/02 13:04:59 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d_parser_private.h"

static size_t  locate_map_start(char **raw_info);

void    get_raw_map_data(char **raw_info, t_raw_map_data *raw_map_data)
{
    raw_map_data->map_start = locate_map_start(raw_info);
}

static size_t  locate_map_start(char **raw_info)
{
    size_t  row_index;

    row_index = 0;
    while(raw_info[row_index])
    {
        size_t char_index;

        char_index = 0;
        while (raw_info[row_index][char_index] == ' ' || raw_info[row_index][char_index] == '\t')
            ++char_index;
        if (raw_info[row_index][char_index] == '\0' || raw_info[row_index][char_index] == '\n')
            continue ;
        while (raw_info[row_index][char_index] != '\0' || raw_info[row_index][char_index] == '\n')
        {
            while (ft_strchr(VALID_MAP_CHARS, raw_info[row_index][char_index]))
                printf("%c", raw_info[row_index][char_index]);
        }
    }
    return row_index;
}