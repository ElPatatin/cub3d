/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:09:13 by alajara-          #+#    #+#             */
/*   Updated: 2024/02/01 17:16:27 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int ac, char **av)
{
	int exit_status;

	if (ac != 2)
	   return(1);
	exit_status = parse(av);
	return (exit_status);
}
