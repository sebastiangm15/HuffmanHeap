#Gilma Sebastian-Mihai 315CA

CC = gcc
CFLAGS = -Wall -Wextra -g
SRC = main.c case_function.c min_heap.c
EXEC = tema2

build:
	$(CC) $(CFLAGS) $(SRC) -o $(EXEC) 

clean:
	rm -f $(EXEC)

run: $(EXEC)
	./$(EXEC)

pack:
	zip sebastian_gilma_315CA.zip Makefile *.c README tema2 *.h

.PHONY: all build run clean pack