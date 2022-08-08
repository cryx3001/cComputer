#include <vector>
#include <map>
#include "instruction.hpp"

typedef std::map<std::string, uint16_t> DictLabels;

void editArgToken(Token** arg, std::vector<Token*> tokens, Type typeArg, size_t *i, DictLabels* dict){
    if(typeArg != NONE){
        (*i)++;
        *arg = tokens[*i];
    }
}

void updateLabelsEntry(std::vector<Instruction*> inst, DictLabels labels){
    for(Instruction* i : inst){
        Token* arg1Token = nullptr;
        Token* arg2Token = nullptr;
        i->getArgs(&arg1Token, &arg2Token);
        if(arg1Token != NULL && arg1Token->getType() == LABEL_ENTRY)
            arg1Token->setCode(labels.at(arg1Token->getName()));
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

    updateLabelsEntry(instructions, labels);
    return instructions;
}
