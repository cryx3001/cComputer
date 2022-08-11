#pragma once

#include "token.hpp"

static Token TOKEN_FUNCTIONS[16] = {
    Token("NOP", FUNCTION, 0x00, createFunction(NONE, NONE)),
    Token("MOV", FUNCTION, 0x01, createFunction(VALUE, VALUE)),
    Token("SET", FUNCTION, 0x02, createFunction(VALUE, VALUE)),

    Token("ADD", FUNCTION, 0x10, createFunction(VALUE, VALUE)),
    Token("SUB", FUNCTION, 0x11, createFunction(VALUE, VALUE)),
    Token("MUL", FUNCTION, 0x12, createFunction(VALUE, VALUE)),
    Token("DIV", FUNCTION, 0x13, createFunction(VALUE, VALUE)),

    Token("CMP", FUNCTION, 0x20, createFunction(VALUE, VALUE)),
    Token("TST", FUNCTION, 0x21, createFunction(VALUE, NONE)),

    Token("BEQ", FUNCTION, 0x30, createFunction(LABEL_ENTRY, NONE)),
    Token("BNE", FUNCTION, 0x31, createFunction(LABEL_ENTRY, NONE)),
    Token("BLT", FUNCTION, 0x32, createFunction(LABEL_ENTRY, NONE)),
    Token("BGT", FUNCTION, 0x33, createFunction(LABEL_ENTRY, NONE)),
    Token("JMP", FUNCTION, 0x34, createFunction(LABEL_ENTRY, NONE)),

    Token("VID", FUNCTION, 0x40, createFunction(NONE, NONE)),

    Token("HLT", FUNCTION, 0xFF, createFunction(NONE, NONE)),
};
