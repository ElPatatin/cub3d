/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:36:08 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/19 14:59:23 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FD_H
# define FT_PRINTF_FD_H

# include "ft_data_structures.h"
# include "../library/inc/libftprintf.h"
# include <stdarg.h>

// Function Reference
# define FTRREF		"%cspdiuxX"

// Hexadecimal Prefix Direction
# define HEXPRE		"0x"
# define HEXPREU	"0X"

// ERROR VALS
# define ERRNUM		-1
# define NLLMSG		"(null)"

// SIGN FLAGS
# define PLSSIGN	1
# define MNSSIGN	2
# define SPCSIGN	3

// BASE VALS
# define STR_BASE10		"0123456789"
# define STR_BASE16L	"0123456789abcdef"
# define STR_BASE16U	"0123456789ABCDEF"

// ft_printf function
int		ft_printf_fd(int fd, const char *fmt, ...);

// Error Control Functions
void	err_check_fd(t_vars *vars, t_flags *flags);
void	err_print_fd(t_vars *vars);
void	err_width_fd(t_vars *vars, t_flags *flags);
void	err_margin_fd(t_vars *vars, t_flags *flags);
void	err_hex_preffix_fd(t_vars *vars, t_flags *flags);

// Parser Function
int		parse_params_fd(t_vars *vars, t_flags *flags);
int		get_params_fd(t_vars *vars, t_flags *flags);
int		check_fd(t_vars *vars, t_flags *flags);

// Init Param
t_vars	init_vars_fd(const char *fmt, int fd);
t_flags	init_flags_fd(void);
int		get_flags_fd(t_vars *vars, t_flags *flags);

// Utils Printf
int		input_check_fd(char c);
ssize_t	ft_clean_str_fd(char **str);
t_ll	aux_check_param_zeros_fd(t_vars *vars, t_flags *flags,
			char c, t_ll len);
ssize_t	print_hex_prefix_fd(t_vars *vars, t_flags *flags);

// Char Utils Printf
ssize_t	print_char_fd(unsigned char c, t_vars *vars);
ssize_t	print_string_fd(char *str, t_vars *var);

// Number Utils Printf
ssize_t	print_ptr_fd(t_ull nbr, t_vars *vars, t_flags *flags);
ssize_t	print_nbr_fd(t_ll nbr, t_vars *vars, t_flags *flags);
ssize_t	print_hex_fd(t_ll nbr, t_vars *vars, t_flags *flags);

// Margin Utils
ssize_t	add_width_fd(t_vars *vars, t_flags *flags);
ssize_t	add_zeros_fd(t_vars *varst, t_flags *flags);

#endif
