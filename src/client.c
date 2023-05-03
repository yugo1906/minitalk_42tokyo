/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:42:05 by yughoshi          #+#    #+#             */
/*   Updated: 2023/05/03 10:26:53 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static bool	is_validation_argc_count(int argc)
{
	if (argc != 3)
	{
		ft_putstr_fd("Error_Usage: ./client <pid> <message>\n", STDERR_FILENO);
		return (ERROR);
	}
	else
		return (NOT_ERROR);
}

static bool	is_validation_pid(char *argv1)
{
	size_t	i;
	int		pid;

	i = 0;
	while (argv1[i])
	{
		if (!(argv1[i] >= '0' && argv1[i] <= '9'))
		{
			ft_putstr_fd("Error: minitalk\n", STDERR_FILENO);
			return (ERROR);
		}
		i++;
	}
	pid = ft_atoi(argv1);
	if (pid < PID_MIN || pid > PID_MAX)
	{
		ft_putstr_fd("Error: minitalk\n", STDERR_FILENO);
		return (ERROR);
	}
	else
		return (NOT_ERROR);
}

static void	signal_handler_usr1_end(int signum)
{
	if (signum == SIGUSR1)
	{
		exit(EXIT_SUCCESS);
	}
}

static void	send_signal(int server_pid, char *str)
{
	size_t	len;
	size_t	i;
	int		bit;

	i = 0;
	len = ft_strlen(str) + 1;
	while (len-- > 0)
	{
		bit = 8;
		while (bit-- > 0)
		{
			if ((str[i] >> bit) & 1)
				kill((pid_t)server_pid, SIGUSR1);
			else
				kill((pid_t)server_pid, SIGUSR2);
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	s_sa;
	int					server_pid;

	if (is_validation_argc_count(argc))
		exit(EXIT_FAILURE);
	if (is_validation_pid(argv[1]))
		exit(EXIT_FAILURE);
	s_sa.sa_handler = signal_handler_usr1_end;
	sigaction(SIGUSR1, &s_sa, NULL);
	server_pid = ft_atoi(argv[1]);
	send_signal(server_pid, argv[2]);
	return (1);
}
