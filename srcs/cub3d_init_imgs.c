/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init_imgs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:13:36 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/06/16 18:18:39 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_data.h"
#include "cub3d_map.h"
#include "cub3d_parser.h"
#include "cub3d_errors.h"

void	init_imgs(t_game *game)
{
	t_imgs	imgs;

	imgs.north = init_img_data(game, 64, 64);
	imgs.south = init_img_data(game, 64, 64);
	imgs.east = init_img_data(game, 64, 64);
	imgs.west = init_img_data(game, 64, 64);
	game->imgs = imgs;
}

t_img_data	init_img_data(t_game *game, int width, int height)
{
	t_img_data	img_data;

	img_data.width = width;
	img_data.height = height;
	img_data.img = mlx_xpm_file_to_image(game->mlx.ptr, game->map.no_path,
			&img_data.width, &img_data.height);
	if (!img_data.img)
		terminate_error(ERR_IMG, SYS_IMG);
	img_data.addr = mlx_get_data_addr(img_data.img, &img_data.bpp,
			&img_data.line_len, &img_data.endian);
	if (!img_data.addr)
		terminate_error(ERR_IMG, SYS_IMG);
	return (img_data);
}

int	*load_img(t_img_data *img_data)
{
	int	*img;
	int	x;
	int	y;

	img = malloc(sizeof(int) * (img_data->width * img_data->height));
	if (!img)
		terminate_error(ERR_MEM, SYS_MEM);
	y = -1;
	while (++y < img_data->height)
	{
		x = -1;
		while (++x < img_data->width)
			img[y * img_data->width + x] = *(int *)(img_data->addr + \
			(y * img_data->line_len + x * (img_data->bpp / 8)));
	}
	return (img);
}
