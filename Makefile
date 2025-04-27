CC=cc
FLAGS=-Wall -Wextra -Werror -g

SRCS=srcs/ft_putnbr.c srcs/ft_putnbr_u.c srcs/ft_putchar.c srcs/ft_putstr.c \
		srcs/ft_puthex.c srcs/ft_putptr.c ft_printf.c
OBJS=$(SRCS:%.c=%.o)

LIBFTPATH=libft
LIBFT=$(LIBFTPATH)/libft.a

NAME=libftprintf.a

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ -Iincludes

$(NAME): $(OBJS)
	make -C $(LIBFTPATH) all
	ar rcs $(NAME) $(OBJS)

$(LIBFT):
	make -C $(LIBFTPATH) all

clean:
	make -C $(LIBFTPATH) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFTPATH) fclean
	rm -f $(NAME)

re: fclean all
