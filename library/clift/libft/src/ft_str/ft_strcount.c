/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:01:01 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/19 16:30:00 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcount(char **str)
{
	size_t	idx;

	idx = 0;
	if (!str || !str[idx])
		return (0);
	while (str[idx])
		++idx;
	return (idx);
}
