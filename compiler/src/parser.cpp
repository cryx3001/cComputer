#include "parser.hpp"

Token* isFunction(std::string s){
    if(s.length() != 3)
        return nullptr;
    for(Token t : TOKEN_FUNCTIONS){
        if(s == t.getName())
            return new Token(s, t.getType(), t.getCode().u16,
                    createFunction(t.getFuncPtr()->arg1, t.getFuncPtr()->arg2));
    }
    return nullptr;
}

Token* isRegister(std::string s){
    if(s.length() == 2 && s[0] == 'R' && s[1] >= '0' && s[1] <= '4')
        return new Token(s, VALUE, (uint16_t) (s[1] - '0'), nullptr);
    return nullptr;
}

Token* isNumber(std::string s){
    if(s[0] == '#' && s.length() > 1){
        uint16_t number = getNumberValue(&s[1]);
        return new Token(s, VALUE, number, nullptr);
    }
    return nullptr;
}

Token* isLabel(std::string s){
    size_t len = s.length();
    if(len >= 2){
        enum Type t = s[len-1] == ':' ? LABEL_EXIT : LABEL_ENTRY;
        return new Token(s.substr(0,len - 1), t, 0x00, nullptr);
    }
    return nullptr;
}

Token* getToken(std::string s){
    Token* (*func[4])(std::string) = {isFunction, isRegister, isNumber, isLabel};
    for(Token* (*f)(std::string) : func){
        Token* t = f(s);
        if(t != nullptr)
            return t;
    }
    return nullptr;
}

