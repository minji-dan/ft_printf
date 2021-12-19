/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:24:55 by mkim2             #+#    #+#             */
/*   Updated: 2021/12/19 17:38:10 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_parse_type(const char c, va_list ap);
int		ft_parse_format(const char *format, va_list ap);
int		ft_printf(const char *format, ...);
int		ft_print_str(va_list ap);
int		ft_print_ch(va_list ap);
char	*ft_get_base(const char c);
int		ft_strlen_pf(char *str);
int		ft_itoa_pf(const char c, char *num_str,
			unsigned long long num, int base);
int		ft_print_num(long long num, const char c, int base);
int		ft_print_mem(va_list ap, const char c);
int		ft_print_int(va_list ap, const char c);
int		ft_print_unsigned_int(va_list ap, const char c);
int		ft_print_hexa(va_list ap, const char c);

#endif
