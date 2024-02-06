/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_reader_private.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:49:46 by alajara-          #+#    #+#             */
/*   Updated: 2024/02/06 15:49:48 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_READER_PRIVATE_H
# define CUB3D_READER_PRIVATE_H

# include "cub3d.h"
# include "cub3d_errors.h"

static int	check_map_extension(const char *map_name);
static char	*read_map_file(int fd, char *buffer);
static void	*clean_buffer(void **dlt);

#endif
