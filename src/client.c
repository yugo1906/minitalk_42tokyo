/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:42:05 by yughoshi          #+#    #+#             */
/*   Updated: 2023/05/04 12:16:38 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

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
	int		kill_result;

	kill_result = 0;
	i = 0;
	len = ft_strlen(str) + 1;
	while (len-- > 0)
	{
		bit = 8;
		while (bit-- > 0)
		{
			if ((str[i] >> bit) & 1)
				kill_result = kill((pid_t)server_pid, SIGUSR1);
			else
				kill_result = kill((pid_t)server_pid, SIGUSR2);
			if (!is_kill_successful(kill_result))
				exit(EXIT_FAILURE);
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
