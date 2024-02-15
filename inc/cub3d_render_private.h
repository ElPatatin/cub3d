/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_render_private.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:17:07 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/15 16:10:44 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_RENDER_PRIVATE_H
# define CUB3D_RENDER_PRIVATE_H

# include "cub3d_struct.h"

# define RAYS 64
# define MMAP_SQR_SIZE 10

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
void	perfome_dda(t_graphics *g);

// On ray_pixel_calc.c
int		calculate_lowest_pixel_to_fill(int line_height);
int		calculate_highest_pixel_to_fill(int line_height);
void	draw_line(t_graphics *g, int x, int draw_start, int draw_end);

#endif
