/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_hooks.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:23:19 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/14 15:49:49 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_HOOKS_H
# define CUB3D_HOOKS_H

# include "cub3d_struct.h"

/**
 * @brief Hooks the events to the window
 * 
 * @param graphics 
*/
void	hooks(t_graphics *graphics);

// KEYBOARD HOOKS
// ==============

int		hooks_keys_press(int keycode, t_graphics *graphics);
void	exit_game(t_graphics *graphics);

int		hooks_keys_release(int keycode, t_graphics *graphics);

// MOUSE HOOKS
// ===========

int exit_on_click(t_graphics *graphics);

#endif