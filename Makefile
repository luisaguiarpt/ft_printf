CC=cc
FLAGS=-Wall -Wextra -Werror

SDIR=srcs
SRC=putnbr_format.c putnbr_u_format.c putchar_format.c \
	 putstr_format.c puthex_format.c putptr_format.c \
	 ft_printf.c ft_nbrsize.c ft_printf_parsers.c \
	 ft_printf_parser_utils.c ft_printf_utils.c pos_diff.c
SRCS=$(addprefix $(SDIR)/, $(SRC))

OBJS=$(SRCS:%.c=%.o)

LIBFTDIR=libft
LIBFT=libft.a

NAME=libftprintf.a

all: $(NAME)

makelibft:
	make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFT) .
	mv $(LIBFT) $(NAME)

$(NAME): makelibft $(OBJS)
	ar -rcs $(NAME) $(OBJS) 

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ -Iincludes

clean:
	make -C $(LIBFTDIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFTDIR) fclean
	rm -f $(NAME)

re: fclean all
