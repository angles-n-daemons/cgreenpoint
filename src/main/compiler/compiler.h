#ifndef cgreenpoint_compiler_h
#define cgreenpoint_compiler_h

#include "../vm/chunk.h"
#include "../object/object.h"

bool compile(const char* source, Chunk* chunk);

#endif
