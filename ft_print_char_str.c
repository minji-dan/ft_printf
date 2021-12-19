/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:23:43 by mkim2             #+#    #+#             */
/*   Updated: 2021/12/19 16:52:45 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ch(va_list ap)
{
	char	c;

	c = (unsigned char)va_arg(ap, int);
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(va_list ap)
{
	int		cnt;
	char	*arg_str;

	arg_str = va_arg(ap, char *);
	if (arg_str == NULL)
		arg_str = "(null)";
	cnt = ft_strlen_pf(arg_str);
	write(1, arg_str, cnt);
	return (cnt);
}
