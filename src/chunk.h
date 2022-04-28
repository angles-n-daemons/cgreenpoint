#ifndef cgreenpoint_chunk_h
#define cgreenpoint_chunk_h

#include "common.h"
#include "line_info.h"
#include "value.h"

typedef enum {
    OP_CONSTANT,
    OP_RETURN,
} OpCode;

// Note: I tried to do an efficient line info implementation at the commit 78ec88764cce29a7b23e604104b42a6b583b6399
// it worked, but it scared the shit out of me

typedef struct {
    int count;
    int capacity;
    uint8_t* code;
    int* lines;
    ValueArray constants;
} Chunk;

void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte, int line);
int addConstant(Chunk* chunk, Value value);

#endif
