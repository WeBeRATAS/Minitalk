/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 09:50:09 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/08/07 10:25:41 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	manage_errors_c(char *error)
{
	ft_putstr_fd(error, 2);
	exit(EXIT_FAILURE);
}

void	send_signal_s(int pid, int signal)
{
	int	sig;

	sig = kill(pid, signal);
	if (sig != 0)
		manage_errors_c(ERROR_4);
}

void	check_arg(char *arg_1, char *arg_2)
{
	int	i;

	if (arg_2[0] == '\0')
		manage_errors_c(ERROR_5);
	if (ft_atoi(arg_1) <= 0)
		manage_errors_c(ERROR_3);
	i = 0;
	while (arg_1[i])
	{
		if (!ft_isdigit(arg_1[i]))
			manage_errors_c(ERROR_3);
		i++;
	}
}
