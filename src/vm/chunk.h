#ifndef cgreenpoint_chunk_h
#define cgreenpoint_chunk_h

#include "../common.h"
#include "value.h"

typedef enum {
    OP_CONSTANT,
    OP_CONSTANT_16,
    OP_NIL,
    OP_FALSE,
    OP_TRUE,
    OP_EQUAL,
    OP_GREATER,
    OP_LESS,
    OP_ADD,
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DIVIDE,
    OP_NOT,
    OP_NEGATE,
    OP_RETURN,
} OpCode;

typedef struct {
    int count;
    int capacity;
    uint8_t* code;
    int* lines;
    ValueArray constants;
    // TODO: add line info
} Chunk;

void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte, int line);
void writeConstant(Chunk* chunk, Value value, int line);
int addConstant(Chunk* chunk, Value value);

#endif
