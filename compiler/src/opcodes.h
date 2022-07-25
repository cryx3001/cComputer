#include <sys/types.h>

#define MAX_INSTRUCTIONS 512
#define INSTRUCTION_BITFIELD_SIZE 40
#define BINARY_MAX_SIZE MAX_INSTRUCTIONS * INSTRUCTION_BITFIELD_SIZE 

enum TypeArg {
    VALUE,
    LABEL,
    NONE,
};

typedef struct {
    char name[4];
    u_int8_t opCode; 
    enum TypeArg type1;
    enum TypeArg type2;
} Instruction;

typedef struct {
    char* labelName;
    u_int16_t opAddr;
} Label;


static Label LABELS[MAX_INSTRUCTIONS];
static Instruction INSTRUCTIONS_SET[15] = {
    {"NOP", 0x00, NONE, NONE},
    {"MOV", 0x01, VALUE, VALUE},
    {"SET", 0x02, VALUE, VALUE},

    {"ADD", 0x10, VALUE, VALUE},
    {"SUB", 0x11, VALUE, VALUE},
    {"MUL", 0x12, VALUE, VALUE},
    {"DIV", 0x13, VALUE, VALUE},

    {"CMP", 0x20, VALUE, VALUE},
    {"TST", 0x21, VALUE, NONE},

    {"BEQ", 0x30, LABEL, NONE},
    {"BNE", 0x31, LABEL, NONE},
    {"BLT", 0x32, LABEL, NONE},
    {"BGT", 0x33, LABEL, NONE},
    {"JMP", 0x34, LABEL, NONE},
    {"RET", 0x35, LABEL, NONE}
};
