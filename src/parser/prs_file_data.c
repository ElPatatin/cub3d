/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_file_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:58:40 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/05 00:57:49 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_parser_private.h"

int prs_file_data(char **data, t_file_data *file_data)
{
    prs_file_header(data, file_data);
    // prs_file_body(data, file_data);
    return (0);
}

