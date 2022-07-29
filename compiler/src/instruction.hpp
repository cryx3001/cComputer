#pragma once

#include <err.h>
#include <map>
#include <vector>
#include <iostream>
#include "token.hpp"

#define SIZE_INSTRUCTION_BITS 40 // 8 (func) + 16 (arg1) + 16 (arg2)

class Instruction {
    private:
        Token* function;
        Token* arg1;
        Token* arg2;

    public:
        Instruction(Token* func, Token* arg1, Token* arg2){
            Function* f;
            if(func == nullptr || (f = func->getFuncPtr()) == nullptr)
                warn("nullptr given for func or not recognized!");
            Token::checkTypes(arg1, f->arg1);
            Token::checkTypes(arg2, f->arg2);
        }

        Token* getFunction(){ return function; }

        void getArgs(Token* arg1, Token* arg2){
            if(arg1 != nullptr)
                *arg1 = *(this->arg1);
            if(arg2 != nullptr)
                *arg2 = *(this->arg2);
        }

        uint8_t* getInstructionBitField();
};

std::vector<Instruction*> createVectInstructions(std::vector<Token*> tokens);
