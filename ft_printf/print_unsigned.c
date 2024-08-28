/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <rbuitrag@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:44:32 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/03/21 11:00:55 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned(unsigned int n)
{
	int	size;

	size = 0;
	if (n == 0)
		size += print_char('0');
	else
	{
		if (n / 10 != 0)
			print_unsigned(n / 10);
		print_char((n % 10) + '0');
		while (n > 0)
		{
			n /= 10;
			size++;
		}
	}
	return (size);
}
