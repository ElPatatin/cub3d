/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:44:39 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/02/01 15:53:08 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	**ft_splitfree(char **ptr, int len);
static int	ft_wordcount(char const *s, char c, t_bool flag);
static int	start(char *s, char c, int i);

char
	**ft_split(char const *str, char c)
{
	int		idx;
	char	**dst;
	size_t	len;

	dst = (char **)ft_calloc((ft_wordcount((char *)str, c, TRUE) + 1),
			sizeof(char *));
	if (!dst)
		return (NULL);
	idx = 0;
	len = 0;
	while (idx < ft_wordcount((char *)str, c, TRUE))
	{
		len = ft_wordcount((char *)&str[start((char *)str, c, idx)], c, FALSE);
		dst[idx] = ft_substr((char *)str, start((char *)str, c, idx), len);
		if (!dst[idx])
			return (ft_splitfree(dst, idx));
		idx++;
	}
	return (dst);
}

static int
	start(char *str, char c, int idx)
{
	int	nbr;
	int	aux;

	nbr = 0;
	aux = 0;
	while (str[nbr] == c)
		nbr++;
	while (str[nbr])
	{
		if (aux == idx)
			return (nbr);
		while (str[nbr] != c)
			nbr++;
		while (str[nbr] == c)
			nbr++;
		aux++;
	}
	return (nbr);
}

static int
	ft_wordcount(char const *str, char c, t_bool flag)
{
	int		count;

	count = 0;
	if (flag == FALSE)
	{
		while (*str && *str != c)
		{
			str++;
			++count;
		}
		return (count);
	}
	while (*str)
	{
		if (*str && *str != c)
		{
			++count;
			while (*str && *str != c)
				str++;
		}
		else
			str++;
	}
	return (count);
}

static char
	**ft_splitfree(char **ptr, int len)
{
	while (len > -1)
	{
		free(ptr[len]);
		ptr[len] = NULL;
		len--;
	}
	free(ptr);
	ptr = NULL;
	return (NULL);
}
