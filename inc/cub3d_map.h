/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:45:34 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/06/09 19:17:07 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_MAP_H
# define CUB3D_MAP_H

# include "cub3d_data.h"
# include "libft.h"

# define MAP_EXT	(char *)".cub"

// Map Functions
void	map_handler(char *cw_map, t_map *map);
void	read_map(int fd, t_map *map);

// Map Utils Function
t_bool	while_isspace(char *str);
t_bool	while_isdigit(char *str);
int		get_line(char **line, int fd);
void	get_map_length(int fd, int *map_len);
void	built_valid_chars(char *valid_chars, int *nullable);

#endif