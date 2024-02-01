/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:46:34 by alajara-          #+#    #+#             */
/*   Updated: 2024/02/01 17:46:36 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
\
#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

/*
			map		map for playing
			txr_XX	texture of [NO]rth, [SO]uth, ...
			clng	cealing color
			flr		floor color
*/
struct typedef s_info
{
	char	**map;
	char	*txr_no;
	char	*txr_so;
	char	*txr_we;
	char	*txr_ea;
	int		c;
	int 	f;
}	t_info;

#endif