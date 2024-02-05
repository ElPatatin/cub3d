/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:09:13 by alajara-          #+#    #+#             */
/*   Updated: 2024/02/05 13:20:02 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_basic_utils.h"
#include "cub3d_parser.h"
#include "cub3d_errors.h"

int	main(int ac, char **av)
{
	char	*raw;
	char	**data;
	t_info	info;

	if (ac != 2)
	   return(print_error(ERR_ARGS, SYS_ARGS));
	raw = reader(av[1]);
	if (!raw)
		terminate_error(ERR_READ_MAP, SYS_READ_MAP);
	data = inclusive_split(raw, '\n');
	if (!data)
		terminate_error(ERR_MEM, SYS_MEM);
	ft_delete(raw);
	parse(data, &info);
	ft_memfree(data);

	// for (size_t i = 0; data[i]; i++)
	// 	printf("%p\n", data[i]);

	// graphics(&info);
	return (0);
}
