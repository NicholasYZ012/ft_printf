NAME := test

# Compiler 
CC := cc 
CFLAGS := -Wall -Werror -Wextra -g -I../ -L../libft/ -L../
LIBS := -lftprintf -lft

all: libftprintf $(NAME) 

$(NAME): $(NAME:%=%.c)
	cc $(CFLAGS) $^ $(LIBS) -o $@
	./test

libftprintf: 
	$(MAKE) all clean -C ../

.SILENT:
.PHONY: test