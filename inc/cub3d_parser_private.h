/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parser_private.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:45:08 by alajara-          #+#    #+#             */
/*   Updated: 2024/02/05 12:34:04 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PARSER_PRIVATE_H
# define CUB3D_PARSER_PRIVATE_H

# include <stddef.h>
# include "cub3d_struct.h"

# define SPCTAB				(char *)" \t"
# define VALID_MAP_CHARS	(char *)"01"
# define EOL				(char *)"\0\n"
# define MIN_HEADER			(int)6

typedef struct s_raw_map_data	t_raw_map_data;
typedef struct s_file_data		t_file_data;

struct	s_raw_map_data
{
	size_t	width;
	size_t	height;
	size_t	map_start;
	size_t	map_end;
};

struct	s_file_data
{
	char	**metadate;
	char	**body;
};

int		prs_file_data(char **data, t_file_data *file_data);

// FILE HEADER
// ===========
int		get_metadata_size(char **data, char **metadata);
int		duplicated_metadata(char **data, char **metadata);
int		get_metadata(char *current_data, char **metadata, t_file_data *file_data);
int		end_of_metadata(char *line);
void	built_valid_metadata(char **valid_metadata);

// FILE BODY
// =========
t_bool	check_metadata(char *currnet_data);


// PARSE MAP
// =========
int		prs_map(char **data, t_info *info);

// MAP DATA
// ========
int		get_raw_map_data(char **raw_info, t_raw_map_data *raw_map_data);
int		allocate_map_grid(t_raw_map_data raw_map_data, t_info *info);

// MAP EXPANDER
// ============
int		map_expander(char **raw_info,
			t_raw_map_data raw_map_data, t_info *info);

// MAP SANITIZER
// =============
t_bool	map_sanitizer(t_info *info, size_t width, size_t height);

// MAP VALIDATOR
// =============
t_bool	map_validator(t_info *info, size_t width, size_t height);

#endif