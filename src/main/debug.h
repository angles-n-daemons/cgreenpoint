#ifndef cgreenpoint_debug_h
#define cgreenpoint_debug_h

#include "vm/chunk.h"

void disassembleChunk(Chunk* chunk, const char* name);
int disassembleInstruction(Chunk* chunk, int offset);
int getLineOffset(Chunk* chunk, int offset, int count);

#endif
