/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_errors.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:03:58 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/01 18:18:14 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_ERRORS_H
# define CUB3D_ERRORS_H

// Error Messages
# define ERR_ARGS		(char *)"\aInvalid number of arguments!\n"
# define ERR_PRNT		(char *)"\aSomething went wrong while doing a print!\n"
# define ERR_MEM		(char *)"\aSomething went wrong while allocating memory!\
									\n"
# define ERR_WIN		(char *)"\aSomething went wrong while opening a window!\n"
# define ERR_OPEN_MAP	(char *)"\aMap could not be opened!\n"
# define ERR_READ_MAP	(char *)"\aMap could not be read!\n"
# define ERR_CLOSE_MAP	(char *)"\aMap could not be closed!\n"
# define ERR_EXT_MAP	(char *)"\aMap extension is invalid!\n"
# define ERR_DUP_MAP	(char *)"\aMap is duplicated!\n"
# define ERR_BAD_MAP	(char *)"\aMap is invalid!\n"
# define ERR_DUP_TEX	(char *)"\aMap texture is duplicated!\n"
# define ERR_BAD_TEX	(char *)"\aMap texture is invalid!\n"
# define ERR_TEX		(char *)"\aA map texture was found missing!\n"
# define ERR_DUP_CLR	(char *)"\aMap colour is duplicated!\n"
# define ERR_BAD_CLR	(char *)"\aMap colour is invalid!\n"
# define ERR_CLR		(char *)"\aA map colour was found missing!\n"
# define ERR_IMG		(char *)"\aA map image was found missing or invalid!\n"

// Error Codes
# define SYS_ARGS		(int)1
# define SYS_PRNT		(int)2
# define SYS_MEM		(int)3
# define SYS_WIN		(int)4
# define SYS_OPEN_MAP	(int)5
# define SYS_READ_MAP	(int)6
# define SYS_CLOSE_MAP	(int)7
# define SYS_EXT_MAP	(int)8
# define SYS_DUP_MAP	(int)9
# define SYS_BAD_MAP	(int)10
# define SYS_DUP_TEX	(int)11
# define SYS_BAD_TEX	(int)12
# define SYS_TEX		(int)13
# define SYS_DUP_CLR	(int)14
# define SYS_BAD_CLR	(int)15
# define SYS_CLR		(int)16
# define SYS_IMG		(int)17

int		print_error(char *str, int syserr);
void	terminate_error(char *str, int syserr);

#endif