/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:22:35 by mkim2             #+#    #+#             */
/*   Updated: 2021/12/19 20:37:54 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_format(const char *format, va_list ap)
{
	int		cnt;

	cnt = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format ++;
			cnt += ft_parse_type(*format, ap);
			if (*format == 0)
				break ;
		}
		else
			cnt += write(1, format, 1);
		format ++;
	}
	return (cnt);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			cnt;

	cnt = 0;
	va_start(ap, format);
	cnt = ft_parse_format(format, ap);
	va_end(ap);
	return (cnt);
}

int	ft_parse_type(const char c, va_list ap)
{
	int		cnt;

	cnt = 0;
	if (c == 'c')
		cnt += ft_print_ch(ap);
	else if (c == 's')
		cnt += ft_print_str(ap);
	else if (c == 'p')
		cnt += ft_print_mem(ap, c);
	else if (c == 'd' || c == 'i')
		cnt += ft_print_int(ap, c);
	else if (c == 'u')
		cnt += ft_print_uint(ap, c);
	else if (c == 'x' || c == 'X')
		cnt += ft_print_hexa(ap, c);
	else if (c == '%')
		cnt += write(1, "%", 1);
	return (cnt);
}
