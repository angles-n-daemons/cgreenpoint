#include <stdio.h>

#include "debug.h"

// simple helper function which tells us when we've reached the end of the line in question
int getLineOffset(Chunk* chunk, int offset, int line_count) {
    if (line_count == chunk->lines.line_counts[offset]) {
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

    int line_offset = 0;
    int line_count = 0;
    for (int offset = 0; offset < chunk->count;) {
        int old_offset = offset;
        offset = disassembleInstruction(chunk, offset, line_offset);
        
        // increment the line count from the instructions
        line_count += offset - old_offset;
        int new_line_offset = getLineOffset(chunk, line_offset, line_count);

        if (new_line_offset != line_offset) {
            line_offset = new_line_offset;
            line_count = 0;
        }
    }
}

static int simpleInstruction(const char* name, int offset) {
    printf("%s\n", name);
    return offset + 1;
}

static int constantInstruction(Chunk* chunk, int offset) {
    uint8_t constant = chunk->code[offset + 1];
    printf("%-16s %4d '", "OP_CONSTANT", constant);
    printValue(chunk->constants.values[constant]);
    printf("'\n");
    return offset + 2;
}

static int constantInstruction16(Chunk* chunk, int offset) {
    uint8_t firstByte = chunk->code[offset + 1];
    uint8_t secondByte = chunk->code[offset + 2];

    int constant = firstByte + (secondByte << 8);
    printf("%-16s %4d '", "OP_CONSTANT_16", constant);
    printValue(chunk->constants.values[constant]);
    printf("'\n");
    return offset + 3;
}

void printLineNum(LineInfo* lines, int offset) {
    if (offset > 0 && lines->line_nums[offset] == lines->line_nums[offset-1]) {
        printf("   | ");
    } else {
        printf("%4d ", lines->line_nums[offset]);
    }
}

int disassembleInstruction(Chunk* chunk, int offset, int line_offset) {
    printf("%04d ", offset);
    printLineNum(&chunk->lines, line_offset);

    uint8_t instruction = chunk->code[offset];
    switch(instruction) {
        case OP_RETURN:
            return simpleInstruction("OP_RETURN", offset);
        case OP_CONSTANT:
            return constantInstruction(chunk, offset);
        case OP_CONSTANT_16:
            return constantInstruction16(chunk, offset);
        default:
            printf("Unknown opcode %d\n", instruction);
            return offset + 1;
    }
}

