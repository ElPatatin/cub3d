/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:42:23 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/19 14:29:47 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_colors.h"
#include "cub3d_errors.h"

int	print_error(const char *str, int syserr)
{
	if (ft_printf_fd(STDERR_FILENO, "%sError\n%s%s", RED, str, RESET) == -1)
		terminate_error(ERR_PRNT, SYS_PRNT);
	return (syserr);
}

void	terminate_error(const char *str, int syserr)
{
	if (ft_printf_fd(STDERR_FILENO, "%sError\n%s%s", RED, str, RESET) == -1)
		exit(ERRNUM);
	exit(syserr);
}
