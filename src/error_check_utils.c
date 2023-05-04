/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_validation_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:06:43 by yughoshi          #+#    #+#             */
/*   Updated: 2023/05/04 12:13:48 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

bool	is_validation_argc_count(int argc)
{
	if (argc != 3)
	{
		ft_putstr_fd("Error_Usage: ./client <pid> <message>\n", STDERR_FILENO);
		return (ERROR);
	}
	else
		return (NOT_ERROR);
}

bool	is_validation_pid(char *argv1)
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

bool	is_kill_successful(int kill_result)
{
	if (kill_result == -1)
	{
		ft_putstr_fd("Error: minitalk_kill_not_successful\n", STDERR_FILENO);
		return (false);
	}
	else
	{
		return (true);
	}
}
