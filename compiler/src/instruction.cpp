#include "instruction.hpp"

uint8_t* Instruction::getInstructionBitField(){
    uint8_t* res = new uint8_t(SIZE_INSTRUCTION_BITS / 8);
    Token* function = this->getFunction();
    Token* arg1;
    Token* arg2;
    this->getArgs(arg1, arg2);

    res[0] = function->getCode().u8;
    res[1] = function->getCode().u16;
    res[3] = function->getCode().u16;

    return res;
}
