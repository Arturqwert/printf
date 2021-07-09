FLAG = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = 	ft_printf.c \
		ft_csdx%.c \
		ft_itoa.c \
		ft_p.c \
		ft_put.c \
		ft_u.c \
		ft_utils.c \

OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	gcc $(FLAG) -c $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re