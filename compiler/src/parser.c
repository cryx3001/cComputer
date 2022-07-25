#include <stdlib.h>
#include <err.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>
#include <string.h>
#include "parser.h"

char* specialChars = ":#$%";

int contains(char c, char *s){
    for(; *s != '\0'; s++)
        if(c == *s)
            return 1;
    return 0;
}

int isText(char c){
    int numeric = c >= '0' && c <= '9';
    int alpha = (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    return alpha || numeric || contains(c, specialChars);
}

void toUpperCase(char* s){
    for(; *s != '\0'; s++)
        if(*s >= 'a' && *s <= 'z')
            *s -= 32;
}

char* fileToString(char* path){
    int fd = open(path, O_RDONLY);
    if(fd == -1)
        errx(1, "Couldn't open file %s!", path);
    off_t lenFile = lseek(fd, 0, SEEK_END);
    char* data = mmap(0, lenFile, PROT_READ, MAP_PRIVATE, fd, 0);
    printf("=====\n%s=====\n", data);
    return data;
}

char** getWords(char* text, size_t* numWords){
    char** words = malloc(sizeof(char*) * 4096);
    *numWords = 0;
    size_t start = 0, end = 0;
    int lookingForString = 1;
    for(size_t i = 0; text[i] != '\0'; i++){
        if(isText(text[i])) {
            if(lookingForString){
                lookingForString = 0;
                start = i;
            }
            end = i;
            continue;
        }
        if(start <= end && !lookingForString) {
            size_t sizeWord = end - start + 1;
            words[*numWords] = malloc(sizeof(char) * (sizeWord + 1));
            strncpy(words[*numWords], text + start, sizeWord);      
            words[*numWords][sizeWord] = '\0';
            toUpperCase(words[*numWords]);
            (*numWords)++;
            lookingForString = 1;
        }
    }
    return words;
}

Instruction* isWordInstruction(char* text, size_t* numArgs){
    for(size_t i = 0; i < INSTRUCTION_SET_SIZE; i++){
        Instruction* ins = &INSTRUCTIONS_SET[i];
        if(strcmp(text, ins->word.name) == 0){
            *numArgs = 2 - (ins->argType1 == NONE) - (ins->argType2 == NONE); 
            return ins;
        }
    }
    return NULL;
}

char* isWordNumber(char* text){
    if(text[0] == '#')
        return text + 1;
    return NULL;
}

int isWordRegister(char* text, int* registerCode){
    if(text[0] == 'R'){
        if(strlen(text) == 2 && text[1] >= '0' && text[1] <= '4')
            return 1;
        errx(1, "Bad register format! %s", text);
    }
    return 0;
}

char* getNumberBase(char* text, enum NumberBase* b){
    if(*text == '\0'){
        err(1, "Bad value format!");
    }
    switch(*text){
        case '$':
            *b = HEX;
            return text + 1;
        case '%':
            *b = BIN;
            return text + 1;
        default:
            *b = DEC;
            return text;
    }
}

u_int8_t getDigitValue(char c){
    if(c >= '0' && c <= '9')
        return c - '0';
    if(c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    errx(1, "Error while parsing digit %c, 0x%02X", c, c);
}

int isDigitOnRightBase(char c, enum NumberBase b){
    int tenFirstDigits = c >= '0' && c <= '9' && b == HEX || b == DEC;
    int twoFirstDigits = (c == '0' || c == '1') && b == BIN;
    int sixLastDigits = c >= 'A' && c <= 'F' && b == HEX;
    return tenFirstDigits || twoFirstDigits || sixLastDigits;
}

u_int8_t getNumberValue(char* text){
    if(*text == '\0'){
        err(1, "Bad value format!");
    }
    enum NumberBase b;
    char* numberText = getNumberBase(text, &b);
    size_t baseMul = 1;
    size_t sizeNumber = strlen(numberText);
    u_int8_t res = 0;
    for(size_t i = 0; i < sizeNumber; i++){
        char c = numberText[sizeNumber - 1 - i];
        if(!isDigitOnRightBase(c, b))
            errx(1, "Digit using wrong format on base %d (%c, 0x%02X)", b,c,c);
        res += getDigitValue(c) * baseMul;
        baseMul *= b;
    }
    return res;
}
