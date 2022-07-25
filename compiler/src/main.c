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
        printf("Word %lu: %s\n", i, y[i]);
    }
    
    return 0;
}
