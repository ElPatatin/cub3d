/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:16:44 by alajara-          #+#    #+#             */
/*   Updated: 2024/02/04 21:08:06 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"
#include "cub3d_parser_private.h"

void	parse(char **data, t_info *info)
{
	// TODO

	(void)prs_map(data, info);
	// if (prs_txt(data, &info))
	// 	return (3);
	// if (prs_clr(data, &info))
	// 	return (4);
}
