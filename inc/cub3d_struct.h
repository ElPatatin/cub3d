/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:46:34 by alajara-          #+#    #+#             */
/*   Updated: 2024/02/19 13:58:48 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

# include "libft.h"
# include "cub3d.h"

// STRUCT S_ARGV
// ============================================================================

/**
 * @brief	This union contains the color of the ceiling and the floor.
 * 
 * @param	clr		Array of 4 unsigned char that contains the color.
 * @param	argb	The color in ARGB format.
*/
typedef union s_argb
{
	unsigned char	clr[4];
	unsigned int	argb;
}	t_argb;

// STRUCT S_INFO
// ============================================================================

/**
 * @brief	This structure contains all the information of the simulaion.
 * 
 * @param	map			The map of the simulation.
 * @param	txr_no		The path to the north texture.
 * @param	txr_so		The path to the south texture.
 * @param	txr_we		The path to the west texture.
 * @param	txr_ea		The path to the east texture.
 * @param	txr_walls	The path to the walls textures.
 * @param	c			The color of the ceiling.
 * @param	f			The color of the floor.
*/
typedef struct s_info
{
	char	**map;
	char	*txr_no;
	char	*txr_so;
	char	*txr_we;
	char	*txr_ea;
	char	*txr_walls[4];
	t_argb	c;
	t_argb	f;
}	t_info;

// STRUCT S_IMAGE
// ============================================================================

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
typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_image;

// STRUCT S_WALL_LINE
// ============================================================================

/**
 * @brief	This structure contains all the information of the wall line.
 * 
 * @param	start	The start of the wall line.
 * @param	end		The end of the wall line.
 * @param	height	The height of the wall line.
*/
typedef struct s_wall_line
{
	int	start;
	int	end;
	int	height;
}	t_wall_line;

// STRUCT S_TEXTURE
// ============================================================================

/**
 * @brief	This structure contains all the information of the texture.
 * 
 * @param	tex_x		The x position of the texture.
 * @param	tex_y		The y position of the texture.
 * @param	tex_pos		The position of the texture.
 * @param	tex_idx		The index of the texture.
 * @param	step		The step of the texture.
 * @param	wall_x		The x position of the wall.
 * @param	color		The color of the texture.
 * @param	img			The image array of the texture.
 * @param	texture		The texture array of the texture.
 * @param	buffer		The buffer of the texture.
*/
typedef struct s_texture
{
	int			tex_x;
	int			tex_y;
	float		tex_pos;
	int			tex_idx;
	float		step;
	float		wall_x;
	uint32_t	color;
	t_image		*img[4];
	uint32_t	*texture[4];
	uint32_t	**buffer;
}	t_texture;

// STRUCT S_PLAYER
// ============================================================================

/**
 * @brief	This structure contains all the information of the player.
 * 
 * @param	pos_x			The x position of the player.
 * @param	pos_y			The y position of the player.
 * @param	dir_x			The direction of the player in the x axis.
 * @param	dir_y			The direction of the player in the y axis.
 * @param	plane_x			The plane of the player in the x axis.
 * @param	plane_y			The plane of the player in the y axis.
 * @param	move_up			The speed of the player moving up.
 * @param	move_down		The speed of the player moving down.
 * @param	move_left		The speed of the player moving left.
 * @param	move_right		The speed of the player moving right.
 * @param	rotate_left		Value of the rotation to the left.
 * @param	rotate_right	Value of the rotation to the right.
 * @param	mouse_rotate	True if the mouse is rotating the player,
							false otherwise.
 * @param	rotate_speed	The speed of the rotation.
*/
typedef struct s_player
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
	t_bool	mouse_rotate;
	float	rotate_speed;
}	t_player;

// STRUCT S_RAY
// ============================================================================

/**
 * @brief	This structure contains all the information of the ray.
 * 
 * @param	dir_x			The direction of the ray in the x axis.
 * @param	dir_y			The direction of the ray in the y axis.
 * @param	delta_dist_x	The distance between the ray and the next x side.
 * @param	delta_dist_y	The distance between the ray and the next y side.
 * @param	side_dist_x		The distance between the ray and the next x side.
 * @param	side_dist_y		The distance between the ray and the next y side.
 * @param	step_x			The step in the x axis.
 * @param	step_y			The step in the y axis.
 * @param	map_x			The x position in the map.
 * @param	map_y			The y position in the map.
 * @param	distance		The distance of the ray.
 * @param	hit				True if the ray hit a wall, false otherwise.
 * @param	side			The side of the wall hit.
*/
typedef struct s_ray
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
	t_bool	hit;
	int		side;
}	t_ray;

// STRUCT S_GRAPHICS
// ============================================================================

/**
 * @brief	This structure contains all the information of the graphics.
 * 
 * @param	mlx		The mlx pointer.
 * @param	win		The window pointer.
 * @param	img		The image pointer.
 * @param	mmap	The mini-map image pointer.
 * @param	info	The info pointer.
 * @param	player	The player info.
 * @param	ray		The ray info.
 * @param	line	The wall line info.
 * @param	tex		The texture info.
*/
typedef struct s_graphics
{
	void		*mlx;
	void		*win;
	t_image		*img;
	t_image		*mmap;
	t_info		*info;
	t_player	player;
	t_ray		ray;
	t_wall_line	line;
	t_texture	tex;
}	t_graphics;

#endif