/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_file_body.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:08:26 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/05 13:16:40 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_parser_private.h"
#include "cub3d_errors.h"

t_bool	check_metadata(char *currnet_data)
{
	ssize_t	i;
    char	*metadata[MIN_HEADER + 1];

	i = -1;
    built_valid_metadata(metadata);
	while (metadata[++i])
	{
		if (currnet_data[0] == '\0' || currnet_data == NULL)
			continue;
		if (!ft_strncmp(currnet_data, metadata[i], ft_strlen(metadata[i])))
			return (TRUE);
	}
	return (FALSE);
}