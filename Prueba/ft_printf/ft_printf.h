/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  ft_printf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <rbuitrag@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:29:59 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/03/25 17:33:26 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>
# include <ctype.h>

int		ft_printf(const char *str, ...);
int		print_char(int c);
int		print_str(char *str);
int		p_digit(long n, int ctrl_uns);
int		print_pointer(unsigned long long ptr);
int		p_hexa(unsigned int num, const char word);

#endif
