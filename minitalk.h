/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:41:58 by yughoshi          #+#    #+#             */
/*   Updated: 2023/05/04 12:15:37 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define PID_MAX 4194304
# define PID_MIN 1
# define ERROR 1
# define NOT_ERROR 0

# include "./include_ft_printf/ft_printf.h"
# include "./include_libft/libft.h"
# include <signal.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

bool	is_validation_argc_count(int argc);
bool	is_validation_pid(char *argv1);
bool	is_kill_successful(int kill_result);

#endif
