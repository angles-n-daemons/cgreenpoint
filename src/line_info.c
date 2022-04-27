#include "line_info.h"
#include "memory.h"

void initLineInfo(LineInfo* lines) {
    lines->count = 0;
    lines->capacity = 0;
    lines->line_nums = NULL;
    lines->line_counts = NULL;
}

bool isNewLine(LineInfo* lines, int line) {
    // array is empty
    if (lines->count == 0) {
        return true;
    }
    int current_line = lines->line_nums[lines->count - 1];
    return current_line != line;
}

void freeLineInfo(LineInfo* lines) {
    FREE_ARRAY(int, lines->line_nums, lines->capacity);
    FREE_ARRAY(int, lines->line_counts, lines->capacity);
    initLineInfo(lines);
}

void writeLineInfo(LineInfo* lines, int line) {
    bool is_new_line = isNewLine(lines, line);
    bool at_capacity = lines->capacity < lines->count + 1;

    if (is_new_line && at_capacity) {
        int oldCapacity = lines->capacity;

        lines->capacity = GROW_CAPACITY(oldCapacity);
        lines->line_nums = GROW_ARRAY(int, lines->line_nums, oldCapacity, lines->capacity);
        lines->line_counts = GROW_ARRAY(int, lines->line_counts, oldCapacity, lines->capacity);
    }

    if (is_new_line) {
        lines->line_nums[lines->count] = line;
        lines->line_counts[lines->count] = 1;
        lines->count++;
    } else {
        lines->line_counts[lines->count-1]++;
    }
}
