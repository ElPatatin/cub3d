/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:16:44 by alajara-          #+#    #+#             */
/*   Updated: 2024/02/02 20:22:35 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_struct.h"
#include "cub3d_parser_private.h"

 // TODO: return struct with main information.
int parse(char **raw_info)
{
	t_info	info;

	// precheck
	if (prs_map(raw_info, &info))
		return (2);
	// if (prs_txt(raw_info, &info))
	// 	return (3);
	// if (prs_clr(raw_info, &info))
	// 	return (4);
	return (0);
}
