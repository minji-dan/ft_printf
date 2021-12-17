/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:23:43 by mkim2             #+#    #+#             */
/*   Updated: 2021/12/17 20:05:28 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_ch(va_list ap)
{
    char c;

    c = (unsigned char)va_arg(ap, int);
    write(1, &c, 1);
    return (1);
}

int ft_print_str(va_list ap)
{
    int cnt;
    char *arg_str;

    arg_str = va_arg(ap, char *);
    if (arg_str == NULL) //가변인자가 null일 경우 (null) 문자열 저장
        arg_str = "(null)";
    cnt = ft_strlen_pf(arg_str);
    write(1, arg_str, cnt);
    return (cnt);
}
