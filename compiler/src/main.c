#include <err.h>
#include <stdio.h>
#include "parser.h"

int main(int argc, char* argv[]){
    if(argc != 2)
        errx(1, "Expected one argument, got %d", argc - 1);
    char* s = fileToString(argv[1]);
    size_t x = 0;
    char** y = getWords(s, &x);
    for(size_t i = 0; i < x; i++){
        printf("Word %lu: %s\t", i, y[i]);
        size_t numArgs = 0;
        Instruction* in = isWordInstruction(y[i], &numArgs);
        if(in != NULL){
            printf("(%p, 0x%02X, %lu)\n", in, in->word.opCode, numArgs);
            continue;
        }

        char* number = isWordNumber(y[i]);
        printf("(%p, ", number);
        if(number != NULL)
            printf(" %d)", getNumberValue(number));
        printf("\n");
    }
    
    return 0;
}
