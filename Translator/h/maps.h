#define INSTR_COUNT 14
#define INSTR_SIZE 4
#define REG_COUNT 7
#define REG_SIZE 4
#define FUNCTION_SIZE 8
#define FUNCTION_COUNT 3

#include "includes.h"

void instruction_map_init(char map[][INSTR_SIZE]) {
    strcpy(map[0], "mov");
    strcpy(map[1], "add");
    strcpy(map[2], "sub");
    strcpy(map[3], "mul");
    strcpy(map[4], "div");
    strcpy(map[5], "and");
    strcpy(map[6], "or");
    strcpy(map[7], "not");
    strcpy(map[8], "cmp");
    strcpy(map[9], "jmp");
    strcpy(map[10], "jg");
    strcpy(map[11], "jl");
    strcpy(map[12], "je");
    strcpy(map[13], "lit");
}

void reg_map_init(char map[][REG_SIZE]) {
    strcpy(map[0], "ayb"); // ayb is readonly
    strcpy(map[1], "ben");
    strcpy(map[2], "gim");
    strcpy(map[3], "da");
    strcpy(map[4], "ech");
    strcpy(map[5], "za");
    strcpy(map[6], "gh");
}

void functionality_map_init(char map[][FUNCTION_SIZE]) {
    strcpy(map[0], "reg-reg");
    strcpy(map[1], "reg-mem");
    strcpy(map[2], "mem-reg");
}

char instr_map[INSTR_COUNT][INSTR_SIZE];
char reg_map[REG_COUNT][REG_SIZE];
