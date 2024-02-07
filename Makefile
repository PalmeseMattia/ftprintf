CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_manage_conversion.c
NAME = libftprintf.a
LIBFT_DIR = libft
LIBFT_MAKEFILE = $(LIBFT_DIR)/Makefile

all: $(NAME)

# Costruzione della libreria ftprintf
$(NAME): $(SRC:.c=.o)
	$(MAKE) -C $(LIBFT_DIR)
	ar rc $(NAME) $^ $(LIBFT_DIR)/*.o

# Compilazione dei file sorgente
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Pulizia
clean:
	$(RM) $(SRC:.c=.o)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
