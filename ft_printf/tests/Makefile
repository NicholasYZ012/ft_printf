NAME := test

# Compiler 
CC := cc 
CFLAGS := -Wall -Werror -Wextra -I../ -L../libft/ -L../
LIBS := -lft -lftprintf

$(NAME): $(NAME:%=%.c)
	cc $(CFLAGS) $^ $(LIBS) -o $@

libftprintf: 
	$(MAKE) all clean -C ../