/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:32:20 by yughoshi          #+#    #+#             */
/*   Updated: 2023/05/01 09:54:26 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int i = 0;
	(void)context;
	(void)info;
	// テスト：シグナルを受け取って出力できるか確認
	if (signum == SIGUSR1)
	{
		ft_printf("%d\n", i);
		i++;
		ft_printf("SIGUSR1\n");
	}
	else if (signum == SIGUSR2)
	{
		ft_printf("%d\n", i);
		i++;
		ft_printf("SIGUSR2\n");
	}
	else
	{
		ft_printf("Error_minitalk\n");
	}
}

// function_sigemptyset: Initialize the signal mask so that it does not block on signals received while running the signal_handler.

int	main(void)
{
	struct sigaction	s_sa;
	pid_t				pid;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	s_sa.sa_sigaction = signal_handler;
	s_sa.sa_flags = SA_SIGINFO;
	sigemptyset(&s_sa.sa_mask);
	sigaction(SIGUSR1, &s_sa, NULL);
	sigaction(SIGUSR2, &s_sa, NULL);
	while(1)
		pause();
	return (0);
}
