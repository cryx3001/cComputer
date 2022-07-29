#include "opcodes.hpp"
#include "parser.hpp"
#include "instruction.hpp"
#include <iostream>
#include <fstream>

using namespace std;

void writeInstructionBytes(Instruction* i, ofstream* file){
    Token* function = i->getFunction();
    Token* arg1 = nullptr;
    Token* arg2 = nullptr;
    i->getArgs(&arg1, &arg2);

    uint8_t funcCode = function->getCode().u8;
    uint16_t code1 = arg1 == nullptr ? 0x0000 : arg1->getCode().u8;
    uint16_t code2 = arg2 == nullptr ? 0x0000 : arg2->getCode().u8;

    file->write((char*)(&funcCode), 1);
    file->write((char*)(&code1) + 1, 1);
    file->write((char*)(&code1), 1);
    file->write((char*)(&code2) + 1, 1);
    file->write((char*)(&code2), 1);
}

int createOutputFile(string pathOut, vector<Instruction*>* instVect){
    pathOut += ".cout";
    ofstream file;
    file.open(pathOut, fstream::out);
    if(!file.is_open()){
        cerr << "Couldn't open or create " << pathOut << "!" << endl;
        return 1;
    }
    for(Instruction* i : *instVect)
        writeInstructionBytes(i, &file);
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
