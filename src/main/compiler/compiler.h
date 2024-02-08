#ifndef cgreenpoint_compiler_h
#define cgreenpoint_compiler_h

#include "../vm/chunk.h"
#include "../object/object.h"

ObjFunction* compile(const char* source);

#endif
