#include <stdint.h>
#include <stddef.h>
#include "test.h"

/* “起動直後クラッシュ” を避け、ミューテーションで到達させる */
int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    if (size > 0 && data[0] == 'X') {
        Fun1();
    }
    return 0;
}
