#pragma once

#include "token.hpp"

static Token TOKEN_FUNCTIONS[17] = {
    Token("NOP", FUNCTION, 0x00, createFunction(NONE, NONE)),
    Token("MOV", FUNCTION, 0x01, createFunction(VALUE, VALUE)),
    Token("SET", FUNCTION, 0x02, createFunction(VALUE, VALUE)),

    Token("ADD", FUNCTION, 0x10, createFunction(NONE, NONE)),
    Token("SUB", FUNCTION, 0x11, createFunction(NONE, NONE)),
    Token("MUL", FUNCTION, 0x12, createFunction(NONE, NONE)),
    Token("DIV", FUNCTION, 0x13, createFunction(NONE, NONE)),

    Token("CMP", FUNCTION, 0x20, createFunction(VALUE, VALUE)),
    Token("TST", FUNCTION, 0x21, createFunction(VALUE, NONE)),

    Token("BEQ", FUNCTION, 0x30, createFunction(LABEL_ENTRY, NONE)),
    Token("BNE", FUNCTION, 0x31, createFunction(LABEL_ENTRY, NONE)),
    Token("BLT", FUNCTION, 0x32, createFunction(LABEL_ENTRY, NONE)),
    Token("BGT", FUNCTION, 0x33, createFunction(LABEL_ENTRY, NONE)),
    Token("JMP", FUNCTION, 0x34, createFunction(LABEL_ENTRY, NONE)),
    Token("RET", FUNCTION, 0x35, createFunction(NONE, NONE)),

    Token("PSH", FUNCTION, 0x40, createFunction(VALUE, NONE)),
    Token("POP", FUNCTION, 0x41, createFunction(VALUE, NONE)),
};
