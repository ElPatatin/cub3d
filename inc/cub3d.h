/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:28:53 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/01 18:20:03 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "ft_printf_fd.h"

# ifdef __APPLE__
#  define OS			(char *)"Apple"
#  include "mlx.h"
# elif __linux__
#  define OS			(char *)"Linux"
#  include "mlx.h"
# endif

# include <math.h>

# define WINHEIGHT	(int)1080
# define WINWIDTH	(int)1920
# define TITLE		(char *)"cub3d gatito miau miau🐱"
# define MAP_EXT	(char *)".cub"

char	**reader(char *map_name);

#endif