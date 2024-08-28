/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <rbuitrag@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:48:27 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/03/25 17:29:46 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

static int	print_format(char type, va_list ap)
{
	if (type == 'c')
		return (print_char(va_arg(ap, int)));
	else if (type == 's')
		return (print_str(va_arg(ap, char *)));
	else if (type == 'd' || type == 'i')
		return (p_digit(va_arg(ap, int), 0));
	else if (type == 'x' || type == 'X')
		return (p_hexa((va_arg(ap, unsigned int)), type));
	else if (type == 'u')
		return (p_digit(va_arg(ap, int), 1));
	else if (type == 'p')
		return (print_pointer(va_arg(ap, unsigned long long)));
	else if (type == '%')
		return (print_char('%'));
	return (-1);
}

static int	validate_str(const char *str, va_list ap)
{
	int	control_s;
	int	count;

	control_s = 0;
	count = 0;
	while (*str)
	{
		control_s = count;
		if (*str == '%')
		{
			count += print_format(*(++str), ap);
			str++;
		}
		else
		{
			if (print_char(*str++) < 0)
				return (-1);
			count++;
		}
		if (control_s > count)
			return (-1);
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count_print;
	int		result_ftprint;

	va_start(ap, str);
	count_print = 0;
	if (!str)
		return (-1);
	result_ftprint = validate_str(str, ap);
	if (result_ftprint < 0)
		return (-1);
	else
		count_print += result_ftprint;
	va_end(ap);
	return (count_print);
}
/*
int	main(void)
{
	ft_printf("x%i", -10);
	count = ft_printf("hello %s\n", "Perraco");
ft_printf("The caracteres son MY %d\n", count);
	count = printf("hello %s\n", "Perraco");
	printf("The caracteres con printf son %d\n", count);
	count = ft_printf("Hex de Myprintf X %X\n", 42);
	ft_printf("The caracteres con MY %d\n", count);
	count = printf("Hex de printf X %X\n", 42);
	printf("The hex are printf  %d\n", count);
	count = ft_printf("Hex de Myprintf x %x\n", 42);
	ft_printf("The caracteres con MY %d\n", count);
	count = printf("Hex de printf x %x\n", 42);
	printf("The hex are printf  %d\n", count);
	:count = ft_printf("%d\n", INT32_MIN);
	ft_printf("The chars written are MY %d\n", count);
	count = printf("%d\n", INT32_MIN);
	printf("The chars written are pirintf  %d\n", count);
	count = ft_printf("%u\n", INT32_MIN);
	ft_printf("The chars written are MY %d\n", count);
	count = printf("%u\n", INT32_MIN);
	printf("The chars written are printf  %d\n", count);
	count =	ft_printf("%p\n", (void *)42);
	count = printf("%p\n", (void *)42);
	printf("The chars written are printf  %d\n", count);
	count = ft_printf("%i\n", INT32_MAX);
	ft_printf("The chars written are MY %d\n", count);
	count = printf("%i\n", INT32_MAX);
	i = printf("%s\n", (char *)NULL);
	i = ft_printf("%s\n", (char *)NULL);
	printf("%d\n", i);
	i = ft_printf("My printf %d\n", i);
	//count = printf("%\n");
	// Si el parametro es NULL, escribe (null) Y CUENTA
	// if (write(1, "(null)", 6) != 6)
	// return (-1);
	return (0);
}*/
