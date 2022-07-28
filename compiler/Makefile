CC=g++
CFLAGS=-Wall -Wextra -g -O1 -fsanitize=address

_SRC=instruction.cpp parser.cpp token.cpp number_utils.cpp
SRC_DIR=src
SRC=$(addprefix $(SRC_DIR)/, $(_SRC))

all: main

main: SRC+= $(SRC_DIR)/main.cpp
main:
	$(CC) $(CFLAGS) $(SRC) $(LDFLAGS) -o main


.PHONY: clean
clean:
	rm main
