#include "opcodes.hpp"
#include "parser.hpp"
#include "instruction.hpp"
#include <iostream>
#include <fstream>

using namespace std;


// Inefficient way to do it
void verboseInstruction(Token* func, Token* arg1, Token* arg2, int index){
    uint16_t codes[2] = {
        arg1 == nullptr ? (uint16_t) 0x0000 : arg1->getCode().u16,
        arg2 == nullptr ? (uint16_t) 0x0000 : arg2->getCode().u16
    };
    string names[3] = {
        func->getName(),
        arg1 == nullptr ? "" : arg1->getName(),
        arg2 == nullptr ? "" : arg2->getName()
    };

    printf("%04X: %02X %04X %04X ", index, func->getCode().u8,
            codes[0], codes[1]);
    printf("=> %s %s %s\n", names[0].c_str(), names[1].c_str(), names[2].c_str());
}

void writeInstructionBytes(Instruction* i, int index, ofstream* file){
    Token* function = i->getFunction();
    Token* arg1 = nullptr;
    Token* arg2 = nullptr;
    i->getArgs(&arg1, &arg2);
    verboseInstruction(function, arg1, arg2, index);

    uint8_t funcCode = function->getCode().u8;
    uint16_t codes[2] = {
        arg1 == nullptr ? (uint16_t) 0x0000 : arg1->getCode().u16,
        arg2 == nullptr ? (uint16_t) 0x0000 : arg2->getCode().u16
    };

    file->write((char*)(&funcCode), 1);
    for(int i = 0; i < 2; i++){
        for(int j = 1; j >= 0; j--)
            file->write((char*)(&codes[i]) + j, 1);
    }
}

int createOutputFile(string pathOut, vector<Instruction*>* instVect){
    pathOut += ".cout";
    ofstream file;
    file.open(pathOut, fstream::out);
    if(!file.is_open()){
        cerr << "Couldn't open or create " << pathOut << "!" << endl;
        return 1;
    }
    int index = 0;
    for(Instruction* i : *instVect){
        writeInstructionBytes(i, index, &file);
        index++;
    }
    file.close();
    return 0;
}

int main(int argc, char* argv[]){
    if(argc < 2) {
        cerr << "Expected one argument, got " << argc - 1 << endl;
        return 1;
    }
    std::vector<Token*> tokens = getVectorTokens(argv[1]);

    std::vector<Instruction*> inst = createVectInstructions(tokens);

    string pathOut = argc >= 3 ? argv[2] : "out";
    return createOutputFile(pathOut, &inst);
}
