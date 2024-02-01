/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_ray.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 10:25:14 by ogonzale          #+#    #+#             */
/*   Updated: 2023/06/17 10:38:56 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_RAY_H
# define CUB3D_RAY_H

# include "cub3d_data.h"

// Ray calculations
void	calc_ray_pos_dir(t_game *game, int x);
void	calc_ray_delta_dist(t_game *game);
void	calc_ray_step_and_side_dist(t_game *game);

// DDA
void	perform_dda(t_game *game);

// Draw
void	draw_wall_and_background(t_game *game, int x);

#endif