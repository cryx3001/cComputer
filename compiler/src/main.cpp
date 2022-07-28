#include "opcodes.hpp"
#include "parser.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){
    if(argc != 2) {
        cerr << "Expected one argument, got " << argc - 1 << endl;
        return 1;
    }

    ifstream file;
    file.open(argv[1]);
    if(!file.is_open()){
        cerr << "Couldn't open file " << argv[1] << endl;
        return 1;
    }

    string word;
    while(file >> word)
    {
        cout << word;
        Token* t = getToken(word);
        cout << " " << t->getCode().u16 << " "  << t->getType() << " " <<  t->getFuncPtr() << "\n";
    }

}
