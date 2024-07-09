/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:22:12 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/07/09 19:34:21 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"minitalk.h"


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}
void	send_binary_signal(char *binary, int sp_id)
{
	int	i;

	i = 0;
	while (binary[i])
	{
		if (binary[i] == '0')
			kill(sp_id, SIGUSR2);
		else if (binary[i] == '1')
			kill(sp_id, SIGUSR1);
		usleep(300);
		i++;
	}
}

void	send_client_pid(int server_pid)
{
	char	*cpid;
	int		i;
	char	*c_binary;
	int		x;
	char	*s;

	i = 0;
	if (kill(server_pid,0) == -1)
	{
		s = "Error: PID invalid\n";
		ft_putstr(s);
		exit(1);
	}
	cpid = itoa_pid(getpid());
	while (cpid[i])
	{
		c_binary = convertbinary(cpid[i]);
		x = 0;
		while (c_binary[x])
		{
			if (c_binary[x] == '0')
				kill(server_pid, SIGUSR2);
			else if (c_binary[x] == '1')
				kill(server_pid, SIGUSR1);
			usleep(300);
			x++;
		}
		free(c_binary);
		i++;
	}
	free(cpid);
}

void	message(int signum)
{
	if (signum == SIGUSR1)
		write(1, "SUCCESS!\n", 10);
}

int	main(int argc, char **argv)
{
	int		i;
	int		len;
	char	*binary;
	char	*s;
	int		server_pid;

	i = 0;
	signal(SIGUSR1, message);
	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		if (server_pid <= 0)
		{
			s = "Error: Invalid server PID\n";
			ft_putstr(s);
			return (1);
		}
		send_client_pid(server_pid);
		len = ft_strlen(argv[2]);
		while (len >= i)
		{
			binary = convertbinary(argv[2][i]);
			send_binary_signal(binary, server_pid);
			free(binary);
			i++;
		}
	}
	else
	{
		s = "ERROR Check your message or PID\n";
		ft_putstr(s);
		return (1);
	}
	return (0);
}
