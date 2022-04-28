#include <stdio.h>

#include "debug.h"

int getLineOffset(LineInfo* lines, int offset, int line_count) {
    if (line_count == lines->line_counts[offset]) {
        return offset+1;
    }
    return offset;
}

void printLineInfo(LineInfo* lines) {
    printf("Line debug info");
    printf("\n");
    for (int i = 0; i < lines->count; i++) {
        printf("line offset %d", i);
        printf("\n");
        printf("num: %d, count: %d", lines->line_nums[i], lines->line_counts[i]);
        printf("\n");
    }
}

void disassembleChunk(Chunk* chunk, const char* name) {
    printf("== %s ==\n", name);

    for (int offset = 0; offset < chunk->count;) {
        offset = disassembleInstruction(chunk, offset);
    }
}

static int simpleInstruction(const char* name, int offset) {
    printf("%s\n", name);
    return offset + 1;
}

static int constantInstruction(const char* name, Chunk* chunk, int offset) {
    uint8_t constant = chunk->code[offset + 1];
    printf("%-16s %4d '", name, constant);
    printValue(chunk->constants.values[constant]);
    printf("'\n");
    return offset + 2;
}

void printLineNum(int* lines, int offset) {
    if (offset > 0 && lines[offset] == lines[offset-1]) {
        printf("   | ");
    } else {
        printf("%4d ", lines[offset]);
    }
}

int disassembleInstruction(Chunk* chunk, int offset) {
    printf("%04d ", offset);
    printLineNum(chunk->lines, offset);

    uint8_t instruction = chunk->code[offset];
    switch(instruction) {
        case OP_RETURN:
            return simpleInstruction("OP_RETURN", offset);
        case OP_CONSTANT:
            return constantInstruction("OP_CONSTANT", chunk, offset);
        default:
            printf("Unknown opcode %d\n", instruction);
            return offset + 1;
    }
}

