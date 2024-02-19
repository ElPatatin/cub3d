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

#  define ESC_KEY		53

#  define W_KEY			13
#  define A_KEY			0
#  define S_KEY			1
#  define D_KEY			2

#  define UP_KEY		126
#  define DWN_KEY		125
#  define RGT_KEY		124
#  define LFT_KEY		123

#  define ZOOM_IN_KEY	4
#  define ZOOM_OUT_KEY	5

#  define SPC_KEY		49
#  define ENT_KEY		36
#  define QUE_KEY		12

# elif __linux__

#  define ESC_KEY			65307

#  define A_KEY				97
#  define D_KEY				100
#  define W_KEY       		119
#  define S_KEY				115

#  define LFT_KEY			65361
#  define RGT_KEY			65363
#  define UP_KEY			65362
#  define DWN_KEY			65364

// #  define ZOOM_IN_KEY	(int)4
// #  define ZOOM_OUT_KEY	(int)5

// #  define SPC_KEY			(int)32
// #  define ENT_KEY		(int)
// #  define QUE_KEY		(int)

# endif

#endif