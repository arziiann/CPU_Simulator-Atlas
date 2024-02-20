#include "maps.h"
#include "type.h"

#define TOKEN_SIZE 4

typedef struct
{
    Type type;
    char* text;
} Token;

void token_init(Token* self, Type type, char* start, int size);

void token_destroy(Token* self);
