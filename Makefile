CC=cc
FLAGS=-Wall -Wextra -Werror -g

MPATH=mandatory
MANDY=ftprintf_putnbr.c ftprintf_putnbr_u.c ftprintf_putchar.c \
	  ftprintf_putstr.c ftprintf_puthex.c ftprintf_putptr.c \
	  ft_printf.c
MANDYS=$(addprefix $(MPATH)/, $(MANDY))

SPATH=srcs
SRC=putnbr_format_bonus.c putnbr_u_format_bonus.c putchar_format_bonus.c \
	 putstr_format_bonus.c puthex_format_bonus.c putptr_format_bonus.c \
	 ft_printf_bonus.c ft_nbrsize_bonus.c ft_printf_parsers_bonus.c \
	 ft_printf_parser_utils_bonus.c ft_printf_utils_bonus.c
SRCS=$(addprefix $(SPATH)/, $(SRC))

MOBJS=$(MANDYS:%.c=%.o)
OBJS=$(SRCS:%.c=%.o)

LIBFTPATH=libft
LIBFT=$(LIBFTPATH)/libft.a

NAME=libftprintf.a

all: $(NAME)

" bonus: $(OBJS) $(LIBFT)
	"make -C $(LIBFTPATH) all
	"ar rcs $(NAME) $^ 

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ -Iincludes

$(NAME): $(MOBJS) $(LIBFT)
	make -C $(LIBFTPATH) all
	ar rcs $(NAME) $(MOBJS)

$(LIBFT):
	make -C $(LIBFTPATH) all

clean:
	make -C $(LIBFTPATH) clean
	rm -f $(MOBJS) $(OBJS)

fclean: clean
	make -C $(LIBFTPATH) fclean
	rm -f $(NAME)

re: fclean all
