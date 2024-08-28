/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_digit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <rbuitrag@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:36:46 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/03/25 17:45:01 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_num(unsigned int n)
{
	int	size;
	int	ctrl;

	size = 0;
	ctrl = 0;
	if (!n)
		return (-1);
	if (n / 10 != 0)
		if (ft_print_num(n / 10) == -1)
			return (-1);
	ctrl = print_char((n % 10) + '0');
	if (ctrl == -1)
		return (-1);
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static int	ctrl_printchar(long n)
{
	int	size;

	size = 0;
	if (n == 0)
	{
		if (print_char('0') < 0)
			return (-1);
		size = 1;
	}
	if (n < 0)
	{
		if (print_char('-') < 0)
			return (-1);
		size = 1;
	}
	return (size);
}

int	p_digit(long n, int ctrl_uns)
{
	int	size;
	int	ctrl;

	ctrl = 0;
	size = 0;
	if (ctrl_uns)
		n = (unsigned int) n;
	if (ctrl_printchar(n) == -1)
		return (-1);
	else if (n < 0 || n == 0)
	{
		size += 1;
		n = -n;
	}
	if (n > 0)
	{
		ctrl = ft_print_num(n);
		if (ctrl == -1)
			return (-1);
	}
	return (size + ctrl);
}
/*
int	main(void)
{
	int	num;
	int	cont;

	num = 10;
	cont = 0;
	p_digit(num, 0);
	return (0);
}*/
