#include <stddef.h>
#include "opcodes.h"

enum NumberBase { BIN = 2, DEC = 10, HEX = 16};

char* fileToString(char* path);
char** getWords(char* text, size_t* numWords);
Instruction* isWordInstruction(char* text, size_t* numArgs);
char* isWordNumber(char* text);
u_int8_t getNumberValue(char* text);
