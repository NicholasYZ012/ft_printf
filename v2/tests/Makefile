NAME := test

# Compiler 
CC := cc 
CFLAGS := -I../ -L../
CDEBUG := -Wall -Werror -Wextra -g 
LIBS := -lftprintf

all: libftprintf $(NAME) 

$(NAME): $(NAME:%=%.c)
	cc $(CFLAGS) $^ $(LIBS) -o $@
	./test

debug: libftprintf 
	cc $(CDEBUG) $(CFLAGS) test.c $(LIBS) -o $@
	./test

libftprintf: 
	$(MAKE) all clean -C ../

.SILENT:
.PHONY: test debug