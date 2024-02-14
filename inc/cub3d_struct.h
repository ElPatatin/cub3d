/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:46:34 by alajara-          #+#    #+#             */
/*   Updated: 2024/02/14 18:29:44 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

typedef struct s_info		t_info;
typedef union s_argb		t_argb;
typedef struct s_image		t_image;
typedef struct s_player		t_player;
typedef struct s_ray		t_ray;
typedef struct s_graphics	t_graphics;

/**
 * @brief	This union contains the color of the ceiling and the floor.
 * 
 * @param	clr		Array of 4 unsigned char that contains the color.
 * @param	argb	The color in ARGB format.
*/
union s_argb
{
	unsigned char	clr[4];
	unsigned int	argb;
};


/**
 * @brief	This structure contains all the information of the simulaion.
 * 
 * @param	map		The map of the simulation.
 * @param	txr_no	The path to the north texture.
 * @param	txr_so	The path to the south texture.
 * @param	txr_we	The path to the west texture.
 * @param	txr_ea	The path to the east texture.
 * @param	c		The color of the ceiling.
 * @param	f		The color of the floor.
*/
struct	s_info
{
	char	**map;
	char	*txr_no;
	char	*txr_so;
	char	*txr_we;
	char	*txr_ea;
	t_argb	c;
	t_argb	f;
};

/**
 * @brief	This structure contains all the information of the image.
 * 
 * @param	img			The image.
 * @param	addr		The address of the image.
 * @param	bpp			The bits per pixel of the image.
 * @param	line_len	The line length of the image.
 * @param	endian		The endian of the image.
 * @param	width		The width of the image.
 * @param	height		The height of the image.
*/
struct	s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
};

struct	s_player
{
	float	pos_x;
	float	pos_y;
	float	dir_x;
	float	dir_y;
	float	plane_x;
	float	plane_y;
	int		move_up;
	int		move_down;
	int		move_left;
	int		move_right;
	int		rotate_left;
	int		rotate_right;
};

struct	s_ray
{
	float	dir_x;
	float	dir_y;
	float	delta_dist_x;
	float	delta_dist_y;
	float	side_dist_x;
	float	side_dist_y;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
	float	distance;
	int		hit;
	int		side;
};

/**
 * @brief	This structure contains all the information of the graphics.
 * 
 * @param	mlx		The mlx pointer.
 * @param	win		The window pointer.
 * @param	img		The image pointer.
 * @param	info	The info pointer.
*/
struct	s_graphics
{
	void		*mlx;
	void		*win;
	t_image		*img;
	t_info		*info;
	t_player	player;
	t_ray		ray;
};


#endif