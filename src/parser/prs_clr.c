/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_clr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:42:09 by alajara-          #+#    #+#             */
/*   Updated: 2024/02/06 17:21:23 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d_struct.h"
#include "cub3d_parser_private.h"
#include "cub3d_basic_utils.h"

static t_bool	is_cf_flag(char c)
{
	if (c == 'C' || c == 'F')
		return (TRUE);
	return (FALSE);
}

static int	get_subcolor(char **s)
{
	int n;
	int	val;

	n = -1;
	val = 0;
	while(++n < 3 && ft_isdigit((*s)[n]))
	{
		val *= 10;
		val += (*s)[n] - '0';
	}
	if (!n)
	{
		printf("error: 38 subcolor\n");
		return (-1);
	}
	*s += n;
	printf("subval = %d\n", val);
	return (val);

}

// Gets a [s]tring begining with 'C' or 'F' and stores the value to the 
// corresponent parameter in t_info.
static void	get_color(char *s, t_argb *clr)
{
	while (*s && is_spc(*s))
		++s;
	clr->clr[1] = get_subcolor(&s);
	// if (trueval < 0 || *s != ',')
	// 	return (-1);				// TODO: Error handling
	++s;
	clr->clr[2] = get_subcolor(&s);
	// if (val < 0 || *s != ',')
	// 	return (-1);				// TODO: Error handling
	++s;
	clr->clr[3] = get_subcolor(&s);
	printf("clr: %d\n", clr->argb);
	//return (trueval);
}

// TODO: proper error handling
// Allocates the information for info.c and info.f
// Also checks for duplicated inputs, in case of error returns the proper message
void	prs_clr(char **r_info, t_info *info)
{
	int	i;

	i = -1;
	while(r_info[++i])
	{
		if (is_cf_flag(r_info[i][0]) && is_spc(r_info[i][1]))
		{
			if (*r_info[i] == 'C')
				get_color(++(r_info[i]), &(info->c));
			else
				get_color(++(r_info[i]), &(info->f));
		}
	}
}