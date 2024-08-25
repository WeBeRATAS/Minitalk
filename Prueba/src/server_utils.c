/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:05:08 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/07/18 18:28:32 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	send_signal_c(int pid, int signal)
{
	int	sig;

	sig = kill(pid, signal);
	if (sig != 0)
		reset_server(ERROR_7);
}

void	reset_server(char *error)
{
	ft_putstr_fd(error, 2);
	init_server();
}

void	manage_errors_s(char *error)
{
	ft_putstr_fd(error, 2);
	exit(EXIT_FAILURE);
}
