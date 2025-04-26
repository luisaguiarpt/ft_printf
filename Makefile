CC=cc
FLAGS=-Wall -Wextra -Werror

SRCS=srcs/ft_putnbr.c srcs/ft_putnbr_u.c srcs/ft_putchar.c srcs/ft_putstr.c \
		srcs/ft_puthex.c srcs/ft_puthex_u.c ft_printf.c
	
OBJS=$(SRCS:%.c=%.o)

NAME=libftprintf.a

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ -I.

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
