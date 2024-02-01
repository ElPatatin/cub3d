/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_player.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 11:33:35 by ogonzale          #+#    #+#             */
/*   Updated: 2023/05/21 18:40:27 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PLAYER_H
# define CUB3D_PLAYER_H

# include "cub3d_data.h"

# define ROT_SPEED	0.02
# define MOVE_SPEED	0.05

// Player movement
void	handle_player_movement(t_game *game);

// Player rotation
void	handle_player_rotation(t_game *game);

#endif