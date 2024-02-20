
#include "../h/lexer.h"

inline bool islower101(char c){
    return 'a' <= c && c <= 'z';
}

inline bool isliteral101(char c){
    return 'a' <= c && c <= 'z';
}

inline bool isspace101(char c){
    return c == ' ';
}

inline bool isnewline101(char c){
    return c == '\n';
}

int parse_line(char* start, Instruction* instr){
    char* end = start;

    Token command;
    Token op1;
    Token op2;

    // Handlers are returning the size of the handled text

    // TODO: handle literals, handle spectial cases, add error handler

    end += handle_word(start, &command);
    end += handle_space(start);
    end += handle_word(start, &op1);
    end += handle_space(start);
    end += handle_word(start, &op2);

    Token* p_op1 = malloc(sizeof(Token));
    *p_op1 = op1;

    Token* p_op2 = malloc(sizeof(Token));
    *p_op2 = op2;

    instruction_init(instr, command, p_op1, p_op2);
    return end - start;
}
int parse(const char* text, int size, Instruction** instrs){
    int i = 0;
    int lines = count_lines(text);
    const char* ptr = text;

    *instrs = (Instruction*)malloc(sizeof(Instruction) * lines);

    for (int i = 0; i < lines && ptr != '\0'; i++){
        ptr += parse_line(ptr, instrs + i);
    }

    return lines;
}


int handle_word(const char* text, Token* token){
    int size = 0;
    char curr = text[size];

    while (islower101(curr) && !isspace101(curr) && !isnewline101(curr)) {
        curr = text[++size];
    }

    Type type = get_type(text);
    token_init(token, type, text, size);

    return size;
}

int handle_space(const char* text){
    int size = 0;

    while (isspace101(text[size])){
        size++;
    }
    return size;
}

Type get_type(const char* text){
    for (int i = 0; i < INSTR_COUNT; i++){
        if (strcmp(text, instr_map[i]) == 0){
            return COMMAND;
        }
    }

    for (int i = 0; i < REG_COUNT; i++){
        if (strcmp(text, reg_map[i]) == 0){
            return REGISTER;
        }
    }

    return UNKNOWN;
}

int count_lines(const char* text){
    int lines = 0;
    char* ptr = text + 1;

    while (*ptr){
        lines += (*ptr != '\n' && ptr[1] == '\n');
        ptr++;
    }

    return lines;
}