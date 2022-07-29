#include "opcodes.hpp"
#include "parser.hpp"
#include "instruction.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){
    if(argc != 2) {
        cerr << "Expected one argument, got " << argc - 1 << endl;
        return 1;
    }
    std::vector<Token*> tokens = getVectorTokens(argv[1]);
    int i = 0;
    for(Token* t : tokens){
        cout << i << ": " <<  t << "\t" << t->getName() << " " << t->getType() << " " << t->getFuncPtr() << endl;
        i++;
    }

    createVectInstructions(tokens);
}
