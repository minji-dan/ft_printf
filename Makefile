SRCS    =    ft_printf.c \
            ft_printf_utils.c \
            ft_print_num_kind.c \
            ft_print_char_str.c

OBJS    =    $(SRCS:.c=.o)

NAME    =    libftprintf.a
RM        =    rm -f
LIB        =    ar rcu
CC        =    gcc
CFLAGS    =    -Wall -Wextra -Werror

$(NAME)    :    $(OBJS)
	$(LIB) $@ $^

all        :    $(NAME)

clean    :
	$(RM) $(OBJS)

fclean    :    clean
	$(RM) $(NAME)

re        :    fclean all

bonus    :    all

.PHONY	:	all clean fclean re
