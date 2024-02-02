/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:09:13 by alajara-          #+#    #+#             */
/*   Updated: 2024/02/02 19:35:13 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_parser.h"

int	main(int ac, char **av)
{
	if (ac != 2)
	   return(1);
	// BEFORE ANYTHING
	/**
	 * New split
	     * Check empty lines with only spaces and new lines characters
	*/
	parse(reader(av[1]));
	return (0);
}
