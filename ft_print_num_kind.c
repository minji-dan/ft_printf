/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num_kind.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:24:12 by mkim2             #+#    #+#             */
/*   Updated: 2021/12/17 19:42:39 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_mem(va_list ap, const char c)
{
    int cnt;
    long long num;

    cnt = 0;
    num = (unsigned long long)va_arg(ap, void *);
    cnt += write(1, "0x", 2);
    cnt += ft_print_num(num, c, 16);
    return (cnt);
}

int	ft_print_int(va_list ap, const char c)
{
    int cnt;
    long long num;

    cnt = 0;
    num = va_arg(ap, int);
    if (num < 0) 
    {
        num = -num; 
        cnt += write(1, "-", 1);
    }
    cnt += ft_print_num(num, c, 10);
    return (cnt);
}

int ft_print_unsigned_int(va_list ap, const char c) //print_int와 같으나 마이너스 부분만 삭제 
{
    int cnt;
    long long num;

    num = va_arg(ap, unsigned int);
    cnt = ft_print_num(num, c, 10);
    return (cnt);
}

int ft_print_heaxadecimal(va_list ap, const char c)
{
    int cnt;
    long long num;

    num = va_arg(ap, unsigned int);
    cnt = ft_print_num(num, c, 16);
    return (cnt);
}
