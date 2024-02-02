/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inclusive_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 23:59:24 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/03 00:08:49 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d_basic_utils.h"

char    **inclusive_split(char const *str, char chr)
{
    char    **tab;

    if (!str)
        return (NULL);
    tab = (char **)ft_calloc((ft_strlen(str) + 1), sizeof(char *));
    if (!tab)
        return (NULL);

    return (tab);
}