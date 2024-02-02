/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_expander.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:39:35 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/02 17:27:05 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_EXPANDER_H
# define CUB3D_EXPANDER_H

# include "cub3d_parser_private.h"

int	map_expander(char **raw_info, t_raw_map_data raw_map_data, t_info *info);

#endif