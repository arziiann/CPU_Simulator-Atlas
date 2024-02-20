#include "../h/instruction.h"

void instruction_init(Instruction* self, Token command, Token* op1, Token* op2){
    self->command = command;
    self->op1 = op1;
    self->op2 = op2;
}

void instruction_destroy(Instruction* self){
    token_destroy(self->op1);
    token_destroy(self->op2);

    free(self->op1);
    free(self->op2);
}

void instruction_print(Instruction* self){
    printf("Command: %d %s, Op1: %d %s, Op2 %d %s \n",
            self->command.type, self->command.text,
            self->op1->type, self->op1->text,
            self->op2->type, self->op2->text);
}