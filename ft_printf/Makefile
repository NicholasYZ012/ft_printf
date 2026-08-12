# cc -L libft -I. ft_printf.c -lft
NAME := libftprintf.a

# Sources and objects
SRCS := ft_printf.c parse.c specifier_handler.c ft_uitoa.c
OBJ := $(SRCS:%.c=%.o)

# Compiler 
CC := cc
CFLAGS := -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) -c $(CFLAGS) $^ $(LIBS) -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all

libft:
	$(MAKE) libonly -C ./libft/

.PHONY: all clean fclean re libft
.SILENT:
