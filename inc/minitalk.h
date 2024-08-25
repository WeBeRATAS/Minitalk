/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 08:44:46 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/08/07 13:31:11 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <signal.h>

# define ERROR_1 "Signal error\n"
# define ERROR_2 "Arguments error, please retry\n"
# define ERROR_3 "PID error, retry\n"
# define ERROR_4 "Connection error\n"
# define ERROR_5 "Empty message\n"
# define ERROR_6 "Server busy. Try later\n"
# define ERROR_7 "Connection error\n"

typedef struct s_server
{
	int				pid_client;
	unsigned char	chr;
	int				bit;
	int				transmiting;
}	t_server;

void	manage_errors_c(char *error);
void	send_signal_s(int pid, int signal);
void	check_arg(char *arg_1, char *arg_2);
void	send_signal_c(int pid, int signal);
void	init_server(void);
void	manage_errors_s(char *error);
void	reset_server(char *error);

#endif
