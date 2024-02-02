/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parser_private.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:45:08 by alajara-          #+#    #+#             */
/*   Updated: 2024/02/02 13:03:10 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PARSER_PRIVATE_H
# define CUB3D_PARSER_PRIVATE_H

# include <stddef.h>
# include "cub3d_struct.h"

typedef struct s_raw_map_data   t_raw_map_data;

struct s_raw_map_data {
    size_t  width;
    size_t  height;
    size_t  map_start;
    size_t  map_end;
};

# define VALID_MAP_CHARS    (char *)"01NEWS"

int prs_map(char **raw_info, t_info *info);

void    get_raw_map_data(char **raw_info, t_raw_map_data *raw_map_data);

#endif