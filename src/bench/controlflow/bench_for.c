#include <stdio.h>

#include "../bench_common.h"

void benchSimpleFor() {
  benchmark("\n \
        var a = 0; \
        for (var i = 0; i < 5; i = i+1) {\n \
            a = a + 1;\n \
        }\n \
    ",
            0);
}

void benchFor() {
  printf("benchFor starting\n");
  benchSimpleFor();
  printf("benchFor completed\n\n");
}
