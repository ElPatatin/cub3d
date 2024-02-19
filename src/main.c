/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:09:13 by alajara-          #+#    #+#             */
/*   Updated: 2024/02/19 16:43:38 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_basic_utils.h"
#include "cub3d_errors.h"
#include "cub3d_parser.h"
#include "cub3d_reader.h"
#include "cub3d_graphics.h"

int	main(int ac, char **av)
{
	char	*raw;
	char	**data;
	t_info	info;

	if (ac != 2)
		return (print_error(ERR_ARGS, SYS_ARGS));
	raw = reader(av[1]);
	if (!raw)
		terminate_error(ERR_READ_MAP, SYS_READ_MAP);
	data = ft_split(raw, '\n');
	ft_delete(raw);
	if (!data)
		terminate_error(ERR_MEM, SYS_MEM);
	parse(data, &info);
	ft_memfree(data);
	graphics(&info);
	return (0);
}
