/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:43:57 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/06 20:50:06 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_foreach(int *tab, int length, void (*f)(int))
{
	ssize_t	i;

	i = -1;
	while (++i < length)
		(*f)(tab[i]);
}
