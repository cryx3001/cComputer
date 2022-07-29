#include <vector>
#include <map>
#include "instruction.hpp"

typedef std::map<std::string, uint16_t> DictLabels;

uint8_t* Instruction::getInstructionBitField(){
    uint8_t* res = new uint8_t(SIZE_INSTRUCTION_BITS / 8);
    std::cout << SIZE_INSTRUCTION_BITS / 8 << "\n";
    Token* function = this->getFunction();
    Token* arg1 = nullptr;
    Token* arg2 = nullptr;
    this->getArgs(&arg1, &arg2);

    uint8_t code1 = (uint8_t)(arg1 == nullptr ? 0x0000 : arg1->getCode().u16);
    uint8_t code2 = (uint8_t)(arg2 == nullptr ? 0x0000 : arg2->getCode().u16);
    printf("%02X, %02X, %02X\n", function->getCode().u8, code1, code2);
    res[0] = function->getCode().u8;
    res[1] = code1;
    res[3] = code2;

    return res;
}

void editArgToken(Token** arg, std::vector<Token*> tokens, Type typeArg, size_t *i, DictLabels* dict){
    if(typeArg != NONE){
        (*i)++;
        *arg = tokens[*i];
        if(typeArg == LABEL_ENTRY)
            (*arg)->setCode(dict->at((*arg)->getName()));
    }
}

std::vector<Instruction*> createVectInstructions(std::vector<Token*> tokens){
    std::vector<Instruction*> instructions = std::vector<Instruction*>();
    DictLabels labels = DictLabels();
    size_t sizeVect = tokens.size();

    for(size_t i = 0; i < sizeVect; i++){
        Token* funcToken = tokens[i];
        Token* arg1Token = nullptr;
        Token* arg2Token = nullptr;
        Function* func = funcToken->getFuncPtr();
        if(funcToken->getType() == LABEL_EXIT){
            labels.insert({funcToken->getName(), instructions.size()});
            continue;
        }
        if(func == nullptr)
            errx(1, "Awaited funcPtr!");
        editArgToken(&arg1Token, tokens, func->arg1, &i, &labels);
        editArgToken(&arg2Token, tokens, func->arg2, &i, &labels);
        instructions.push_back(new Instruction(funcToken, arg1Token, arg2Token));
    }

    return instructions;
}
