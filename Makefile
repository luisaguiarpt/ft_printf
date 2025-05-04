CC=cc
FLAGS=-Wall -Wextra -Werror -g

MDIR=mandatory
MANDY=ftprintf_putnbr.c ftprintf_putnbr_u.c ftprintf_putchar.c \
	  ftprintf_putstr.c ftprintf_puthex.c ftprintf_putptr.c \
	  ft_printf.c
MANDYS=$(addprefix $(MDIR)/, $(MANDY))

SDIR=srcs
SRC=putnbr_format_bonus.c putnbr_u_format_bonus.c putchar_format_bonus.c \
	 putstr_format_bonus.c puthex_format_bonus.c putptr_format_bonus.c \
	 ft_printf_bonus.c ft_nbrsize_bonus.c ft_printf_parsers_bonus.c \
	 ft_printf_parser_utils_bonus.c ft_printf_utils_bonus.c pos_diff.c
SRCS=$(addprefix $(SDIR)/, $(SRC))

MOBJS=$(MANDYS:%.c=%.o)
OBJS=$(SRCS:%.c=%.o)

LIBFTDIR=libft
LIBFT=libft.a

NAME=libftprintf.a

all: $(NAME)

makelibft:
	make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFT) .
	mv $(LIBFT) $(NAME)

bonus: makelibft $(OBJS)
	ar -rcs $(NAME) $(OBJS) 

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ -Iincludes

$(NAME): $(MOBJS)
	ar rcs $(NAME) $(MOBJS)

clean:
	make -C $(LIBFTDIR) clean
	rm -f $(MOBJS) $(OBJS)

fclean: clean
	make -C $(LIBFTDIR) fclean
	rm -f $(NAME)

re: fclean all
