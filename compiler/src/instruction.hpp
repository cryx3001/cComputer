#include <err.h>
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
            if(!Token::isTypeValid(arg1, func->getType()))
                warn("arg1 doesn't have excepted type!");
            if(!Token::isTypeValid(arg2, func->getType()))
                warn("arg2 doesn't have excepted type!");
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
