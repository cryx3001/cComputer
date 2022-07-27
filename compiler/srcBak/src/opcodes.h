#include <sys/types.h>

#define MAX_INSTRUCTIONS 512
#define INSTRUCTION_BITFIELD_SIZE 40
#define INSTRUCTION_SET_SIZE 15 
#define BINARY_MAX_SIZE MAX_INSTRUCTIONS * INSTRUCTION_BITFIELD_SIZE 

enum WordType {
    INSTRUCTION,
    VALUE,
    LABEL,
    NONE,
};

union WordDataType {
    u_int8_t u8;
    u_int16_t u16;
};

typedef struct {
    char name[4];
    union WordDataType opCode; 
    enum WordType type;
} Word;

typedef struct {
    Word word;
    enum WordType argType1;
    enum WordType argType2;
} Instruction;

typedef struct {
    char* labelName;
    u_int16_t opAddr;
} Label;


static Label LABELS[MAX_INSTRUCTIONS];
static Instruction INSTRUCTIONS_SET[INSTRUCTION_SET_SIZE] = {
    {{"NOP", {0x00}, INSTRUCTION}, NONE, NONE},
    {{"MOV", {0x01}, INSTRUCTION}, VALUE, VALUE},
    {{"SET", {0x02}, INSTRUCTION}, VALUE, VALUE},

    {{"ADD", {0x10}, INSTRUCTION}, VALUE, VALUE},
    {{"SUB", {0x11}, INSTRUCTION}, VALUE, VALUE},
    {{"MUL", {0x12}, INSTRUCTION}, VALUE, VALUE},
    {{"DIV", {0x13}, INSTRUCTION}, VALUE, VALUE},

    {{"CMP", {0x20}, INSTRUCTION}, VALUE, VALUE},
    {{"TST", {0x21}, INSTRUCTION}, VALUE, NONE},

    {{"BEQ", {0x30}, INSTRUCTION}, LABEL, NONE},
    {{"BNE", {0x31}, INSTRUCTION}, LABEL, NONE},
    {{"BLT", {0x32}, INSTRUCTION}, LABEL, NONE},
    {{"BGT", {0x33}, INSTRUCTION}, LABEL, NONE},
    {{"JMP", {0x34}, INSTRUCTION}, LABEL, NONE},
    {{"RET", {0x35}, INSTRUCTION}, LABEL, NONE}
};
