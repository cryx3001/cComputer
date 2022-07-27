#include "token.hpp"

static Token* TOKEN_FUNCTIONS[17] = {
    new Token("NOP", FUNCTION, 0x00, createFunction(NONE, NONE)),
    new Token("MOV", FUNCTION, 0x01, createFunction(VALUE, VALUE)),
    new Token("SET", FUNCTION, 0x02, createFunction(VALUE, VALUE)),

    new Token("ADD", FUNCTION, 0x10, createFunction(VALUE, VALUE)),
    new Token("SUB", FUNCTION, 0x11, createFunction(VALUE, VALUE)),
    new Token("MUL", FUNCTION, 0x12, createFunction(VALUE, VALUE)),
    new Token("DIV", FUNCTION, 0x13, createFunction(VALUE, VALUE)),

    new Token("CMP", FUNCTION, 0x20, createFunction(VALUE, VALUE)),
    new Token("TST", FUNCTION, 0x21, createFunction(VALUE, NONE)),

    new Token("BEQ", FUNCTION, 0x30, createFunction(LABEL, NONE)),
    new Token("BNE", FUNCTION, 0x31, createFunction(LABEL, NONE)),
    new Token("BLT", FUNCTION, 0x32, createFunction(LABEL, NONE)),
    new Token("BGT", FUNCTION, 0x33, createFunction(LABEL, NONE)),
    new Token("JMP", FUNCTION, 0x34, createFunction(LABEL, NONE)),
    new Token("RET", FUNCTION, 0x35, createFunction(NONE, NONE)),

    new Token("PSH", FUNCTION, 0x40, createFunction(VALUE, NONE)),
    new Token("POP", FUNCTION, 0x41, createFunction(VALUE, NONE)),
};
