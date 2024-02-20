#define _GNU_SOURCE
#include "h/lexer.h"

void init() {
    instruction_map_init(instr_map);
    reg_map_init(reg_map);
}

int read(char* path, char** text) {
    FILE *f = fopen(path, "r");
    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET);

    char* string = (char*)malloc(fsize + 1);
    fread(string, fsize, 1, f);
    string[fsize] = 0;
    fclose(f);

    *text = string;

    return fsize;
}

int main(int argc, char ** argv)
{
    init();
    char* text;
    int size = read(argv[1], &text);

    printf("%s\n", text);

    Instruction* instrs;
    int lines = parse(text, size, &instrs);
    
    for (int i = 0; i < lines; i++) {
        instruction_print(instrs + i);
    }

    for (int i = 0; i < lines; i++) {
        instruction_destroy(instrs + i);
    }

    free(text);
}
