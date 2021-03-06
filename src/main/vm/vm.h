#ifndef cgreenpoint_vm_h
#define cgreenpoint_vm_h

#include "../object/value.h"
#include "../object/table.h"

#include "chunk.h"

#define STACK_MAX 512

typedef struct {
    Chunk* chunk;
    uint8_t* ip;
    Value stack[STACK_MAX];
    Value* stackTop;
    Table globals;
    Table strings;
    Obj* objects;
} VM;

typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR,
} InterpretResult;

extern VM vm;

void initVM();
void freeVM();
InterpretResult interpret(const char* source);
InterpretResult interpretChunk(Chunk* chunk);
void push(Value value);
Value pop();

#endif
