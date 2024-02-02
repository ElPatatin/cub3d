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

is_cf_flag(char c)
{
	
}

get_color(char *)
{

}

// TODO proper error handling
// Allocates the information for info.c and info.f
// Also checks for duplicated inputs, in case of not 
prs_clr(char **r_info, t_info *info)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while(r_info[++i])
	{
		sc = r_info[i][1];
		if (r_info[i][0] == 'C' && (sc == ' ' || sc == '\t')) // reemplazar por is_spc
		{
			if (j++ % 2 == 1)
				return(1); 								// ERROR mas de una C
			info.c = ft_strlcpy(r_info[i] + 2, ft_strlen(r_info[i] + 2));
		}
		else if (r_info[i][0] == 'F' && (sc == ' ' || sc == '\t'))
		{
			if (j >> 1 == 1)
				return(1); 								// ERROR mas de una F
			j += 2;
			get_color(r_info[i]);
		}
	}
	if (j != 3)
		return (1);										// ERROR no hay un C y F
	return (0);
}