/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_hooks.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:57:18 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/06/17 11:20:06 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_HOOKS_H
# define CUB3D_HOOKS_H

# include "cub3d_data.h"

# ifdef __APPLE__

#  define ESC_KEY		(int)53

#  define W_KEY			(int)13
#  define A_KEY			(int)0
#  define S_KEY			(int)1
#  define D_KEY			(int)2

#  define UP_KEY		(int)126
#  define DWN_KEY		(int)125
#  define RGT_KEY		(int)124
#  define LFT_KEY		(int)123

#  define ZOOM_IN_KEY	(int)4
#  define ZOOM_OUT_KEY	(int)5

#  define SPC_KEY		(int)49
#  define ENT_KEY		(int)36
#  define QUE_KEY		(int)12

# elif __linux__

#  define ESC_KEY			(int)65307

#  define A_KEY				(int)97
#  define D_KEY				(int)100
#  define W_KEY       		(int)119
#  define S_KEY				(int)115

#  define LFT_KEY			(int)65361
#  define RGT_KEY			(int)65363
#  define UP_KEY			(int)65362
#  define DWN_KEY			(int)65364

// #  define ZOOM_IN_KEY	(int)4
// #  define ZOOM_OUT_KEY	(int)5

#  define SPC_KEY			(int)32
// #  define ENT_KEY		(int)
// #  define QUE_KEY		(int)

# endif

// Key Hooks
int	handle_keys(int keycode, t_game *game);
int	handle_keys_release(int keycode, t_game *game);
int	handle_keys_press(int keycode, t_game *game);
int	key_close_on_esc(int keycode, t_mlx *vals);
int	key_print_hook(int keycode, t_mlx *vals);

// Mouse Hooks
int	mouse_close_onclick(t_mlx *vals);
int	mouse_press_handler(int button, int x, int y, t_game *game);
int	mouse_release_handler(int button, int x, int y, t_game *game);
int	mouse_camera_handler(int x, int y, t_game *game);

#endif