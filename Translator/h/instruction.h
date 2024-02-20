#include "token.h"

typedef struct {
    Token command;
    Token* op1;
    Token* op2;
} Instruction;

void instruction_init(Instruction* self, Token command, Token* op1, Token* op2);

void instruction_destroy(Instruction* self);

void instruction_print(Instruction* self);