CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic

all: monty

monty: main.c opcode_push.c opcode_pall.c stack_functions.c error_handling.c
    $(CC) $(CFLAGS) $^ -o $@

clean:
    rm -f monty

.PHONY: all clean
