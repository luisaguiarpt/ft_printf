CC=cc 
FLAGS=-Wall -Wextra -Werror

SRCS=ft_atoi.c
SRCS+=ft_bzero.c 
SRCS+=ft_calloc.c
SRCS+=ft_isalnum.c 
SRCS+=ft_isalpha.c 
SRCS+=ft_isascii.c 
SRCS+=ft_isdigit.c 
SRCS+=ft_isprint.c 
SRCS+=ft_itoa.c 
SRCS+=ft_memchr.c 
SRCS+=ft_memcmp.c 
SRCS+=ft_memcpy.c 
SRCS+=ft_memmove.c 
SRCS+=ft_memset.c 
SRCS+=ft_putchar_fd.c 
SRCS+=ft_putendl_fd.c 
SRCS+=ft_putnbr_fd.c 
SRCS+=ft_putstr_fd.c 
SRCS+=ft_split.c 
SRCS+=ft_strchr.c 
SRCS+=ft_strdup.c 
SRCS+=ft_striteri.c 
SRCS+=ft_strjoin.c 
SRCS+=ft_strlcat.c 
SRCS+=ft_strlcpy.c 
SRCS+=ft_strlen.c 
SRCS+=ft_strmapi.c 
SRCS+=ft_strncmp.c 
SRCS+=ft_strnstr.c 
SRCS+=ft_strrchr.c
SRCS+=ft_strtrim.c 
SRCS+=ft_substr.c 
SRCS+=ft_tolower.c 
SRCS+=ft_toupper.c

BONUS=ft_lstnew_bonus.c 
BONUS+=ft_lstadd_front_bonus.c 
BONUS+=ft_lstsize_bonus.c 
BONUS+=ft_lstlast_bonus.c 
BONUS+=ft_lstadd_back_bonus.c 
BONUS+=ft_lstclear_bonus.c 
BONUS+=ft_lstdelone_bonus.c  
BONUS+=ft_lstiter_bonus.c 
BONUS+=ft_lstmap_bonus.c

OBJS=$(SRCS:%.c=%.o)
BONUS_O=$(BONUS:%.c=%.o)

NAME=libft.a

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ 

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(NAME) $(BONUS_O)
	ar rcs $(NAME) $(OBJS) $(BONUS_O)
so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS) $(BONUS_O)
	
clean:
	rm -f $(OBJS) $(BONUS_O)

fclean: clean
	rm -f $(NAME)

re: fclean all
