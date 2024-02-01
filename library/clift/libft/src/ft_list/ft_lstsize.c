/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:16:50 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/04/09 13:29:43 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t
	ft_lstsize(t_list *lst)
{
	size_t	size;
	t_list	*current;

	size = 0;
	current = lst;
	while (current)
	{
		current = current->next;
		++size;
	}
	return (size);
}
