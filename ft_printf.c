/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:22:35 by mkim2             #+#    #+#             */
/*   Updated: 2021/12/17 20:10:58 by mkim2            ###   ########.fr       */
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
		}
		else
			cnt += write(1, format, 1);
		format++;
	}
	return (cnt);
}

/* 가변인자 : 함수의 매개변수의 개수가 유동적인 것 */
/* %[플래그][넓이][.(정밀도)][길이]서식지정자 */
int ft_printf(const char *format, ...)
{
    va_list	ap;
	int		cnt;

	va_start(ap, format);
	cnt = ft_parse_format(format, ap);
	va_end(ap);
	return (cnt);
}

int	ft_parse_type(const char c, va_list ap)
{
	int		cnt;

	cnt = 0;
	if (c == 'c') //문자
		cnt += ft_print_ch(ap);
	else if (c == 's') //문자열
		cnt += ft_print_str(ap);
	else if (c == 'p') //포인터의 메모리 주소
		cnt += ft_print_mem(ap, c);
	else if (c == 'd' || c == 'i') //부호가 있는 10진 정수
		cnt += ft_print_int(ap, c);
	else if (c == 'u') //부호가 없는 10진 정수
		cnt += ft_print_unsigned_int(ap, c);
	else if (c == 'x' || c == 'X') //부호가 없는 16진 정수 (소문자 / 대문자)
		cnt += ft_print_hexadecimal(ap, c);
	else if (c == '%') //형식 지정에 필요한 문자, %기호 출력 
		cnt += write(1, "%", 1);
	return (cnt);
}
