/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_errors.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:03:58 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/19 14:56:10 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_ERRORS_H
# define CUB3D_ERRORS_H

// ERROR MESSAGES
// ==============
# define ERR_ARGS		"\aInvalid number of arguments!\n\
 > Program usage: ./cub3D [path_to_file.cub]\n"
# define ERR_PRNT		"\aSomething went wrong while doing a print!\n"
# define ERR_MEM		"\aSomething went wrong while allocating memory!\n"
# define ERR_WIN		"\aSomething went wrong while opening a window!\n"
# define ERR_OPEN_MAP	"\aMap could not be opened!\n"
# define ERR_READ_MAP	"\aMap could not be read!\n"
# define ERR_CLOSE_MAP	"\aMap could not be closed!\n"
# define ERR_EXT_MAP	"\aMap extension is invalid!\n"
# define ERR_DUP_MAP	"\aMap is duplicated!\n"
# define ERR_BAD_MAP	"\aMap is invalid!\n"
# define ERR_DUP_TEX	"\aMap texture is duplicated!\n"
# define ERR_BAD_TEX	"\aMap texture is invalid!\n"
# define ERR_TEX		"\a texture was found missing!\n"
# define ERR_DUP_CLR	"\aMap colour is duplicated!\n"
# define ERR_BAD_CLR	"\aMap colour is invalid!\n"
# define ERR_CLR		"\aA map colour was found missing!\n"
# define ERR_IMG		"\aA map image was found missing or invalid!\n"
# define ERR_INV_DTA	"\aInvalid data found while parsing map!\n"
# define ERR_EXP_MAP	"\aMap expansion have gone wrong at some point!\n"
# define ERR_HDR_MIS    "\aThe header is incomplete or does not exist!\n"
# define ERR_HDR_DUP    "\aThe content of the header is duplicated!\n"
# define ERR_TEX_CLS	"\aTexture could not be closed!\n"
# define ERR_TEX_DIR	"\aDirectory not allowed as texture file!\n"

// ERROR CODES
// ===========
# define SYS_ARGS		1
# define SYS_PRNT		2
# define SYS_MEM		3
# define SYS_WIN		4
# define SYS_OPEN_MAP	5
# define SYS_READ_MAP	6
# define SYS_CLOSE_MAP	7
# define SYS_EXT_MAP	8
# define SYS_DUP_MAP	9
# define SYS_BAD_MAP	10
# define SYS_DUP_TEX	11
# define SYS_BAD_TEX	12
# define SYS_TEX		13
# define SYS_DUP_CLR	14
# define SYS_BAD_CLR	15
# define SYS_CLR		16
# define SYS_IMG		17
# define SYS_INV_DTA	18
# define SYS_EXP_MAP	19
# define SYS_HDR_MIS    20
# define SYS_HDR_DUP    21
# define SYS_TEX_CLS	22
# define SYS_TEX_DIR	23

int		print_error(const char *str, int syserr);
void	terminate_error(const char *str, int syserr);

#endif
