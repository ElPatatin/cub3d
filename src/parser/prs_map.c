/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:42:26 by alajara-          #+#    #+#             */
/*   Updated: 2024/02/18 19:33:52 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"
#include "cub3d_parser.h"
#include "cub3d_parser_private.h"
#include "cub3d_errors.h"

/**
 * @brief Parses the map data and stores it in the info struct.
 * 
 * @param data {char **} - The raw data.
 * @param info {t_info *} - The info struct.
 * 
 * @retval 0 - Success.
 * 
 * @note
 * First, it gets the raw map data, such as with, height and  where the map
 * starts and ends.
 * Then, it allocates the memory for the map grid.
 * After that, it expands the map, adding a border of walls around it.
 * Then, it sanitizes the map, checking if it has any invalid characters.
 * Finally, it validates the map, checking if it has any invalid configurations.
 */
int	prs_map(char **data, t_info *info)
{
	t_raw_map_data	raw_map_data;

	if (get_raw_map_data(data, &raw_map_data))
		terminate_error(ERR_INV_DTA, SYS_INV_DTA);
	if (allocate_map_grid(raw_map_data, info))
		terminate_error(ERR_MEM, SYS_MEM);
	if (map_expander(data, raw_map_data, info))
		terminate_error(ERR_EXP_MAP, SYS_EXP_MAP);
	if (map_sanitizer(info, raw_map_data.width, raw_map_data.height))
		terminate_error(ERR_BAD_MAP, SYS_BAD_MAP);
	if (map_validator(info, raw_map_data.width, raw_map_data.height))
		terminate_error(ERR_BAD_MAP, SYS_BAD_MAP);
	return (0);
}
