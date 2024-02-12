/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:45:08 by alajara-          #+#    #+#             */
/*   Updated: 2024/02/12 11:26:03 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PARSER_H
# define CUB3D_PARSER_H

# include "cub3d_struct.h"

# define NORTH	"NO"
# define SOUTH	"SO"
# define WEST	"WE"
# define EAST	"EA"
# define SPRITE	"S"

# define FLOOR	"F"
# define CEALING	"C"

# define WALL		'1'
# define MPTY		'0'
# define P_NO		'N'
# define P_SO		'S'
# define P_WE		'W'
# define P_EA		'E'
# define CLOSE_DOOR	'D'
# define OPEN_DOOR	'C'

# define VOID	'V'

void	parse(char **raw_info, t_info *info);

#endif