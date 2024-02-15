/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_keys.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:31:59 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/15 22:38:30 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_KEYS_H
# define CUB3D_KEYS_H

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

// #  define SPC_KEY			(int)32
// #  define ENT_KEY		(int)
// #  define QUE_KEY		(int)

# endif

#endif