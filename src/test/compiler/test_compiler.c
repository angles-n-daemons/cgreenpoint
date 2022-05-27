#include <stdlib.h>

#include "../../common.h"
#include "../../vm/vm.h"

void testBasic() {
    initVM();
    interpret("5+4");
}

void testCompiler() {
    testBasic();
}
