#ifndef cgreenpoint_compiler_h
#define cgreenpoint_compiler_h

#include "../object/object.h"
#include "../vm/chunk.h"

ObjFunction *compile(const char *source);
void markCompilerRoots();

#endif
