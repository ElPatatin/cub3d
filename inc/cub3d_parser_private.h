/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parser_private.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:45:08 by alajara-          #+#    #+#             */
/*   Updated: 2024/02/15 15:50:43 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PARSER_PRIVATE_H
# define CUB3D_PARSER_PRIVATE_H

# include "libft.h"
# include "cub3d_struct.h"

# define SPCTAB				" \t"
# define VALID_MAP_CHARS	"01"
# define EOL				"\0\n"
# define MIN_HEADER			6

typedef struct s_raw_map_data	t_raw_map_data;
typedef struct s_file_data		t_file_data;

struct	s_raw_map_data
{
	ssize_t	width;
	ssize_t	height;
	ssize_t	map_start;
	ssize_t	map_end;
};

struct	s_file_data
{
	char	**metadata;
	char	**body;
};

int		prs_file_data(char **data, t_file_data *file_data);

// FILE HEADERS
// ===========
int		get_metadata_size(char **data, char **metadata);
int		duplicated_metadata(char **data, char **metadata);
int		get_metadata(char *current_data, char **metadata,
			t_file_data *file_data);
int		end_of_metadata(char *line);
void	built_valid_metadata(char **valid_metadata);

// MAO TEXTURE
// ===========
int	prs_txt(char **metadata, t_info *info);

// FILE BODY
// =========
t_bool	check_metadata(const char *currnet_data);
int	get_body_size(char **data, ssize_t i, size_t *size);

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

// MAP COLOR
// =========
void	prs_clr(char **r_info, t_info *info);

#endif