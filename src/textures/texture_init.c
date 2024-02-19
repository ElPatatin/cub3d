/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:43:31 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/19 17:45:32 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"
#include "cub3d_texture.h"
#include "cub3d_errors.h"

static void		build_walls_array(t_graphics *g);
static void		get_wall_texture(t_graphics *g);
static void		set_wall_texture(t_graphics *g);
static uint32_t	*set_texture_pixel(t_image *img);

/**
 * @brief Initialize the textures
 * 
 * @param graphics (t_graphics *) - The graphics structure
 * 
 * @retval None
 * 
 * @note
 * This function initializes the textures. It builds the walls array, gets the
 * wall texture, and sets the wall texture.
*/
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

/**
 * @brief Build the walls array
 * 
 * @param g (t_graphics *) - The graphics structure
 * 
 * @retval None
 * 
 * @note
 * This function builds the walls array. It allocates memory for the walls array
 * and copies the texture paths to the walls array.
*/
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

/**
 * @brief Get the wall texture
 * 
 * @param g (t_graphics *) - The graphics structure
 * 
 * @retval None
 * 
 * @note
 * This function gets the wall texture. It loops through the walls array and
 * gets the wall texture.
*/
static void	get_wall_texture(t_graphics *g)
{
	int		i;
	void	*img;

	i = -1;
	while (++i < 4)
	{
		img = (t_image *)malloc(sizeof(t_image));
		if (!img)
			terminate_error(ERR_MEM, SYS_MEM);
		g->tex.img[i] = img;
		g->tex.img[i] = mlx_xpm_file_to_image(g->mlx, g->info->txr_walls[i],
				&g->tex.img[i]->width, &g->tex.img[i]->height);
		if (!g->tex.img[i])
			terminate_error(ERR_TEX_RED, SYS_TEX_RED);
		ft_delete(img);
	}
}

/**
 * @brief Set the wall texture
 * 
 * @param g (t_graphics *) - The graphics structure
 * 
 * @retval None
 * 
 * @note
 * This function sets the wall texture. It loops through the walls array and
 * sets the wall texture.
*/
static void	set_wall_texture(t_graphics *g)
{
	int	i;

	i = -1;
	while (++i < 4)
		g->tex.texture[i] = set_texture_pixel(g->tex.img[i]);
	i = -1;
}

/**
 * @brief Set the texture pixel
 * 
 * @param img (t_image *) - The image structure
 * 
 * @retval uint32_t * - The texture pixel
 * 
 * @note
 * This function sets the texture pixel. It gets the texture pixel from the
 * image structure.
*/
static uint32_t	*set_texture_pixel(t_image *img)
{
	return ((uint32_t *)mlx_get_data_addr(img, &img->bpp,
			&img->line_len, &img->endian));
}
