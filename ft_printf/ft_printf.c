#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
    int cnt;
    va_list ap;
    char *tmp;

    tmp = (char *)format;
    va_start(ap, format);
    cnt = ft_read_format(tmp, ap);
    return (cnt);
}

int ft_treat_format(char c, va_list ap)
{
    int cnt;

    if (c == 'c')
        fd_putchar_fd();
    else if (c == 's')
        fd_putchar_fd();
    else if (c == 'p')
        fd_putchar_fd();
    else if (c == 'd' || c == 'i')
        fd_putchar_fd();
    else if (c == 'u')
        fd_putchar_fd();
    else if (c == 'x')
        fd_putchar_fd();
    else if (c == 'X')
        fd_putchar_fd();
    else if (c == '%')
        fd_putchar_fd();
    if (c == 'c' || c == '%')
        cnt = 1;
    return (cnt);
}