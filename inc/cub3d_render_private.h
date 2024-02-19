/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_render_private.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:17:07 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/19 14:57:23 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_RENDER_PRIVATE_H
# define CUB3D_RENDER_PRIVATE_H

# include "cub3d_struct.h"

# define RAYS 64
# define PITCH 0
// PITCH is the distance from the top of the screen to the top of the wall

void	put_background_layer(t_graphics *graphics);
void	put_wall_layer(t_graphics *graphics);

// RAY FUNCTIONS
// =============

// On ray_calc.c
void	calculate_ray_position(t_graphics *g, int x);
void	calculate_map_position(t_graphics *g);
void	calculate_length_of_ray(t_graphics *g);
void	calculate_step_and_initial_side_dist(t_graphics *g);
void	calculate_distance_projected(t_graphics *g);

// On ray_dda.c
void	perfom_dda(t_graphics *g);

// On ray_pixel_calc.c
void	set_line_limit(t_graphics *g);
void	calculate_texture(t_graphics *g, int x);
void	draw_buffer(t_graphics *g);

#endif
