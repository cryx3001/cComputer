CC=g++
CFLAGS=-Wall -Wextra

_SRC=instruction.cpp parser.cpp token.cpp number_utils.cpp
SRC_DIR=src
OBJ_DIR=obj
BIN_DIR=bin
SRC=$(addprefix $(SRC_DIR)/, $(_SRC))
OBJ=$(subst $(SRC_DIR), $(OBJ_DIR), $(SRC:.cpp=.o))


all: directories compiler

debug: CFLAGS+= -g -O1 -fsanitize=address
debug: all

directories:
	mkdir -p $(OBJ_DIR) $(BIN_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $^ $(LDFLAGS) -o $@

compiler: $(OBJ) $(SRC_DIR)/compiler.cpp
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $(BIN_DIR)/$@


.PHONY: clean
clean:
	rm -r ./bin
	rm -r ./obj
