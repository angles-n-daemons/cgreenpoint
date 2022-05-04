#include "../common.h"
#include "../debug.h"
#include "vm.h"

VM vm;

static void resetStack() {
    vm.stackTop = vm.stack;
}

void initVM() {
    resetStack();
}

void freeVM() {

}

void push(Value value) {
    *vm.stackTop = value;
    vm.stackTop++;
}

Value pop() {
    vm.stackTop--;
    return *vm.stackTop;
}

static InterpretResult run() {
#define READ_BYTE() (*vm.ip++)
#define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()])
#define READ_CONSTANT_16() (vm.chunk->constants.values[(READ_BYTE()) + (READ_BYTE() << 8)])
#define BINARY_OP(op) \
    do { \
        double b = pop(); \
        double a = pop(); \
        push(a op b); \
    } while (false);

    uint8_t* last_ip = vm.ip;
    int line_count = 0;
    for (;;) {

#ifdef DEBUG_TRACE_EXECUTION

        // Print the stack
        printf("          ");
        for (Value* slot = vm.stack; slot < vm.stackTop; slot++) {
            printf("[ ");
            printValue(*slot);
            printf(" ]");
        }
        printf("\n");

        // Dissasemble instruciton and modify the line counts
        line_count += vm.ip - last_ip;
        int new_line_offset = getLineOffset(vm.chunk, vm.line_offset, line_count);
        if (new_line_offset != vm.line_offset) {
            vm.line_offset = new_line_offset;
            line_count = 0;
        }
        disassembleInstruction(vm.chunk, (int)(vm.ip - vm.chunk->code), vm.line_offset);
        last_ip = vm.ip;
#endif

        uint8_t instruction;
        switch (instruction = READ_BYTE()) {
            case OP_CONSTANT: {
                Value constant = READ_CONSTANT();
                push(constant);
                break;
            }
            case OP_CONSTANT_16: {
                Value constant = READ_CONSTANT_16();
                push(constant);
                break;
            }
            case OP_NEGATE: {
                push(-pop());
                break;
            }
            case OP_ADD: {
                BINARY_OP(+);
                break;
            }
            case OP_SUBTRACT: {
                BINARY_OP(-);
                break;
            }
            case OP_MULTIPLY: {
                BINARY_OP(*);
                break;
            }
            case OP_DIVIDE: {
                BINARY_OP(/);
                break;
            }
            case OP_RETURN: {
                printValue(pop());
                printf("\n");
                return INTERPRET_OK;
            }
        }
    }
#undef READ_BYTE
#undef READ_CONSTANT
#undef READ_CONSTANT16
}

InterpretResult interpret(Chunk* chunk) {
    vm.chunk = chunk;
    vm.ip = vm.chunk->code;
    return run();
}
