/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:24:32 by mkim2             #+#    #+#             */
/*   Updated: 2021/12/19 17:57:18 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_base(const char c)
{
	if (c == 'u' || c == 'd' || c == 'i')
		return ("0123456789");
	else if (c == 'x' || c == 'p')
		return ("0123456789abcdef");
	else if (c == 'X')
		return ("0123456789ABCDEF");
	return (0);
}

int	ft_strlen_pf(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

int	ft_itoa_pf(const char c, char *num_str,
				unsigned long long num, int base)
{
	int	cnt;

	cnt = 0;
	if (num == 0)
		num_str[cnt++] = '0';
	else
	{
		while (num != 0)
		{
			num_str[cnt++] = ft_get_base(c)[num % base];
			num = num / base;
		}
	}
	return (cnt);
}

int	ft_print_num(long long num, const char c, int base)
{
	int		cnt;
	int		len;
	char	num_str[17];

	cnt = 0;
	len = ft_itoa_pf(c, num_str, num, base);
	while (len -- > 0)
		cnt += write(1, &num_str[len], 1);
	return (cnt);
}
