all:
	cc -o vm -fsanitize=signed-integer-overflow -fsanitize=undefined -ggdb3 -DDEBUG $(wildcard *.c)
