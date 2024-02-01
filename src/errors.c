/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:42:23 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/01 18:22:06 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_colors.h"
#include "cub3d_errors.h"

int	print_error(char *str, int syserr)
{
	if (ft_printf_fd(STDERR_FILENO, "%sError\n%s", RED, str) == ERRNUM)
		terminate_error(ERR_PRNT, SYS_PRNT);
	return (syserr);
}

void	terminate_error(char *str, int syserr)
{
	if (ft_printf_fd(STDERR_FILENO, "%sError\n%s", RED, str) == ERRNUM)
		exit(ERRNUM);
	exit(syserr);
}