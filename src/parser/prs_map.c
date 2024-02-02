/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:42:26 by alajara-          #+#    #+#             */
/*   Updated: 2024/02/02 16:05:42 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"
#include "cub3d_parser.h"
#include "cub3d_parser_private.h"
#include "cub3d_errors.h"

int prs_map(char **raw_info, t_info *info)
{
    t_raw_map_data  raw_map_data;
    
    if (get_raw_map_data(raw_info, &raw_map_data))
        terminate_error(ERR_INV_DTA, SYS_INV_DTA);
    if (allocate_map_grid(raw_info, raw_map_data, info))
        terminate_error(ERR_MEM, SYS_MEM);
    return (0);
}