#ifndef cgreenpoint_debug_h
#define cgreenpoint_debug_h

#include "chunk.h"

void disassembleChunk(Chunk* chunk, const char* name);
int disassembleInstruction(Chunk* chunk, int offset, int line_offset);

#endif
