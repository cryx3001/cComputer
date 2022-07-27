#include <string>

union Code {
    uint16_t u16;
    uint8_t u8;
};

enum Type {
    FUNCTION,
    VALUE, // Which includes register and numbers (+ memory address)
    LABEL,
    NONE
};

typedef struct {
    enum Type arg1;
    enum Type arg2;
} Function;

Function* createFunction(enum Type arg1, enum Type arg2);

class Token {
    private:
        std::string name;
        enum Type type;
        Code code;
        Function* func;

    public:
        Token(std::string name, enum Type type, uint16_t code,
                Function* func = NULL){
            this->name = name;
            this->code = {code}; // If the token is a label, the code will be
                                 // the instruction address
            this->type = type;
            this->func = func;
        }

        Function* getFuncPtr(){ return this->func; }
        enum Type getType(){ return this->type; }
        union Code getCode(){ return this->code; }

        static int isTypeValid(Token* arg, enum Type exceptedType){
            return (exceptedType == NONE && arg == nullptr) ||
                (arg != nullptr && arg->getType() == exceptedType);
        }
};
