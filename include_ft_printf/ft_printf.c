/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yughoshi <yughoshi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:17:52 by yughoshi          #+#    #+#             */
/*   Updated: 2023/04/28 09:30:08 by yughoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_fmt(va_list *ap, const char *fmt, int *len, char *s_ap)
{
	if (*fmt == '%')
		my_putchar_and_increment('%', 1, len);
	else if (*fmt == 'c')
		my_putchar_and_increment(va_arg(*ap, int), 1, len);
	else if (*fmt == 's')
	{
		s_ap = va_arg(*ap, char *);
		if (!s_ap)
			my_putstr_and_increment("(null)", 1, len);
		else
			my_putstr_and_increment(s_ap, 1, len);
	}
	else if (*fmt == 'd' || *fmt == 'i')
		my_putnbr_and_increment(va_arg(*ap, int), 1, len);
	else if (*fmt == 'u')
		my_putnbr_and_increment(va_arg(*ap, unsigned int), 1, len);
	else if (*fmt == 'x')
		put_base16(va_arg(*ap, unsigned int), "0123456789abcdef", len);
	else if (*fmt == 'X')
		put_base16(va_arg(*ap, unsigned int), "0123456789ABCDEF", len);
	else if (*fmt == 'p')
	{
		my_putstr_and_increment("0x", 1, len);
		put_address(va_arg(*ap, unsigned long long), "0123456789abcdef", len);
	}
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		res_len;
	char	*fmt_s_ap;

	va_start(ap, fmt);
	res_len = 0;
	fmt_s_ap = NULL;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			print_fmt(&ap, fmt, &res_len, fmt_s_ap);
		}
		else
		{
			my_putchar_and_increment(*fmt, 1, &res_len);
		}
		fmt++;
	}
	va_end(ap);
	return (res_len);
}
