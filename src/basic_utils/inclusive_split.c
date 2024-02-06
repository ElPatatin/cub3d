/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inclusive_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 23:59:24 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/05 19:36:12 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d_basic_utils.h"

static char	**do_split(char **tab, const char *str, char chr, size_t len);

/**
 * @brief Splits a string into an array of strings using a character as delimiter.
 * It includes the delimiter in the strings.
 * 
 * @param str {char const *} - The string to split.
 * @param chr {char} - The delimiter character.
 * 
 * @retval char ** - The array of strings.
 */
char	**inclusive_split(const char *str, char chr)
{
	char	**tab;
	size_t	len;
	
	if (!str)
		return (NULL);
	len = ft_strlen(str);
	tab = (char **)ft_calloc((len + 1), sizeof(char *));
	if (!tab)
		return (NULL);
	tab = do_split(tab, str, chr, len);
	if (!tab)
		return (NULL);
    return (tab);
}

static char	**do_split(char **tab, const char *str, char chr, size_t len)
{
	size_t count;
	size_t start;
	size_t i;
	size_t substr_len;

	count = 0;
	start = 0;
	i = -1;
	while (++i <= len)
	{
		if (str[i] == chr || str[i] == '\0')
		{
			substr_len = i - start + 1;
			tab[count] = (char *)ft_calloc(substr_len, sizeof(char));
			if (!tab[count])
				return ((char **)ft_memfree(tab));
			ft_strncpy(tab[count], str + start, substr_len - 1);
			++count;
			start = i + 1;
        }
    }
	tab[count] = NULL;
	return (tab);
}
