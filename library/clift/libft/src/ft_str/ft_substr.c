/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:52:20 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/04/18 18:12:00 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*dst;

	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	dst = (char *)ft_calloc(len + 1, sizeof(char));
	if (!dst)
		return (NULL);
	ft_memcpy(dst, s + start, len);
	return (dst);
}
