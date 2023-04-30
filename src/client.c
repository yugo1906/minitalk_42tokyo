/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:42:05 by yughoshi          #+#    #+#             */
/*   Updated: 2023/04/28 09:32:18 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
#include <limits.h>
#include <sys/types.h>

static bool	is_validation_argc_count(int argc)
{
	if (argc != 3)
		return (true);
	else
		return (false);
}

static bool	is_validation_pid(char *argv1)
{
	size_t	i;
	int		pid;

	i = 0;
	while (argv1[i])
	{
		if (argv1[i] < '0' || argv1[i] > '9')
			return (ERROR);
		i++;
	}
	pid = ft_atoi(argv1);
	if (pid < PID_MIN || pid > PID_MAX)
		return (ERROR);
	else
		return (NOT_ERROR);
}

int	main(int argc, char **argv)
{
	int pid;
	(void)argv;
	// 引数が2つではない場合はプログラム終了
	if (is_validation_argc_count(argc))
		exit(EXIT_FAILURE);
	if (is_validation_pid(argv[1]))
		exit(EXIT_FAILURE);

	pid = ft_atoi(argv[1]);
	return (1);
}
