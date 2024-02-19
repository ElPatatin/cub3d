/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:43:31 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/19 15:51:47 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"
#include "cub3d_texture.h"

static void		build_walls_array(t_graphics *g);
static void		get_wall_texture(t_graphics *g);
static void		set_wall_texture(t_graphics *g);
static uint32_t	*set_texture_pixel(t_image *img);

void	texture_init(t_graphics *graphics)
{
	int	x;
	int	y;

	x = -1;
	build_walls_array(graphics);
	get_wall_texture(graphics);
	while (++x < TEXWIDTH)
	{
		y = -1;
		while (++y < TEXHEIGHT)
			set_wall_texture(graphics);
	}
}

static void	build_walls_array(t_graphics *g)
{
	g->info->txr_walls[0] = ft_strdup(g->info->txr_no);
	if (!g->info->txr_walls[0])
		exit(1);
	g->info->txr_walls[1] = ft_strdup(g->info->txr_so);
	if (!g->info->txr_walls[1])
		exit(1);
	g->info->txr_walls[2] = ft_strdup(g->info->txr_we);
	if (!g->info->txr_walls[2])
		exit(1);
	g->info->txr_walls[3] = ft_strdup(g->info->txr_ea);
	if (!g->info->txr_walls[3])
		exit(1);
}

static void	get_wall_texture(t_graphics *g)
{
	int		i;
	void	*img;

	i = -1;
	while (++i < 4)
	{
		img = (t_image *)malloc(sizeof(t_image));
		if (!img)
			exit(EXIT_FAILURE);
		g->tex.img[i] = img;
		g->tex.img[i] = mlx_xpm_file_to_image(g->mlx, g->info->txr_walls[i],
				&g->tex.img[i]->width, &g->tex.img[i]->height);
		if (!g->tex.img[i])
			exit(EXIT_FAILURE);
		ft_delete(img);
	}
}

static void	set_wall_texture(t_graphics *g)
{
	int	i;

	i = -1;
	while (++i < 4)
		g->tex.texture[i] = set_texture_pixel(g->tex.img[i]);
	i = -1;
}

static uint32_t	*set_texture_pixel(t_image *img)
{
	return ((uint32_t *)mlx_get_data_addr(img, &img->bpp,
			&img->line_len, &img->endian));
}
