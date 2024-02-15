/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_player.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:52:21 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/15 22:41:27 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PLAYER_H
# define CUB3D_PLAYER_H

# include "cub3d_struct.h"

# define ROT_SPEED	0.03
# define MOVE_SPEED	0.05

void	player_init(t_graphics *graphics);
void	handle_player_movement(t_graphics *graphics);
void	handle_player_rotation(t_graphics *graphics);

#endif