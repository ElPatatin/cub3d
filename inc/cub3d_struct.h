/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:46:34 by alajara-          #+#    #+#             */
/*   Updated: 2024/02/02 12:14:53 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

typedef struct s_info	t_info;
typedef union s_argb	t_argb;

union s_argb
{
	unsigned char	clr[4];
	unsigned int	argb;
};

/*
			map		map for playing
			txr_XX	texture of [NO]rth, [SO]uth, ...
			clng	cealing color
			flr		floor color
*/
struct s_info
{
	char	**map;
	char	*txr_no;
	char	*txr_so;
	char	*txr_we;
	char	*txr_ea;
	t_argb	c;
	t_argb	f;
};

#endif