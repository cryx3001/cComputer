#include "instruction.hpp"

uint8_t* Instruction::getInstructionBitField(){
    uint8_t* res = new uint8_t(SIZE_INSTRUCTION_BITS / 8);
    Token* function = this->getFunction();
    Token* arg1 = (Token*) malloc(sizeof(Token));
    Token* arg2 = (Token*) malloc(sizeof(Token));
    this->getArgs(arg1, arg2);

    res[0] = function->getCode().u8;
    res[1] = arg1->getCode().u16;
    res[3] = arg2->getCode().u16;

    free(arg1);
    free(arg2);

    return res;
}
