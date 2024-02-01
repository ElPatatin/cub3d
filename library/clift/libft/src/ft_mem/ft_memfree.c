/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:41:15 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/04/17 20:05:55 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	**ft_memfree(char **ptr)
{
	ssize_t	idx;

	idx = -1;
	while (ptr[++idx])
	{
		if (ptr[idx])
		{
			free(ptr[idx]);
			ptr[idx] = NULL;
		}
	}
	free(ptr);
	ptr = NULL;
	return (NULL);
}
