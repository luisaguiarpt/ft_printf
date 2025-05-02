CC=cc
FLAGS=-Wall -Wextra -Werror -g

SRCS=srcs/ft_putnbr.c srcs/ft_putnbr_u.c srcs/ft_putchar.c srcs/ft_putstr.c \
		srcs/ft_puthex.c srcs/ft_putptr.c ft_printf.c

B_SRCS=srcs/ft_putnbr_bonus.c srcs/ft_putnbr_u_bonus.c srcs/ft_putchar_bonus.c \
		srcs/ft_putstr_bonus.c srcs/ft_puthex_bonus.c srcs/ft_putptr_bonus.c \
		ft_printf_bonus.c srcs/ft_nbr_of_digits.c srcs/ft_printf_bonus_utils.c

OBJS=$(SRCS:%.c=%.o)
B_OBJS=$(B_SRCS:%.c=%.o)

LIBFTPATH=libft
LIBFT=$(LIBFTPATH)/libft.a

NAME=libftprintf.a
B_NAME=blibftprintf.a

all: $(NAME)

bonus: $(B_NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ -Iincludes

$(NAME): $(OBJS)
	make -C $(LIBFTPATH) all
	ar rcs $(NAME) $(OBJS)

$(B_NAME): $(B_OBJS)
	make -C $(LIBFTPATH) all
	ar rcs $(B_NAME) $(B_OBJS)

$(LIBFT):
	make -C $(LIBFTPATH) all

clean:
	make -C $(LIBFTPATH) clean
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	make -C $(LIBFTPATH) fclean
	rm -f $(NAME) $(B_NAME)

re: fclean all
