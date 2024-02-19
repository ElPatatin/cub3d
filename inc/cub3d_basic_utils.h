/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_basic_utils.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:57:48 by alajara-          #+#    #+#             */
/*   Updated: 2024/02/18 17:43:08 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BASIC_UTILS_H
# define CUB3D_BASIC_UTILS_H

# include "libft.h"
# include "cub3d_struct.h"

t_bool	is_spc(char c);
char	**inclusive_split(char const *str, char chr);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strnchr(const char *s, int c, size_t n);
void	ft_mlx_put_pixel(t_graphics *graphics, int x, int y, int color);
int		fix_angle(int a);
float	deg_to_rad(int a);
void	ft_bit_swap(int a, int b);

#endif