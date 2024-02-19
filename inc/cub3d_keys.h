/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_keys.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:31:59 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/19 14:56:43 by cpeset-c         ###   ########.fr       */
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

# endif

#endif
