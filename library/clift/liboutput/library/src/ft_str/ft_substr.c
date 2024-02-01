/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:21:55 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/04/03 15:51:33 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char
	*ft_substr(char const *s, t_unt start, size_t len)
{
	char	*dst;
	size_t	i;
	size_t	size;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (start > i)
		return (ft_strdup(""));
	if (start + len > i)
		len = i - start;
	size = len + 1;
	dst = (char *)malloc(sizeof(char) * size);
	if (!dst)
		return (NULL);
	ft_memcpy(dst, s + start, len);
	dst[len] = '\0';
	return (dst);
}
