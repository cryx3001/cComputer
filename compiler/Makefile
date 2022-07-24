CC=gcc
CFLAGS=-Wall -Wextra -g -O1 -fsanitize=address

_SRC=
SRC_DIR=src
SRC=$(addprefix $(SRC_DIR)/, $(_SRC))

all: main

main: SRC+= $(SRC_DIR)/main.c
main:
	$(CC) $(CFLAGS) $(SRC) $(LDFLAGS) -o main


.PHONY: clean
clean:
	rm main
