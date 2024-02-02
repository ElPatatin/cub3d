/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parser_private.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:45:08 by alajara-          #+#    #+#             */
/*   Updated: 2024/02/02 18:18:02 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PARSER_PRIVATE_H
# define CUB3D_PARSER_PRIVATE_H

# include <stddef.h>
# include "cub3d_struct.h"

# define SPCTAB				(char *)" \t"
# define VALID_MAP_CHARS	(char *)"01"
# define EOL				(char *)"\0\n"

typedef struct s_raw_map_data	t_raw_map_data;

struct	s_raw_map_data
{
	size_t	width;
	size_t	height;
	size_t	map_start;
	size_t	map_end;
};

int	prs_map(char **raw_info, t_info *info);

int	get_raw_map_data(char **raw_info, t_raw_map_data *raw_map_data);
int	allocate_map_grid(t_raw_map_data raw_map_data, t_info *info);

#endif