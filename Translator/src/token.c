#include "../h/token.h"

void token_init(Token* self, Type type, char* start, int size){
    self->type = type;
    self->text = malloc(size + 1);
    self->text[size] = 0;
    strcpy(self->text, start);
}

void token_destroy(Token* self){
    free(self->text);
}