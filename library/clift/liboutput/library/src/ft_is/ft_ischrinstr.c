/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ischrinstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:36:37 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/04/03 16:46:46 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_bool
	ft_ischrinstr(char *str)
{
	while (*str)
	{
		if (ft_pstrchr(&str[1], str[0]))
			return (TRUE);
		str++;
	}
	return (FALSE);
}
