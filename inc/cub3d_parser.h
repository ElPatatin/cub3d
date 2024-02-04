/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:45:08 by alajara-          #+#    #+#             */
/*   Updated: 2024/02/04 20:28:22 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PARSER_H
# define CUB3D_PARSER_H

# include "cub3d_struct.h"

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

void  parse(char **raw_info, t_info *info);

#endif