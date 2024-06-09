#ifndef cgreenpoint_vm_h
#define cgreenpoint_vm_h

#include "../object/table.h"
#include "../object/value.h"

#include "../object/object.h"
#include "chunk.h"

#define FRAME_MAX 64
#define STACK_MAX (FRAME_MAX * UINT8_COUNT)

typedef struct {
  ObjClosure *closure;
  uint8_t *ip;
  Value *slots;
} CallFrame;

typedef struct {
  CallFrame frames[FRAME_MAX];
  int frameCount;
  Value stack[STACK_MAX];
  Value *stackTop;
  Table globals;
  Table strings;
  Obj *objects;
} VM;

typedef enum {
  INTERPRET_OK,
  INTERPRET_COMPILE_ERROR,
  INTERPRET_RUNTIME_ERROR,
} InterpretResult;

extern VM vm;

void initVM();
void freeVM();
InterpretResult interpret(const char *source);
InterpretResult interpretChunk(Chunk *chunk);
void push(Value value);
Value pop();

#endif
