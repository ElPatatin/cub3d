/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:16:51 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/06/17 11:50:00 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_map.h"
#include "cub3d_data.h"
#include "cub3d_player.h"
#include "cub3d_ray.h"
#include "cub3d_hooks.h"
#include "cub3d_errors.h"

static void	render_game(t_game *game);

int	main(int ac, char **av)
{
	t_game	game;
	t_map	map;

	if (ac != 2)
		return (print_error(ERR_ARGS, SYS_ARGS));
	map_handler(av[1], &map);
	game.map = map;
	init_player(&game);
	graphics(&game);
	return (EXIT_SUCCESS);
}

void	graphics(t_game *game)
{
	t_mlx	vals;
	t_data	data;

	init_vals(&vals, &data);
	game->mlx = vals;
	init_imgs(game);
	new_window(&game->mlx, game->mlx.data);
	hooks(game);
	game_loop(game);
	mlx_loop(vals.ptr);
}

int	game_loop(t_game *game)
{
	mlx_destroy_image((&game->mlx)->ptr, (&game->mlx)->data->img);
	game->mlx.data->img = mlx_new_image((&game->mlx)->ptr, WINWIDTH, WINHEIGHT);
	game->mlx.data->addr = mlx_get_data_addr(
			game->mlx.data->img, &game->mlx.data->bpp,
			&game->mlx.data->line_len, &game->mlx.data->endian);
	render_game(game);
	mlx_put_image_to_window((&game->mlx)->ptr, (&game->mlx)->win,
		(&game->mlx)->data->img, 0, 0);
	return (0);
}

static void	render_game(t_game *game)
{
	int		x;

	handle_player_movement(game);
	handle_player_rotation(game);
	x = -1;
	while (++x < WINWIDTH)
	{
		calc_ray_pos_dir(game, x);
		calc_ray_delta_dist(game);
		calc_ray_step_and_side_dist(game);
		perform_dda(game);
		draw_wall_and_background(game, x);
	}
}

void	hooks(t_game *game)
{
	mlx_loop_hook((&game->mlx)->ptr, game_loop, game);
	mlx_hook((&game->mlx)->win, 2, 1L << 0, handle_keys_press, game);
	mlx_hook((&game->mlx)->win, 3, 1L << 1, handle_keys_release, game);
	mlx_hook((&game->mlx)->win, 17, 0, mouse_close_onclick, &game->mlx);
	mlx_hook((&game->mlx)->win, 4, 1L << 2, mouse_press_handler, game);
	mlx_hook((&game->mlx)->win, 5, 1L << 3, mouse_release_handler, game);
	mlx_hook((&game->mlx)->win, 6, 1L << 6, mouse_camera_handler, game);
}
