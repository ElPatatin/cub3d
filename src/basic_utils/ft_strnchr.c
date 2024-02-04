/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 23:05:20 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/04 23:25:09 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d_basic_utils.h"

/**
 * @brief Returns a pointer to the first occurrence of the character c in the
 * string s, or NULL if the character is not found in the first n bytes of s.
 * 
 * @param s The string to be searched.
 * @param c The character to be located.
 * @param n The number of bytes to be searched.
 * 
 * @retval char*
*/
char	*ft_strnchr(const char *s, int c, size_t n)
{
	while (n > 0 && *s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
		n--;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}