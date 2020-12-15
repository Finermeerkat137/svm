all:
	cc -o vm -Wall -Werror -fsanitize=signed-integer-overflow -fsanitize=undefined -ggdb3 -DDEBUG $(wildcard *.c)
