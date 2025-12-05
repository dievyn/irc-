
NAME = libft.a

CC = cc

AR = ar

CFLAGS = -Werror -Wall -Wextra

SRC = ft_itoa.c				\
	ft_atoi.c				\
	ft_atol.c				\
	tab_len.c				\
	ft_bzero.c				\
	ft_split.c				\
	free_tab.c				\
	copy_tab.c				\
	ft_memcmp.c				\
	ft_memchr.c				\
	ft_memcpy.c				\
	ft_memset.c				\
	ft_strchr.c				\
	ft_strlen.c				\
	ft_calloc.c				\
	ft_substr.c				\
	ft_strdup.c				\
	print_tab.c				\
	skip_space.c			\
	ft_strncpy.c			\
	ft_strlcat.c			\
	ft_isalnum.c			\
	ft_isalpha.c			\
	ft_isascii.c			\
	ft_isdigit.c			\
	ft_isprint.c			\
	ft_isspace.c			\
	ft_strncmp.c			\
	ft_strnstr.c			\
	ft_strrchr.c			\
	ft_tolower.c			\
	ft_toupper.c			\
	ft_strtrim.c			\
	ft_memmove.c			\
	ft_strjoin.c			\
	ft_strlcpy.c			\
	ft_strmapi.c			\
	ft_striteri.c			\
	ft_putnbr_fd.c			\
	ft_putstr_fd.c			\
	ft_putchar_fd.c			\
	ft_putendl_fd.c			\
	printf_ex/ft_printf.c	\
	printf_ex/put_x.c		\
	printf_ex/put_x2.c		\
	gnl/get_next_line.c		\
	gnl/get_next_line_utils.c

OBJET = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJET)
	$(AR) rcs $(NAME) $(OBJET)
	
test : $(OBJET)
	echo

clean:
	rm -f $(OBJET)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
