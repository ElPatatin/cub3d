/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:03:49 by cpeset-c          #+#    #+#             */
/*   Updated: 2023/05/06 18:10:10 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_colors.h"
#include "cub3d_errors.h"

int	print_error(char *str, int syserr)
{
	if (ft_printf_fd(STDERR_FILENO, "%sError: %s", RED, str) == ERRNUM)
		terminate_error(ERR_PRNT, SYS_PRNT);
	return (syserr);
}

void	terminate_error(char *str, int syserr)
{
	if (ft_printf_fd(STDERR_FILENO, "%sError: %s", RED, str) == ERRNUM)
		exit(ERRNUM);
	exit(syserr);
}
