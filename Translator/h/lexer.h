//#ifndef "../h/lexer.h"
//#define "../h/lexer.h"

#include "instruction.h"
#include <stdbool.h>

inline bool islower101(char c);
inline bool isliteral101(char c);
inline bool isspace101(char c);
inline bool isnewline101(char c);

int parse(const char* text, int size, Instruction** instrs);

int parse_line(char* start, Instruction* instr);

int handle_word(const char* text, Token* token);

int handle_space(const char* text);

Type get_type(const char* text);

int count_lines(const char* text);
//#endif