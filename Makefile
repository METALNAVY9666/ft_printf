NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src
SRC = ft_putchar.c ft_puthex.c ft_putnbr.c ft_putstr.c ft_putunsignednbr.c ft_putvoid.c ft_strcpy.c ft_printf.c
OBJ = $(SRC:.c=.o)
OBJ := $(addprefix $(SRC_DIR)/, $(OBJ))

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
