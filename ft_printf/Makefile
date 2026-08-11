NAME := libftprintf.a

# Sources and objects
SRCS := ft_printf.c
OBJ := $(SRCS:%.c=%.o)

# Compiler 
CC := cc 
CFLAGS := -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) -c $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all

libft.a:
	$(MAKE) libonly -C ./libft/

.PHONY: all clean fclean re