CC=g++
CFLAGS=-Wall -Wextra -g -O1

_SRC=instruction.cpp parser.cpp token.cpp number_utils.cpp
SRC_DIR=src
SRC=$(addprefix $(SRC_DIR)/, $(_SRC))

all: main

main: SRC+= $(SRC_DIR)/main.cpp
main:
	$(CC) $(CFLAGS) $(SRC) $(LDFLAGS) -o cryxc


.PHONY: clean
clean:
	rm main
