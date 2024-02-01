/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:06:24 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/06/05 16:13:04 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	*ft_realloc(void *ptr, size_t count, size_t size)
{
	void	*new_ptr;

	if (!ptr)
		return (ft_calloc(count, size));
	if (!size)
		ft_delete(ptr);
	new_ptr = ft_calloc(count, size);
	if (!new_ptr)
		return (NULL);
	ft_memcpy(new_ptr, ptr, ft_strlen(ptr));
	ft_delete(ptr);
	return (new_ptr);
}
