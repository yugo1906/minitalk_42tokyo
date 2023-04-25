/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:42:05 by yughoshi          #+#    #+#             */
/*   Updated: 2023/04/26 08:23:20 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
# include <sys/types.h>

static bool	is_validation_arg(int argc)
{
	if (argc != 3)
		return (true);
	else
		return (false);
}

int	main(int argc, char **argv)
{
	(void)argv;
	// 引数が2つではない場合はプログラム終了
	if (is_validation_arg(argc))
		exit(EXIT_FAILURE);
	return (1);
}
