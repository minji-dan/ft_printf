NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
ft_treat.c \
ft_uitoa.c \
ft_ull_base.c 
OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
				$(LIB) $@ $^

all : $(NAME)

clean : 
		$(RM) $(OBJS)

fclean : clean
				$(RM) $(OBJS)

re : fclean all

bonus : all


