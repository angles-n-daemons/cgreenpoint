#include <stdlib.h>

#include "../object/value.h"
#include "../util/memory.h"

#include "chunk.h"
#include "vm.h"

void initChunk(Chunk *chunk) {
  chunk->count = 0;
  chunk->capacity = 0;
  chunk->code = NULL;
  chunk->lines = NULL;
  initValueArray(&chunk->constants);
}

void freeChunk(Chunk *chunk) {
  FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
  FREE_ARRAY(int, chunk->lines, chunk->capacity);
  freeValueArray(&chunk->constants);
  initChunk(chunk);
}

void writeChunk(Chunk *chunk, uint8_t byte, int line) {
  if (chunk->capacity < chunk->count + 1) {
    int oldCapacity = chunk->capacity;

    chunk->capacity = GROW_CAPACITY(oldCapacity);
    chunk->code =
        GROW_ARRAY(uint8_t, chunk->code, oldCapacity, chunk->capacity);
    chunk->lines = GROW_ARRAY(int, chunk->lines, oldCapacity, chunk->capacity);
  }

  chunk->code[chunk->count] = byte;
  chunk->lines[chunk->count] = line;
  chunk->count++;
}

void writeConstant(Chunk *chunk, Value value, int line) {
  int count = chunk->count;
  int constant = addConstant(chunk, value);
  bool shouldUse16 = constant > 255;
  if (shouldUse16) {
    uint8_t firstByte = constant & 0xff;
    uint8_t secondByte = (constant >> 8) & 0xff;

    writeChunk(chunk, OP_CONSTANT_16, line);
    writeChunk(chunk, firstByte, line);
    writeChunk(chunk, secondByte, line);
  } else {
    writeChunk(chunk, OP_CONSTANT, line);
    writeChunk(chunk, constant, line);
  }
}

int addConstant(Chunk *chunk, Value value) {
  push(value);
  writeValueArray(&chunk->constants, value);
  pop();
  return chunk->constants.count - 1;
}
