/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:16:44 by alajara-          #+#    #+#             */
/*   Updated: 2024/02/05 13:17:45 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"
#include "cub3d_parser_private.h"

void	parse(char **data, t_info *info)
{
	t_file_data	file_data;

	(void)info;
	file_data.metadate = NULL;
	file_data.body = NULL;
	(void)prs_file_data(data, &file_data);
	for (size_t i = 0; file_data.metadate[i]; i++)
		printf("%s\n", file_data.metadate[i]);
	// (void)prs_map(file_data.body, info);
	// (void)prs_txt(file_data.metadate, &info);
	// (void)prs_clr(file_data.metadata, &info);

	ft_memfree(file_data.metadate);
}
