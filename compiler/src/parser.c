#include <stdlib.h>
#include <err.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>
#include <string.h>
#include "opcodes.h"

int isText(char c){
    int numeric = c >= '0' && c <= '9';
    int alpha = (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    return alpha || numeric || c == ':';
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
            (*numWords)++;
            lookingForString = 1;
        }
    }

    return words;
}
