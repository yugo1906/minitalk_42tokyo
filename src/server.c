/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:32:20 by yughoshi          #+#    #+#             */
/*   Updated: 2023/05/04 11:28:05 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

//c = c << 1 : Shifts the bits of c to the left by 1. Repeat until 8 bits.
static void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int				counter_bit_receive = 0;
	static unsigned char	output_char = 0;

	(void)context;
	if (signum == SIGUSR1)
		output_char |= 1;
	if (++counter_bit_receive == 8)
	{
		counter_bit_receive = 0;
		if (output_char == '\0')
		{
			kill(info->si_pid, SIGUSR1);
			output_char = 0;
			return ;
		}
		ft_putchar_fd(output_char, STDIN_FILENO);
		output_char = 0;
	}
	else
		output_char = output_char << 1;
}

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
	while (1)
		pause();
	return (0);
}
