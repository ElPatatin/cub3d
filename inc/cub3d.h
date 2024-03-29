/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:28:53 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/21 15:34:31 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "ft_printf_fd.h"

# ifdef __APPLE__
#  define OS			"Apple"
#  include "mlx.h"
# elif __linux__
#  define OS			"Linux"
#  include "mlx.h"
# endif

# include <math.h>

// # define WINHEIGHT		1080
// # define WINWIDTH		1920
# define WINHEIGHT		720
# define WINWIDTH		1280
# define TITLE			"cub3d gatito miau miau"
# define MAP_EXT		".cub"
# define TEXWIDTH		64
# define TEXHEIGHT		64

#endif
