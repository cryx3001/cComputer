#include "token.hpp"

Function* createFunction(enum Type arg1, enum Type arg2){
    Function* f = new Function();
    f->arg1 = arg1;
    f->arg2 = arg2;
    return f;
}
