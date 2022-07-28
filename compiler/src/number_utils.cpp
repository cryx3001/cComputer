#include <err.h>
#include <string.h>
#include "number_utils.hpp"

enum NumberBase {
    BIN = 2, DEC = 10, HEX = 16
};

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
    int tenFirstDigits = c >= '0' && c <= '9' && (b == HEX || b == DEC);
    int twoFirstDigits = (c == '0' || c == '1') && b == BIN;
    int sixLastDigits = c >= 'A' && c <= 'F' && b == HEX;
    return tenFirstDigits || twoFirstDigits || sixLastDigits;
}

u_int16_t getNumberValue(char* text){
    if(*text == '\0'){
        err(1, "Bad value format!");
    }
    enum NumberBase b;
    char* numberText = getNumberBase(text, &b);
    size_t baseMul = 1;
    size_t sizeNumber = strlen(numberText);
    u_int16_t res = 0;
    for(size_t i = 0; i < sizeNumber; i++){
        char c = numberText[sizeNumber - 1 - i];
        if(!isDigitOnRightBase(c, b))
            errx(1, "Digit using wrong format on base %d (%c, 0x%02X)", b,c,c);
        res += getDigitValue(c) * baseMul;
        baseMul *= b;
    }
    return res;
}
