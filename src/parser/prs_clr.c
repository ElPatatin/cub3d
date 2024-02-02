/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_clr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:42:09 by alajara-          #+#    #+#             */
/*   Updated: 2024/02/01 17:42:15 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d_struct.h"

t_bool	is_cf_flag(char c)
{
	if (c == 'C' || c == 'F')
		return (TRUE);
	return (FALSE);
}

int	get_subcolor(char **s)
{
	int n;
	int	val;

	n = -1;
	val = 0;
	while(++n < 3 && is_digit(s[n]))
	{
		val *= 10;
		val += (*s)[n] - '0'
	}
	if (!n)
		return (-1);
	*s += n;
	return (val);

}

// Gets a [s]tring begining with 'C' or 'F' and stores the value to the 
// corresponent parameter in t_info.
int	get_color(char *s)
{
	char	where;
	int		n;
	int		val;
	int		trueval;

	where = *s;
	while (*s && is_spc(*s))
		++s;
	trueval = get_subcolor(&s)
	if (trueval < 0 || *s != ',')
		return (-1);				// TODO: Error handling
	++s;
	trueval <<= 8;
	val = get_subcolor(&s)
	if (val < 0 || *s != ',')
		return (-1);				// TODO: Error handling
	++s;
	trueval = trueval << 8 + val;
	val = get_subcolor(&s)
	if (val < 0 || *s != ',')
		return (-1);				// TODO: Error handling
	trueval = trueval << 8 + val;
	return (trueval);
}

// TODO: proper error handling
// Allocates the information for info.c and info.f
// Also checks for duplicated inputs, in case of error returns the proper message
void	prs_clr(char **r_info, t_info *info)
{
	int	i;
	int	j;

	i = -1;
	while(r_info[++i])
	{
		if (is_c_flag(r_info[i][0]) && is_spc(r_info[i][1]))
		{
			if (*r_info[i] == 'C')
				info->c = 1 << 24 + get_color(++(r_info[i]));
			else
				info->f = 1 << 24 + get_color(++(r_info[i]));
		}
	}
	if (j != 3)
		return (1);										// ERROR no hay un C y F
	return (0);
}