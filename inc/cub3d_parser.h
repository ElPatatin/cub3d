/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:23:46 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/01 16:06:30 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PARSER_H
# define CUB3D_PARSER_H

# include "cub3d_data.h"

# define NORTH	(char *)"NO"
# define SOUTH	(char *)"SO"
# define WEST	(char *)"WE"
# define EAST	(char *)"EA"
# define SPRITE	(char *)"S"

# define FLOOR	(char *)"F"
# define CEALING	(char *)"C"

# define WALL		(char)'1'
# define MPTY		(char)'0'
# define P_NO		(char)'N'
# define P_SO		(char)'S'
# define P_WE		(char)'W'
# define P_EA		(char)'E'
# define CLOSE_DOOR	(char)'D'
# define OPEN_DOOR	(char)'C'

# define VOID	(char)'V'

// Parser Functions
void	get_map(int fd, size_t map_len, t_map *map);

// Parser Utils Functions
t_bool	check_valid_path(char *path);
void	check_valid_number(int *nbr, char *line);
char	**ft_grid_realloc(char **grid, ssize_t count, ssize_t size);
void	ft_gridcpy(char **grid, char **cpygrid, char *first);
t_bool	ft_gridcheck(char *line);

// Parser Texture Functions
void	load_north_texture(t_map *map);
void	load_south_texture(t_map *map);
void	load_west_texture(t_map *map);
void	load_east_texture(t_map *map);
void	load_sprite_texture(t_map *map);

// Parser Textures Utils Functions
void	parse_texture(char **line, char **texture, char *type);
t_bool	check_file(char *path);
t_bool	validate_textures(t_map *map);

// Parser Colours Functions
void	load_floor_colour(t_map *map);
void	load_cealing_colour(t_map *map);
void	parse_colour(char *line, int *colour, char letter);
t_bool	validate_colours(t_map *map);

// Parser Map Functions
size_t	get_max_length(t_map *map);
void	allocate_grid(t_map *map, size_t width);
void	replace_spaces_with_void(t_map *map);

// Parser Map Expander Functions
void	map_expander_handler(t_map *map, size_t width);

// Parser Map Validation Functions
t_bool	validate_map(t_map *map);

// Parser Map Format Functions
void	format_map(t_map *map);

#endif