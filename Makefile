CC = gcc
FLAGS = -Wall -ggdb -std=c99

main: main.c
	$(CC) $(FLAGS) -o main main.c
