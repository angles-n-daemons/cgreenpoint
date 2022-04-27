#ifndef cgreenpoint_line_info_h
#define cgreenpoint_line_info_h

#include "common.h"

typedef struct {
    int count;
    int capacity;
    int* line_nums;
    int* line_counts;
} LineInfo;

void initLineInfo(LineInfo* lines);
bool isNewLine(LineInfo* lines, int line);
void freeLineInfo(LineInfo* lines);
void writeLineInfo(LineInfo* lines, int line_num);

#endif
