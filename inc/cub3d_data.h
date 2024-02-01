/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_data.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:54:19 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/06/17 11:37:06 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_DATA_H
# define CUB3D_DATA_H

# include <stddef.h>

# define WINHEIGHT	(int)1080
# define WINWIDTH	(int)1920
# define TITLE		(char *)"cub3d gatito miau miau"

typedef struct s_mlx		t_mlx;
typedef struct s_data		t_data;
typedef struct s_map		t_map;
typedef struct s_player		t_player;
typedef struct s_ray		t_ray;
typedef struct s_img_data	t_img_data;
typedef struct s_imgs		t_imgs;
typedef struct s_wall		t_wall;
typedef struct s_game		t_game;

struct s_player {
	float	x;
	float	y;
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
	int		mouse_rotate;
	double	normalized_rotate_speed;
};

struct s_ray
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

struct s_img_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
};

struct s_imgs
{
	t_img_data	north;
	t_img_data	south;
	t_img_data	east;
	t_img_data	west;
	t_img_data	sprite;
};

struct s_wall
{
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		color;
};

struct s_map {
	size_t	width;
	size_t	height;
	char	**map;
	size_t	length;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*s_path;
	int		floor_colour;
	int		ceiling_colour;
	char	**grid;
};

struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
};

struct s_mlx
{
	void	*ptr;
	void	*win;
	t_data	*data;
};

struct s_game
{
	t_map		map;
	t_player	player;
	t_ray		ray;
	t_wall		wall;
	t_imgs		imgs;
	t_mlx		mlx;
	double		time;
	double		old_time;
	int			**buffer;
};

#endif