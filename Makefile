# cc -L libft -I. ft_printf.c -lft
NAME := libftprintf.a

# Sources and objects
SRCS := ft_printf.c\
		parse.c putarg.c setarglen.c\
		ft_putuint_fd.c ft_putptr_fd.c\
		pf_putchar_fd.c pf_putnbr_fd.c pf_putstr_fd.c
OBJ := $(SRCS:%.c=%.o)

# Compiler 
CC := cc
CFLAGS := -Wall -Werror -Wextra

all: $(NAME)

$(NAME): libft $(OBJ) 
	ar rs $@ $(OBJ)

%.o: %.c
	$(CC) -c $(CFLAGS) $^ $(LIBS) -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all

libft:
	$(MAKE) libonly -C ./libft/
	cp libft/libft.a ./libftprintf.a

.PHONY: $(NAME) all clean fclean re libft
.SILENT:
